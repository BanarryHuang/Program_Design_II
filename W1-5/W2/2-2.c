#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 510

struct person{
    char name[21];
    int list_of_friends[510];
    int friends;
};

typedef struct person P;

int main()
{
    int G,T,i,j,k,l;
    char a,buf[100];
    int xA,xB;
    P group[MAX_LEN];
    char *argv[4];
    for(i=0;i<4;i++)
        argv[i]=malloc(sizeof(char));

    //freopen("input.txt","r",stdin);

    scanf("%d\n",&G);

    for(i=0;i<G;i++){
        scanf("%s",group[i].name);
        if(group[i].name[strlen(group[i].name)-2]=='\r')
            group[i].name[strlen(group[i].name)-2]=0;
        if(group[i].name[strlen(group[i].name)-1]=='\n')
            group[i].name[strlen(group[i].name)-1]=0;
        group[i].friends=-1;
    }

    scanf("%d\n",&T);

    for(i=0;i<T;i++){

        scanf("%s",argv[0]);

        if(strcmp(argv[0],"MakeFriend")==0){
            scanf("%s %s",argv[1],argv[2]);
            xA=-1;
            xB=-1;
            for(j=0;j<G;j++){
                if(strcmp(group[j].name,argv[1])==0)
                    xA=j;
                else if(strcmp(group[j].name,argv[2])==0)
                    xB=j;
                if(xA>-1&&xB>-1)
                    break;
            }
            group[xA].friends++;
            group[xA].list_of_friends[group[xA].friends]=xB;
            group[xB].friends++;
            group[xB].list_of_friends[group[xB].friends]=xA;
        }
        else if(strcmp(argv[0],"ListFriend")==0){
            scanf("%s",argv[1]);
            for(j=0;j<G;j++){
                if(strcmp(group[j].name,argv[1])==0)
                    break;
            }
            for(l=0;l<group[j].friends+1;l++){
                if(l>0)
                    printf(" ");
                printf("%s",group[group[j].list_of_friends[l]].name);
            }
            printf("\n");
        }
    }
    return 0;
}
