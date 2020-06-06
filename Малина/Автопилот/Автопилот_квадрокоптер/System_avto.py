class Tsac:
    def __init__(self):
        self.mass=0
        self.G=9.8*self.mass
        self.mission_ttarget=[0,0,1,0,0]#режимы [арминг, взлет, автозависание,разворот, движение]
        self.vector_status=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    #    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0]#d X Y Z vx vy vz health pitch roll wx wy wz
        self.dt=0.1
        self.throttle=[0,0,0,0]# левый передний, правый передний,левый задний, правый задний
## 7---6
##
## 5---4


    def avto(self,vector1):
        return self.throttle
