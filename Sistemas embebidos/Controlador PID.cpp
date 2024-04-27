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
    double a1= 2, a2=17, b=4.25;
    //Parametros de controlador
    double kp= 2.352, kd= 1.176, ki=20;
    double ref = 1, e, e_1=0, I=0;

    printf("t \t\t y(t) \n\n");
    for (int i = 0; i<n; i++){
        //Vector de tiempo
        t[i] = i*h;

        //controlador
        e = ref-y[i];
        u[i]= kp*e+ki*I+kd*(e-e_1)/h;
        e_1 = e;

        //planta
        y[i+2] = 2*y[i+1]-y[i]-a1*h*(y[i+1]-y[i])-a2*h*h*y[i]+b*h*h*u[i];

        //Resultados
        printf("%0.16f \t\t %0.16f \n", t[i], y[i]);

    }
    return 0;
}