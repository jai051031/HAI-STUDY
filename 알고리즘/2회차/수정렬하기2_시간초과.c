#include<stdio.h>
int *arr[1000000];
int s(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}
int main(){
    int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(arr[j+1] < arr[j])
                s(&arr[j+1], &arr[j]);
		}
	}
	for(int i=0; i<n; i++)
		printf("%d\n", arr[i]);
	return 0;
}