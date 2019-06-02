#include <stdio.h>
#include <string.h>
int main(){

    char string[50];
    long long int x=1/2+2147483647/2,max=2147483647,min=1;

    while(1){
        printf("? %lld\n",x);
        fflush(stdout);
        fgets(string,50,stdin);

        if(string[0]=='<'){
            if(min!=x){
                min=x;
                x=(max+min)/2;
            }
            else
                x++;
        }
        else if(string[0]=='>'){
            if(max!=x){
                max=x;
                x=(max+min)/2;
            }
        }
        else
            break;
    }

    return 0;
}
