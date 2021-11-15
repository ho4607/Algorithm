#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

typedef struct Node{
    int key[4];
    int* parent;
    Node *subNode[4];
} Node;

void insertion(int value, struct Node *N);

int main (void){

    Node *root;

    insertion( /*TODO: change the input value*/ 3 , root);

    return 0;
};

void insertion(int value, struct Node *N){
    // 현재 위치가 leaf node 일 때
    if ( N->subNode[0] = NULL /*TODO: 언제 NIL인지 결정해야함.*/){
        /* TODO: 언제 length로 판별하는 방법은 C언어에서 잘못 됌.
        if(length(N->key[0]) <= 1) N->key[0] = value;
        else if(length(N->key) <= 2) N->key[1] = value;
        */
    }
    // 현재 위치가 core Node 일 때
    else if(N->subNode[0] != NULL && (N->key[0] != NULL)){  
        if(value <= N->key[0]){insertion(value, N->subNode[0]);}
        else if(N->key[0] < value <= N->key[1]){insertion(value, N->subNode[1]);}
        else if(N->key[1] < value <= N->key[2]){insertion(value, N->subNode[2]);}
        else if(N->key[2] < value <= N->key[3]){insertion(value, N->subNode[3]);}
    }
    // 현재 위치가 Core Node 이고, node에 element가 존재하지 않을 때 
    else if( N->subNode[0] != NULL && (N-> key[0] = NULL)){
        N->key[0] = value;
    }
    

};