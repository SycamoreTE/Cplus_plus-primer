#include <stdio.h>

int main(){
	printf("please enter A and B\n");
	int a, b;
	scanf("%d %d",&a,&b);
	if(a < -1000000000 || a > 1000000000){
		printf("A is invalid, please enter again\n");
		scanf("%d", &a);
	}
	if(b < -1000000000 || b > 1000000000){
		printf("B is invalid, please enter again\n");
		scanf("%d", &b);
	}
	printf("\n%d", a+b);
	return a+b;
}