class TMath_model:
    import numpy as np
    """docstring for ."""
    def __init__(self, X_come):
        self.X = X_come
        self.X_for_analiz=self.X
    def write_result(self):
        print(X)



    def rightpart(self,t):

        dX=self.f(t,self.X,self.U(t))
        return dX
    def DU(self,t):
        self.t0=self.t1
        self.t1=t
        dt=self.t1-self.t0
        self.X=self.X+self.rightpart(t)*dt
    def analiz_vector(X_came_for_analiz,t_come):
        self.X_for_analiz=X_came_for_analiz
        self.time_bort=t_come
        DU(self.time_bort)
        dx_analiz=X_came_for_analiz-self.X
        return dx_analiz





    def f(self,t):
        F_out=
        return F_out
    def U(self,t):
        U_out=[]
        return U_out
