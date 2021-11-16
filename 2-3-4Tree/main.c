#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

typedef struct Node{
    int key[4];
    Node *parent;
    Node *subNode[4];
} Node;

void insertion(int value, struct Node *N);

int main (void){

    Node *root;

    insertion( /*TODO: change the input value*/ 3 , root);

    return 0;
};

void insertion(int value, Node *N){
    // 현재 위치가 leaf node 일 때
    if ( (N->subNode[0] == NULL) && (N->subNode[1] == NULL) && (N->subNode[2] == NULL) && (N->subNode[3] == NULL) ){


        if(N->key[0] == 0 ){ N->key[0] = value;}      // 첫전빼 키에 넣기
        else if(N->key[1] == 0 ){ N->key[1] = value;} // 두번째 키에 넣기
        else if(N->key[2] == 0 ){ N->key[2] = value;} // 세번째 키에 넣기
        else if(N->key[3] == 0 ){                     // 네번째 키에 넣고 split 실행
            N->key[3] = value;
            
            //split 작업 시작
            insertion(N->key[2], N->parent);
            N->parent->subNode[0] = &N;

            insertion(N->key[3], N->parent);
            N->key[2]=0;
            N->key[3]=0;
        }
    }
    // 현재 위치가 core Node 일 때, 값이 같은 경우는 논하지 않음.
    else if(N->subNode[0] != NULL && N->key[0] != 0){  
        if(value < N->key[0]){insertion(value, N->subNode[0]);}
        else if(N->key[0] < value && value < N->key[1]){insertion(value, N->subNode[1]);}
        else if(N->key[1] < value && value < N->key[2]){insertion(value, N->subNode[2]);}
        else if(N->key[2] < value && value < N->key[3]){insertion(value, N->subNode[3]);}
    }
    // 현재 위치가 Core Node 이고, node에 element가 존재하지 않을 때 / 새로운 노드값에 입력 
    else if( N->subNode[0] != NULL && N-> key[0] == 0){
        N->key[0] = value;
        //N->
    }
};

// void split(Node *currentNode){
// }