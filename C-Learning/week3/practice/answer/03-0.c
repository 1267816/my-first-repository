#include <stdio.h>
 
int main()
{
  int i;
  scanf("%d", &i);
  if(i <= 60)
    printf("Speed: %d - OK", i);
  else
    printf("Speed: %d - Speeding", i);
  return 0;
}