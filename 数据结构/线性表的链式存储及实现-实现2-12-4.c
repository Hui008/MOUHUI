//程序名称：线性表的链式存储及实现
//编译环境：Dev-C++5.11
//作者：邹子辉
//最后修改：2020-12-4
 
#include"stdio.h"
#include"stdlib.h"

//符号变量
#define ERROR NULL
#define MAXSIZE 100
#define true 1
#define false 0

//数据类型定义 
typedef int ElementType;
typedef int bool;
typedef struct LNode *PtrToLNode;
struct LNode{
	ElementType Data;
	PtrToLNode Next; 
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

//MakeEmepty函数
//创建空表（此处为带头结点的单链表）
List MakeEmpty()
{
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Next=NULL;
	return L;
 } 
 
 //Insert函数
 //插入
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
		printf("插入位置参数错误\n");
		free(tmp);
		return ERROR;
	}
	else{
		tmp->Next=pre->Next;
		pre->Next=tmp;
		return L; 
	}
  } 
  
//Delete函数
//删除
bool Delete(List L,int i)
{
	Position tmp,pre;
	int cnt=0;
	pre=L;//pre指向表头
	while(pre&&cnt<i-1){
		pre=pre->Next;
		cnt++;
	} 
	if(pre==NULL||cnt!=i-1||pre->Next==NULL){
		printf("删除位置参数错误\n");
		return false;
	}
	else{
		tmp=pre->Next;
		pre->Next=tmp->Next;
		free(tmp);
		return true;
	}
 } 
 
 //Print函数
 //输出
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
  
//Length函数
int Length(List L)
{
	Position p;
	int cnt=0;//初始化计数器 
	p=L;//p指向表的第一个结点 
	while(p){
		p=p->Next;
		cnt++;//当前p指向的是第cnt个结点 
	}
	return cnt;
 } 
 
 //Find函数
 Position Find(List L,ElementType X)
 {
 	Position p=L;//p指向L的第一个结点
	while(p&&p->Data!=X)
	p=p->Next;
	return p; 
  } 
  
//FindKth函数
ElementType FindKth(List L,int K)
{
	//根据指定位序K，返回L中相应元素
	Position p;
	int cnt=1;//位序从1开始 
	p=L;//p指向L的第1个结点
	while(p&&cnt<K){
		p=p->Next;
		cnt++;
	} 
	if((cnt==K)&&p)
	  return p->Data;//找到第K个
	else
	  return -1;//返回错误信息 
	     
}
//main函数
  int main()
  {
  	List L;
  	int i;
  	L=MakeEmpty();
  	for(i=1;i<=10;i++)
  	   Insert(L,i,i);
  	Delete(L,3);
  	Print(L);
  	return 0;
} 
 
 
