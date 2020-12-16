//�������ƣ����Ա��˳��洢��ʵ��
//���뻷����Dev-c++5.11
//���ߣ����ӻ�
//����޸ģ�2020-11-30

#include"stdio.h"
#include"stdlib.h"

//���ű���
#define ERROR -1
#define MAXSIZE 100
#define true 1
#define false 0

//�������Ͷ���
typedef int bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
}; 

//MakeEmpty����
List MakeEmpty()
{
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Last=-1;
	
	return L;
 } 
 
 //Find����
 Position Find(List L,ElementType X)
 {
 	Position i=0;
 	
 	while(i<=L->Last&&L->Data[i]!=X)
 	   i++;
 	if(i>L->Last)
 	   return ERROR;//���û�ҵ������ش�����Ϣ 
	else
	    return i;//�ҵ�֮�󷵻ص��Ǵ洢λ�� 
  } 
  
bool Insert(List L,ElementType X,int i)
{
	Position j;
	if(L->Last==MAXSIZE-1){
		printf("����");
		return false;
	}
	if(i<1||i>L->Last+2){
		printf("λ�򲻺Ϸ�");
		return false;
	}
	for(j=L->Last;j>=i-1;j--)
	L->Data[j+1]=L->Data[j];
	L->Data[i-1]=X;
	L->Last++;
	return true; 
}

//Delete���� 
bool Delete(List L,int i)
{
	Position j;
	if(i<1||i>L->Last+1){
		printf("λ��%d������Ԫ��",i);
		return false;
	}
	for(j=i;j<=L->Last;j++)
	L->Data[j-1]=L->Data[j];
	L->Last--;
	return true; 
}
 
 //Print����
bool Print(List L)
{
	int i;
	for(i=0;i<=L->Last;i++)
	printf("%d\t",L->Data[i]);
	return true;
}
  //Length����
   int Length(List L)
  {
  	return L->Last+1; 
   } 
   
  //FindKth����
  int FindKth(List L,ElementType K)
  {
  	L->Data [K-1]; 
   } */
  //main����
int main()
{
	List L;
	int i;
	L=MakeEmpty();
	for(i=1;i<=10;i++)
    	Insert(L,i,i);
	Delete(L,3);
	Insert(L,100,10);
	Print(L);
	return 0;
}
