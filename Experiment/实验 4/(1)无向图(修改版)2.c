#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;

typedef struct GNode * PtrToGNode;

struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode * PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

MGraph CreateGraph(int VertexNum);
void InsertEdge(MGraph Graph,Edge E);
MGraph BuildGraph();
int showdegree(MGraph Graph,int n);


int main()
{
    MGraph Graph=BuildGraph();
    int i,j;
    printf("\n");
    for(i=0;i<Graph->Nv;i++)
    {
        for(j=0;j<Graph->Nv;j++)
        {
            printf("%d ",Graph->G[i][j]);
        }
        printf("\n");
    }
    int n;
    printf("请输入你想知道的顶点的度\n");
    scanf("%d",&n);
    printf("这个顶点的度是 %d \n",showdegree(Graph,n));


    return 0;
}

MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;

    Graph=(MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(V=0;V<Graph->Nv;V++)
    {
        for(W=0;W<Graph->Nv;W++)
        {
            Graph->G[V][W]=0;
        }
    }
    return Graph;
}


int showdegree(MGraph Graph,int n)
{
    int i,num=0;
    for(i=0;i<Graph->Nv;i++)
    {
        if(Graph->G[i][n]!=0)
        {
            num++;
        }
    }
    return num;
}

void InsertEdge(MGraph Graph,Edge E)
{
    Graph->G[E->V1][E->V2]=E->Weight;
    Graph->G[E->V2][E->V1]=E->Weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    printf("请输入顶点个数：\n");
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    printf("请输入边数：\n");
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0)
    {
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++)
        {
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }


    }


    return Graph;
}




