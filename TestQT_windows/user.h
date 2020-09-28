#ifndef USER_H
#define USER_H
#include <mathmodel.h>
#include <avto.h>
class user
{
public:
    user();


       mathmodel    math_model;
        avto   system_avtomatic;
         string  operation_mode;



       void Get_way_point(float vector[]);

        void  Set_way_point(float vector[]);
        float* ttarget(self);

        float* User_mode(float vector[]);
        void Change_mode(float vector[]);

};

#endif // USER_H
