#include<stdio.h>
int a[1001][1001];
int b[1001];
int c[1001];
int dfs(int n, int v){
    b[v] = 1;
    printf("%d ", v);
    for(int i=1; i<=n; i++){
		if(b[i] == 0 && a[v][i])
			dfs(n, i);
	}
    return;
}
int bfs(int n, int v){
    int front = -1, rear = -1, pop;
	printf("%d ", v);
	b[v] = 1;
	c[++rear] = v;
	while(front < rear){
		pop = c[++front];
		for(int i=1; i<=n; i++){
			if(b[i] == 0 && a[pop][i]){
				printf("%d ", i);
				b[i] = 1;
				c[++rear] = i;
			}
		}
	}
	return;
}
int main(){
    int n, m, v, x, y;
    scanf("%d %d %d", &n, &m, &v);
    for(int i=0; i<m; i++){
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    dfs(n, v);
    printf("\n");
    for(int i=0; i<=n; i++)
        b[i] = 0;
    bfs(n, v);
    return 0;
}