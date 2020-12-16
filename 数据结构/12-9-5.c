//程序名称：线性表的顺序存储及实现
//编译环境：Dev-c++5.11
//作者：邹子辉
//最后修改：2020-11-30

#include"stdio.h"
#include"stdlib.h"

//符号变量
#define ERROR -1
#define MAXSIZE 100
#define true 1
#define false 0

//数据类型定义
typedef int bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode{
	ElementType Data[MAXSIZE];
	Position Last;
}; 

//MakeEmpty函数
List MakeEmpty()
{
	List L;
	L=(List)malloc(sizeof(struct LNode));
	L->Last=-1;
	
	return L;
 } 
 
 //Find函数
 Position Find(List L,ElementType X)
 {
 	Position i=0;
 	
 	while(i<=L->Last&&L->Data[i]!=X)
 	   i++;
 	if(i>L->Last)
 	   return ERROR;//如果没找到，返回错误信息 
	else
	    return i;//找到之后返回的是存储位置 
  } 
  
bool Insert(List L,ElementType X,int i)
{
	Position j;
	if(L->Last==MAXSIZE-1){
		printf("表满");
		return false;
	}
	if(i<1||i>L->Last+2){
		printf("位序不合法");
		return false;
	}
	for(j=L->Last;j>=i-1;j--)
	L->Data[j+1]=L->Data[j];
	L->Data[i-1]=X;
	L->Last++;
	return true; 
}

//Delete函数 
bool Delete(List L,int i)
{
	Position j;
	if(i<1||i>L->Last+1){
		printf("位序%d不存在元素",i);
		return false;
	}
	for(j=i;j<=L->Last;j++)
	L->Data[j-1]=L->Data[j];
	L->Last--;
	return true; 
}
 
 //Print函数
bool Print(List L)
{
	int i;
	for(i=0;i<=L->Last;i++)
	printf("%d\t",L->Data[i]);
	return true;
}
  //Length函数
   int Length(List L)
  {
  	return L->Last+1; 
   } 
   
  //FindKth函数
  int FindKth(List L,ElementType K)
  {
  	L->Data [K-1]; 
   } */
  //main函数
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
