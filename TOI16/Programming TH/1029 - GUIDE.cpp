#include<stdio.h>  
#include<stdlib.h>  
  
int a[200002],n,num,q,m;  
  
void qsort(int h,int t)  
{  
    if(t<=h)    return;  
    int i=h,j=t,x=h+(rand()%(t-h+1));  
    int k=a[x];  
    a[x]=a[h];  
    a[h]=k;  
    while(i!=j)  
    {  
        while(a[j]>k&&i!=j)  
        {  
            j--;  
        }  
        if(i==j)    break;  
        int z=a[j];  
        a[j]=a[i];  
        a[i++]=z;  
        while(a[i]<k&&i!=j)  
        {  
            i++;  
        }  
        if(i==j)    break;  
        z=a[j];  
        a[j--]=a[i];  
        a[i]=z;  
    }  
    a[i]=k;  
    qsort(h,i-1);  
    qsort(i+1,t);  
}  
int delrep(int t)  
{  
    int z=1,c;  
    for(int i=1;i<=t;i++)  
    {  
        c=1;  
        if(i+1==t)  
        {  
            a[z]=a[i];
			z++;  
            break;  
        }  
  
        while(a[i]==a[i+1])  
        {  
            i++;  
            c++;  
        }  
        if(c%2==1)  
        {  
            a[z++]=a[i];  
        }  
  
    }  
    a[z]=a[t];  
    return z;  
}  
void bsap(int h,int t,int x)  
{  
    int m=(h+t)/2;  
    if(x>=a[m]&&x<a[m+1])  
    {  
        printf("%d\n",a[m+1]-a[m]);  
    }  
    else  
    {  
        if(x>a[m])  
        {  
            bsap(m,t,x);  
        }  
        else  
        {  
            bsap(h,m,x);  
        }  
    }  
}  
  
int main()  
{  
    int id;  
    scanf("%d %d %d",&num,&n,&q);  
    a[0]=1;  
    a[2*n+1]=num+1;  
    for(int i=0;i<n;i++)  
    {  
        scanf("%d %d",&a[2*i+1],&a[2*i+2]);  
        a[2*i+2]+=a[2*i+1];  
    }  
    qsort(0,2*n+1);  
    id=delrep(2*n+1);  
    qsort(0,id);  
    for(int i=0;i<q;i++)  
    {  
        scanf("%d",&m);  
        bsap(0,id,m);  
    }  
    return 0;  
}  
