// 判断是否为相似树
int isSame(TREE a, TREE b)
{
  if (!a && !b)
  {
    return 1;
  }
  else
  {
    if (a && b)
    {
      if (isSame(a->lchild, b->lchild) && isSame(a->rchild, b->rchild))
        return 1;
    }
    else
    {
      return 0;
    }
  }
}