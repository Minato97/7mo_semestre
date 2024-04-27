#include <stdio.h>
#include <math.h>

main(){
	//Tiempo de simulación
	double tfin = 10;
	
	//paso de integración
	double h = 0.01;
	
	//tamanio de vector
	int n = tfin/h;
	
	//declaracion de vectores
	double y[n], u[n], t[n];
	
	//parámetros de la planta
	double b0 =0,b1=4.25, a1 = 2, a2 = 17;
	
	//Parámetros del controlador
	double ref=1, e, I=0,e_1=0;
	double kp=2.352, kd=1.176, ki=20;
	
	
	printf("t \t\t y(t) \n\n");
	
	for(int i=0;i<n;i++){
		
		//tiempo continuo
		t[i]=i*h;
		
		//controlador proporcional derivativo integral
		e =ref-y[i];
		u[i]=kp*e+ki*(e-e_1)/h;
		I=I+h*e;
		e_1 = e;
		
		//planta / sistema a controlar 
		y[i+1]=2*y[i]-y[i-1]-a1*h*(y[i]-y[i-1])-a2*pow(h,2)*y[i-1]+b0*h*(u[i]-u[i-1])+b1*pow(h,2)*u[i-1];		
		printf("%f \t\t %0.16f \n",t[i],y[i]);
	}
}

