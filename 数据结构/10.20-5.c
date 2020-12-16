#include"stdio.h"
int main()
{
	int num=0;
	int a=0;
	int i;
	printf("请输入一个整数；");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			a++;
		}
	 } 
	 if(a==0)
	 printf("%d是素数",num);
	 else
	 {
	 printf("%d不是素数",num);}
	 return 0;
 } 
