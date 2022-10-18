/* L170300102 XUJUNHE DSAA h/w - Josephus Problem */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, M;
    struct node
    {
        int player_id;
        struct node *next;
    };
    struct node *p, *q;
    int i, count;

    printf("Enter N (number of players): ");
    scanf("%d", &N);
    printf("Enter M (every M-th payer gets eliminated): ");
    scanf("%d", &M);

    /* Create circular linked list containing all the players: */
    p = q = malloc(sizeof(struct node));
    p->player_id = 1;

    for (i = 2; i <= N; ++i)
    {
        p->next = malloc(sizeof(struct node));
        p = p->next;
        p->player_id = i;
    }

    p->next = q;  /* Close the circular linked list by having the last node point to the first. */

    /* Eliminate every M-th player as long as more than one player remains: */
    for (count = N; count > 1; --count)
    {
        for (i = 0; i < M - 1; ++i)
            p = p->next;
        struct node *tmp;
        tmp = p->next;
        p->next = tmp->next;    /*Remove the eiminated player from the circular linked list.*/
        free(tmp);
    }

    printf("Last player left standing is %d\n.", p->player_id);

    return 0;
}
