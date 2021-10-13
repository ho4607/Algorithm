#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable :4996)
#define max_len 10000


void main (){
	int dataBox[max_len];
	int max,temp,index,i,n,key,E;
	
	E = 0;
 	//file input
    FILE* fin;
    fin = fopen("input.txt","r");
    if (fin == NULL) { 
        printf("Fail to read file. \n\nCheck if the \"input.txt\" file exists in the directory.\n\n");
        E = 1;
    }
    for(i=0; i<max_len ;i++){   // loop invariant: i-1 ������ ���� �迭�� ����ִ�. 
   		fscanf(fin,"%d",&dataBox[i]);
	}
	fclose(fin);
	
	//Selection Sort
	n = max_len;
	for(i=1;i<n;i++){
		key=dataBox[i];
		for(index=i-1;index>=0&&dataBox[index]>key;index--)
			dataBox[index+1] = dataBox[index];		
		dataBox[index+1]=key;
	}
	
	//Check if there is a valid value inside the array and display it in the console. 
//	for(i=0; i<max_len; i++){
//		printf("%d ",dataBox[i]);
//	}
//	
		//�����ؾ���. 
	if (dataBox[0] < dataBox[max_len-1]&&E==0) { 
        printf("Sorting is complete.\nOpen the output file to check the results.  \n\n");
    }
	
	//file output
    FILE* fout;
	fout = fopen("output.txt", "w+");
    for(i=0; i<max_len; i++){   // loop invariant: i-1 ������ ���� txt���Ͽ� ����ִ�.
   		fprintf(fout,"%d ",dataBox[i]);
	}
	fclose(fout);
}


