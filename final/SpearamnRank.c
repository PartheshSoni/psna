#include<stdio.h>

int main()
{
     int n,i,j,size;
     printf("Enter the number of data : ");
     scanf("%d",&n);
     float x[n],y[n],rx[n],ry[n],sum,af=0,d2=0;
     int ix[n],iy[n];

     printf("Enter all the x values :");
     for ( i = 0; i < n; ++i)
     {
     	scanf(" %f",&x[i]);
     }
     printf("Enter all the corresponding y values :");
     for ( i = 0; i < n; ++i)
     {
      	scanf(" %f",&y[i]);
     }

     for(i=0;i<n;++i)
     {
     	ix[i]=i; iy[i]=i;
     }

     for(i=0;i<n-1;++i)
     {
     	for(j=0;j<n-1-i;++j)
     	{
     		if(x[j]<x[j+1])
     		{
     			float temp = x[j+1];
     			x[j+1] = x[j];
     			x[j]=temp;
     			int temp1;
     			temp1=ix[j];
     			ix[j]=ix[j+1];
     			ix[j+1]=temp1;
     		}
     	}
     }

     for(i=0;i<n-1;++i)
     {
     	for(j=0;j<n-1-i;++j)
     	{
     		if(y[j]<y[j+1])
     		{
     			float temp = y[j+1];
     			y[j+1] = y[j];
     			y[j]=temp;
     			int temp1;
     			temp1=iy[j];
     			iy[j]=iy[j+1];		
     			iy[j+1]=temp1;
     		}
     	}
     }
     i=0;j=0;
     while(i<n)
     {
         sum=i; size=1;
         
         while(i<n && x[i]==x[i+1])
         {
         	size++;sum+=i+1;i++;
         }
         af += (float)size * (float)( size * size - 1) / 12;
         
         i++;
         
         while(j<n && j<i )
         {
         	rx[ix[j]]=sum/size;j++;
         }
      }

      i=0;j=0;
     while(i<n)
     {
         sum=i; size=1;
         
         while(i<n && y[i]==y[i+1])
         {
         	size++;sum+=i+1; i++;
         }
         
         af += (float) size * (float)( size * size - 1) / 12;
         
         i++;
         
         while(j<n && j<i )
         {
         	ry[iy[j]]=sum/size; j++;
         }
      } 
      for(i=0;i<n;++i) 
      {
      	d2+= ( rx[i] - ry[i] ) * ( rx[i] - ry[i] );
	  }

      
      float ans = 1 - ( 6 * d2 + af ) / ( n * ( n * n - 1) );
      printf(" The Spearman's rank coefficient for the following data is %f",ans);
      

         

        return 0;
}
