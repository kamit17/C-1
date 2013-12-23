/*
*	Finding out if a string has unique characters in it or not
*	1. If the string length is larger than 256 Characters, It cannot have
*	   unique characters
*	2. a. Compare every character with the rest of the characters
*		O(n^2)
*	OR
*
*	2. b. Compare every character with it's hashed value
*		O(n)
*
*/

#include<string.h>
#include<stdio.h>

int main(){

char *s;

s = "Pror";

//scanf("%s",s);

int length = strlen(s);
//printf("Length is %d",length);

if(length>256){
	printf("String Length larger than 256, can't have unique characters");
	return 1;
}

int i=0,j;

// 2. a. 

/*
while(i<length){
	j=i+1;
	while(j<length){
		if(s[i]==s[j]){
			printf("\nThe String doesn't have only unique Characters: \'%c\'",s[i]);
			return 1;
		}
		j++;
	}
	i++;
}
*/

// 2. b. 

int hash_array[256] = { 0 } ;

i = 0;

while(i<length){
	if(!hash_array[s[i]%256])
		hash_array[s[i]%256]=1;
	else {
		printf("\n (2.b) \nThe String doesn't have only unique Characters: %c",s[i]);
	return 1;
	}
	i++;
}
return 0;
}

