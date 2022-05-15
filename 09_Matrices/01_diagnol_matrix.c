#include<stdio.h>
struct Matrix
{
    int A[10];
    int n;
};

void sety(struct Matrix *a, int i, int j, int x)
{
    if (i == j)
    {
        a->A[i - 1] = x;
    }
}
int get(struct Matrix *a, int i, int j)
{
    if (i == j)
    {
        return a->A[i - 1];
    }
    return 0;
}
void display(struct Matrix *m)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->n; j++)
        {
            if (i == j)
            {
                printf("%d ", m->A[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m;
    m.n = 4;
    sety(&m, 1, 1, 9);
    sety(&m, 2, 2, 4);
    sety(&m, 3, 3, 7);
    sety(&m, 4, 4, 8);
    display(&m);
    printf("%d",get(&m,4,4));
    return 0;
}