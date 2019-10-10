#include "head.c"

char str[11] = {'A', 'B', 'D', '#', '#', 'E', '#', '#', 'C', '#', '#'};
int stri = 0;

typedef enum {child, link} PointTag;

typedef struct TreeNode {
  ElemType data;
  struct TreeNode *lchild, *rchild;
  PointTag lpointTag, rpointTag;
}TreeNode, *Tree;

Tree pre = NULL;

Status init(Tree *T) {
  (*T)->lchild = NULL;
  (*T)->rchild = NULL;
  (*T)->lpointTag = child;
  (*T)->rpointTag = child;
  return OK;
}

void CreateTree(Tree *T) {
  ElemType ch;
  // scanf("\n%c", &ch);
  ch = str[stri++];
  if (ch == '#') {
     *T  = NULL;
  } else {
    *T = (Tree)malloc(sizeof(TreeNode));
    if (!T)
      exit(1);
    (*T) -> data = ch;
    (*T) -> lpointTag = child;
    (*T) -> lpointTag = child;
    CreateTree(&(*T) -> lchild);
    CreateTree(&(*T) -> rchild);
  }
}

void linkHead(Tree T) {
  if (T) {
    linkHead(T->lchild);
    if (!T->lchild) {
      T->lpointTag = link;
      T->lchild = pre; 
    }
    if (pre && !pre->rchild) {
      pre->rpointTag = link;
      pre->rchild = T;
    }
    pre = T;
    linkHead(T->rchild);
  }
}

void Front (Tree T) {
  if (T == NULL)
    return;
  if (T->lpointTag == child) {
    Front(T->lchild);
  }
  printf("main %c |", T->data);
  if (T->lpointTag == link) {
    if (T->lchild)
      printf("left  %c |", T->lchild->data);
  }
  if (T->rpointTag == link) {
    if (T->rchild)
      printf("right %c |", T->rchild->data);
  }
  printf("\n");
  if (T->rpointTag == child) {
    Front(T->rchild);
  }
}

int main() {
  Tree T = NULL;
  CreateTree(&T);
  linkHead(T);
  Front(T);
  return 0;
}