#include <stdio.h>

int isPrime(int i){
    int ret=1;
    int k;
    for (k=2;k<i-1;k++) {
        if (i%k==0) {
            ret=0;
            break;
        }
    }
    return ret;
}

int main(){
    return 0;
}