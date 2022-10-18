/* L170300102 XUJUNHE BURBBLE SORT */
#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
    int i, j, t, a[N];
    srand(time(NULL));
    for(i = 0; i < N; i++){
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }
        //scanf("%d", &a[i]);
    printf("\n");
    for(i=0; i<N-1; i++){
        for(j=0; j<N-i-1; j++)
    if(a[j]>a[j+1]){
        t = a[j];
        a[j] = a[j+1];
        a[j+1] = t;
    } }
    for(i=0; i<N; i++)
        printf("%5d,",a[i]);
    printf("\n");

}
