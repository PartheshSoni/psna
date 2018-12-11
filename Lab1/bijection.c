#include<stdio.h>
int main()
{
    float a=0,b=4;
    int i;
    for(i=1;i<10;i++)
    {
        float x=(a+b)/2;
        float y=x*x*x -3;
        printf(" %d c=%f f(c)=%f\ta=%f b=%f \n",i,x,y,a,b);
        if(y>0)
        {
            b=x;
        }
        if(y<0)
        {
            a=x;
        }
        if(y==0)
        {
            printf("the answer is %f",x);
        }

    }
}
