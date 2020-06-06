import SAC
import Math_model_quadrocopter
class TUser:
    def __init__(self):
        self.mission_ttarget=[[0,0,0],[0,0,0]]#режимы [арминг, взлет, автозависание,разворот, движение]

        self.math_model=Math_model_quadrocopter.TMath_model_quadrocopter()
        self.system_avtomatic=SAC.sac()
        self.operation_mode="avto"

        ## 7---6
##
## 5---4

    def Get_way_point(self,X):
        if (self.operation_mode=="avto"):
            system_avtomatic.avto(X)
        return
    def Set_way_point(self):
        self.
        return
    def ttarget(self):
        self.
        return
    def User_mode(self,X):
        self.
        return
    def Change_mode(self):
        if (self.operation_mode=="avto"):
            return system_avtomatic.avto(X)
        if (self.operation_mode=="not_avto"):
            return User_mode(X)
