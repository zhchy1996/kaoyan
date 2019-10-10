#include "head.c"

typedef struct TNode {
  ElemType data;
  struct TNode *lChild, *rChild;
} TNode, *Tree;

void CreateTree(Tree *T) {
  ElemType ch;
  scanf("\n%c", &ch);
  if (ch == '#') {
     *T  = NULL;
  } else {
    *T = (Tree)malloc(sizeof(TNode));
    if (!T)
      exit(1);
    (*T) -> data = ch;
    CreateTree(&(*T) -> lChild);
    CreateTree(&(*T) -> rChild);
  }
}

Status Front (Tree T) {
  if (T == NULL)
    return OK;
  printf("%c", T->data);
  Front(T->lChild);
  Front(T->rChild);
};

int main() {
  Tree T = NULL;
  CreateTree(&T);
  Front(T);
  return 0;
}