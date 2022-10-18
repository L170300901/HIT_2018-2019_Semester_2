/* L170300102 XUJUNHE SELECTION SORT */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int N = 10;
    int i, j, k, t, a[N];
    for(i=0; i<N; i++)
    {
        a[i] = rand()%61;
        printf("%d ", a[i]);

    }
    printf("\n");
    for(i=0; i<N-1; i++)
    {
        k=i;
        for(j=i; j<N; j++)
        {
            if(a[k]> a[j])
                k = j;
        }
        if(k != i)
        {
            t = a[k];
            a[k] = a[i];
            a[i] = t;
        }
    }

    for(i=0; i<N; i++)
        printf("%5d", a[i]);
    printf("\n");
}
