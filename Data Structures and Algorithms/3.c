#include <stdio.h>

typedef enum {false, true} bool;


int number = 6;
int INF = 10000000;

int a[6][6] = {
    {-1,100,30,-1,10},
    {1,-1,-1,-1,-1},
    {-1,60,-1,60,-1},
    {-1,10,-1,-1,-1},
    {-1,-1,-1,50,-1},
};
bool v[6];
int d[6];

int getSmallIndex(){
      int min = INF;
      int index = 0;
      for(int i = 0; i < number; i++){
        if(d[i] < min && !v[i]){
            min =d[i];
            index =i;
        }
      }
      return index;
}

void dijkstra(int start){
      for(int i = 0; i< number; i++){

        d[i] = a[start][i];
      }
      v[start] = true;
      for(int i =0; i < number-2; i++){
        int current = getSmallIndex();
        v[current] = true;
        for(int j =0; j< 6; j++){
            if(!v[j]){
                if(d[current] + a[current][j] < d[j]){
                    d[j] = d[current] + a[current][j];
                }
            }
        }
      }
}

int main(void)
{
    dijkstra(0);
    for(int i =0; i < number; i++){
        printf("%d",d[i]);
    }
}
