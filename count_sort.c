#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 25

int INT_MAX = 2147483647;

int main(void) {

	long n = 0;
	
	FILE *count_time;
	count_time = fopen("count_time (3).csv", "w");
	if(count_time == NULL){
		exit(404);
	}
	fprintf(count_time, "memory;time\n");
	fclose(count_time);

	char file_way[N];
	char n_file[N];

	FILE* file_names = fopen("files (3).txt", "r");
	int row = 0;
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


		for (int l = row - 1; l >= 0; --l){

			fscanf(file_names, "%[^\n]%*c", file_way);
			fscanf(file_names, "%[^\n]%*c", n_file);

			n = atoi(n_file);

			printf("%s\n", file_way);
			
			if (l == 0){
				row = 0;
				fclose(file_names);
			}

			FILE *nums = fopen(file_way, "r");

			if (nums == NULL) {
				printf("Can't open file\n");
				return 0;
			}

			int* array = (int*) calloc(n - 1, sizeof(int));

			int min = INT_MAX;
			int max = 0;
			char number[100];
			for(i = 0; i < n; i++){
				fscanf(nums, "%[^,],", number);

				array[i] = atoi(number);
			
				if (array[i] < min){
					min = array[i];
				} 
				if (array[i] > max){
					max = array[i];
				}
			}

			fclose(nums);


			// Counting sort

			int* count = (int*) calloc(max - min, sizeof(int));

			int* result = (int*) calloc(n - 1, sizeof(int));
			clock_t start, stop;
			int res_counter = 0;

			start = clock();

			for (int i = 0; i < n; ++i){
				++count[array[i] - min];
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < count[i]; j++){
					result[res_counter] = i;
					++res_counter;
				}
			}

			stop = clock();
			free(count);
			free(array);

			printf("The time for sorting of %ld elements was: %.3f ms\n", n, 1000.0*(stop - start)/CLOCKS_PER_SEC);
			
			count_time = fopen("count_time (3).csv", "a");

			if(count_time == NULL){
				exit(404);
			}
			fprintf(count_time, "%ld;%.3f\n", n, 1000.0*(stop - start)/CLOCKS_PER_SEC);
			fclose(count_time);
			
			free(result);
	}

	}
	return 0;
}
