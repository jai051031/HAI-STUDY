#include<stdio.h>
int hanoi(int out, int in, int n, int swap){
	if(n == 1)
		printf("%d %d\n", out, in);
	else{
		hanoi(out, swap, n-1, in);
		printf("%d %d\n", out, in);
		hanoi(swap, in, n-1, out);
	}
    return 0;
}
int main(){
	int n, cnt=1;
	scanf("%d", &n);
	cnt = (1 << n) - 1;
    printf("%d\n", cnt);
	hanoi(1, 3, n, 2);
	return 0;
}