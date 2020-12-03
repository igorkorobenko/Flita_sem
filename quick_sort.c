#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>
#define N 100

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

void quick_sort(unsigned int *arr, long n) {
    bool *trueposition = (bool *)calloc(n, sizeof(bool));
	int i, j;
    for (i = 0; i < n - 1; i += (trueposition[i+1] | trueposition[i])) {
        int l = i;
        int r = l + 1;
        while (trueposition[r] != 1 && r != n) {
            ++r;
        }
        --r;
        int middle = (r + l) / 2;
        for (j = l; j < middle; ++j){
            if (arr[j] > arr[middle]){
            	swap(&arr[j], &arr[middle-1]);
            	swap(&arr[middle - 1], &arr[middle]);
                --j;
                --middle;
            }
        }
        for (j = middle + 1 ; j <= r; ++j){
            if (arr[j] < arr[middle]){
            	swap(&arr[j], &arr[middle+1]);
            	swap(&arr[middle + 1], &arr[middle]);
                ++middle; 
            }
        }
        trueposition[middle] = true;
    }
    free(trueposition);
}

int main(void) {
	FILE *quick_time;
	char name[N];
	char number[N];
	clock_t start, stop;
	long n = 0;
	int i = 0;
	int check = 1;
	
	quick_time = fopen("quick_time.csv", "w");
	fprintf(quick_time, "memory;time\n");
	fclose(quick_time);

	FILE* file_names = fopen("files (3).txt", "r");
	int l, row = 0;
	while(!feof(file_names)){
		if((getc(file_names)) == '\n'){
			++row;
		}
	}
	row = row/2;
	fclose(file_names);
	file_names = fopen("files (3).txt", "r");
	while(row != 0){
		if(file_names == NULL){
			exit(404);
		}
		for (l = row - 1; l >= 0; --l){
			fscanf(file_names, "%[^\n]%*c", name);
			fscanf(file_names, "%[^\n]%*c", number);
			n = atoi(number);
			printf("%s\n", name);
			if (l == 0){
				row = 0;
				fclose(file_names);
			}
			
			FILE *block;
		    
			unsigned int *arr = (unsigned int *)calloc(n, sizeof(unsigned int));
			block = fopen(name, "r");
			if(block == NULL){
				exit(1);
			}
			for(i = 0; i < n; i++){
				fscanf(block, "%[^,],", number);
				arr[i] = atoi(number);
			}
			fclose(block);
			start = clock();
			quick_sort(arr, n);
			stop = clock();
		    free(arr);
		    printf("The Time for sorting of %ld elements was: %.3f ms\n", n, 1000.0*(stop - start)/CLOCKS_PER_SEC);
		    quick_time = fopen("quick_time.csv", "a");
		    if(quick_time == NULL){
		    	exit(2);
			}
		    fprintf(quick_time, "%ld;%.3f\n", n, 1000.0*(stop - start)/CLOCKS_PER_SEC);
		    fclose(quick_time);
		}
	}
    return 0;
}
