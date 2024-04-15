// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>

int main() {
    // Write C code here
    //Tiempo de simulación
    double tfin = 10;
    double h=0.01;
    int n = tfin/h;
    double y[n], u[n], t[n];
    //Parametros de planta
    double a= 1.5, b=.8;
    //Parametros de controlador
    double kp= 5.625, kd= 3.75;
    double ref = 1, e, e_1=0;

    printf("t \t\t y(t) \n\n");
    for (int i = 0; i<n; i++){
        //Vector de tiempo
        t[i] = i*h;

        //controlador
        e = ref-y[i];
        u[i]= kp*e+kd*(e-e_1)/h;
        e_1 = e;

        //planta
        y[i+2] = 2*y[i+1]-y[i]-a*h*(y[i+1]-y[i])+b*h*h*u[i];

        //Resultados
        printf("%0.16f \t\t %0.16f \n", t[i], y[i]);

    }
    return 0;
}