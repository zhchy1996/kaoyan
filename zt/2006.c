// 复制二叉树
int copyBTree(BTREE &A)
{
  if (T == NULL)
  {
    A = NULL;
    return;
  }
  A = (BTREE)malloc(sizeof(BTNode));
  A->data = T->data;
  copyBTree(A->lchild, B->lchild);
  copyBTree(A->rchild, B->rchild);
}

// 统计有向图度数
void agree(int A[][3], int n, int e, int agree[n][2])
{
  // agree[n][0]为出度，agree[n][1]为入度
  // 初始化各个定点度数
  for (int j = 0; j < n; j++)
  {
    agree[j][0] = 0;
    agree[j][1] = 0;
  }

  for (int i = 0; i < e; i++)
  {
    agree[i][0]++;
    agree[i][1]++;
  }
}