#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int from, to, n, aux;
    int state;  // state: 0 = 처음, 1 = 중간, 2 = 두 번째 재귀
} HanoiFrame;

void hanoi(int n) {
    HanoiFrame* stack = (HanoiFrame*)malloc(sizeof(HanoiFrame) * (2 * n - 1));  // 최대 깊이는 2n-1
    int top = -1;  // 스택 포인터

    // 초기 상태를 스택에 푸시
    stack[++top] = (HanoiFrame){1, 3, n, 2, 0};

    while (top >= 0) {
        HanoiFrame* current = &stack[top];
        
        if (current->n == 1) {
            // 출력하는 조건
            printf("%d %d\n", current->from, current->to);
            top--;  // 스택에서 pop
        } else {
            // state에 따라 작업을 나눈다.
            if (current->state == 0) {
                // 첫 번째 재귀 호출
                current->state = 1;
                stack[++top] = (HanoiFrame){current->from, current->aux, current->n - 1, current->to, 0};
            } else if (current->state == 1) {
                // 출력
                printf("%d %d\n", current->from, current->to);
                current->state = 2;
                stack[++top] = (HanoiFrame){current->aux, current->to, current->n - 1, current->from, 0};
            } else {
                // 두 번째 재귀 호출 완료 후 pop
                top--;
            }
        }
    }

    free(stack);  // 스택 메모리 해제
}

int main() {
    int n;
    scanf("%d", &n);

    // 출력 횟수
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        cnt *= 2;
    }
    printf("%d\n", cnt - 1);

    hanoi(n);
    return 0;
}
