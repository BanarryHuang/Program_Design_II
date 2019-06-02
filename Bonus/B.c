#include <stdio.h>
#include <string.h>
#define N 100010
int main(){
    int i,j,k,n,sum,apSum=0,temp,index,l;
    int a[N],b[N],w[N],g[N];
    double max=0,seg,res,temp_s,temp_r;

    scanf("%d %d",&n,&sum);

    for(i=0;i<n;i++){
        scanf("%d%d",w+i,a+i);
        if(a[i]>=sum){
            apSum=a[i];
            b[i]=i+1;
        }
        else{
            apSum+=a[i];
            if(apSum<sum)
                b[i]=-1;
            else if(b[i-1]!=-1){
                temp=b[i-1]-1;
                while(apSum>=sum){
                    apSum-=a[temp];
                    temp++;
                }
                apSum+=a[--temp];
                b[i]=temp+1;
            }
            else{
                temp=0;
                while(apSum>=sum){
                    apSum-=a[temp];
                    temp++;
                }
                apSum+=a[--temp];
                b[i]=temp+1;
            }
        }
    }

    for(i=0;i<n;i++){
        g[i]=b[i];
        if(b[i]!=-1){
            seg=0;
            res=0;
            for(j=b[i]-1;j<=i;j++){
                seg+=w[j];
                res+=a[j];
            }
            temp_s=seg;
            temp_r=res;
            seg/=res;
            if(i>0){
                l=b[b[i]-1]-1;
                if(l<0){
                    for(j=b[i]-2;j>0;j--){
                        temp_s+=w[j];
                        temp_r+=a[j];
                        if(temp_s/temp_r>seg){
                            g[i]=j+1;
                            seg=temp_s/temp_r;
                        }
                    }
                }
                else{
                    for(j=b[i]-2;j>l;j--){
                        temp_s+=w[j];
                        temp_r+=a[j];
                        if(temp_s/temp_r>seg){
                            g[i]=j+1;
                            seg=temp_s/temp_r;
                        }
                    }
                }
            }
            if(seg>max){
                max=seg;
                index=i;
            }
        }
    }
    printf("%f\n",max);
    printf("%d %d\n",g[index],index+1);
    return 0;
}
