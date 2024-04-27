#include <stdio.h>
#include <math.h>

main(){
	//TIEMPO DE SIMULACION
	double tfin=10;
	double h=0.01;
	
	//PASO DE INTEGRACION
	int n=tfin/h;
	
	//DECLARACION DE VECTORES
	double y[n], u[n], t[n];
	
	//PARAMETROS DE LA PLANTA
	double b0=0, b1=14.5, a1=-4, a2=29;
	
	//PARAMETROS DEL CONTROLADOR

	double kd=0.896, kp=1.379, ki=10;
	double I=0, e, e_1=0, ref=1; 
	
	printf("t \t\t y(t) \n\n");
	
	for(int i=0; i<n; i++){
		//VECTOR DE TIEMPO
		t[i]=i*h;
		
		//CONTROLADOR PID
		e=ref-y[i];
		u[i]=kp*e+ki*I+kd*(e-e_1)/h;
		I=I+h*e;
		e_1=e;

		//PLANTA O SISTEMA A CONTROLAR
		y[i+1]=2*y[i]-y[i-1]-a1*h*(y[i]-y[i-1])-a2*pow(h,2)*y[i-1]+b0*h*(u[i]-u[i-1])+b1*pow(h,2)*u[i-1];
		
		printf("%f \t\t %0.16f\n", t[i] ,y[i]);
	}		
}
