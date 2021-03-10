#include <Servo.h>
//#include <Ultrasonic.h> 
 
#include <Wire.h>
#include <LSM303.h>
#include <L3G.h>
LSM303 compass;

L3G gyro;
float vector_test[3];
float D_vector_test[3];
/////////////////////////////////////////////
float fXA,fYA,fZA,X2,Y2,Z2,time_1,dt,time_0;
float pitch, roll,  ax, ay, az, Xa, Ya, Za, Xm_off, Ym_off, Zm_off, Xm_cal, Ym_cal, Zm_cal, fXm_comp, fYm_comp;
int t;
float X,Y,Z,Vx,Vy,Vz,gx,gy,gz,Heading,pitch_print,roll_print;
const float alpha = 0.15;
float fXa = 0;
float fYa = 0;
float fZa = 0;
float fXm = 0;
float fYm = 0;
float fZm = 0;
//float sss;
const int N_servo =4;
int servo_speed[N_servo];
int servo_pin[N_servo]= {4,5,6,7};
long duration, cm;
int trigPin = 2;    //Триггер – зеленый проводник
 int max_pwm = 2300;

	 //Минимальное значени ШИМ 0.8 мс

	 int min_pwm = 800;


int echoPin = 3;    //Эхо – желтый проводник
//1 | 2
//3 - 4


const int ledPin = 13; 
String incoming ="";      // [Nomber_servo speed]
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() {

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

  Serial.begin(57600);
  start();
  pinMode(ledPin, OUTPUT);
}

void loop() {

  
  sensor();
 message_com ();
 Get_array(servo_speed);
 vector_status();
 if (millis()>15000) t=1;
//Serial.print(' '+String(servo_speed[0]) +' '+String(servo_speed[1])+' '+String(servo_speed[2])+' '+String(servo_speed[3])+' ');  

 //Serial.print(String(cm) +' '+String(X)+ ' '+String(Y)+ ' '+String(Z)+ ' '+String(Vx)+ ' '+String(Vy)+ ' '+String(Vz)+ ' '+String(Heading)+ ' '+String(pitch_print)+ ' '+String(roll_print)+ ' '+String(gz)+ ' '+String(gy)+ ' '+String(gx));Serial.print("\r\n");
}






void start () {
  
Wire.begin();

compass.init();
gyro.init();

compass.enableDefault();
 gyro.enableDefault();

 compass.m_min = (LSM303::vector<int16_t>){-556, -524, -336};
  compass.m_max = (LSM303::vector<int16_t>){+804, +747, +720};

    servo1.attach(servo_pin[0]);
    servo2.attach(servo_pin[1]);
   servo3.attach(servo_pin[2]);
   servo4.attach(servo_pin[3]);
     delay(1000);

	 servo1.writeMicroseconds(max_pwm);
servo2.writeMicroseconds(max_pwm);
servo3.writeMicroseconds(max_pwm);
servo4.writeMicroseconds(max_pwm);

	 delay(2000);

	 servo1.writeMicroseconds(min_pwm);
servo2.writeMicroseconds(min_pwm);
servo3.writeMicroseconds(min_pwm);
servo4.writeMicroseconds(min_pwm);
	 delay(6000);
   servo_speed[0]=800;
servo_speed[1]=800;
servo_speed[2]=800;
servo_speed[3]=800;
  Serial.print("armed \r\n");
 }
 



void message_com ()
{String inString;
int inChar; inString = "";
// Serial.print(String(cm));Serial.print("\r\n");
while (Serial.available() > 0) {

  inChar = Serial.read();
//   Serial.print(inChar);Serial.print("\r\n");
   
 // if ( inChar == 110) {
    incoming=inString;
//Serial.print(inString);Serial.print("111\r\n");
  //  inString = "";
  //   inChar = Serial.read();
 //   break;
 // }
   inString += (char)inChar; incoming=inString;
}
inChar=0;

 //if (Serial.available() > 0) {

 
  //  incoming = Serial.readString();
    
   //  Serial.println(incoming);
  char str[50] ;
   strcpy(str,incoming.c_str());
 int j;

    int i = 0;
    for(char* ptr = str, *ptr1 = str; ;i++)
    {
        long num = strtol(ptr, &ptr, 10);
        if(ptr == ptr1)
        {
            break;
        }
        else
        {
      //     Serial.println(String(num));

            servo_speed[i] =int( num);
            ptr1 = ptr;
        }
    
     //  Serial.println(incoming);
  }
}





void Get_array (int arr[])
{
  servo1.writeMicroseconds(arr[0]);
  servo2.writeMicroseconds(arr[1]);
  servo3.writeMicroseconds(arr[2]);
  servo4.writeMicroseconds(arr[3]);
  //   for (int i = 0; i < sizeof(arr); i++)
 //  {  
 //       Get_Speed_Servo (arr[i], i);    
 //     }
}


