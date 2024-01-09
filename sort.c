#include <stdio.h>
#include <stdlib.h>

// practicing recursion in sort

void sort(int *nums, int len);
void insert(int i, int *nums, int len);
void display(int *nums, int len);
int main()
{
    int variable_len;
    srand((unsigned)time(NULL));

    for (variable_len = 1; variable_len < 7; variable_len++)
    {
        // generate array to be sorted
        int numbers[variable_len];
        int i;
        for (i = 0; i < variable_len; i++)
        {
            int j = rand() % 100 + 1;
            numbers[i] = j;
        }
        // display array
        display(numbers, variable_len);
        sort(numbers, variable_len); // sort original array
        display(numbers, variable_len);
    }
    return (0);
}

void sort(int *nums, int len)
// assume len is at least 1
{
    if (len)
    {
        sort(nums+1, len-1);
        insert(*nums, nums + 1, len - 1);
    }
}

void insert(int i, int *nums, int len)
{ // assumes list is already sorted
    if (len == 0)
        *(nums - 1) = i;
    else if (i > *nums) // number to be inserted is larger than first number
        {
            *(nums - 1) = *nums;
            insert(i, nums + 1, len - 1); // use insert on the number and the rest of the array
        }
    else *(nums - 1) = i; // number to be inserted is smaller than first number in the array
}


// the bubble sort function for comparison
void bsort(int *nums, int len)
{
    int i, j, temp;
    for (i = 0; i < len; i++)
    {
        for (j = i + 1; j < len; j++)
        {
            if (*(nums + i) > *(nums + j))
            {
                temp = *(nums + i);
                *(nums + i) = *(nums + j);
                *(nums + j) = temp;
            }
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
