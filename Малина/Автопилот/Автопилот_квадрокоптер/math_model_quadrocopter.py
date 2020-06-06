import math_model
class TMath_model_quadrocopter(math_model.TMath_model):
    import numpy as np
    def __init__(self, X_come,mass):
        self.a=0.4
        self.h1=0.4
        self.h=0.15
        self.g=9.8
        self.L=0.20
        self.L_perpendikular=self.L*cos(3.14/4.0)
        self.Ix=1.0/12.0*self.mass*a*a
        self.Iy=1.0/12.0*self.mass*a*a
        self.Iz=1.0/12.0*self.mass*(a*a+h1*h1)
        self.Ir=0.0001
        self.w1=0 # левый передний
        self.w2=0 # правый передний
        self.w3=0 # левый задний
        self.w4=0 # правый задний
        self.u1=0 # управляющие вертикальное
        self.u2=0 # управление на крен
        self.u3=0 # управление на тангаж
        self.u4=0 # управление на курс
        self.Q=0
        self.d=0
        self.b=0
        self.l=0
        TMath_model.__init__(X_come)
        self.X = X_come #X Y Z Vx Vy Vz speed_heating speed_pitch speed_roll  heating pitch roll
        self.mass=mass

    def DU(self):
        self.X=self.X+self.rightpart(t)*dt
    def B(self,t):
        -(cos(self.X[11])*sin(self.X[10])*cos(self.X[9])+sin(self.X[11])*sin(self.X[9]))/self.mass
        -(cos(self.X[11])*sin(self.X[10])*sin(self.X[9])+sin(self.X[11])*cos(self.X[9]))/self.mass
        -(cos(self.X[11])*cos(self.X[10]))/self.mass
        B_out=np.matrix()
        return B_out
    def f(self,t):
        k1=self.l/self.Ix
        k2=self.l/self.Iy
        k3=self.l/self.Iz
        C1=(self.Iy-self.Iz)/self.Ix
        C2=-self.Ir/self.Iz
        C3=(self.Iz-self.Ix)/self.Iy
        C4=-self.Ir/self.Iy
        C5=(self.Ix-self.Iy)/self.Iz
        Ux=cos(self.X[11])*sin(self.X[10])*cos(X[9])+sin(self.X[11])*sin(self.X[9])
        Uy=(cos(self.X[11])*sin(self.X[10])*sin(self.X[9])+sin(self.X[11])*cos(self.X[9]))
        self.X[8]
        self.X[6]*self.X[7]*C1+C2*self.X[7]*self.Q+k1*self.u2
        self.X[7]
        self.X[6]*self.X[8]*C3+C4*self.X[7]*self.Q+k2*self.u3
        self.X[6]
        self.X[6]*self.X[7]*C5+k3*self.u4
        self.X[5]
        self.g-(cos(self.X[8])*cos(self.X[7]))*self.u1/self.mass
        self.X[3]
        Ux*1/self.mass*self.u1
        self.X[4]
        Uy*1/self.mass*self.u1
        F_out=np.matrix()
        return F_out
    def U(self,t):
        U_out=F_thrttle
        return U_out
    def U_signal():
        self.u1=self.d*(self.w1*self.w1+self.w2*self.w2+self.w3*self.w3+self.w4*self.w4)
        self.u2=self.d*(self.w1*self.w1-self.w2*self.w2+self.w3*self.w3-self.w4*self.w4)
        self.u3=self.d*(self.w1*self.w1+self.w2*self.w2-self.w3*self.w3-self.w4*self.w4)
        self.u4=self.d*(-self.w1*self.w1+self.w2*self.w2+self.w3*self.w3-self.w4*self.w4)
        self.Q=self.w1+self.w2+self.w3+self.w4
