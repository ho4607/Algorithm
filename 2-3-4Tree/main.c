#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

typedef struct Node{
    Node *parent;
    int key[4];
    Node *subNode[4];
} Node;

Node* initNode();
void insertion(int value, struct Node *N);
int sorting(int array[4]);

int main (void){

    Node *root = initNode(); 

    insertion( /*TODO: change the input value*/ 3 , root);

    return 0;
};

//구조체를 반환하는 함수
Node* initNode(){
    Node *root = (Node*) malloc (sizeof(Node)); 

    root->parent = NULL;
    for(int i=0 ; i<4; i++){
        root->subNode[i] = NULL;
    }
    
    return root;
}


void insertion(int value, Node *current){
    // 현재 위치가 leaf node 일 때
    if ( (current->subNode[0] == NULL) && (current->subNode[1] == NULL) && (current->subNode[2] == NULL) && (current->subNode[3] == NULL) ){
        if(current->key[0] == 0 ){ current->key[0] = value;}      // 첫번째 키에 넣기
        else if(current->key[1] == 0 ){ current->key[1] = value;} // 두번째 키에 넣기
        else if(current->key[2] == 0 ){ current->key[2] = value;} // 세번째 키에 넣기
        else if(current->key[3] == 0 ){                     // 네번째 키에 넣고 sorting 후 split 실행
            current->key[3] = value;
            
            //노드 내부 키 값을 정렬
            sorting(current->key); 

            // split작업 실행
            Node *another = initNode();
            insertion(current->key[3], another);
            
            //부모노드가 존재하지 않을 때
            if(current->parent == NULL){
                Node *parent = initNode();
                insertion(current->key[2], parent);
                current->parent = parent;     // 
                //TODO: 자식의 포인터 위치도 올바르게 정렬해줘야 함.
                parent->subNode[0] = current; // 첫번째 자식으로 연결
                parent->subNode[1] = another; // 두번째 자식으로 연결
            }//부모 노드가 존재할 때
            else if(current->parent != NULL){
                insertion(current->key[2],current->parent);
                current->parent->subNode[1] = another;
            }
            another->parent = current->parent;
            another->subNode[0] = current->subNode[3];
             
            //초기화
            current->key[2]=0;
            current->key[3]=0;
            current->subNode[3] = NULL;
        }
    }
    //현재 위치가 leaf node가 아닐 때(자식 tree가 있을 때), 자식 위치로 가게 jump
    else if(current->subNode[0] != NULL){
        //현재 위치가 Core Node이고, node에 element가 존재할 때, 올바른 subNode를 선택해 다시 삽입진행.
        if(current->key[0] != 0){  
            if(value < current->key[0] && current->subNode[0] != NULL){insertion(value, current->subNode[0]);}
            else if(current->key[0] < value && value < current->key[1] && current->subNode[1] != NULL){insertion(value, current->subNode[1]);}
            else if(current->key[1] < value && value < current->key[2] && current->subNode[2] != NULL){insertion(value, current->subNode[2]);}
            else if(current->key[2] < value && value < current->key[3] && current->subNode[3] != NULL){insertion(value, current->subNode[3]);}
        }
        // 현재 위치가 Core Node 이고, node에 element가 존재하지 않을 때 / 노드에 삽입 
        else if( current->key[0] == 0){
            current->key[0] = value;
        }
    }
    
};

arrangePtr(Node *ptr[4]){


}

//Bubble sort + 0은 맨뒤로 정렬 0,1,3,2 -> 1,2,3,0
int sorting(int key[4]){
    int n = 4;
    int index,j,i,temp;
	for(i=n-1;i>0;i--){
		for(int index=0;index<i;index++){
			if(key[index]>key[index+1]||key[index]==0){
			temp= key[index];
			key[index] = key[index+1];
			key[index+1]=temp;		
			}
		}
	}
}
