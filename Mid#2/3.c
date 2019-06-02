#include <stdio.h>
#include <string.h>
#define d 100003
#define max_int 3*1e14
long long int num;
long long int X,Y;
char dis[d];
long long int neg_NS=0,neg_EW=0,NS=0,EW=0,B=0,E=0,W=0,N=0,S=0;

int test(long long int x){
    int i,flag=1;
    long long int neg_NS_now=0,neg_EW_now=0,NS_now=0,EW_now=0,B_now=0,re_x,re_y,temp,E_now=0,W_now=0,N_now=0,S_now=0;

    NS_now=NS*((long long int)x/num);
    EW_now=EW*((long long int)x/num);
    B_now=B*((long long int)x/num);
    neg_NS_now=neg_NS*((long long int)x/num);
    neg_EW_now=neg_EW*((long long int)x/num);
    if(X==0){
        E_now=E*((long long int)x/num);
        W_now=W*((long long int)x/num);
    }
    if(Y==0){
        N_now=N*((long long int)x/num);
        S_now=S*((long long int)x/num);
    }
    for(i=0;i<x%num;i++){
        if(dis[i]=='E'){
            if(X>0){
                EW_now++;
                B_now++;
            }
            else if(X==0)
                E_now++;
            else
                neg_NS_now++;
        }
        if(dis[i]=='W'){
            if(X<0){
                EW_now++;
                B_now++;
            }
            else if(X==0)
                W_now++;
            else
                neg_NS_now++;
        }
        if(dis[i]=='N'){
            if(Y>0){
                NS_now++;
                B_now++;
            }
            else if(Y==0)
                N_now++;
            else
                neg_EW_now++;
        }
        if(dis[i]=='S'){
            if(Y<0){
                NS_now++;
                B_now++;
            }
            else if(Y==0)
                S_now++;
            else
                neg_EW_now++;
        }
    }

    if(X>0)
        re_x=X-EW_now;
    else
        re_x=-X-EW_now;
    if(Y>0)
        re_y=Y-NS_now;
    else
        re_y=-Y-NS_now;

    if(X==0&&Y==0)
        return 1;
    else if(X==0){
        temp=E_now;
        if(W_now<temp)
            temp=W_now;
        if(re_y-2*temp-B_now<=0)
            return 1;
        else
            return 0;
    }
    else if(Y==0){
        temp=N_now;
        if(S_now<temp)
            temp=S_now;
        if(re_x-2*temp-B_now<=0)
            return 1;
        else
            return 0;
    }
    if(re_x<=0&&re_y<=0){
        return flag;
    }
    else if(re_x>0&&re_y>0){
        if(re_x+re_y>B_now)
            flag=0;
        return flag;
    }
    else if(re_x>0){
        temp=-re_y;
        if(neg_EW_now<temp){
            B_now-=(temp-neg_EW_now);
            temp=neg_EW_now;
        }
        if(re_x-temp-B_now>0)
            flag=0;
    }
    else if(re_y>0){
        temp=-re_x;
        if(neg_NS_now<temp){
            B_now-=(temp-neg_NS_now);
            temp=neg_NS_now;
        }
        if(re_y-temp-B_now>0)
            flag=0;
    }

    return flag;

}
long long int binary_search(long long int left,long long int right )
{
    if( test(left) == 1 )
        return left;

    if( test(right) == 0 )
        return -1;

    long long int mid;

    while( left < right - 1 )
    {
        mid = ( left + right ) / 2;

        if( test(mid) == 0 )
            left = mid;
        else
            right = mid;
    }

    return right;
}

int main(){
    int i;
    scanf("%lld",&num);

    scanf("%s",dis);

    scanf("%lld%lld",&X,&Y);

    for(i=0;i<num;i++){
        if(dis[i]=='E'){
            if(X>0){
                EW++;
                B++;
            }
            else if(X==0)
                E++;
            else
                neg_NS++;
        }
        if(dis[i]=='W'){
            if(X<0){
                EW++;
                B++;
            }
            else if(X==0)
                W++;
            else
                neg_NS++;
        }
        if(dis[i]=='N'){
            if(Y>0){
                NS++;
                B++;
            }
            else if(Y==0)
                N++;
            else
                neg_EW++;
        }
        if(dis[i]=='S'){
            if(Y<0){
                NS++;
                B++;
            }
            else if(Y==0)
                S++;
            else
                neg_EW++;
        }
    }

    printf("%lld\n",binary_search(1,max_int));

    return 0;
}
