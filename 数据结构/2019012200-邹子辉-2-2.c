//�������ƣ����Ա����ʽ�洢��ʵ��
//���뻷����Dev-C++5.11
//���ߣ����ӻ�
//����޸ģ�2020-12-4
 
#include"stdio.h"
#include"stdlib.h"

//���ű���
#define ERROR NULL
#define MAXSIZE 100
#define true 1
#define false 0

//�������Ͷ��� 
typedef int ElementType;
typedef int bool;
typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode Next; 
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

//MakeEmpty����
List MakeEmpty() 
{//�����ձ��˴�Ϊ��ͷ���ĵ�����
  List L;
  L=(List)malloc(sizeof(struct LNode));
  L->Next=NULL;
  return L;
}

//Insert���������뺯����
List Insert(List L,ElementType X,int i)
{
	Position tmp,pre;
	int cnt=0;
	tmp=(Position)malloc(sizeof(struct LNode));
	tmp->Data=X;
	pre=L;
	while(pre&&cnt<i-1){
		pre=pre->Next;
		cnt++;
	}
	if(pre==NULL||cnt!=i-1){
		printf("����λ�ò�������\n");
		free(tmp);
		return ERROR;
	}
	else{
		tmp->Next=pre->Next;
		pre->Next=tmp;
		return L;
	}
} 
 
//Delete������ɾ��������
bool Delete(List L,int i)
 {
 	Position tmp,pre;
 	int cnt=0;
 	pre=L;//preָ���ͷ
	while(pre&&cnt<i-1){
		pre=pre->Next;
		cnt++;
	} 
	if(pre==NULL||cnt!=i-1||pre->Next==NULL){
		printf("ɾ��λ�ò�������\n");
		return false;
	}
	else{
		tmp=pre->Next;
		pre->Next=tmp->Next;
		free(tmp);
		return true;
	}
} 


//Print���������������
bool Print(List L)
{
  	PtrToLNode p;
  	p=L->Next;
  	while(p){
  		printf("%d\t",p->Data);
  		p=p->Next;
	  }
	  return true;
} 

//Length����
int Length(List L){
  	Position p;
  	int cnt=0;//��ʼ��������
	 p=L->Next;//pָ���ĵ�һ�����
	 while(p){
	 	p=p->Next;
	 	cnt++;//��ǰpָ��ĵ�cnt����� 
	 } 
	 return cnt; 
} 

//Find����
Position Find(List L,ElementType X)
{
	Position p=L;
	while(p&&p->Data!=X);
	p=p->Next;
	return p; 
}

//FindKth����
ElementType FindKth(List L,int K)
{
	Position p;
	int cnt=1;//λ���1��ʼ 
	p=L->Next;//pָ��L�ĵ�һ����� 
	while(p&&cnt<K){
		p=p->Next;
		cnt++;
	}
	if((cnt==K)&&p)
	 return p->Data;//�ҵ���K�� 
	else
	 return ERROR;//���򷵻ش�����Ϣ 
 } 
  
//main����
int main()
{
  	List L;
  	int i;
  	L=MakeEmpty();
  	for(i=1;i<=10;i++)
  	  Insert(L,i,i);
  	Delete(L,3);
  	Print(L);
  	//printf("\n%d�Ƿ��ҵ�\n",Find(L,4));
  	//Find(L,4);
	printf("\n���Ա�ı�Ϊ��%d\t",Length(L));
	printf("\nλ��Ϊ4������:%d",FindKth(L,4)); 
  	return 0;
  }
