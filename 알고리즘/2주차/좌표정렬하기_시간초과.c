#include<stdio.h>
struct xy{
	int x[100000];
	int y[100000];
};
int s(int* a, int* b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main(){
	struct xy a;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
		scanf("%d %d", &a.x[i], &a.y[i]);
	for(int i=0; i<n; i++){
		for(int j=0; j<n-1; j++){
			if(a.x[j+1] < a.x[j]){
				s(&a.x[j+1], &a.x[j]);
				s(&a.y[j+1], &a.y[j]);
			}
			else if(a.x[j+1] == a.x[j]){
				if(a.y[j+1] < a.y[j]){
					s(&a.x[j+1], &a.x[j]);
					s(&a.y[j+1], &a.y[j]);
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		printf("%d %d\n", a.x[i], a.y[i]);
	}
}