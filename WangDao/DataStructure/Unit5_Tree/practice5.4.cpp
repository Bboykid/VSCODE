#define Elemtype int

//5
/**
 * @brief 求孩子森林表示法存储的森林的叶子结点数
 * 
 * 解法：孩子森林表示法中叶子结点的特征：fistchild指针为空
 *  遍历，找到所有左指针为空的节点
 * 
 */
typedef struct CSNode{
    Elemtype data;
    struct CSNode *firstchild,*nextsibling;
} CSNode,*CSTree;
//递归
int GetLeavesNum2(CSTree T)
{
    if( T==NULL )
        return 0;
    else
    {
        if(T->firstchild==NULL)
            return GetLeavesNum2(T->nextsibling) + 1;
        else
            return GetLeavesNum2(T->firstchild) + GetLeavesNum2(T->nextsibling);
    }
}

//6
/**
 * @brief 设计递归算法求树的深度（孩子兄弟链表）
 * 解法：
 */
int GetCSTreeDeep(CSTree T)
{
    if( T==NULL )
        return 0;
    else
    {
        int ldeep,rdeep;
        ldeep = GetCSTreeDeep(T->firstchild) + 1;
        rdeep = GetCSTreeDeep(T->nextsibling);
        if( ldeep > rdeep )
            return ldeep;
        else
            return rdeep;
    }

}

//7
/**
 * @brief 已知一颗树的层次序列和每个结点的度，编写算法构造此树的孩子-兄弟链表 
 * 
 */
#define maxNodes 15
void CreateCSTree_Degree(CSTree &T,Elemtype e[],int degree[],int n)
{
    //n为结点个数
    CSNode *pointer = new CSNode[maxNodes];
    int i,j,d,k=0;
    for(i = 0 ; i<n;i++)//初始化
    {
        pointer[i]->data = e[i];
        pointer[i]->lchild = pointer[i]->nextsib = NULL;
    }
    for(i=0; i<n; i++)
    {
        d = degree[i];
        if(d)//有孩子
        {
            k++;//k为孩子节点的序号
            pointer[i]->lchild = pointer[k];
            fo(j=2 ; i<=d ; j++)
            {
                k++;
                pointer[k-1]->nextsib = pointer[k];
            }
        }
    }
    T = pointer[0];
    delete []pointer;

}