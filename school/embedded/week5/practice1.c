#include <stdio.h>
void main(){
	int sum,i;
	sum=0;
	i=0;
	__asm__(
		"loop:\n\t"
		"	ADD %[i],%[i],#1\n\t"
        "	ADD %[sum],%[sum],%[i]\n\t"
		"	CMP %[i],#100\n\t"
		"	BLE loop\n\t"
        :[sum]"+r"(sum)
		:[i]"r"(i)
        );
	printf("summation 1 to 100 is %d\n",sum);
}	
