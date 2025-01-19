#include<stdio.h>
#include<string.h>
int main(){
    char b[7];
    int n, a[10000], cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%s", b);
        if(strcmp(b, "push") == 0){
            int num;
            scanf("%d", &num);
            a[cnt] = num;
            cnt++;
        }
        else if(strcmp(b, "pop") == 0){
            if(cnt == 0)
                printf("-1\n");
            else{
                printf("%d\n", a[cnt-1]);
                cnt--;
            }
        }
        else if(strcmp(b, "size") == 0){
            printf("%d\n", cnt);
        }
        else if(strcmp(b, "empty") == 0){
            if(cnt == 0)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(strcmp(b, "top") == 0){
            if(cnt == 0)
                printf("-1\n");
            else
                printf("%d\n", a[cnt-1]);
        }
    }
}