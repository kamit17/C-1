/*
*	Assume the matrix is n x n (square matrix)
*/

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

	int temp_buffer;	

	// Rotate the Matrix
	while(i < rows/2){
		j=i;
		while(j < columns-i-1){
			temp_buffer = m1[complement(j,rows)][i];
			m1[complement(j,rows)][i] = m1[complement(i,rows)][complement(j,rows)];
			m1[complement(i,rows)][complement(j,rows)]=m1[j][complement(i,rows)];
			m1[j][complement(i,rows)]=m1[i][j];
			m1[i][j]=temp_buffer;	

			j++;
		}
		i++;
	}
	
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

