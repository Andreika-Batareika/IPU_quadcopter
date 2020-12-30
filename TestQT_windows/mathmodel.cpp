#include "mathmodel.h"

mathmodel::mathmodel(float  X_come[])
{

    X = X_come;
    X_for_analiz=X;
}

void mathmodel::write_result()
{

}


//  правые части
float* mathmodel::rightpart(float t)
{

    float dX[8]={0,0,0,0,0,0,0,0};
    return dX;
}

// интегрирование
float* mathmodel::DU(float t){
    t0=t1;
    t1=t;
    float dt=t1-t0;
    float *dx;
    dx=rightpart(t);

    for(int i=0;i<8;i++){

        X[i]=X[i]+dx[i]*dt;
    }

   return X;
}
            //анализ вектора
float mathmodel::analiz_vector(float X_came_for_analiz[], float t_come)
{
    X_for_analiz=X_came_for_analiz;
    float time_bort=t_come;
    DU(time_bort);
    float dx_analiz=X_came_for_analiz-X;
    return dx_analiz;
}




/*float* mathmodel::f(float t):
    F_out=
    return F_out
*/
float* mathmodel::U(float t)
{
    float U_out[8]={0,0,0,0,0,0,0,0};
    return U_out;
}
