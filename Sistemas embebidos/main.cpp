#include <stdio.h>
#include <math.h>

//Ignaio Andrade Salazar
main() {
    //Tiempo de simulación
    double tfin = 10;

    //paso de integración
    double h = 0.01;

    //Tamaño del vector
    int n = tfin / h;

    // Vectores
    double t[n], y[n], u[n];

    // Parametros de la FT
    double b = 0.125, a = 8;

    printf("t \t\t y(t)\n\n");

    for (int i = 0; i < n; i++) {
        t[i] = i * h;
        u[i] = 1;                    //u[i]=sin(t[i])
        y[i + 1] = y[i] + h * (-a * y[i] + b * u[i]);

        printf("%f \t\t %f \n", t[i], y[i]);
    }


}