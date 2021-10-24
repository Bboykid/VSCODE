#define Elemtype char

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void Visit(BiTree T);


/**
 * @brief 遍历
 * 
 */

void PreOrder(BiTree root)
{
    if(root!=NULL) {
        Visit(root);
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

void InOrder(BiTree root)
{
    
}

/**
 * @brief 非递归遍历
 * 
 */

//
void InOrder_2(BiTree root)
{
    BiTree p = root;
    InitStack(S);

    while(p!=NULL || !S.isEmpty() )
    {
        if(p)
        {
            S.push(p);
            p = p->lchild;
        }
        else
        {
            p = S.pop();
            Visit(p);
            p=p->rchild
        }
    }
}

// 先序遍历
void PreOrder2(BiTree root)
{
    BiTree p = T;
    InitStack(S);

    while( p || !S.isEmpty() )
    {
        if(p)
        {
            Visit(p);
            S.push(p);
            p=p->lchild
        }
        else
        {
            p = S.pop();
            p = p->rchild;
        }
    }
}





/**
 * @brief 层次遍历
 * 
 */

void LevelOrder(BiTree root)
{
    Queue Q;
    BiTree p;
    Q.in(root);

    while(!Q.isEmpty())
    {
        p = Q.pop();
        Visit(p);
        if(p->lchild) Q.in(p->lchild);
        if(p->rchild) Q.in(p->rchild);
    }

}



// T6
BiTree getTree(int pre[],int in[],int pre_start,int pre_end,int in_start,int in_end)
{
    BiTNode t = (BiTNode *)malloc(sizeof(BiTNode));
    t->data = pre[pre_start];

    int index;
    for(index = pre_start;index<=pre_end;index++)
    {
        if(in[index]==pre[pre_start]) break;
    }
    int l_len = index-in_start;
    int r_len = in_end - index;

    if(l_len>0)
    {
        t->lchild = getTree(pre,in,pre_start+1,pre_start+l_len,in_start,in_start+l_len-1);
    }
    else
        t->lchild = NULL;
    if(r_len>0)
    {
        t->rchild = getTree(pre,in,pre_start+l_len+1,pre_end,index+1,in_end);
    }
    else
        t->rchild = NULL;


    return t;

}