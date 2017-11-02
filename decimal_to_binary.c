#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void test()
{
	int n = 0;
	char bin_str[64] = {}; 
	//char * bin_str = (char *)malloc(64);
	printf("please input a int number:");
	scanf("%d",&n);
	int q = n/2;
	int r = n%2;
	printf("q=%d,r=%d\n",q,r);
	sprintf(bin_str,"%s%d",bin_str,r); //attenion !
	while(q!=0){
		r = q%2;//attention sequence of r , q
		q = q/2;
		printf("q=%d,r=%d\n",q,r);
		sprintf(bin_str,"%s%d",bin_str,r);
	}
	printf("%s\n",bin_str);
	int len = strlen(bin_str);
	char buf[64] = {};
	for(int i=0;i<len;i++){
		sprintf(buf,"%s%c",buf,bin_str[len-1-i]);
	}
	printf("%d to binary is : %s\n",n,buf);
}

void sprintf_test()
{
	char a[64] = {};
	int n = 1231;
	sprintf(a,"%d",n);
	printf("%s\n",a); 
}
int main(){
	test();
	//sprintf_test();
	return 0;
}
