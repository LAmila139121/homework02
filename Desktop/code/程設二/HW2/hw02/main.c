#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "headfile.h"

int cmp(const void *num1,const void *num2){
	return *(int *)num1 - *(int *)num2;
}

int main(int argc,char **argv){
	int datasize = 10;
	int c = argv[2][2]-'0';
	for (int i = 0; i < c;i++)
		datasize = datasize * 10;
	int *data = malloc(sizeof(int) * datasize);
	for (int i = 0; i < datasize;i++)
		data[i] = rand();

	int querysize = 10;
	c = argv[4][2]-'0';
	for (int i = 0; i < c;i++)
		querysize = querysize * 10;
	int *query = malloc(sizeof(int) * querysize);
	for (int i = 0; i < querysize;i++){
		int num = rand() % datasize;
		query[i] = data[num];
	}
	struct timeval start1, end1, start2, end2;
	unsigned  long diff1, diff2;

	for(int parameter = 0; parameter < argc; parameter++){
		if(strcmp(argv[parameter],"-bst")==0){
			printf("bst:\n");
			BinTree BST = NULL;
			gettimeofday(&start1, NULL);
			for (int i = 0; i < datasize; i++){
				BST = bst_insert(BST, data[i]);
			}
			gettimeofday(&end1, NULL);
			diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;
			printf("building time: %f sec\n", diff1 / 1000000.0);
			gettimeofday(&start2, NULL);
			for (int i = 0; i < querysize; i++){
				BST = bst_search(BST, query[i]);
			}
			gettimeofday(&end2, NULL);
			diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
			printf("query time: %f sec\n", diff2 / 1000000.0);
		}
		else if(strcmp(argv[parameter],"-arr")==0){
			printf("arr:\n");
			gettimeofday(&start1, NULL);
			int *arr = malloc(sizeof(int) * datasize);
			arr_insert(arr, data,datasize);
			gettimeofday(&end1, NULL);
			diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;
			printf("building time: %f sec\n", diff1 / 1000000.0);
			gettimeofday(&start2, NULL);
			for (int i = 0; i < querysize; i++){
				arr_search(arr, query[i], datasize);
			}
			gettimeofday(&end2, NULL);
			diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
			printf("query time: %f sec\n", diff2 / 1000000.0);
			free(arr);
		}
		else if(strcmp(argv[parameter],"-bs")==0){
			printf("bs:\n");
			gettimeofday(&start1, NULL);
			int *arr = malloc(sizeof(int) * datasize);
			arr_insert(arr, data ,datasize);
			qsort(arr, datasize, sizeof(int), cmp);
			gettimeofday(&end1, NULL);
			diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;
			printf("building time: %f sec\n", diff1 / 1000000.0);
			gettimeofday(&start2, NULL);
			for (int i = 0; i < querysize; i++){
				bs_search(data, query[i], datasize);
			}
			gettimeofday(&end2, NULL);
			diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
			printf("query time: %f sec\n", diff2 / 1000000.0);
			free(arr);
		}
		else if(strcmp(argv[parameter],"-ll")==0){
			printf("ll:\n");
			Node *list = NULL;
			gettimeofday(&start1, NULL);
			for (int i = 0; i < datasize;i++){
				list=ll_insert(list,data[i]);
			}
			gettimeofday(&end1, NULL);
			diff1 = 1000000 * (end1.tv_sec - start1.tv_sec) + end1.tv_usec - start1.tv_usec;
			printf("building time: %f sec\n", diff1 / 1000000.0);
			gettimeofday(&start2, NULL);
			for (int i = 0; i < querysize; i++){
				ll_search(list, query[i]);
			}
			gettimeofday(&end2, NULL);
			diff2 = 1000000 * (end2.tv_sec - start2.tv_sec) + end2.tv_usec - start2.tv_usec;
			printf("query time: %f sec\n", diff2 / 1000000.0);
		}
	}
}
