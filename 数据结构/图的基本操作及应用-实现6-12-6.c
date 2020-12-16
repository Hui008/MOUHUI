//�������ƣ�ͼ���ڽӱ�洢��ʵ��
//���뻷��:Dev-C++5.11
//���ߣ����ӻ�
//����޸�:2020-12-6

#include"stdio.h"
#include"stdlib.h"

//���ű���
#define MaxVertexNum 100//��󶥵�����Ϊ100

//�������Ͷ���
typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����
typedef int WeightType;
typedef char DataType;//����洢������������Ϊ�ַ���

//�ߵĶ���
typedef struct ENode *PtrToENode; 
struct ENode{
	Vertex V1,V2;//�����<V1,V2>
	WeightType Weight;//Ȩ�� 
}; 
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex Adjv;//�ڽӵ��±�
	WeightType Weight;//��Ȩ��
	PtrToAdjVNode Next;//ָ����һ���ڽӵ��ָ�� 
};  

//�����ͷ���Ķ���
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;//�߱�ͷָ��
	DataType Data;//�涥�������
	//ע�⣺�ܶ�����ģ����������ݣ���ʱData���Բ��ó��� 
}AdjList[MaxVertexNum];//AdjList���ڽӱ�����

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;//������
	int Ne;//����
	AdjList G;//�ڽӱ� 
}; 
typedef PtrToGNode LGraph;//���ڽӱ�ʽ�洢��ͼ����

//Search����
int Search(LGraph G,int e)
//��ͼG�в���ֵΪe�Ķ��㣬���ҵ����򷵻ظö����ڶ��������� ����-1
{
	int i;
	if(G->Nv<=0)
	  return -1;
	for(i=0;i<G->Nv&&e!=G->G[i].Data;i++);
	if(i>=G->Nv)
	  return -1;
	else
	  return i; 
 } 
 
//GreateGraph���� 
LGraph CreateGraph(int VertexNum)
{//��ʼ��һ����VertexNum�����㵫��û�бߵ�ͼ 
 	Vertex V;
	 LGraph Graph;
	 
	 Graph=(LGraph)malloc(sizeof(struct GNode));//����ͼ
	 Graph->Nv=VertexNum;
	 Graph->Ne=0;
	 //��ʼ���ڽӱ�ͷָ��
	 //ע�⣺����Ĭ�϶����Ŵ�0��ʼ����(Graph->Nv-1)
	 for(V=0;V<Graph->Nv;V++)
	    Graph->G[V].FirstEdge=NULL;
		
	return Graph; 
}

//InsertEdge����
void InsertEdge(LGraph Graph,Edge E)
{
	PtrToAdjVNode NewNode;
	int i,j;
	i=Search(Graph,E->V1);
	j=Search(Graph,E->V2);
	
	//�����<V1,V2>
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv=j;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[i].FirstEdge;
	Graph->G[i].FirstEdge=NewNode;
	
	//��������ͼ����Ҫ�����<V1,V2>
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv=i;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[i].FirstEdge;
	Graph->G[i].FirstEdge=NewNode;
	
	//��������ͼ����Ҫ�����<V2,V1>
	NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->Adjv=i;
	NewNode->Weight=E->Weight;
	NewNode->Next=Graph->G[j].FirstEdge;
	Graph->G[j].FirstEdge=NewNode; 
 } 
 
 //BuildGraph����
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv,i;
	
	printf("�����붥�������\n");
	scanf("%d",&Nv);//���붥�����
	Graph=CreateGraph(Nv);//��ʼ����Nv�������������û�бߵ�ͼ
	//������������ݵĻ�����������
	for(V=0;V<Graph->Nv;V++)
	{
		printf("�����%d����\n",V+1);
		scanf("%d",&(Graph->G[V].Data));
	 } 
	 printf("\n�����������\n");
	 scanf("%d",&(Graph->Ne));//�������
	 if(Graph->Ne!=0){//����б�
	   E=(Edge)malloc(sizeof(struct ENode));//������
	   //����ߣ���ʽΪ����� �յ� Ȩ�ء��������ڽӾ���
	   for(i=0;i<Graph->Ne;i++){
	   	printf("\n������߼�Ȩֵ��\n");
	   	scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
	   	//ע�⣺���Ȩ�ز������ͣ�Weight�Ķ����ʽҪ�� 
	   InsertEdge(Graph,E); 
	   } 
	 } 
	 return Graph;
 } 
 
 //PrintGraph����
void PrintGraph(LGraph G)
{
	int i;
	PtrToAdjVNode p;
	printf("/n����ڽӱ�\n");
	for(i=0;i<G->Nv;i++)
	{
		printf("%d:%d ",i,G->G[i].Data);
		p=G->G[i].FirstEdge;
		while(p)
		{
			printf("->%d",p->Adjv);
			p=p->Next;
		 } 
		 printf("\n");
	}
 } 
 
 //main����
 int main()
 {
 	LGraph G;
 	G=BuildGraph();
 	PrintGraph(G);
 	return 0;
  } 
