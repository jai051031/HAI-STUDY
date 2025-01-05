#include<stdio.h>
#include<stdlib.h>
int c(int *a, int *b) { 
	return(*a - *b);
}
int main() {
	int a[1000001], n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	qsort(a, n, sizeof(int), c);
	for(int i=0; i<n; i++){
		printf("%d\n", a[i]);
	}
	return 0;
}