#include<stdio.h>
int main(void) {
	int a[100], b[100], n, num=2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	b[0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = i-1; j >= i-a[i]; j--) {
			b[j+1] = b[j];
		}
		b[i-a[i]] = num;
		num++;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", b[i]);
	}
}