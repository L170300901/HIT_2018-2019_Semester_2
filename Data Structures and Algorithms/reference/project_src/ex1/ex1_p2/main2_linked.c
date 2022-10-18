#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define NUM 300

struct poly
{
    int coef;
    int exp;
    poly * next;
};
typedef poly * polypointer;

void init(polypointer head)   // initialize
{
    polypointer x;
    x = new polypointer;
    int i;
    for (i = 0; i <= MAX; i++)
    {
        x->coef = 0;
        x->exp = 0;
        head->next = x;
    }
}

void PolyInput(polypointer head)     // receives exp and coef from input, save these
{
    int c = 0;
    int e = 0;
    init(head);
    while(scanf("%d %d", &c, &e) && e >= 0)
    {
        head->coef = c;
        if(head->exp < e)
            head->exp = e;
    }
}

void PolyPrint(polypointer head)
{
    int i;
    printf("[ %d %d ]", head.coef, head.exp);
    for(i = head->(coef - 1); i >= 0; i--)
        if(head.coef != 0)
            printf(" [ %d %d ]", head.coef, i);
        printf("\n");


}

void PolyAdd(const polypointer Poly1, const polypointer Poly2, polypointer PolySum)
{
    int i;
    init(PolySum);
    if(Poly1->exp < Poly2->exp)
        PolySum->exp = Poly2->exp;
    else
        PolySum->exp = Poly1->exp;

    for(i = PolySum->exp; i >= 0; i--)
    {
        PolySum->coef = Poly1->coef + Poly2->coef;
    }
}





int main()
{
    polypointer head;
    polypointer PolySum;

    int n;
    scanf("%d", &n);

    int i;
    for(i = 0; i < 2 * n; i++)
        PolyInput(head);
    for(i = 0;i < n; i++)
    {
        PolyAdd((head * 2*i), (head * 2*i +1), &PolySum);
        PolyPrint(PolySum);
    }
    return 0;
}
