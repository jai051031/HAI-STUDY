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
        int start = 0;
        int end = n-1;
        int mid;
        int check = 0;
        while(start <= end){
            mid = (start+end)/2;
            if(b[i] == a[mid]){
                printf("1 ");
                check = 1;
                start = end + 1;
            }
            else if(b[i] > a[mid])
                start = mid + 1;
            else{
                end = mid - 1;
            }  
        }
        if(check == 0)
            printf("0 ");
    }
}