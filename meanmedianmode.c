#include <stdio.h>

void main(){
    printf("Enter the number of number of observation in the table: ");
    int n;
    scanf("%d", &n);
    float from[n], to[n], freq[n];
    int i, j;
    printf("Enter the table:(format: Lower_bound Upper_bound freq) ");
    for(i=0; i<n; i++){
        scanf("%f%f%f", &from[i], &to[i], &freq[i]);
    }
    float cf[n];
    cf[0]=freq[0];

    for(i=1; i<n; i++){
        cf[i]=freq[i]+cf[i-1];
    }

    here:
    printf("Choose for the following...\n");
    printf("1. Mean\n2. Median\n3. Mode\nEnter choice: ");
    int choice;
    scanf("%d", &choice);

    switch(choice){
    case 1:
        {
        float mid[n];
        for(i=0; i<n;i++)
            mid[i]=(from[i]+to[i])/2;
        double xifi=0.00f;

        for(i=0; i<n; i++)
            xifi+=mid[i]*freq[i];
        double mean=xifi/cf[n-1];
        printf("The mean of the given observations is %f\n\n", mean);
    }
        break;
    case 2:
        {
        float nby2=cf[n-1]/2;
        int index=0;
        for(i=0; i<n; i++)
        if(nby2<=cf[i]){
            index=i;
            break;
        }
        int l=to[index]-from[index];
        double median;

        median=from[index]+((nby2-cf[index-1])*l)/freq[index];
        printf("The median of the given data is %f\n\n", median);
        //printf("L=%d, low=%.2f, upp=%.2f, nby2=%.2f, freq[index]=%.2f, cf[index-1]=%.2f\n\n", l, from[index], to[index], nby2, freq[index], cf[index-1]);
        }
        break;
    case 3:
        {
        float low=0.00f;
        float f0, f1, f2;
        float fmax=-99999;
        for(i=0; i<n; i++){
            if(freq[i]>fmax)
                fmax=freq[i];
        }
        int index=0;
        for(i=0; i<n; i++){
            if(freq[i]==fmax){
                 index=i;
                 break;
            }
        }

        float result=from[index]+((freq[index]-freq[index-1])/(2*freq[index]-freq[index-1]-freq[index+1]))*(to[i]-from[i]);
        printf("The mode of the given data is %.2f\n\n", result);
        }
        break;
    default:
        printf("Please enter a valid choice!\n\n");
        break;
    }
    printf("Any other choice?(1/0): ");
    int cho;
    scanf("%d",&cho);
    if(cho==1)
        goto here;

}
