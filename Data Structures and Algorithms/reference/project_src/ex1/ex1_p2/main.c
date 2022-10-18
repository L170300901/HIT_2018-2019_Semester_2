// L170300102  problem 2
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NUM 300

typedef struct poly
{
    int coef[MAX];
    int highstExp;
}poly;

void init(poly *head)   // initialize
{
    int i;
    for (i = 0; i <= MAX; i++)
    {
        head->coef[i] = 0;
        head->highstExp = 0;
    }
}

void PolyInput(poly *head)     // receives exp and coef from input, save these
{
    int c = 0;
    int e = 0;
    init(head);
    while(scanf("%d %d", &c, &e) && e >= 0)
    {
        head->coef[e] = c;
        if(head->highstExp < e)
            head->highstExp = e;
    }
}

void PolyPrint(poly head)
{
    int i;
    printf("[ %d %d ]", head.coef[head.highstExp], head.highstExp);
    for(i = head.highstExp - 1; i >= 0; i--)
        if(head.coef[i] != 0)
            printf(" [ %d %d ]", head.coef[i], i);
        printf("\n");


}

void PolyAdd(const poly *Poly1, const poly *Poly2, poly *PolySum)
{
    int i;
    init(PolySum);
    if(Poly1->highstExp < Poly2->highstExp)
        PolySum->highstExp = Poly2->highstExp;
    else
        PolySum->highstExp = Poly1->highstExp;

    for(i = PolySum->highstExp; i >= 0; i--)
    {
        PolySum->coef[i] = Poly1->coef[i] + Poly2->coef[i];
    }
}





int main()
{
    poly head[2 * NUM];
    poly PolySum[NUM];

    int n;
    scanf("%d", &n);

    int i;
    for(i = 0; i < 2 * n; i++)
        PolyInput(&head[i]);
    for(i = 0;i < n; i++)
    {
        PolyAdd(&head[2 * i], &head[2 * i + 1], &PolySum[i]);
        PolyPrint(PolySum[i]);
    }
    return 0;
}
