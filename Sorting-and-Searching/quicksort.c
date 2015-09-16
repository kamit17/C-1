#include<stdio.h>
#include<stdlib.h>

void printpretty(int *a, int size){
	int x;
	for(x=0;x<size;) printf("%d",a[x++]);
	printf("\n");
}

void swap(int *a, int i, int j){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void quicksort(int *a, int size){
	if (size < 2) return;
	int p = rand() % size;
	int i,j;
	for(i=0, j=size-1;;){
		while(a[i]<a[p]) i++;
		while(a[j]>a[p]) j--;
		swap(a,i,j);
       if (i>=j) break;
	}
	quicksort(a,i);
	quicksort(a + i, size - i);
}

int main(){
	int a[] = {8,2,-1,4,5};
	int size = sizeof(a)/sizeof(int);
	printpretty(a,size);
    quicksort(a,size);
	printpretty(a,size);
	return 0;
}
