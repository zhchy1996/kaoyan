#include "head.c"

typedef struct TNode
{
  ElemType data;
  struct TNode *lChild, *rChild;
} TNode, *Tree;

void CreateTree(Tree *T)
{
  ElemType ch;
  scanf("\n%c", &ch);
  if (ch == '#')
  {
    *T = NULL;
  }
  else
  {
    *T = (Tree)malloc(sizeof(TNode));
    if (!T)
      exit(1);
    (*T)->data = ch;
    CreateTree(&(*T)->lChild);
    CreateTree(&(*T)->rChild);
  }
}

// 复制二叉树
void copyBTree(Tree A, Tree *B)
{
  if (A == NULL)
  {
    *B = NULL;
    return;
  }
  *B = (Tree)malloc(sizeof(TNode));
  (*B)->data = A->data;
  copyBTree(A->lChild, &(*B)->lChild);
  copyBTree(A->rChild, &(*B)->rChild);
}

Status Front(Tree T)
{
  if (T == NULL)
    return OK;
  printf("%c", T->data);
  Front(T->lChild);
  Front(T->rChild);
  printf("\n");
};

int main()
{
  Tree T = NULL;
  Tree B = NULL;
  CreateTree(&T);
  copyBTree(T, &B);
  Front(T);
  Front(B);
  return 0;
}