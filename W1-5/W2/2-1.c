#include <stdio.h>
#include <string.h>
#define MAX_LEN 200

int cmp( const void *a , const void *b );

struct person{
    char name[MAX_LEN];
    int age;
    int weight;
};

typedef struct person P;

int main()
{
    int T,i=0,j,ret;
    char a;
    P group[MAX_LEN],temp;

    //freopen("input.txt","r",stdin);

    scanf("%d\n",&T);

    for(i=0;i<T;i++){
        while(1){
            scanf("%c",&a);
            if(a==' ')
                break;
            if(isalpha(a))
                group[i].name[strlen(group[i].name)]=a;
        }
        scanf("%d %d",&group[i].age,&group[i].weight);
    }
    qsort(group,T,sizeof(group[0]),cmp);
    for(i=0;i<T;i++)
        printf("%s %d %d\n",group[i].name,group[i].age,group[i].weight);
    return 0;
}
int cmp( const void *a , const void *b )
{
    P *c = (P *)a;
    P *d = (P *)b;
    if(strcmp( c->name , d->name )!=0) return strcmp( c->name , d->name );
    if(c->age != d->age) return d->age - c->age;
    else return d->weight - c->weight;
}
