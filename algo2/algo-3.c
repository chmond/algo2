#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct node {
    int value;
    struct node* next;
};

typedef struct node node;
typedef node* list;

bool is_empty(list l){
    l==NULL;
}

int length(list l){
    int count = 0;
    list p = l;
    while (p!=NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void print_values(list l){
    list p = l;
    while (p != NULL)
    {
        printf("%d",p->value);
        p = p->next;
    }
}

bool element_at(list l, int index, int* value){
    list p = l;
    int i = 0;

    if (index < length(l)-1)
    {
        while (i<index)
        {
            if (i = index)
            {
                *value = p-> value;
            }
            i++;
            p = p->next;
        }
        
    }
    else{
        false;
    }
    
}

int main(){
        node n2 = {2,NULL};
        node n1 = {1,&n2};
    list l = {&n1};
}
