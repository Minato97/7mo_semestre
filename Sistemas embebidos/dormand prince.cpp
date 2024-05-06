#include <stdio.h>
#include <math.h>

double f(double z){
    return -5*z+6;
}

main(){

    double tfin =10;
    double h=0.01;
    int n=tfin/h;


    double y[n], t[n];


    printf("t \t\t\t  y(t)\n\n");
    for (int i=0;i<n;i++){
        t[i]=i*h;

        double k1=h*f(y[i]);
        double k2=h*f(y[i]+k1/5);
        double k3=h*f(y[i]+(3*k1/40)+(9*k2/40));
        double k4=h*f(y[i]+44*k1/45+56*k2/15+32*k3/9);
        double k5=h*f(y[i]+19372*k1/6561+25360*k2/2187+64448*k3/6561-212*k4/729);
        double k6=h*f(y[i]+9017*k1/3168+355*k2/33+46732*k3/5247+49*k4/17-5103*k5/18656);

        y[i+1]=y[i]+35*k1/384+500*k3/1113+125*k4/192-2187*k5/6784+11*k6/84;

        printf("%f \t\t%0.16f\n ",t[i],y[i]);
    }



    return 0;
}