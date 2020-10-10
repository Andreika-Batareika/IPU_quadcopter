#ifndef TPOINT_H
#define TPOINT_H
#include <string.h>

class Tpoint
{
public:
    Tpoint();
bool completed;// флаг выполнения точки
bool started; //флаг начала к выполнению движения к точке
float min_dR ; // минимальное значение при котором считается что точка выполнена по требованию достижеия расстояния до ней
      bool TVV,TVPS,TKT_GSK,TKT_SSK; // флаги учитывающие TVV, TVPS, TKT_GSK, TKT_SSK
    float X,Y,Z, t_TVV,t_TVPS;//X, Y, Z - координаты в стартовой системе координат/координаты в другой иной системе координат при переключении типа системы координат
    // t_TVV  - Требуемое время выполнения,  t_TVV  - Требуемое время выполнения
      std::string type_SK;// тип системы координат "SSK, GSK"
        std::string maneuver; // маневр
float time_start;// время запуска котрольной точки
};

#endif // TPOINT_H