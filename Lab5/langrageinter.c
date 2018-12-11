#include <stdio.h>

float doit(float xf, float x[], float y[], int n){
    int i=0, j=0;
    float ans=1.00f;
    float temp=0.00f;
    for(i=0; i<n; i++){
            ans=1.00f;
        for(j=0; j<n; j++){
                if(j==i)
                continue;

                ans*=(xf-x[j]);
        }
        for(j=0; j<n; j++){
            if(j==i)
                continue;
            ans/=(x[i]-x[j]);
        }
        ans*=y[i];
        temp+=ans;
    }
    return temp;
}

void main(){
    printf("Enter the number of values to be entered: ");
    int n;
    scanf("%d", &n);
    float x[n];
    float y[n];
    printf("\nEnter the values of X and corresponding Y for %d times...\n", n);
    int i=0;
    for(i=0; i<n; i++){
        scanf("%f%f", &x[i], &y[i]);
    }
    printf("\nEnter the value of X corresponding to which interpolation is to be done: ");
    float xf;
    scanf("%f", &xf);

    float ans=doit(xf, x, y, n);
    printf("\nThe interpolated value of the given X is %.9f\n", ans);
}
