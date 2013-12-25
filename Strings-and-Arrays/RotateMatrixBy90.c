#include<stdio.h>

int complement(int n, int base){
	return base-1-n;
}

int main(){
	const int rows=5;
	const int columns=5;
	int m1[rows][columns];
	int i=0,j=0,n=0;
	
	// Set the Matrix
	while(i<rows){
		while(j<columns){
			m1[i][j]=++n;
			j++;
		}
		i++;
		j=0;
	}
	
	i=0;
	j=0;

	
	// Rotate the Matrix
	while(i < rows/2){
		j=i;
		while(j<columns-i){
			printf("%d ",m1[i][j]);	
			j++;
		}
		i++;
	}
	
	printf("\nChosen over\n");

	i=0;
	j=0;
	
	// Display the Matrix
	while(i<rows){
		while(j<columns){
			printf("%d\t",m1[i][j]);
			j++;
		}
		i++;
		j=0;
		printf("\n");
	}	
return 0;
}

