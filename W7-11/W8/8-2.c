#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000003
int Quick_sel(int start, int end, int k);
int num[N];
int main(){
    int i,n,k;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        scanf("%d",num+i);

    scanf("%d",&k);

    printf("%d\n",Quick_sel(1, n, k));

    return 0;
}
int Quick_sel(int start, int end, int k){

    int les_num=start,gre_num=end,pivot,sel,temp;

    if(end-start+1>RAND_MAX)
        pivot=end-start+1-k;
    else
        pivot=(rand()%(end-start+1))+start;

    sel=num[pivot];

    while(1){
        while(num[les_num]<=sel)
            les_num++;
        while(num[gre_num]>sel)
            gre_num--;
        if(les_num>gre_num)
        	break;
        temp=num[les_num];
        num[les_num]=num[gre_num];
        num[gre_num]=temp;
    }
    les_num--;
    gre_num++;
    if(k>les_num)
        return Quick_sel(gre_num, end, k);
    else if(k<les_num)
        return Quick_sel(start, les_num, k);
    else
        return sel;
}
