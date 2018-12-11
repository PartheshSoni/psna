#include <stdio.h>
#include <math.h>

double fun(float val, float co[], int n){
  double ans=0.00f;
  for(int i=0; i<n; i++){
    ans+=co[i]*pow(val, i);
  }
  return ans;
}

void main(){
  int n;
  printf("Enter the highest degree of the equation:");
  scanf("%d", &n);
  float coeff[n+1];int  i;
  for(i=n; i>=0; i--){
    printf("\nEnter the %dth index:", i);
    scanf("%f",&coeff[i]);
  }

   float l, r;
  again:
  printf("\nEnter the range for calculation:(eg. 4 8)");
  scanf("%f %f", &l, &r);

  if((fun(l, coeff, n+1)>0&&fun(r, coeff, n+1)>0)||(fun(l, coeff, n+1)<0&&fun(r, coeff, n+1)<0)){
    printf("There are no roots between the given range, do you want to add the range again?(1/0): \n");
    int choice;
    scanf("%d", &choice);
    if(choice!=0)
      goto again;

  }
  if((fun(l, coeff, n+1)>0&&fun(r, coeff, n+1)<0)){
    float temp=l;
    l=r;
    r=temp;
  }
  for(i=0; i<20; i++){
    float m=(l*fun(r, coeff, n+1)-r*fun(l, coeff, n+1))/(fun(r, coeff, n+1)-fun(l, coeff, n+1));
    double fm=fun(m, coeff, n+1);
    printf("Iteration: %d, l=%.2f, f(l)=%.2lf, r=%.2f, f(r)=%.2lf, m=%f, f(m)=%.2lf\n",i+1, l, fun(l, coeff, n+1), r, fun(r, coeff, n+1), m,fm);
    if(fm<0){
      l=m;
    }
    else
    r=m;
  }
  printf("\n");

}