void sensor (){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
 
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT);

duration = pulseIn(echoPin, HIGH);

// преобразование времени в расстояние

cm = (duration/2) / 29.1;


}

void vector_status()
{


compass.read();
//float pitch, pitch_print, roll, roll_print, Heading, ax, ay, az, Xa, Ya, Za, Xm_off, Ym_off, Zm_off, Xm_cal, Ym_cal, Zm_cal, fXm_comp, fYm_comp;

Xa = compass.a.x/16.0; //Acceleration data registers contain a left-aligned 12-bit number, so values should be shifted right by 4 bits (divided by 16)
Ya = compass.a.y/16.0;
Za = compass.a.z/16.0;
ax= 0.977749*(Xa+51.656307) + 0.015075 *(Ya-21.998557)    -0.001169  *(Za+203.497002) ;
ay= 0.015075*(Xa+51.656307) +  0.983102*(Ya-21.998557)      -0.006601*(Za+203.497002); 
az= -0.001169*(Xa+51.656307)   -0.006601*(Ya-21.998557)   +  0.995014 *(Za+203.497002);


// Magnetometer calibration

Xm_off = compass.m.x*(100000.0/1100.0)  -10126.799873; //X-axis combined bias (Non calibrated data - bias)
Ym_off = compass.m.y*(100000.0/1100.0)  -15565.512455; //Y-axis combined bias (Default: substracting bias)
Zm_off = compass.m.z*(100000.0/980.0 ) + 13778.751287; //Z-axis combined bias

Xm_cal =  1.019643*Xm_off  -0.027997*Ym_off + 0.046337*Zm_off; //X-axis correction for combined scale factors (Default: positive factors)
Ym_cal =  -0.027997*Xm_off + 1.000410*Ym_off + 0.057080*Zm_off; //Y-axis correction for combined scale factors
Zm_cal =  0.046337*Xm_off + 0.057080*Ym_off + 0.977073*Zm_off; //Z-axis correction for combined scale factors


// Low-Pass filter accelerometer
fXa = ax * alpha + (fXa * (1.0 - alpha));
fYa = ay * alpha + (fYa * (1.0 - alpha));
fZa = az * alpha + (fZa * (1.0 - alpha));
//Serial.print("fXa: "); Serial.print(fXa); Serial.print("  ");
//Serial.print("fYa: "); Serial.print(fYa); Serial.print("  ");
//Serial.print("fZa: "); Serial.print(fZa); Serial.print("  ");

//Serial.print(1.0/100.0*sqrt(sq(ax)+sq(ay)+sq(az)));Serial.print("  "); 

//Serial.print(1.0/100.0*sqrt(sq(fXa)+sq(fYa)+sq(fZa)));Serial.print("  "); 
// Low-Pass filter magnetometer
fXm = Xm_cal * alpha + (fXm * (1.0 - alpha));
fYm = Ym_cal * alpha + (fYm * (1.0 - alpha));
fZm = Zm_cal * alpha + (fZm * (1.0 - alpha));

// Pitch and roll
roll  = atan2(fYa, sqrt(fXa*fXa + fZa*fZa));
pitch = atan2(fXa, sqrt(fYa*fYa + fZa*fZa));
roll_print = roll*180.0/M_PI;
pitch_print = pitch*180.0/M_PI;

// Tilt compensated magnetic sensor measurements
fXm_comp = fXm*cos(pitch)+fZm*sin(pitch);
fYm_comp = fXm*sin(roll)*sin(pitch)+fYm*cos(roll)-fZm*sin(roll)*cos(pitch);

// Arctangent of y/x
//Heading =180+ (atan2(fYm_comp,fXm_comp)*180.0)/M_PI;
Heading = compass.heading();




/////удаление кажущиегося ускроения 
matrixA(0,0,9.86,3.14/180.0*Heading,roll,pitch);
//Serial.print(sqrt(sq(X2)+sq(Y2)+sq(Z2)));Serial.println("  "); 
fXA=(fXa/100.0-Z2);
fYA=(fYa/100.0-X2);
fZA=(fZa/100.0-Y2);

/////перевод в бортовую ск
matrix_A_T(fXA,fYA,fZA,3.14/180.0*Heading,roll,pitch);
///// интегрирование *9.8
time_1=millis();
dt=(time_1-time_0)/1000.0;
time_0=time_1;






//Q тангаж
//w курс
//v  крен
 func_D(pitch,3.14/180.0*Heading,-roll,ax/100.0,az/100.0,ay/100.0);
  float v[3]={Vx,Vy,Vz};

 func_axyz(D_vector_test,v,0.64,100);
Serial.println(String(3.14/180.0*Heading)+ ' '+String(roll)+' '+String(ax/100.0) +' '+String(az/100.0)+ ' '+String(ay/100.0)+' '+String(Xa) +' '+String(Ya)+ ' '+String(Za)+' '+String(vector_test[0]) +' '+String(vector_test[1])+ ' '+String(vector_test[2])+' '+String(D_vector_test[0]) +' '+String(D_vector_test[1])+ ' '+String(D_vector_test[2]));
Z2=vector_test[2];
Y2=vector_test[1];
X2=vector_test[0];

if ((dt<0.2)&& (t==1)){
  
  if (abs(Z2)>0.1)
Vx=Vx-Z2*dt;
if (abs(X2)>0.1)
Vy=Vy-X2*dt;
if (abs(Y2)>0.1)
Vz=Vz-Y2*dt;
X=X+Vx*dt;
Y=Y+Vy*dt;
Z=Z+Vz*dt;
}
  gyro.read();

  
  gx=((int)gyro.g.x/131.0);
  
  gy=((int)gyro.g.y/131.0);
 gz=((int)gyro.g.z/131.0);





}

