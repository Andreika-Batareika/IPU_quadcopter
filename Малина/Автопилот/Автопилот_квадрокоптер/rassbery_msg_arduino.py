import serial
import SAC
#import RPi.GPIO as GPIO
import time
system_avtomatic=SAC.sac()
array_motors = [1200,0,0,0]
ser=serial.Serial("/dev/ttyUSB0")  #change ACM number as found from ls /dev/tty/ACM*
ser.baudrate=57600
#read_ser=ser.write(0)
ser.write_timeout=0.5
ser.timeout=0.5
t_start=time.time()
t=t_start
ser.dsrdtr=1
ser.rtscts=1
ser.xonxoff =1

print(ser)
#cd /home/fastil/github/Python/work
# python3 rassbery_msg_arduino.py
def get_string(array):
    str1=str(round(array[0]))+' ' +str(round(array[1]))+' '+str(round(array[2]))+' '+str(round(array[3]))+' '
    print(str1)
    return  str1


print(serial.__version__)

def read_comport(string_from_COMPORT):
        l = len(string_from_COMPORT)
        integ = []
        i = 0
        print(l)
        print(string_from_COMPORT)
        while i < l:
            s_int = ''
            a = string_from_COMPORT[i]
            print(a)
            while ( a!= ' '):
        #    if ( a=='0')or (a=='.')or ( a=='1')or (a=='2')or( a=='3')or (a=='4')or ( a=='5')or (a=='6')or( a=='7')or (a=='8')or (a=='9'):
                s_int += a
                i += 1
                print(s_int)
                #i += 1
            if s_int != '':
                integ.append(float(s_int))
        print("1")
    #    print(integ)
        return inteq

def read_comport1(string_from_COMPORT):
        integ=string_from_COMPORT.split()
    #    print(integ)
        integ = list(map(float, integ))
        return integ


while 1:
    print(t)
    system_avtomatic.dt=time.time()-t
    t=time.time()-t_start
    d= ser.readline()

    if( t>17) :
        ##d= ser.readline()
        vector_from_dron=read_comport1(d.decode('utf-8'))
        print(d.decode('utf-8'))
        print(vector_from_dron)
        if vector_from_dron!=[]:
            array_motors=system_avtomatic.avto(vector_from_dron)#vector_from_dron)
            string_for_Arduino=get_string(array_motors)
            print(string_for_Arduino)
            print(1)
            ser.write(string_for_Arduino.encode('ascii'))
        #    ser.write("2300 2300 2300 2300 ".encode('ascii'))


    #d= ser.readline()
#    print(d)

    #    ser.reset_input_buffer( )
    #    if( t>7)&(t<16) :
    #        ser.write("2300 2300 2300 2300 ".encode('ascii'))
    #    if( t>20)&(t<24) :
    #        ser.write("800 800 800 800 ".encode('ascii'))
    #    if( t>30)&(t<35) :
    #        ser.write("2000 2200 2200 2100 ".encode('ascii'))
    #    if( t>60) :
    #        ser.write("1500 1400 1200 1100 ".encode('ascii'))



    #get_string(array_motors).encode('utf-8')
    #    ser.reset_output_buffer( )

     #if ser.in_waiting>0:
