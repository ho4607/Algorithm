#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define max_len 10000

#pragma warning(disable :4996)

//void MergeSort(int A[], int p, int q);
void MergeSort(int arr[], int n);
void Merge(int A[], int p, int q, int r);
char compare(int a, int b);
int temp[max_len];


int main(void) {
	int dataBox[max_len];
	int i,E;
	
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

	//Merge Sort
	MergeSort(dataBox, max_len);
	
	//file output
    FILE* fout;
	fout = fopen("output.txt", "w+");
    for(i=0; i<max_len; i++){   
   		fprintf(fout,"%d ",dataBox[i]);
	}
	fclose(fout);
	
	return 0;
}

//void MergeSort(int A[], int p, int r){
//	for (int m = 1; m <= r-p; m=2*m){
//		
//		for (int i = p; i<r; i+=2*m){
//			int x = i;
//			int y = i+m-1;
//			int z = (i+2*m-1 > r) ? r : i+2*m-1;
//			Merge(A,x,y,z);
//		}
//	}
//}

void MergeSort(int arr[], int n){
   int curr_size; 
   int left_start; 
 
   
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           int mid = (left_start + curr_size - 1> n-1)? left_start + curr_size - 1 : n-1;       
           int right_end = (left_start+ 2*curr_size - 1<n-1)? left_start+ 2*curr_size - 1: n-1;
           Merge(arr, left_start, mid, right_end);
       }
   } 
}

// subroutine Merge
void Merge(int A[], int p, int q, int r){	
	int k = p; 
	int i = p ;
	int j = q+1;
	
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

// subroutine compare left with right
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
}
