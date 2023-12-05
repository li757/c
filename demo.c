#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    struct node *lchild, *rchild;  
    char data;
} BTNode;
//根据中序遍历和先序遍历创建二叉树
BTNode* CreateBTree(char *pre, char *in, int n)
{
    int k;
    char *p;
    if (n <= 0)
        return NULL;
    BTNode *b = (BTNode*)malloc(sizeof(BTNode));
    b->data = *pre;  //根结点赋值
    for (p = in; p < in + n; ++p)  //查找子树根节点
        if (*p == *pre)
            break;
    k = p-in;
    b->lchild = CreateBTree(pre+1, in, k);  //递归调用
    b->rchild = CreateBTree(pre+k+1, p+1, n-k-1);
    return b;
}

int GetHeight(BTNode* BT)
{
    int HL,HR,MaxH;
    if(BT)
    {
        HL = GetHeight(BT->lchild);
        HR = GetHeight(BT->rchild);
        MaxH = HL > HR ? HL:HR;  //比较左右子树高度
        return (MaxH + 1);
    }
    else  return 0;
}

int main()
{
    BTNode* b;
    int h,n;
    scanf("%d",&n);
    char pre[n];
    char in[n];
    scanf("%s",pre);
    scanf("%s",in);

    b = CreateBTree(pre, in, n);
    h = GetHeight(b);
    printf("%d",h);
    return 0;
}

