#include<stdio.h>
int c(int* a, int* b){
	return((*a>*b) ? 1 : -1);
}
int main(){
    int n, m;
    long long int a[500000], b[500000];
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%lld", &a[i]);
    qsort(a, n, sizeof(long long int), c);
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        scanf("%lld", &b[i]);
        int start1 = 0, start2 = 0;
        int end1 = n-1, end2 = n-1;
        int mid1, mid2;
        while(start1 < end1){
            mid1 = start1 + (end1 - start1) / 2;
            if(b[i] > a[mid1]){
                start1 = mid1 + 1;
            }
            else{
                end1 = mid1;
            }
        }

        while(start2 < end2){
            mid2 = start2 + (end2 - start2) / 2;
            if(b[i] >= a[mid2]){
                start2 = mid2 + 1;
            }
            else{
                end2 = mid2;
            }
        }
        if(a[start1] == b[i] && a[start2] == b[i])
            printf("%d ", start2-start1+1);
        else if(start1 == start2)
            printf("0 ");
        else
            printf("%d ", start2-start1);
    }
}