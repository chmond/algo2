#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"



typedef struct AVL_node{
    int value;
    struct AVL_node* parent;
    struct AVL_node* left;
    struct AVL_node* right;
    struct AVL_node* bf;
} AVL_node ;


AVL_node* new_AVL_node(int value){
    AVL_node* t = (AVL_node*) malloc(sizeof(AVL_node));
    if (t){
        t -> value = value;
        t -> left = NULL;
        t -> right = NULL;
        t -> bf = 0;
    } return t;
};


bool is_empty(AVL_node* t){
   return t == NULL;

}


int height(AVL_node* t){
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

void insert(AVL_node** t, int value){
    if (t == NULL){
        if (is_empty(*t)){
            (*t=new_AVL_node(value));
        }
        if (value > (*t)->value){
            insert(&((*t)->right),value);
        }
        else{
            insert(&((*t)->left),value);
        }
        };
}

void fill(AVL_node** t, int n){
    for (int i = 0; i < n; i++)
    {
    insert((t),rand()%100);
    }
    
}

void set_left_child(AVL_node*t,AVL_node*lc){
    t->left = lc;
    if(lc != NULL){
        lc->parent = t;
    }
}
void set_right_child(AVL_node*t,AVL_node*rc){
    t->left = rc;
    if(rc != NULL){
            rc->parent = t;
    }
}


AVL_node* right_rotate(AVL_node* t){
    AVL_node* x = t->left;
    AVL_node* b = x->right;
    set_left_child(t,b);
    set_right_child(x,t);
    return x;
}

AVL_node* left_rotate(AVL_node* t){
    AVL_node* x = t->right;
    AVL_node* b = x->left;
    set_right_child(t,b);
    set_left_child(x,t);
    return x;
}

AVL_node* delete(AVL_node* t){

}