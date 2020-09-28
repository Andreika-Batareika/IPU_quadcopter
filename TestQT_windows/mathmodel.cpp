#include "mathmodel.h"

mathmodel::mathmodel()
{

    self.X = X_come;
        self.X_for_analiz=self.X;
}

void mathmodel::write_result()
{

}



float* mathmodel::rightpart(float t)
{

    dX=self.f(t,self.X,self.U(t));
    return dX;
}
void mathmodel::DU(self,t):
    self.t0=self.t1;
    self.t1=t;
    dt=self.t1-self.t0
    self.X=self.X+self.rightpart(t)*dt
void mathmodel::analiz_vector(X_came_for_analiz,t_come):
    self.X_for_analiz=X_came_for_analiz
    self.time_bort=t_come
    DU(self.time_bort)
    dx_analiz=X_came_for_analiz-self.X
    return dx_analiz





float* mathmodel::f(float t):
    F_out=
    return F_out
float* mathmodel::U(self,t):
    U_out=[]
    return U_out
