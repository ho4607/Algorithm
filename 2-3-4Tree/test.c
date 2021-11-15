#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct Node{
    int key[4];
    int* parent;
    Node *subNode[4];
} Node;

int main (void){

    Node *root;

    insertion( /*TODO: change the input value*/ 3 , root);

    return 0;
};
