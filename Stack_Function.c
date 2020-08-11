#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
int stack[MAXSIZE];
int top=0;

void push(int x){
    stack[top++] = x;
}

int pop(){
    return stack[--top];
}

int main(){
    int x,i;
    while(1){
        printf("stop(0), push(1), pop(2):");
        scanf("%d",&i);
        if(i == 0)break;
        if(i == 1){
            printf("値の入力：");
            scanf("%d",&x);
            if(top == MAXSIZE) printf("記憶領域(オーバーフロー)\n");
            else{
                push(x);
                printf("スタックに格納しました\n");
            }
        }
        if(i == 2){
            if(top == 0) printf("記憶領域(アンダーフロー)\n");
            else printf("pop = %d\n",pop());
        }
    }
    return 0;
}
