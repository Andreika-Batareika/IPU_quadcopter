#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_7_activated(const QString &arg1);

    void on_pushButton_12_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;


   void start(); // процедура старта программы
   void restart();// процедура перезапуска программы
    void exit();// процедура завершения программы
    void writefile(std::string file_name, std::string arr[]); // запись в файл file_name в строчку через пробел все значения arr[]
    void readfile(std::string file_name, std::string arr[]); // считывание из файла file_name в значения arr
     void update_parametrs(bool arrbool[], float dt, std::string filename); // процедура обновление/ задание параметров объектра
     void view_control(int number_view); // выбор котнроля : ручной/автопилот и др, выбирается путем смены активрованной ячейки комбобокса
     void add_waypoint(bool TVPS ,bool TVV, bool GSK, bool SSK, float X1,float X2, float X3 ); // добавление маршрутной точки с описанными ранее  параметрами
    void  delete_maneuver(int number_point);// удаление маневра с текущим порядковым номером
    void add_maneuver(int number_point, std::string maneuver); // добавление маневра в список маневров с порядковым номером  number_point и типом маневра   maneuver
    void first_point_for_model( std::string type_SK, float X1,float X2, float X3 ); // создание  первой точки для модлиррования
   void  finish_point_for_model( std::string type_SK, float X1,float X2, float X3);// создание конечной точки для модлиррования
    void modeling_waypoint(); // моделирование  полета по двум точкам
    void set_start_position(); // задание параметров состояния объекта в начальной точке моделирования
    void set_finish_position();// задание параметров состояния объекта в конечной точке моделирования


};

#endif // MAINWINDOW_H
