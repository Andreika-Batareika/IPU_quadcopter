import System_avto
class sac(System_avto.Tsac):
    def __init__(self):
        System_avto.Tsac._init__()
    #    TMath_model.__init__(X_come)
        self.P_pitch=1
        self.D_pitch=1
        self.P_roll=1
        self.D_roll=1
        self.mass=0
        self.G=9.8*self.mass
        self.mission_ttarget=[0,0,1,0,0]#режимы [арминг, взлет, автозависание,разворот, движение]

        self.mission_roll=0
        self.error_pitch=0
        self.error_roll=0
        self.error_roll_previous=0
        self.error_pitch_previous=0
        self.mission_pitch=0
        self.throttle_mission_avto_z=1500
        self.throttle_mission_r=0
        self.vector_status=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    #    self.vector_status=[[0],0,0,0,0,0,0,0,0,0,0,0,0]#d X Y Z vx vy vz health pitch roll wx wy wz
        self.dt=0.1
        self.throttle=[0,0,0,0]# левый передний, правый передний,левый задний, правый задний
## 7---6
##
## 5---4

    def f_Forse(self,P,D,error,spin):
        return P*error+D*spin
    def f_Pitch(self,pitch,target_pitch):
        self.error_pitch_previous=self.error_pitch
        self.error_pitch= target_pitch-pitch
        spin_pitch=(self.error_pitch-self.error_pitch_previous)/self.dt
        return self.f_Forse(self.P_pitch,self.D_pitch,self.error_pitch,spin_pitch)
    def f_Roll(self,roll,target_roll):
        self.error_roll_previous=self.error_roll
        self.error_roll=target_roll-roll
        spin_roll=(self.error_roll-self.error_roll_previous)/self.dt
        return self.f_Forse(self.P_roll,self.D_roll,self.error_roll,spin_roll)
    def F_throttle_p(self,read_pitch,mission_pitch):
        forse_pitch=self.f_Pitch(read_pitch,mission_pitch)
        return forse_pitch



    def F_throttle_r(self,read_roll,mission_roll):
        forse_roll=self.f_Roll(read_roll,mission_roll)
        return  forse_roll

    def  F_throttle_H():
        return

    def mission_stabilizacia(self,p,tp,r,tr):
        self.mission_roll=0
        self.mission_pitch=0
        throttle_p=self.F_throttle_p(p,tp);
        throttle_r=self.F_throttle_r(r,tr);
        #двигатель 4
        self.throttle[3]=self.throttle_mission_avto_z+throttle_p+throttle_r
#двигатель 5
        self.throttle[2]=self.throttle_mission_avto_z+throttle_p-throttle_r
#двигатель 6
        self.throttle[1]=self.throttle_mission_avto_z-throttle_p+throttle_r
#двигатель 7
        self.throttle[0]=self.throttle_mission_avto_z-throttle_p-throttle_r
        print(self.throttle)

    def calc_F(pitch,roll,f):
        return f*cos(pitch)*cos(roll)


    def avto(self,vector1):
        print(vector1)
        print("v")

        self.vector_status=vector1
        print(self.vector_status)
        if self.mission_ttarget[2]==1:
            self.mission_stabilizacia(self.vector_status[12],0,self.vector_status[13],0)
        return self.throttle
