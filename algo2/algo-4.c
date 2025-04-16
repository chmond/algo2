#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"



typedef struct node{
    int value;
    struct node* parent;
    struct node* left;
    struct node* right;
} node ;


node* new_node(int value){
    node* t = (node*) malloc(sizeof(node));
    if (t){
        t -> value = value;
        t -> left = NULL;
        t -> right = NULL;
    } return t;
};


bool is_empty(node* t){
   return t == NULL;

}


int height(node* t){
    if (is_empty(t)){
        return -1;
    }
    int left_height = height(t -> left);
    int right_height = height(t -> right);
    if (left_height > right_height){
        return left_height + 1;}
    else{
        return right_height + 1;}

}

void insert(node** t, int value){
    if (t == NULL){
        if (is_empty(*t)){
            (*t=new_node(value));
        }
        if (value > (*t)->value){
            insert(&((*t)->right),value);
        }
        else{
            insert(&((*t)->left),value);
        }
        };
}

void fill(node** t, int n){
    for (int i = 0; i < n; i++)
    {
    insert((t),rand()%100);
    }
    
}

void set_left_child(node*t,node*lc){
    t->left = lc;
    if(lc != NULL){
        lc->parent = t;
    }
}
void set_right_child(node*t,node*rc){
    t->left = rc;
    if(rc != NULL){
            rc->parent = t;
    }
}


node* right_rotate(node* t){
    node* x = t->left;
    node* b = x->right;
    set_left_child(t,b);
    set_right_child(x,t);
    return x;
}

node* left_rotate(node* t){
    node* x = t->right;
    node* b = x->left;
    set_right_child(t,b);
    set_left_child(x,t);
    return x;
}


