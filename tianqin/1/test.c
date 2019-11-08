typedef struct Node
{
  int data;
  struct Node *next;
} Node;

void change(Node *n)
{
  n->data = 1;
}

int a = 1;
int b = 2;
void point(int **pa)
{
  *pa = &b;
}

int main()
{
  int *pa = &a;
  point(&pa);
  printf("%d\n", *pa);
  // Node *n = (Node *)malloc(sizeof(Node));
  // n->data = 0;
  // change(n);
  // printf("%d", n->data);
  return 0;
}