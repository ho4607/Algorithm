#include <stdio.h>  
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

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

int main(void){
    int Array[4] = {0,0,1,2};
    int Arrayb[4] = {0,3,1,2};
    int Arrayc[4] = {0,0,0,1};
    sorting(Array);
    sorting(Arrayb);
    sorting(Arrayc);

    for(int i = 0; i < 4; i++) {
        printf("%d ", Array[i]);
    } 
    printf("\n");

    for(int i = 0; i < 4; i++) {
        printf("%d ", Arrayb[i]);
    }

    printf("\n");
    for(int i = 0; i < 4; i++) {
        printf("%d ", Arrayc[i]);
    } 
    
    return 0;
}

