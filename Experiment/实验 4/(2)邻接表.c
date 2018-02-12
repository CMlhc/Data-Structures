#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef int DataType;


typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Wight;
    PtrToAdjVNode Next;

};

typedef struct Vnode{
    PtrToAdjVNode FirstEdge;
    //DataType Data;
}AdjList[MaxVertexNum];


typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;



typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;

LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;

    Graph=(LGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(V=0;V<Graph->Nv;V++)
    {
        Graph->G[V].FirstEdge=NULL;
    }

    return Graph;
}

void InsertEdge(LGraph Graph,Edge E)
{
    PtrToAdjVNode NewNode;

    NewNode=(PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV=E->V2;
    NewNode->Wight=E->Weight;

    NewNode->Next=Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge=NewNode;

}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    printf("请输入顶点个数：\n");
    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);

    printf("请输入边的个数：\n");
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

int main()
{
    LGraph Graph=BuildGraph();
    int i;
    printf("\n");
    for(i=0;i<Graph->Nv;i++)
    {
        PtrToAdjVNode point;
        point=Graph->G[i].FirstEdge;
        printf("%d :",i);
        while(point!=NULL)
        {

            printf(" -->  %d  ",point->AdjV);
            point=point->Next;

        }
        printf("\n");
    }



    return 0;
}






