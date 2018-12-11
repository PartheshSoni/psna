#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sort(float *x, int n){
    int i, j=0;
    for(i=0; i<n; i++){
        for(j=1; j<n; j++){
            if(x[j]<x[j-1]){
                float temp=x[j];
                x[j]=x[j-1];
                x[j-1]=temp;
            }

        }

    }
    return x;
}
void main(){
    printf("Enter the number of observations: ");
    int n;
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter the values of x and corresponding y:(format: x y)");
    int i=0;
    for(i=0; i<n; i++){
        printf("%dth obs: ", i+1);
        scanf("%f%f", &x[i], &y[i]);
    }
    printf("Choose from the following\n1. Karl Pearson's Coefficient\n2. Spearman's Rank Coefficient\nCode: ");
    int choice;
    scanf("%d", &choice);
    switch(choice){
    case 1:{
        float sumxy=0.00f, sumx=0.00f, sumy=0.00f, sumx2=0.00f, sumy2=0.00f;
        for(int i=0; i<n; i++){
            sumxy+=x[i]*y[i];
            sumx+=x[i];
            sumy+=y[i];
            sumx2+=x[i]*x[i];
            sumy2+=y[i]*y[i];
        }

            float result=(n*sumxy-(sumx*sumy))/(sqrt(n*sumx2-(sumx*sumx))*sqrt(n*sumy2-(sumy*sumy)));
            printf("The Karl Pearson's Coefficient is %.4f", result);
            }
            break;
    case 2:{
        float tempx[n], tempy[n], rankx[n], ranky[n], m[n];
        int mc=0;
        int j=0;
        for(j=0; j<n ; j++)
            m[j]=-1;

        for(j=0; j<n; j++){
            tempx[i]=x[i];
            tempy[i]=y[i];
        }

        sort(tempx, n);
        sort(tempy, n);

        int k=0;

        for(j=0; j<n; j++){
                int rank;
                int locate=x[j];

            for(k=0; k<n; k++){
                if(locate==tempx[k])
                {
                    rank=k+1;
                    rankx[j]=rank;
                    break;
                }
            }
        }

        for(j=0; j<n; j++){
                int rank;
                int locate=y[j];

            for(k=0; k<n; k++){
                if(locate==tempy[k]){
                    rank=k+1;
                    ranky[j]=rank;
                    break;
                }
            }
        }
        int i=0;
        //just serach for all the occurences of a particular obs and change them.
        for(i=0; i<n; i++){
            int itmax=0;
            float same=tempx[i];
            if(i!=n-1){
            for(j=i+1; j<n; j++){
                if(same!=tempx[j]){
                    itmax=j-1;
                    break;
                }
                itmax=n-1;
            }
            float avg=(i+itmax)/2;
            if((itmax-i)>0)
                m[mc++]=(itmax-i)+1;
            for(j=i; j<=itmax; j++)
                rankx[j]=avg;

            }
        }
        for(i=0; i<n; i++){
            int itmax=0;
            int same=tempy[i];
            if(i!=n-1){
            for(j=i+1; j<n; j++){
                if(same!=tempy[j]){
                    itmax=j-1;
                    break;
                }
                itmax=n-1;
            }
            float avg=(i+itmax)/2;
            if((itmax-i)>0)
                m[mc++]=(itmax-i)+1;
            for(j=i; j<=itmax; j++)
                ranky[j]=avg;

            }
        }

        float d[n];
        float sumd2=0;
        for(i=0; i<n; i++){
            d[i]=(rankx[i]-ranky[i]);
            sumd2+=d[i]*d[i];
        }
        float af=0;
        for(i=0; i<n; i++){
            if(m[i]==-1)
                break;
            af+=(m[i]*(m[i]*m[i]-1))/12;
        }


        float result=1-(6*sumd2+af)/(n*(n*n-1));
        printf("The Spearman's Coefficient for the given data is %.4f", result);
    }

    }
}
