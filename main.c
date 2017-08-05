#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE 2000;

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} BiTree;

typedef int DataType;


//创造空树
void InitBiTree(BiTree* root);

//销二叉毁树
void DestroyBiTree(BiTree* root);

//构造二叉树
void CreatBiTree(BiTree* root, DataType* data, int len);

//清空二叉树
void ClearBiTree(BiTree* root);

//判断空树
int BiTreeEmpty(BiTree* root);

//二叉树深度
int BiTreeDepth(BiTree* root);

//返回二叉树的根
BiTree* Root(BiTree* root);

//返回e的双亲节点
BiTree* Parent(BiTree* root, BiTree* e);

//返回e的左孩子节点
BiTree* LeftChild(BiTree* root, BiTree* e);

//返回e的右孩子节点
BiTree* RightChild(BiTree* root, BiTree* e);

//返回e的左兄弟节点
BiTree* LeftSibling(BiTree* root, BiTree* e);

//返回e的右兄弟节点
BiTree* RightSibling(BiTree* root, BiTree* e);

//前序遍历
void PreOrderTravers(BiTree* root);

//中序遍历
void InOrderTravers(BiTree* root);

//后序遍历
void PostOrderTravers(BiTree* root);

//层次遍历
void LevelOrderTravers(BiTree* root);

int main() {

    return 0;
}

//创造空树
void InitBiTree(BiTree* root)
{
    root = NULL;
}

//销二叉毁树
void DestroyBiTree(BiTree* root)
{
    if (root == NULL)
        return;

    DestroyBiTree(root->left);
    DestroyBiTree(root->right);

    free(root);
    root = NULL;
}

//构造二叉树
void CreatBiTree(BiTree* root, DataType* data, int len)
{
    BiTree *p = NULL, *queue[len];
    int front = 1, rear = 0;

    for (int i = 0; i < len; i++)
    {
        p = (BiTree*)malloc(sizeof(BiTree));
        p->data = data[i];
        p->right = p->left = NULL;

        rear++;
        queue[rear] = p;

        if (front == 1)
            root = p;
        else
        {
            if (queue[front] != NULL)
            {
                if (rear%2 == 0)
                    queue[front]->left = p;
                else
                    queue[front]->right = p;
            }

        }
        if (rear%2 == 1)
            front++;
    }

}

//清空二叉树
void ClearBiTree(BiTree* root)
{
    if (root == NULL)
        return;

    ClearBiTree(root->left);
    ClearBiTree(root->right);

    free(root);
}

//判断空树
int BiTreeEmpty(BiTree* root)
{
    if (root == NULL)
        return 1;
    else
        return 0;
}

//二叉树深度
int BiTreeDepth(BiTree* root)
{
    if (!root)
        return 0;

    return
            BiTreeDepth(root->left) > BiTreeDepth(root->right) ?
            (BiTreeDepth(root->left)+1) : (BiTreeDepth(root->right)+1);
}

//返回二叉树的根
BiTree* Root(BiTree* root)
{
    return root;
}

//返回e的双亲节点
BiTree* Parent(BiTree* root, BiTree* e)
{
    BiTree* p;

    if (e == NULL || root == NULL || root == e)
        return NULL;

    if (root->right == e || root->left == e)
        return root;

    p = Parent(root->left,e);
    if (p != NULL)
        return p;

    p = Parent(root->right,e);
    if (p != NULL)
        return p;

    return NULL;
}

//返回e的左孩子节点
BiTree* LeftChild(BiTree* root, BiTree* e)
{
    return e->left;
}

//返回e的右孩子节点
BiTree* RightChild(BiTree* root, BiTree* e)
{
    return e->right;
}

//返回e的左兄弟节点
BiTree* LeftSibling(BiTree* root, BiTree* e)
{
    BiTree* p;

    if (e == root)
        return NULL;

    if (root->right == e)
        return root->left;

    p = LeftSibling(root->left, e);
    if (p != NULL && p->left != NULL)
        return p;

    p = LeftSibling(root->right, e);
    if (p != NULL && p->left != NULL)
        return p;

    return NULL;
}

//返回e的右兄弟节点
BiTree* RightSibling(BiTree* root, BiTree* e)
{
    BiTree* p;

    if (e == root)
        return NULL;

    if (root->right == e)
        return root->right;

    p = LeftSibling(root->left, e);
    if (p != NULL && p->right != NULL)
        return p;

    p = LeftSibling(root->right, e);
    if (p != NULL && p->right != NULL)
        return p;

    return NULL;
}

//前序遍历
void PreOrderTravers(BiTree* root)
{
    if (root)
    {
        printf("%g  ",root->data);    //模拟访问函数

        PreOrderTravers(root->left);

        PreOrderTravers(root->right);
    }
}

//中序遍历
void InOrderTravers(BiTree* root)
{
    if (root)
    {
        InOrderTravers(root->left);

        printf("%g  ",root->data);    //模拟访问函数

        InOrderTravers(root->right);
    }
}

//后序遍历
void PostOrderTravers(BiTree* root)
{
    if (root)
    {
        PreOrderTravers(root->left);

        PreOrderTravers(root->right);

        printf("%g  ",root->data);    //模拟访问函数
    }
}

//层次遍历
void LevelOrderTravers(BiTree* root)
{
     typedef struct queue{
         BiTree* node[MAX_QUEUE];
         int front;
         int rear;
     } BinQue;

    BinQue que;
    BiTree* temp;

    que.front = que.rear = 0;

    if (root)
    {
        //enter queue
        if (que.rear == MAX_QUEUE)
            printf("the queue is full\n");
        else
        {
            que.node[que.rear] = *root;
            que.rear++;
        }


        while(que.front != que.rear)
        {
            //out queue
            if (que.front == que.rear)
                root == NULL;
            else
            {
                *root = que.node[que.front];
                que.front ++;
            }

            printf("%g  ",root->data);    //模拟访问函数

            if (root->left)
            {
                //enter queue
                if (que.rear == MAX_QUEUE)
                printf("the queue is full\n");
                else
                {
                    que.node[que.rear] = *root->left;
                    que.rear++;
                }
            }

            if (root->right)
            {
                //enter queue
                if (que.rear == MAX_QUEUE)
                printf("the queue is full\n");
                else
                {
                    que.node[que.rear] = *root->right;
                    que.rear++;
                }
            }
        }
    }
    return;
}