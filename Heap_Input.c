#include <stdio.h>

#define MAXSIZE 1000

int n = 9;
int heap[MAXSIZE]={72,35,47,18,29,32,13,5,9};

void PrintHeap(){
    int i;
    for(i=0; i<n-1; i++) printf("%d,",heap[i]);
    printf("%d\n",heap[i]);
}

void PushHeap(int x) //ヒープへのデータの格納
{
    int i,j;
    if(n >= MAXSIZE) printf("Heap Overflow\n");
    else{
        heap[n] = x; //heapの拡張した末尾に入力した値を格納
        i = n; //子の番号
        j = (i-1)/2; //親の番号
        while(i != 0 && x>heap[j]) //子が根ではない、かつ、親より子の方が大きいなら
        {
            heap[i] = heap[j]; //親と子を交換する
            i = j;
            j = (i-1)/2;
        }
        heap[i] = x;
        n++;
    }
}

int main(void){
    int x,i;
    PrintHeap();
    do{
        printf("終了(0), 追加(1):");
        scanf("%d",&i);
        if(i == 1){
            printf("ヒープに追加：");
            scanf("%d",&x);
            PushHeap(x);
            PrintHeap();
        }
    }while(i != 0);
    return 0;
}

