#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <D:/ENG/ECE 1/second term/Introduction to Embedded Systems/project/lib/tm4c123gh6pm.h>
#define pi 3.14159265358979323846


float Total_Distance = 0;
double Latitude[2] = {0.0 , 0.0} ;
double Longitude[2] = {0.0 , 0.0} ;
int f = 0 ; 

void SystemInit(){}

double deg2rad(double deg) {
    return (deg * pi / 180);
    }

double rad2deg(double rad) {
        return (rad * 180 / pi);
    }


double Distance(double Lat, double Long) {
		double theta;
		double dist;

		if 	(f == 1){

 			Latitude[1] = Lat ;
			Longitude[1] = Long ;           

            if((Latitude[0] == Latitude[1]) && (Longitude[0] == Longitude[1]) ){
                return Total_Distance;
            }            
            theta = Longitude[0] - Longitude[1];
            dist = sin(deg2rad(Latitude[0]))*sin(deg2rad(Latitude[1]))+cos(deg2rad(Latitude[0]))*cos(deg2rad(Latitude[1]))*cos(deg2rad(theta));
            Total_Distance += rad2deg(acos(dist)) * 60 * 1.1515 * 1.609344 * 1000;

			Latitude[0] = Lat ;
			Longitude[0] = Long ;

		}
		else if (f==0){
			f=1;
			Latitude[0] = Lat ;
			Longitude[0] = Long ;
		}

		return Total_Distance;
}
int main(){}
	
	

           