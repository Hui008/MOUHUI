#include"stdio.h"
int main()
{
	int num=0;
	int a=0;
	int i;
	printf("������һ��������");
	scanf("%d",&num);
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			a++;
		}
	 } 
	 if(a==0)
	 printf("%d������",num);
	 else
	 {
	 printf("%d��������",num);}
	 return 0;
 } 
