#include <stdio.h>
#include <string.h>
int dice[10];
int map[40];
int check[40]={0};
int turn[40];
int horse[4];
int score[40];
int result = 0;
void init(){
    for(int i=0; i<10; i++)
        scanf("%d", &dice[i]);

    for(int i=0; i<21; i++)
        map[i] = i + 1;

    map[21] = 21;
    for(int i=22; i<27; i++)
        map[i] = i + 1;

    map[28] = 29;
    map[29] = 30;
    map[30] = 25;
    map[31] = 32;
    map[32] = 25;
    map[27] = 20;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;
    turn[25] = 26;

    for(int i=0; i<21; i++)
        score[i] = i * 2;

    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[31] = 22;
    score[32] = 24;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
}

void dfs(int cnt, int sum){
    if(cnt == 10) {
        if(sum > result)
            result = sum;
        return;
    }

    for(int i=0; i<4; i++){
        int now = horse[i];
        int next = horse[i];
        int move_count = dice[cnt];

        if(turn[now] != 0){
            next = turn[now];
            move_count--;
        }

        while(move_count--)
            next = map[next];

        if(next != 21 && check[next])
            continue;

        check[now] = 0;
        check[next] = 1;
        horse[i] = next;

        dfs(cnt+1, sum+score[next]);

        check[now] = 1;
        check[next] = 0;
        horse[i] = now;
    }
}

int main(){
    init();
    dfs(0, 0);
    printf("%d\n", result);
    return 0;
}
