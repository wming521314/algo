#include <stdio.h>

int main(){
	int s = 0;
	printf("please input second num:");
	scanf("%d",&s);
	int second = s%60; 
	//printf("      : %d\r",second);
	int minute = (s/60)%60;
	//printf("  : %d\r",minute);
	int hour = s/3600;
	//printf("%d\n",hour);
	printf("%d : %d : %d\n",hour,minute,second);
}
