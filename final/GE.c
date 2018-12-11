#include<stdio.h.>
#include<math.h>

#define d double



int main()
{
	int i,j,k,l,r,c,alt,flag=0;
	int *p1,*p2;
	printf(" Enter number of equations : ");
	scanf("%d",&r);
	printf(" Enter number of variables : ");
	scanf("%d",&c);
	if(r<c)
	{ printf(" Cannot find solution"); return 0; }
    d ar[r][c+1],sol[c],tmp,mf;
    printf(" Enter the equations :");
    for (i = 0; i < r; ++i)
    {
    	for (j = 0; j < c+1; ++j)
    	{
    		scanf("%lf",& ar[i][j]);
    	}
    }

    for( i=0;i<c;++i)
    {
        if(ar[i][i]==0)
		{
		  	alt=i+1;
		  	while(alt<r && ar[alt][i]==0)
		  	 {  alt++;}
			if(alt==r)
			 {  continue; }
			for(l=0;l<c+1;++l)
			{
			 tmp=ar[i][l];
			 ar[i][l]=ar[alt][l];
			 ar[alt][l]=tmp; 
			} 
			     
	    
		}     
		
		for( j=i+1;j<r;++j)
        {
          mf=ar[j][i] / ar[i][i];
          for( k=i ; k<c+1; ++k )
           {
           	 ar[j][k]-= ar[i][k] * mf ;
           }
        }
    }
   
    for(i=c-1;i>=0;--i)
    {
      tmp=0;
      for(j=i+1;j<c;++j)
      {
      	tmp+=sol[j]*ar[i][j];
      }
      if(tmp==0 && ar[i][i]==0)
      {
      	if(ar[i][c]==0)
      	{  flag=1;}
      	else 
      	{
		      printf("\nNo solution");
		      return 0;  
	    }
	  }
         
      sol[i] = ( ar[i][c] - tmp ) / ar[i][i];
    }
    if(flag)
    {
    	printf("\nInfinite solutions");
    	return 0;
	}
    printf("\n The solution of the equation is : ");

    for(i=0;i<c;++i)
    {
       printf("%lf ",sol[i]);
    }

   return 0;
}
