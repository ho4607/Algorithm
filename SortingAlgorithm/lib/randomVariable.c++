
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
 FILE* fout;
 srand(time(NULL));
 int random = 0;

 fout = fopen("input.txt", "w");

 for (int i = 0; i < 10000; i++) {
  random = rand() % 10000;
  fprintf(fout, "%d ", random);
 }
}