void matrixA(float X1,float Y1, float Z1, float a,float b,float c)
{
  matrix_1(Y1,Z1,X1,a);
 //matrix_1(X1,Y1,Z1,-a);
 matrix_2(X2,Y2,Z2,b);
 matrix_3(X2,Y2,Z2,-c);

}
void matrix_3(float X1,float Y1, float Z1, float a)
{
  X2=X1;
  Y2=Y1*cos(a)+Z1*(sin(a));
  Z2=-Y1*sin(a)+Z1*cos(a);
}
void matrix_2(float X1,float Y1, float Z1, float a)
{//heating
  X2=X1*cos(a)+Y1*(sin(a));
  Y2=-X1*sin(a)+Y1*cos(a);
  Z2=Z1;
}
void matrix_1(float X1,float Y1, float Z1, float a)
{
  X2=X1*cos(a)+-Z1*sin(a);
  Y2=Y1;
  Z2=X1*sin(a)+Z1*cos(a);
}

void matrix_A_T(float X1,float Y1, float Z1, float a,float b,float c)
{matrix_3(X2,Y2,Z2,-c);
matrix_2(X2,Y2,Z2,b);
matrix_1(Y1,Z1,X1,a);
 
 }



 void func_D(float Q,float w,float v,float x, float y, float z){
  //float D_vector[3];
  D_vector_test[0]=x*cos(Q)*cos(w)+y*(-cos(v)*cos(w)*sin(Q)+sin(v)*sin(w))+z*(sin(v)*cos(w)*sin(Q)+cos(v)*sin(w));
  D_vector_test[1]=x*sin(Q)+y*cos(v)*cos(Q)-z*sin(v)*cos(Q);
  D_vector_test[2]=x*(-cos(Q)*sin(w))+y*(cos(v)*sin(w)*sin(Q)+sin(v)*cos(w))+z*(-sin(v)*sin(w)*sin(Q)+cos(v)*cos(w));
  //D_vector_test = D_vector;
 }




/*
 void func_D(float Q,float w,float v,float x, float y, float z){
  //float D_vector[3];
  D_vector_test[0]=x*(cos(Q)*cos(w)*cos(v)-cos(v*sin(w))+y*(-cos(v)*sin(w)*cos(Q)-sin(v)*sin(w))+z*(cos(v)*sin(Q));
  D_vector_test[1]=x*sin(Q)+y*cos(v)*cos(Q)-z*sin(v)*cos(Q);
  D_vector_test[2]=x*(-cos(Q)*sin(w))+y*(cos(v)*sin(w)*sin(Q)+sin(y)*cos(w))+z*(cos(Q));
  //D_vector_test = D_vector;
 }

*/



 void func_axyz(float n[],float V[],float fi,float h){
  float vector[3];
float  g0=9.780327;
float  a=6378136;
float  g=g0*(1+0.0053024*sin(fi)*sin(fi)-0.0000058*sin(2*fi)*sin(2*fi))-3.686E-6;
float omega=7.292115E-5;
//float f=298.25784;
float e=0.08181910644;
float R=a*(1-0.5*exp(2)*sin(fi)*sin(fi))+h;
  vector_test[0]=n[0]-V[2]*V[2]/R*tan(fi)-V[0]*V[1]/R-2*V[2]*omega*sin(fi);
  vector_test[1]=n[1]+V[0]*V[0]/R+V[2]*V[2]/R+2*V[2]*omega*cos(fi)-g;
  vector_test[2]=n[2]-V[2]*V[1]/R+V[0]*V[2]/R*tan(fi)-2*omega*(V[1]*cos(fi)-V[0]*sin(fi));
 // vector_test=vector;
 }


 
