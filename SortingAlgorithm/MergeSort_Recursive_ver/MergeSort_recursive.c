#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)

#define max_len 10000
void Merge(int A[], int p, int q, int r);	
void Merge_Sort(int A[],int p,int r);
char compare(int a, int b);

int temp[max_len];

int main(void){
	int dataBox[max_len];
	int i,E;
	
	// Error significant
	E=0;
	
 	//file input
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
	
	//Merge Sort Algorithm
	Merge_Sort(dataBox, 0, max_len-1);
	
	//file output
    FILE* fout;
	fout = fopen("output.txt", "w+");
    for(i=0; i<max_len; i++){  
   		fprintf(fout,"%d ",dataBox[i]);
	}
	fclose(fout);
	
}




void Merge(int A[], int p, int q, int r){	
//	int temp[max_len]; // temporary array
	int k = p; 
	int i = p ;
	int j = q + 1;
	
	while (i <= q && j <= r){
		 switch(compare(A[i],A[j])){
		 	case '>': 
			 	temp[k] = A[j]; j++; k++; break;
		 	case '<': 
			 	temp[k] = A[i]; i++; k++; break;
	 	case '=': 
			 	temp[k] = A[i]; i++; k++; 
		 		temp[k] = A[j]; j++; k++; break;
		}	
	}
	
	for(;i<=q;i++) {temp[k] = A[i]; k++;}
	for(;j<=r;j++) {temp[k] = A[j]; k++;}
	
	//insert value of temp to A
	for(int t=p; t<=r; t++){
		A[t] = temp[t];
	}
}


// subroutine Merge_Sort 
void Merge_Sort(int A[], int p, int r){
	//p,q,r are index number of Array A
	if(p<r) {
		int q = (p+r)/2; //divide Array
		Merge_Sort(A,p,q);
		Merge_Sort(A,q+1,r);		
		Merge(A,p,q,r); //combine subArray
	}
		
}

// compare left with right and return char.
char compare(int left, int right){
	if(left>right){
		return '>';
	}
	else if(left<right){
		return '<';	
	}
	else if(left=right){
		return '=';
	}
	else{
		return 'N';
	}
}
