#include <stdio.h>

void main(){
    printf("Enter the number of variables: ");
    int nv;
    scanf("%d", &nv);
    float matrix[nv][nv+1];
    printf("Enter the coefficient as follows...");
    int i=0, j=0;
    for(i=0; i<nv; i++){
        printf("For %dth equation...\n", i+1);
        printf("\n");
        for(j=0; j<nv+1; j++){
            if(j==nv){
                printf("Enter the constant: ");
                scanf("%f", &matrix[i][j]);
                continue;
            }
            printf("Coefficient for x%d: ", j+1);
            scanf("%f", &matrix[i][j]);
        }
    }
    int  k=0;

    for(i=0; i<nv; i++){
      for(j=i+1; j<nv; j++){
        float temp=matrix[j][i]/matrix[i][i];
        matrix[j][i]=0;
        for(k=i+1; k<nv+1; k++){
          matrix[j][k]=matrix[j][k]-matrix[i][k]*temp;
        }
      }
    }
    int invalid=0;
    for(i=0; i<nv; i++){
      if(matrix[i][i]==0&&matrix[i][nv]!=0)
        invalid=1;
        else if(matrix[i][i]==0&&matrix[i][nv]==0)
          invalid=2;
    }

        if(invalid==1){
          printf("\nThe roots of the given pair of equations are not possible.\n");
          return;
        }
        else if(invalid==2){
          printf("\nThe roots of the given pair of equations are infinite.\n");
          return;

        }
        float x[nv];


        for(i=nv-1; i>=0; i--){
          float tempsum=0.0f;
          if(i==nv-1){
            x[nv-1]=matrix[nv-1][nv]/matrix[nv-1][nv-1];
            continue;
          }
          for(j=i+1; j<nv; j++)
            tempsum+=matrix[i][j]*x[j];

          x[i]=(matrix[i][nv]-tempsum)/matrix[i][i];
        }
        printf("\n");
        printf("\nThe roots of the given equations are....\n");

        for(i=0; i<nv; i++){
          printf("x%d=%f ",i+1, x[i]);
      }
      printf("\n\n");

    }
