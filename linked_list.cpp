#include <stdio.h>
#include <stdlib.h>

//

typedef struct node* ptr_node;

struct node {
    int data;
    ptr_node next;

    node( int init_value )
    {
        data = init_value;
    }
};

//

struct linked_list {

    ptr_node head = NULL;
    ptr_node last = NULL;

    void add_to_tail( ptr_node nde )
    {
        if( head == NULL ) // the list is empty
        {
            head = last = nde;
            nde->next = NULL;
        }
        else
        {
            last->next = nde;
            nde->next = NULL;
            last = nde;
        }
    }

    ptr_node remove_from_head()
    {
        ptr_node original_head = head;

        if( head != NULL )
        {
            head = head->next;

            if( head == NULL )
                last = NULL;
        }

        return original_head;
    }

};

//

int main()
{
    linked_list lst;

    lst.add_to_tail( new node(7) );

    //

    ptr_node node2 = (ptr_node) malloc(sizeof(node));
    node2->data = 3;

    lst.add_to_tail( node2 );

    //

    return 0;
}
