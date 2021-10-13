#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)
#define max_len 10000
// #include <ctype.h>

void main (){
	int dataBox[max_len];
	int max,temp,index,i,n,E;
	
	E = 0;
 	//file input
    FILE* fin;
    fin = fopen("input.txt","r");
    if (fin == NULL) { 
        printf("Fail to read file. \n\nCheck if the \"input.txt\" file exists in the directory.\n\n");
        E = 1;
    }
    for(i=0; i<max_len ;i++){   // loop invariant: i-1 까지의 값은 배열에 담겨있다. 
   		fscanf(fin,"%d",&dataBox[i]);
	}
	fclose(fin);

	
	//Selection Sort
	n = max_len;
    while(n>0){
    	max = 0;
		for(index = 1; index<n; index++){
			if(dataBox[index]>dataBox[max])
				max = index;
		}
		temp = dataBox[n-1];
		dataBox[n-1] = dataBox[max];
		dataBox[max] = temp;
		n--;
	}
	
	//Check if there is a valid value inside the array and display it in the console. 
//	for(i=0; i<max_len; i++){
//		printf("%d ",dataBox[i]);
//	}
//	
	if (dataBox[0] < dataBox[max_len-1]&& E==0) { 
        printf("Sorting is complete.\nOpen the output file to check the results.  \n\n");
    }
	//file output
    FILE* fout;
	fout = fopen("output.txt", "w+");
    for(i=0; i<max_len; i++){   // loop invariant: i-1 까지의 값은 txt파일에 담겨있다. 
   		fprintf(fout,"%d ",dataBox[i]);
	}
	fclose(fout);
}

