#include <stdio.h>

int isMajority(int *array, int start, int end, int arrayLength)
{
    int length = end - start + 1;
    int majority = length / 2;
    int frequency[arrayLength][2];
    frequency[0][0] = array[0];
    int index = 0;
    for (int i = start - 1; i < end; i++)
    {
        if (array[i] == frequency[index][0])
        {
            frequency[index][1]++;
        }
        else if (array[i] > frequency[index][0])
        {
            index++;
            frequency[index][0] = array[i];
            frequency[index][1] = 1;
        }
    }
    for (int i = 0; i <= index; i++)
    {
        if (frequency[i][1] > majority)
        {
            return frequency[i][0];
        }
    }
    return 0;
}

int main()
{
    int length, query;
    scanf("%d %d", &length, &query);
    int array[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", array + i);
    }
    int queries[query][2];
    for (int i = 0; i < query; i++)
    {
        scanf("%d %d", *(queries + i), *(queries + i) + 1);
    }
    for (int i = 0; i < query; i++)
    {
        printf("%d\n", isMajority(array, queries[i][0], queries[i][1], length));
    }
    return 0;
}
