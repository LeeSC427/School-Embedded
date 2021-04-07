#include <stdio.h>

int * intoneplus(int * i);
char * charoneplus(char * c);

int my_strcmp(const char *src1, const char *src2);
void my_strcpy(const char *src, char *dst);
int main(void)

{
	const char *a = "Hello world!";
	const char *a1 = "Hello world!";
	const char *a2 = "hello aorld!";
	
	if(my_strcmp(a, a1)==0)
		printf("a and a1 are same sentence\n");
	else
		printf("a and a1 are different\n");

	if(my_strcmp(a, a2)==0)
		printf("a and a2 are same sentence\n");
	else
		printf("a and a2 are different\n");
	
	return 0;

}

int my_strcmp(const char *src1, const char *src2)
{
	int ch1, ch2, ret=0;
	__asm__ (
		"loop:\n\t"
				//ch1,ch2 에 src1, src2 첫 문자를 로드
		"	LDRB %[ch1],[%[src1]]\n\t"
		"	ADD %[src1],%[src1],#1\n\t"
		"	LDRB %[ch2],[%[src2]]\n\t"
		"	ADD %[src2],%[src2],#1\n\t"
				//ch1,ch2를 비교
		"	CMP %[ch1],%[ch2]\n\t"
				//같지 않으면 ret=1, 종료(done 라벨)
		"	MOVNE %[ret],#1\n\t"
		"	BNE done\n\t"
				//ch1이 NULL문자(#0)를 만나지 않은 경우에는 loop
		"	CMP %[ch1],#0\n\t"
		"	BNE loop\n\t"
		"	BEQ done\n\t"
				//ch1이 NULL문자(#0)를 만난 경우에 종료
		"done:\n\t"
		//"	ADD %[ret],%[ret],#1\n\t" //항상 실행된다?
			:	[ret]"+r"(ret)
				/* fill this area */	
			:	[ch1]"r"(ch1),
				[src1]"r"(src1),
				[ch2]"r"(ch2),
				[src2]"r"(src2)
	);
	return ret;
}
