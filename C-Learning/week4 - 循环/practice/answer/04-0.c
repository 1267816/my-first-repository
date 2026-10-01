#include <stdio.h>

int main(){
    //初始化
    int a;
    scanf("%d",&a);
    int i,j,k;
    int cnt=0;

    i=a;
    while (i<=a+3) {
        //遍历i时，j要从a一直加到a+3，所以需要在一开始重置j=a
        //下面k=a同理
        j=a;
        while (j<=a+3) {
            k=a;
            while (k<=a+3) {
                if (i!=j) {
                    if (i!=k) {
                        if (j!=k) {
                            cnt++;
                            printf("%d%d%d",i,j,k);
                            //符合输出格式要求
                            if (cnt==6) {
                                printf("\n");
                                cnt=0;
                            } else {
                                printf(" ");
                            }
                        }
                    }
                }
                //为了遍历k，不要忘记k++
                //下面j++同理
                k++;
            }
            j++;
        }
        i++;
    }

    return 0;
}