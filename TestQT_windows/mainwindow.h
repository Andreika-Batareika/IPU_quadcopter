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

      float X,Y,Z, t_TVV,t_TVPS;
        std::string type_SK;
       bool TVV,TVPS,TKT_GSK,TKT_SSK;
   void start();
   void restart();
    void exit();
    void writefile(std::string file_name, float arr[]);
    void readfile(std::string file_name, float arr[]);
     void update_parametrs(bool arrbool[], float dt, std::string filename);
     void view_control(int number_view);
     void add_waypoint(bool TVPS ,bool TVV, bool GSK, bool SSK, int X1,int X2, int X3, float dt, float tk  );
    void  delete_maneuver(int number_point);
    void add_maneuver(int number_point, std::string maneuver);
    void first_point_for_model();
   void  finish_point_for_model();
    void modeling_waypoint();
    void set_start_position();
    void set_finish_position();


};

#endif // MAINWINDOW_H
