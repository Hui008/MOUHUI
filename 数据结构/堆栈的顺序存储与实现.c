//�������ƣ���ս��˳��洢��ʵ��
//���뻷����Dev-c++5.11
//���ߣ����ӻ�
//����޸ģ�2020-12-11

#include"stdio.h"
#include"stdlib.h"

#define false 0
#define true 1
#define ERROR '#'

typedef char ElementType;
typedef int bool;
typedef int Position;
struct SNode{
	ElementType *Data;//�洢Ԫ�ص�����
	Position Top;//ջ��ָ�� 
	int MaxSize;//��ջ������� 
}; 
typedef struct SNode *Stack; 

//CreateStack������������ջ��
Stack CreateStack(int MaxSize)
{
	Stack S=(Stack)malloc(sizeof(struct SNode));
	S->Data=(ElementType *)malloc(MaxSize *sizeof(ElementType));
	S->Top=-1;
	S->MaxSize=MaxSize;
	return S; 
}

//IsFull����
bool IsFull(Stack S)
{
	return(S->Top==S->MaxSize-1);
 } 
//Push����
bool Push(Stack S,ElementType X)
{
	if(IsFull(S)){
		printf("��ջ��");
		return false; 
	}
	else{
		S->Data[++(S->Top)]=X;
		return true;
	}
 } 

//IsEmpty����
bool IsEmpty(Stack S)
{
	return(S->Top==-1);
 } 

//Pop����
ElementType Pop(Stack S)
{
	if(IsEmpty(S)){
		printf("��ջ��");
		return ERROR; 
	}
	else 
	 return(S->Data[(S->Top)--]);
 } 

//GetTop����
ElementType GetTop(Stack S) 
{
	if(IsEmpty(S)){
		printf("��ջ��");
		return false;
	}
	else 
	 return (S->Data[S->Top]);
}
//StackLength����
int StackLength(Stack S)
{
	return (S->Top+1);
}
 
//main����
int main()
{
	Stack S;
	char x;
	S=CreateStack(10);
	Push(S,'1');
	Push(S,'2');
	Push(S,'3');
	printf("ջ��ָ���ǣ�%c\n",GetTop(S));
	printf("��ջ�����ǣ�%d\n",StackLength(S));
	while(!IsEmpty(S))
	{
		x=Pop(S);
		printf("%c\n",x);
	}
	return 0;
 } 
