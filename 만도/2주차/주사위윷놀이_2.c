#include<stdio.h>
#include<string.h>

int dice[10];
int map[40];
int turn[40];
int score[40];
int horse[4];
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

int simul(int move[]){
    int horse2[4]={0};
    int check2[40]={0};
    int score2 = 0;

    for(int i=0; i<10; i++){
        int horse3 = move[i];
        int now = horse2[horse3];
        int next = now;
        int move_count = dice[i];

        if(turn[now] != 0){
            next = turn[now];
            move_count--;
        }

        while(move_count-- > 0)
            next = map[next];

        if(next != 21 && check2[next])
            return -1;

        check2[now] = 0;
        check2[next] = 1;
        horse2[horse3] = next;
        score2 += score[next];
    }

    return score2;
}

void dfs(int cnt, int move[]){
    if(cnt == 10){
        int score = simul(move);
        if(score > result)
            result = score;
        return;
    }

    for(int i=0; i<4; i++){
        move[cnt] = i;
        dfs(cnt+1, move);
    }
}

int main(){
    init();
    int move[10]={0};
    dfs(0, move);
    printf("%d\n", result);
    return 0;
}
