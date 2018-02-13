List MakeEmpty()//：创建并返回一个空的线性表；
{List a=(List)malloc(sizeof(struct LNode));
a->Data=0;a->Next=NULL;
return a;
}
Position Find( List L, ElementType X )//：返回线性表中X的位置。若找不到则返回ERROR；
{List F=L;
while(F){
    if(F->Data==X)break;
    F=F->Next;
}
return F;

}
bool Insert( List L, ElementType X, Position P )//：将X插入在位置P指向的结点之前，返回true。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回false；
{   List F=L;
while(F->Next){
    if(F->Next==P)break;
    F=F->Next;
}if(F->Next!=P){printf("Wrong Position for Insertion\n");
return false;
}F->Next=(List)malloc(sizeof(struct LNode));
F->Next->Data=X;
F->Next->Next=P;
return true;
}
bool Delete( List L, Position P )//：将位置P的元素删除并返回true。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回false。
{List F=L;
if(!P){
    printf("Wrong Position for Deletion\n");
return false;
}

while(F->Next){
    if(F->Next==P)break;
    F=F->Next;
}if(F->Next!=P){
    printf("Wrong Position for Deletion\n");
return false;
}F->Next=P->Next;
return true;
}
