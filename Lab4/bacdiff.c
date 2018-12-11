#include <stdio.h>
#include <math.h>

void main(){
    int n;
    printf("Enter the number of elements to be backward differenced:");
    scanf("%d", &n);
    float table[n][n];
    int i=0, j=0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
          table[i][j]=-9943544.00f;
        }
    }
    printf("Enter the actual numbers...\n");
    for(i=0; i<n; i++){
        scanf("%f", &table[0][i]);
    }

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            table[i+1][j]=table[i][j]-table[i][j-1];
        }
    }
    printf("The contents of the backward difference table are...\n");
    for(i=0; i<n; i++){
            if(i==0)
        printf("  y  \t");
        else
        printf(" d^%dy  \t", i);
    }
    printf("\n");

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
                if(table[j][i]==-9943544)
                printf(" \t");
        else
            printf(" %.2f\t", table[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}
