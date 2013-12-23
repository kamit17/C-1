/*
* Reverse a string in place
* 
* What's special about this program?
*   It reverses the string with the characters in place
*   It doesn't use a string buffer
*     So, why is it better than using a string buffer?
*       It uses only a single extra character instead of a whole buffer
*           so if a string of 1000bytes is passed it would only need 1 extra byte. Space consumed for data = 1001bytes
*       If a buffer is used
*           a string of 1000bytes would need a 1000bytes character buffer. Space consumed for data = 2000bytes
*/

#include<stdio.h>
#include<string.h>

int swapC(char *s,int a,int b){
	char temp;
	temp = s[a];
	s[a] = s[b];
	s[b] = temp;
	//printf("\n%s",s);
return 1;
}

int reverseString(char *s){

int length;

length = strlen(s);

int counter_head=0,counter_tail=length-1;

while(counter_head<counter_tail){
	swapC(s,counter_head,counter_tail);
	counter_head++;
	counter_tail--;
	}
return 1;
}

int main(){

char s[100]= "Save the Tigers\nEspecially Siberians and Bengals";

printf("<Original String:> \n%s",s);

reverseString(s);

printf("\n<Reversed:> \n%s",s);

reverseString(s);

printf("\n<Reversed again (should match original string):> \n%s",s);

return 0;

}
