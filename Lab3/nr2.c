#include <stdio.h>
#include <math.h>

double function(float x){
    double ans=2*x-3*sin(x)-5;
    return ans;
}
double fd(float x){
    double ans=2-3*cos(x);
    return ans;
}

double fdd(float x){
    double ans=3*sin(x);
}
void main(){
    float x0;
    again:
    printf("Enter the value of x0:");
    scanf("%f", &x0);
    int i=0,li=0;
    printf("Enter the number of iterations for precision:");
    scanf("%d", &li);;

    for(i=0; i<10; i++){
        double buffer=function(x0);
        double b1=fd(x0);
        double b2=fdd(x0);
        if(abs(buffer*b2)>=powf(b1, 2)){
            printf("The x0 provided is not valid (Constraints not satisfies), please enter another value of x0");
            goto again;
        }
        double x=0.00f;

        x=x0-function(x0)/fd(x0);
        x0=x;
        printf("%d. x=%.6f\n",i+1, x0);

    }
}
