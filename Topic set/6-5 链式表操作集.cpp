Position Find( List L, ElementType X )
{
    List p=L;
    while(p!=NULL&&(p->Data!=X))
    {
        p=p->Next;
    }
    //return p;
    if ( p )
        return p;
    else
        return ERROR;
}

/*
将X插入在位置P指向的结点之前，
返回链表的表头。
如果参数P指向非法位置，
则打印“Wrong Position for Insertion”，返回ERROR；
*/
List Insert( List L, ElementType X, Position P )
{
    List tmp;
    List pre;
    //1先考虑特殊情况：P插入在表头，没有前面的节点，直接申请填装
    if(P==L)
    {
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        return tmp;
    }
    //2查找P-1个节点，如果不存在就无法插入，存在就可以插入
     /* 查找P的前一个结点 */
    for ( pre=L; pre&&pre->Next!=P; pre=pre->Next ) ;

    if ( pre==NULL )
    { /* P所指的结点不在L中 */
        printf("Wrong Position for Insertion\n");
        return ERROR;
    }
    //3存在P-1个节点，申请、填装节点
    //4将新节点装在P-1个节点后面
    else /* 找到了P的前一个结点pre */
    {
        /* 在P前插入新结点 */
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return L;
    }
}

/*
将位置P的元素删除并返回链表的表头。
若参数P指向非法位置，
则打印“Wrong Position for Deletion”并返回ERROR。
*/
List Delete( List L, Position P )
{
    List removeP,temP;
    /********如果删除的是头的话*********/
    if(P==L)
    {
        removeP=L;
        if(L!=NULL)
        {
            L=L->Next;
        }
        //释放空间
        free(removeP);
        return L;
    }

    /********删除第P个节点*********/
    //1先找到P-1个节点,用temP指向
    for ( temP=L; temP&&temP->Next!=P; temP=temP->Next ) ;
    if(temP==NULL)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }
    if(temP->Next==NULL)
    {
        printf("Wrong Position for Deletion\n");
        return ERROR;
    }

    //2将要删除的P给removeP
    removeP=temP->Next;
    //3将temP的next赋值"为"remoP的next
    temP->Next=removeP->Next;
    //4释放removeP的空间
    free(removeP);
    //5返回L
    return L;
}
