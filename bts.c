#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// experimenting with coding a recursive search
// we will use stdlib's quick sort to sort the array prior to the search
#define LEN 20 // length of the array

void display(int *nums, int len);
int lookup(int i, int *nums, int len); // returns 0 when i is found in nums
int compare(const void *a, const void *b);

int main()
{
    srand((unsigned)time(NULL));

    // generate array
    int numbers[LEN];
    int i;
    for (i = 0; i < LEN; i++)
    {
        int j = rand() % 100 + 1;
        numbers[i] = j;
    }
    // display array
    display(numbers, LEN);
    // sort the array
    qsort(numbers, LEN, sizeof(int), compare);
    display(numbers, LEN);

    int result = lookup(53, numbers, LEN);
    // display result
    printf("The result is %d.\n", result);

    return (0);
}

int lookup(int i, int *nums, int len)
// assume len is at least 1
{
    if (len == 1)
        return (i - *nums);
    else
    {
        int mid = *(nums + len / 2);
        if (i == mid)
            return 0;
        if (i < mid)
        {
            display(nums, len / 2);//just to see where the recursion will be working
            return lookup(i, nums, len / 2); 
        }
        else
        {
            display(nums + len / 2, len - len / 2);
            return lookup(i, nums + len / 2, len - len / 2);
        }
    }
}

void display(int *nums, int len)
{
    int i;
    puts("Displaying the array:");
    for (i = 0; i < len; i++)
        printf(" %3d", *(nums + i));
    putchar('\n');
}
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
