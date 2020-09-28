#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


ui->

 //   for ( ; ; )
  //  {
        QString x = QString("Strart");
        QString y = QString("1");

        ui->textEdit->setText(x+"\n");

 //   }




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
    update_parametrs();
}
//кнопка создания маршрутной точки
void MainWindow::on_pushButton_4_clicked()
{
   add_waypoint(lineEdit.,);
}


// запись в файл из панели текста
void MainWindow::on_pushButton_7_clicked()
{
    writefile();
}

//считать из файла в панель текста
void MainWindow::on_pushButton_6_clicked()
{
    readfile();
}


//вид управления ЛА
void MainWindow::on_comboBox_7_activated(const QString &arg1)
{
    view_control();
}

//удалить маневр
void MainWindow::on_pushButton_12_clicked()
{
    delete_maneuver();
}

//добавление маевра после выполнение кнотрольной точки
void MainWindow::on_pushButton_8_clicked()
{
add_maneuver();
}

// начальная точка для моделирования маршрута
void MainWindow::on_pushButton_9_clicked()
{
first_point_for_model();
}

// конечная точка для моделирования маршрута
void MainWindow::on_pushButton_13_clicked()
{
finish_point_for_model();
}

//смоделировать маршрут
void MainWindow::on_pushButton_14_clicked()
{
modeling_waypoint();
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
read_from_file();
}


//нарисовать график перемннной из файла

void MainWindow::on_pushButton_10_clicked()
{
watch_fromfile();
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

//запись в файл массив float
void MainWindow::writefile(std::string file_name, float arr[])
{

}

//обновление параметров объекта
void MainWindow::update_parametrs(bool arrbool[], float dt, std::string filename)
{

}
// смена вида управления
void MainWindow::view_control(int number_view)
{

}
// добавление точки маршрута
void MainWindow::add_waypoint(bool TVPS ,bool TVV, bool GSK, bool SSK, int X1,int X2, int X3, float dt, float tk  )
{

}
