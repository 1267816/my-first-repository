#include <stdio.h>
 
int main()
{
     int A, B, C;
     scanf("%d%d%d",&A, &B, &C);
     if(A != B && B ==C)
           printf("A");
     else if(B != A && A == C)
           printf("B");
     else if(C != A && A == B)
           printf("C");
    return 0;
}