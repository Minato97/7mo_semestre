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
    double a = .8, b=.4;
    //Parametros de controlador
    double kp= 5, ki= 4.8;
    double ref = 1, e, I;

    printf("t \t\t y(t) \n\n");
    for (int i = 0; i<n; i++){
        //Vector de tiempo
        t[i] = i*h;

        //controlador
        e = ref-y[i];
        u[i]= kp*e+ki*I;
        I = I+h*e;

        //planta
        y[i+1] = y[i]+h*(-a*y[i]+b*u[i]);

        //Resultados
        printf("%0.16f \t\t %0.16f \n", t[i], y[i]);

    }
    return 0;
}