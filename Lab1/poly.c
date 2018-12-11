#include <stdio.h>
#include <math.h>

void main(){
    float l, u;
    printf("Enter the range of values:(leave space between the upper and lower bound)");
    scanf("%f %f", &u, &l);
    int degree;
    printf("Enter the degree of the polynomial:");
    scanf("%d", &degree);
    int coeff[degree+1];
    int i;
    for( i=0; i<degree+1; i++){
        printf("Enter the %dth coefficient:", i);
        scanf("%d", &coeff[i]);
    }
    float test1;
    for( i=0; i<degree+1; i++){
             test1+=coeff[i]*pow(l, i);}
    float test2;
    int flag=1;
    for(i=0; i<degree+1; i++){
             test2+=coeff[i]*pow(u, i);}
    if(test1>0&&test2>0||test1<0&&test2<0){
        printf("Roots are not possible in the given range.\n");
        flag=0;
    }

    if(test1>0&&test2<0)
        flag=2;
    if(flag==1)
    for(i=0; i<100; i++){
        float x=(u+l)/2;
        float y=0;
        int j=0;
        for(j=0; j<degree+1; j++){
             y+=coeff[j]*pow(x, j);
        }
         printf(" %d c=%f f(c)=%f\tl=%f u=%f \n",i,x,y,l,u);
        if(y>0)
            u=x;
        if(y<0)
            l=x;
        if(y==0)
            printf("The root of the equation in the given range is %f\n", x);
    }

    else
    for( i=0; i<100; i++){
        float x=(u+l)/2;
        float y=0;
        int j=0;
        for(j=0; j<degree+1; j++){
             y+=coeff[j]*pow(x, j);
        }
         printf(" %d c=%f f(c)=%f\tl=%f u=%f \n",i,x,y,l,u);
        if(y>0)
            l=x;
        if(y<0)
            u=x;
        if(y==0)
            printf("The root of the equation in the given range is %f\n", x);
    }
}

