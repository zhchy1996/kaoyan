#include <stdio.h>
#define DLURB "Authentic imitation! "
int main(void)
{
  printf("/%2s/\n", DLURB);
  printf("/%24s/\n", DLURB);
  printf("/%24.5s/\n", DLURB);
  printf("/%-24.5s/\n", DLURB);
  return 0;
}