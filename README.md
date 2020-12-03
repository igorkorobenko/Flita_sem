# Изучение сортировок - сортировка подсчетом и быстрая сортировка

## Алгоритм сортировки подсчетом:

```C
			for (int i = 0; i < n; ++i){
				++count[array[i] - min];
			}

			for (int i = 0; i < n; ++i){
				for (int j = 0; j < count[i]; j++){
					result[res_counter] = i;
					++res_counter;
				}
			}
```

## Структурная схема алгоритма:

![Alt-текст](https://github.com/igorkorobenko/Flita_sem/blob/main/count_scheme.png "структурная схема сортировки подсчетом")

## Алгоритм быстрой сортировки:

```C
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
``` 

## Структурная схема алгоритма:

![Alt-текст](https://github.com/igorkorobenko/Flita_sem/blob/main/quick_scheme.png "структурная схема быстрой сортировки")

## рафик на малых количествах входных данных: 

![Alt-текст](https://github.com/igorkorobenko/Flita_sem/blob/main/graph1.png "график на малых количествах входных данных")

## График на больших количествах входных данных:

![Alt-текст](https://github.com/igorkorobenko/Flita_sem/blob/main/graph2.png "График на больших количествах входных данных")
