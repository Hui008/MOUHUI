//程序名称：对战的顺序存储及实现
//编译环境：Dev-c++5.11
//作者：邹子辉
//最后修改：2020-12-11

#include"stdio.h"
#include"stdlib.h"

#define false 0
#define true 1
#define ERROR '#'

typedef char ElementType;
typedef int bool;
typedef int Position;
struct SNode{
	ElementType *Data;//存储元素的数组
	Position Top;//栈顶指针 
	int MaxSize;//堆栈最大容量 
}; 
typedef struct SNode *Stack; 

//CreateStack函数（建立空栈）
Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType *)malloc(MaxSize *sizeof(ElementType));
	S->Top=-1;
	S->MaxSize=MaxSize;
	return S; 
}

//IsFull函数
bool IsFull(Stack S)
{
	return(S->Top==S->MaxSize-1);
 } 
//Push函数
bool Push(Stack S,ElementType X)
{
	if(IsFull(S)){
		printf("堆栈满");
		return false; 
	}
	else{
		S->Data[++(S->Top)]=X;
		return true;
	}
 } 

//IsEmpty函数
bool IsEmpty(Stack S)
{
	return(S->Top==-1);
 } 

//Pop函数
ElementType Pop(Stack S)
{
	if(IsEmpty(S)){
		printf("堆栈满");
		return ERROR; 
	}
	else 
	 return(S->Data[(S->Top)--]);
 } 

//GetTop函数
ElementType GetTop(Stack S) 
{
	if(IsEmpty(S)){
		printf("堆栈空");
		return false;
	}
	else 
	 return (S->Data[S->Top]);
}
//StackLength函数
int StackLength(Stack S)
{
	return (S->Top+1);
}
 
//main函数
int main()
{
	Stack S;
	char x;
	S=CreateStack(10);
	Push(S,'1');
	Push(S,'2');
	Push(S,'3');
	printf("栈顶指针是：%c\n",GetTop(S));
	printf("堆栈长度是：%d\n",StackLength(S));
	while(!IsEmpty(S))
	{
		x=Pop(S);
		printf("%c\n",x);
	}
	return 0;
 } 
