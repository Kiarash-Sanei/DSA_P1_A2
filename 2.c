#include <stdio.h>
#include <stdlib.h>

struct LinkableInteger
{
    int value;
    struct LinkableInteger *next;
} typedef LI;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    LI list[n];
    for (int i = 0; i < n; i++)
    {
        list[i].next = NULL;
        list[i].value = -1;
    }

    int arr[n];
    int input;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        arr[i] = input;
        LI* entry = list + input - 1;
        while (entry->next != NULL)
        {
            entry = entry->next;
        }
        LI *newEntry = (LI *)malloc(sizeof(LI));
        entry->next = newEntry;
        entry->value = i;
        newEntry->next = NULL;
        newEntry->value = -1;
    }

    for (int i = 0; i < q; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        int flag = 0;
        int range = r - l + 1;
        l--;
        r--;

        for (int j = 0; j < 30; j++)
        {
            int random = (rand() % range) + l;
            int candidate = arr[random];

            int count = 0;
            LI entry = list[candidate - 1];
            while (entry.next != NULL)
            {
                if (entry.value >= l)
                {
                    if (entry.value > r)
                    {
                        break;
                    }
                    count++;
                }
                entry = *entry.next;
            }

            if (count > range / 2)
            {
                flag = candidate;
                break;
            }
        }
        printf("%d\n", flag);
    }

    return 0;
}
