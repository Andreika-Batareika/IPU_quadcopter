#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
#include <user.h>
#include <mathmodel.h>
#include <mathmodel.h>
#include "avto.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),  ui(new Ui::MainWindow)
{
    system("python3 /home/fastil/build-TestQt_windows_Desctop-Debug/TestQT_windows/test1.py");

    ui->setupUi(this);
    QString x = QString("Start");
    QString y = QString("1");
    ui->textEdit->setText(x+"\n");







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
 //   update_parametrs();
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
    std::string arr[]={"1","2"};
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
    add_maneuver(ui->number_point->currentIndex(),ui->types_of_maneuvres->currentText().toStdString());
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
    std::string arr[]={"1","2"};
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
    // тип автопилота
    //маршрутные точки
    //маневры после достижения котрольных точек
    //список заданий

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
void MainWindow::update_parametrs(std::string typeaudopilot,std::string typemodel, bool arrbool[], float dt, std::string filename)
{
    if (typeaudopilot=="avtopilot_for_quatrocopter"){
       WAvto = new avtoquatro(0);
    }
    if (typemodel=="model_for_quatrocopter"){
        WMathmodel  = new mathmodel_quatro(new float[0,1],0);
    }
    std::vector<Tpoint> vectorPoints;
   WUser=new user(WMathmodel,WAvto,vectorPoints);
}
// смена вида управления
void MainWindow::view_control(int number_view)
{

}
// добавление точки маршрута
void MainWindow::add_waypoint(bool TVPS ,bool TVV, bool GSK, bool SSK, float X1,float X2, float X3  )
{

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
void MainWindow::add_maneuver(int number_point, std::string maneuver)
{

}// добавление маневра в список маневров с порядковым номером  number_point и типом маневра   maneuver



std::vector<float> MainWindow::modeling_waypoint(float t1,float t2,std::vector<float> V1){

}

void MainWindow::readFile(std::string file_name, std::string arr[])
{

}

//запись в файл массив float
void MainWindow::writeFile(std::string file_name, float arr[])
{

}

void MainWindow:: set_start_position()
{

}


void MainWindow:: set_finish_position()
{

}
