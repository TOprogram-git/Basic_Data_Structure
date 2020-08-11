#include <stdio.h>

#define MAXSIZE 1000

int n = 9;
int heap[MAXSIZE]={72,35,47,18,29,32,13,5,9};

void PrintHeap(){
    int i;
    if(n != 0){
        for(i=0; i<n-1; i++) printf("%d,",heap[i]);
        printf("%d\n",heap[i]);
    }
    else{
        printf("データがありません\n");
    }
}

int DeleteMax() //ヒープの最大値を取り出す
{
   int x, i, j, t;
   if(n == 0) return -1;
   else{
       x = heap[0];
       heap[0] = heap[--n];
       i = 0;
       while(i*2+1 <= n-1){
            j = i*2+1;
            if( (i+1)*2 <= n-1 && heap[i*2+1] < heap[(i+1)*2]) j=(i+1)*2;
            if(heap[i] >= heap[j]) break;
            else{
                t = heap[i];
                heap[i] = heap[j];
                heap[j] = t;
            }
            i = j;
       }
       return x;
   }
}

int main(void){
    int x,i;
    PrintHeap();
    do{
        printf("終了(0), 最大値のデータを取り出す(1):");
        scanf("%d",&i);
        if(i == 1){
            x = DeleteMax();
            if(x == -1){
                printf("Heap UnderFlow\n");
                PrintHeap();
            }
            else{
                printf("最大値%dを取り出しました\n",x);
                PrintHeap();
            }
        }
    }while(i != 0);
    return 0;
}
