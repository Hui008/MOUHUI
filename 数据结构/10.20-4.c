#include"stdio.h"
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h> 
int main()
{
	int a,b,i,n;
	long long temp,f1,f2;
	while(n--)
	{
	    scanf("%d%d",&a,&b);
		f1=0;
		f2=1;
		for(i=0;i<b-a;i++)
		{
			temp=f1+f2;
			f1=f2;
			f2=temp;
			}	
			printf("%lld",f2);
			
	}
	return 0;
 } 
