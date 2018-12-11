#include <stdio.h>
#include <math.h>

double function(float x){
    double ans=2*powf(x, 6)-3*powf(x, 5)-5*powf(x, 3)+6*powf(x, 2)-5*x-3;
    return ans;
}
double fd(float x){
    double ans=12*powf(x,5)-15*powf(x, 4)-15*powf(x, 2)+12*x-5;
    return ans;
}

double fdd(float x){
    double ans=60*powf(x, 4)-60*powf(x, 3)-30*x+12;
}
void main(){
    float x0;
    again:
    printf("Enter the value of x0:");
    scanf("%f", &x0);
    int i=0, li=0;
    printf("Enter the number of iterations for precision:");
    scanf("%d", &li);
    printf("\n");
    for(i=0; i<li; i++){
        double buffer=function(x0);
        double b1=fd(x0);
        double b2=fdd(x0);
        if(abs(buffer*b2)>=powf(b1, 2)){
            printf("The x0 provided is not valid(Constraints not satisfies), please enter another value of x0");
            goto again;
        }
        double x=0.00f;

        x=x0-function(x0)/fd(x0);
        x0=x;
        printf("%d. x=%.6f\n",i+1, x0);

    }
}
