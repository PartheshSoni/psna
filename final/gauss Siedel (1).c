#include<stdio.h>

float abs(float a )
{
     if(a>0)
          return a;
     else
          return -a;
}

int main()
{
    int n,i,j,cont=1;
    printf("Enter number of equations: ");
    scanf("%d",&n);
    float eqn[n][n+1],sol[n],prev[n],tmp,hm;
    for(i=0;i<n;++i)
    {
      sol[i]=0;
    }
    printf("Enter %d equations:\n",n);

    for(i=0;i<n;++i)
    {
        for(j=0;j<n+1;++j)
        {
          scanf("%f",&eqn[i][j]);
        }
    }

    do{

          for(i=0;i<n;++i)
          {
              prev[i]=sol[i];
          }
          for(i=0;i<n;++i)
          {
            tmp=0;
            for(j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                tmp+=eqn[i][j]*sol[j];

            }
             sol[i] = ( eqn[i][n] - tmp ) / eqn[i][i] ;
          }
          hm=0;
          for( i=0 ; i<n ; ++i)
          {
                tmp = abs(sol[i]-prev[i]);
                if(tmp>0.001)
                hm++;
          }

          if(hm==0)
          cont=0;

        }while(cont);
        printf(" The values are:\n ");

        for(i=0;i<n;++i)
        {
           printf("x%d=%f,",i+1,sol[i]);
        }

    return 0;
}
