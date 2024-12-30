#include<stdio.h>
#include<string.h>
int main() {
    char a[101], apb[26];
    int len, sum = 0;
    char* p = apb;
    for (int i = 0; i < 26; i++) {
        p[i] = -1;
    }
    scanf("%s", a);
    len = strlen(a);
    for (int i = 0; i < len; i++) {
        if (apb[a[i] - 97] == -1) {
            apb[a[i] - 97] = i;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", apb[i]);
    }
}