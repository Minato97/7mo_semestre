#include <stdio.h>
#include <math.h>
//Ignacio Andrade
main()
{
    //Tiempo de simulación
    double tfin=2;

    //paso de integración
    double h=0.01;

    //Tamaño del vector
    int n=tfin/h;

    // Vectores
    double t[n], y[n], u[n];

    // Parametros de la FT
    double b0=12,b1= 4, a=8;

    printf("t \t\t y(t)\n\n");

    for(int i=0;i<n;i++)
    {
        t[i]=i*h;
        u[i]=1;					//u[i]=sin(t[i])
        y[i]=y[i-1]+h*(-a*y[i-1]+(b0*(u[i]-u[i-1])/h)+b1*u[i-1]);

        printf("%0.16f \t\t %0.16f \n", t[i],y[i]);
    }




}//
// Created by Nacho Andrade on 19/02/2024.
//
