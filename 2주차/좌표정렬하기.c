#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int x, y;
} point;
int c(int *a, int *b){
    point* ap = (point*)a;
    point* bp = (point*)b;
    if((*ap).x == (*bp).x)
        return (*ap).y - (*bp).y;
    else
        return (*ap).x - (*bp).x;
}
point a[100000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d %d", &a[i].x, &a[i].y);
    qsort(a, n, sizeof(point), c);
    for(int i=0; i<n; i++)
        printf("%d %d\n", a[i].x, a[i].y);
    return 0;
}