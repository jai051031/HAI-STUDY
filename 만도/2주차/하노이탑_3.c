#include<stdio.h>
int hanoi(int n, int cnt){
    for(int i=1; i<=cnt; i++){
        int out = 1, in = 1;
        for(int j=0; j<n; j++){
            if (i & (1 << j)) {
                out = 1 + (j % 3);
                in = 1 + ((j + 1) % 3);
                break;
            }
        }
        printf("%d %d\n", out, in);
    }
}
int main(){
    int n, cnt;
    scanf("%d", &n);
    cnt = (1 << n) - 1; 
    printf("%d\n", cnt);
    hanoi(n, cnt);
    return 0;
}
