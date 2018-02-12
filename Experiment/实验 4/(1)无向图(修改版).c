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
void showdegree(MGraph Graph);


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
    showdegree(Graph);

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


void showdegree(MGraph Graph)
{
    printf("这个无图的度是：\n");
    printf("%d",Graph->Ne*2);
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




