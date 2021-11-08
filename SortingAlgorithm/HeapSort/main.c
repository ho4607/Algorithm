#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#define max_len 10000

#pragma warning(disable :4996)

void HeapSort(int A[]);


int main(void){

    int dataBox[max_len];
	int i,E;
	
	// Error significant
	E=0;
	
 	//File input
    FILE* fin;
    fin = fopen("input.txt","r");
    if (fin == NULL) { 
        printf("Fail to read file. \n\nCheck if the \"input.txt\" file exists in the directory.\n\n");
        E=1;
    }
    for(i=0; i<max_len ;i++){  
   		fscanf(fin,"%d",&dataBox[i]);
	}
	fclose(fin);
	
    //HeapSort
    HeapSort(dataBox);


	//File output
    FILE* fout;
	fout = fopen("output.txt", "w+");
    for(i=0; i<max_len; i++){  
   		fprintf(fout,"%d ",dataBox[i]);
	}
	fclose(fout);
    printf("Successful");

}

void MaxHeapify(int A[], int i){
    int l = 2*i;
    int r = 2*i+1;
    int largest;
    int temp;
    if(l <= (sizeof(A)/sizeof(int)+1)&& A[l] > A[i]){
        largest = l;
    }else{
        largest = i;
    }
    if(r <= sizeof(A)/sizeof(int)&& A[r] > A[largest]){
        largest = r;
    }
    if(largest != i){
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest);
    }
}

void BuildMaxHeap(int A[]){
    for(int i = (sizeof(A)/sizeof(int))/2; i < 0 ; i-- ){
        MaxHeapify(A,i);
    }
}

void HeapSort(int A[]){
    int temp;
    BuildMaxHeap(A);
    for(int i = sizeof(A)/sizeof(int); i < 1 ; i--){
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;
        MaxHeapify(A,1);
    }
}