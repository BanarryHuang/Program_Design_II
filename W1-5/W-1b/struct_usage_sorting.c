#include <stdio.h>
#include <stdlib.h>

//
//  宣告一個名為 _person 的結構 :
//

typedef struct _person _person;

struct _person {
    int age;
    char name[20];
};

//
//  宣告一個型態是 _person 的陣列
//

_person personal_data[100];

//
//

int main()
{
    int i,j,k;

    printf("%d\n", sizeof(_person));

    //

    int n = 0;

    personal_data[n].age = 10;
    strcpy( personal_data[n].name, "Amy" );
    n++;

    //
    //  排序 _person 型態的陣列
    //
    int compare_person( const void *a, const void *b );

    qsort( personal_data, n, sizeof(_person), compare_person );

    return 0;
}


//
//  compare function for data type _person
//
int compare( const void *a, const void *b )
{
    _person *A = (_person*)a;
    _person *B = (_person*)b;

    // compare the age
    return A->age - B->age;
}
