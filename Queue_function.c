#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 11 //キューが空か満杯かを区別するために必要サイズより1つスペースを確保する
int queue[MAXSIZE];
int head = 0;
int tail = 0;

void Enqueue(int x){
    if(head == (tail+1)%MAXSIZE) //次の末尾の記憶領域が先頭と等しい(満杯)
    {
        printf("記憶領域が満杯です\n");
    }
    else{
        queue[tail] = x;
        tail = (tail+1) % MAXSIZE; //末尾を次へ移動する
        printf("Enqueue(%d)\n",queue[tail]);
    }
}

void Dequeue(){
    if(head == tail) //先頭と末尾が等しい(空)
    {
        printf("記憶領域に値はありません\n");
    }
    else{
        printf("Dequeue(%d)\n",queue[head]);
        head = (head+1) % MAXSIZE; //先頭を次へ移動する
    }
}

void PrintQueue() //現在のキューの表示
{
    int i;
    if(head != tail%MAXSIZE){
        for(i=head; i != tail-1; i=(i+1)%MAXSIZE) printf("%d, ",queue[i]);
        printf("%d\n",queue[i]);
    }
    else printf("キューの中身は空\n");
}

int main(){
    int x,i;
    do{
        printf("現在のキュー\n");
        PrintQueue();
        printf("stop(0), Enqueue(1), Dequeue(2):");
        scanf("%d",&i);
        switch(i){
        case 1:
            printf("値の入力：");
            scanf("%d",&x);
            Enqueue(x);
            break;
        case 2:
            Dequeue();
            break;
        }
    }while(i != 0); //終了するまで繰り返す
    return 0;
}
