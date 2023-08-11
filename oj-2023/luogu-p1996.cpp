#include <cstdio>
#include <list>
#include <cstdlib>
using namespace std;

typedef struct NODE
{
    int v;
    NODE *next;
} NODE;

int main()
{
    int n, m, v;
    list<int> a;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        NODE *cur = (NODE *)malloc(sizeof(NODE));
        NODE *head = cur;
        NODE *prev = NULL;
        for (int i = 0; i < n; i++)
        {
            //scanf("%d", &v);
            cur->v = i + 1;
            if(i<n-1)
                cur->next = (NODE *)malloc(sizeof(NODE));
            else
            {
                cur->next = head;
                prev = cur;
            }

            cur = cur->next;
        }

        cur = head;
        int i = 1;
        while (prev->next!=prev)
        {
            if(i%m==0)
            {
                NODE *tmp = prev->next;
                prev->next = tmp->next;
                printf("%d ", tmp->v);
                free(tmp);
            }
            else
            {
                prev = prev->next;
            }
            i += 1;
            
        }
        printf("%d\n", prev->v);
    }

    return 0;
}