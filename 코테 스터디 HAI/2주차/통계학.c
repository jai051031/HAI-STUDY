#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int s(int* a, int* b) { 
	return(*a - *b);
}
int func1(int n, int sum){
    double a;
    a = (double)sum / n;
    printf("%d\n", (int)round(a));
    return 0;
}
int func2(int n, int a[]){
    if(n % 2 == 0)
        printf("%d\n", (a[n/2-1]+a[n/2])/2);
    else
        printf("%d\n", a[n/2]);
    return 0;
}
int func3(int n, int a[], int b[]){
    int max=0, mod, cnt=0;
    for(int i=0; i<8001; i++){
        if(b[i] > max){
            max = b[i];
            mod = i - 4000;
            cnt = 1;
        }
        else if(b[i] == max && cnt == 1){
            mod = i - 4000;
            cnt = 0;
        }
    }
    printf("%d\n", mod);
    return 0;
}
int func4(int n, int a[]){
    printf("%d\n", a[n-1] - a[0]);
    return 0;
}
int main(){
    int n, a[500000], sum=0, b[8001];
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        sum += a[i];
        b[a[i]+4000]++;
    }
    qsort(a, n, sizeof(int), s);
    func1(n, sum);
    func2(n, a);
    func3(n, a, b);
    func4(n, a);
}