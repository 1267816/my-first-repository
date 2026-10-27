#include <stdio.h>
enum COLOR {RED=1, YELLOW, GREEN=5, NumCOLORS};

int main(int argc, char const *argv[])
{
    enum COLOR color = 0;

    printf("code for GREEN is %d\n", GREEN);
    printf("and color is %d\n", color);

    return 0;
}