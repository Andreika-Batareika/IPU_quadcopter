#include <QSerialPort>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"
#include <string.h>
#include <user.h>
#include <mathmodel.h>
#include <mathmodel.h>
#include "avto.h"
#include "serialportreader.h"


#include <QMessageBox>
#include <QTextStream>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow),  serialPortReader(new QSerialPort(this)), m_settings(new SettingsDialog)
{
    m_settings->exec();
    ui->setupUi(this);
    QString x = QString("Start");
    QString y = QString("1");
    ui->textEdit->setText(x+"\n");

   // connect(serialPortReader, &QSerialPort::ge, this, &MainWindow::writeData);
     connect(serialPortReader, &QSerialPort::readyRead, this, &MainWindow::readData);

/*

    QString str = "123.2 234.2   23123  432";
    QTextStream stream(&str);
    QList<float> array;
    while (!stream.atEnd()) {
        float number;
        stream >> number;
        array.append(number);
    }


*/

}








bool MainWindow::openSerialPort()
{

    const SettingsDialog::Settings p = m_settings->settings();
    serialPortReader->setPortName(p.name);
  //  serialPortReader->setPortName("/dev/ttyUSB0");
    serialPortReader->setBaudRate(p.baudRate);
    serialPortReader->setDataBits(p.dataBits);
    serialPortReader->setParity(p.parity);
    serialPortReader->setStopBits(p.stopBits);
    serialPortReader->setFlowControl(p.flowControl);
    if (serialPortReader->open(QIODevice::ReadWrite)) {

       readText(tr("Connected to %1 : %2, %3, %4, %5, %6")
                              .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                              .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
       QMessageBox messageBox;
       messageBox.information(this,"USB найден",tr("Connected to %1 : %2, %3, %4, %5, %6")
                              .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
                                                      .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
       return true;

         } else {

             readText( tr("Error %1").arg(serialPortReader->errorString()));
             QMessageBox messageBox;
             messageBox.critical(this,"Error",tr("Error %1").arg(serialPortReader->errorString()));
             return false;


        }


}














void MainWindow::writeData(const QByteArray &data)
{
    serialPortReader->write(data);
}
//! [6]

//! [7]
void MainWindow::readData()
{
    const QByteArray data = serialPortReader->readAll();
    readText(data);
}














MainWindow::~MainWindow()
{
    delete ui;
}
//кнопка рестарта
void MainWindow::on_pushButton_3_clicked()
{
  restart();
}


//start_button
void MainWindow::on_pushButton_2_clicked()
{
     start();
}
//кнопка завершения программы
void MainWindow::on_pushButton_clicked()
{
    exit();
}
//кнопка обновления параметров
void MainWindow::on_pushButton_5_clicked()
{
    bool arrBool [6];
    arrBool[0] = ui->checkBox->isChecked();
    arrBool[1] = ui->checkBox_2->isChecked();
    arrBool[2] = ui->checkBox_3->isChecked();
    arrBool[3] = ui->checkBox_4->isChecked();
    arrBool[4] = ui->checkBox_5->isChecked();
    arrBool[5] = ui->checkBox_6->isChecked();
    update_parametrs(ui->type_avtopilot->currentText(),ui->Match_model->currentText(),arrBool,ui->lineEdit_12->text().toFloat(),ui->lineEdit_11->text());
}
//кнопка создания маршрутной точки
void MainWindow::on_pushButton_4_clicked()
{
   add_waypoint(true,true,true,true,ui->lineEdit_3->text().toFloat(),ui->lineEdit_2->text().toFloat(),ui->lineEdit->text().toFloat());
}


// запись в файл из панели текста
void MainWindow::on_pushButton_7_clicked()
{
    float arr[]={1,2};

    writeFile("1.txt",arr);
}

//считать из файла в панель текста
void MainWindow::on_pushButton_6_clicked()
{
    QString arr[]={"1","2"};
    readFile("1.txt",arr);
}


//вид управления ЛА
void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
  //  view_control();
}

//удалить маневр
void MainWindow::on_pushButton_12_clicked()
{
 //   delete_maneuver();
}

//добавление маевра после выполнение кнотрольной точки
void MainWindow::on_pushButton_8_clicked()
{
    add_maneuver(ui->number_point->currentIndex(),ui->types_of_maneuvres->currentText());
}

// начальная точка для моделирования маршрута
void MainWindow::on_pushButton_9_clicked()
{
  //  first_point_for_model();
}

// конечная точка для моделирования маршрута
void MainWindow::on_pushButton_13_clicked()
{
//    finish_point_for_model();
}

//смоделировать маршрут
void MainWindow::on_pushButton_14_clicked()
{
    float t1=0;
    float t2=0;
    std::vector <float> V1;
modeling_waypoint(t1,t2,V1);
}


//задать параметры как начальные значения для моделирования
void MainWindow::on_pushButton_15_clicked()
{
   set_start_position();
}
//задать параметры как конечные значения для моделирования
void MainWindow::on_pushButton_16_clicked()
{
   set_finish_position();
}
// считать из файла
void MainWindow::on_pushButton_11_clicked()
{
    QString arr[]={"1","2"};
    readFile("1.txt",arr);
 //   read_from_file();
}


//нарисовать график перемннной из файла

void MainWindow::on_pushButton_10_clicked()
{
   // watch_fromfile();
}







// загрузка в параметры пользователя все параметры введеные в панель
void MainWindow::start()
{
   bool boolOpenSerialPort = openSerialPort();
   if (boolOpenSerialPort){
       if (WMathmodel==nullptr) {
           QMessageBox messageBox;
           messageBox.critical(0,"Ошибка","Математическая модель не выбрана !");
       } else
           if (WAvto ==nullptr){
           QMessageBox messageBox;
           messageBox.critical(0,"Ошибка","Автопилот не выбран !");
       } else
           WUser = new user(WMathmodel,WAvto,arrayPointsForStart);

   }

    // тип автопилота
    //маршрутные точки
    //маневры после достижения котрольных точек
    //список заданий

 /*   const int argumentCount = QApplication::arguments().size();
    const QStringList argumentList = QApplication::arguments();

    //  QTextStream standardOutput(stdout);

    // standardOutput << QObject::tr("Usage: %1 <serialportname> [baudrate]");

QSerialPort serialPort;
  //  serialPort =new QSerialPort ();

    const QString serialPortName = "/dev/ttyUSB0"  ;  //argumentList.at(1);
    serialPort.setPortName(serialPortName);

    const int serialPortBaudRate = (argumentCount > 2)
                                       ? argumentList.at(2).toInt() : QSerialPort::Baud9600;
    serialPort.setBaudRate(serialPortBaudRate);

    if (!serialPort.open(QIODevice::ReadOnly)) {
        //      standardOutput << QObject::tr("Failed to open port %1, error: %2")
        //                        .arg(serialPortName)
        //                       .arg(serialPort.errorString())
        //                    << "\n";
      //  return 1;
        readText("--");
    }
  //  serialPortReader =new SerialPortReader(&serialPort);
    //serialPortReader->mainWindow=this;
    QApplication::exec();
*/
}


//перезапуск программы
void MainWindow::restart()
{
    //обнуление всех значений
}
// выход из программы
void MainWindow::exit()
{
    // удаление объекта пользователя
    // сохранение (информация/значения датчиков) и (информация/ошибки) в файлы программы заданные по умолчанию
}




//обновление параметров объекта
void MainWindow::update_parametrs(QString typeaudopilot,QString typemodel, bool arrbool[], float dt, QString filename)
{
    bool* boolArr =arrbool;
    readText(QString(boolArr[0]));
    readText(QString(boolArr[1]));
    readText(QString(boolArr[2]));
    readText(QString(boolArr[3]));
    readText(QString(boolArr[4]));
    readText(QString(boolArr[5]));

    if (typeaudopilot=="Квадрокоптер"){
       WAvto = new avtoquatro(0);
    }
    if (typemodel=="Квадрокоптер"){
        WMathmodel  = new mathmodel_quatro(new float[0,1],0);
    }

}
// смена вида управления
void MainWindow::view_control(int number_view)
{

}
// добавление точки маршрута
void MainWindow::add_waypoint(bool TVPS ,bool TVV, bool GSK, bool SSK, float X1,float X2, float X3  )
{
    arrayPointsForStart.resize(arrayPointsForStart.size()+1);
    arrayPointsForStart[arrayPointsForStart.size()-1].t_TVPS = TVPS;
    arrayPointsForStart[arrayPointsForStart.size()-1].TVV= TVV;
    arrayPointsForStart[arrayPointsForStart.size()-1].TKT_GSK = GSK;
    arrayPointsForStart[arrayPointsForStart.size()-1].TKT_SSK = SSK;

    arrayPointsForStart[arrayPointsForStart.size()-1].X1 = X1;
    arrayPointsForStart[arrayPointsForStart.size()-1].X2 = X2;
    arrayPointsForStart[arrayPointsForStart.size()-1].X3 = X3;

}

void MainWindow::on_Match_model_currentIndexChanged(int index)
{

}

void MainWindow::on_type_avtopilot_currentIndexChanged(int index)
{switch (index) {
    case 0:

        break;
    default:
        break;
    }

}
void MainWindow::add_maneuver(int number_point, QString maneuver)
{

}// добавление маневра в список маневров с порядковым номером  number_point и типом маневра   maneuver



std::vector<float> MainWindow::modeling_waypoint(float t1,float t2,std::vector<float> V1){

}

void MainWindow::readFile(QString file_name, QString arr[])
{
}

//запись в файл массив float
void MainWindow::writeFile(QString file_name, float arr[])
{

}

void MainWindow:: set_start_position()
{

}


void MainWindow:: set_finish_position()
{

}


void MainWindow::readText(QString comeText){

        ui->textEdit->setText(comeText);
}
// насйтройка usb
void MainWindow::on_pushButton_17_clicked()
{
    m_settings->exec();
}
