#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int len = 5;
void populate(int *array, int len);
void display(int *array, int len);
void sort(int *nums, int len);
void merge(int *nums, int len);

int main()
{
    srand((unsigned)time(NULL));
    int numbers[len];
    populate(numbers, len);

    // display array
    display(numbers, len);

    sort(numbers, len);
    display(numbers, len);

    return (0);
}

void sort(int *nums, int len)
{
    if (len >= 2)
    {
        sort(nums, len / 2);
        sort(nums + len / 2, len - len / 2);
        merge(nums, len);
    }
}

void merge(int *nums, int len)
{
    int mid = len / 2, l_len = mid, r_len = len - mid, cnt = 0;
    int *left = nums, *right = nums + mid;
    int temp[len];
    while (cnt < len)
    {                   // knowing when cnt == len is when both l_len and r_len are 0
        if (l_len == 0) // left side is exhausted
        {
            temp[cnt++] = *right++; // use the value, increment the address
            r_len--;
        }
        else if (r_len == 0) // right side is exhausted
        {
            temp[cnt++] = *left++; // use the value, increment the address
            l_len--;
        }
        else // neither side is empty
        {
            if (*left <= *right)
            {
                temp[cnt++] = *left++; // use the value, increment the address
                l_len--;
            }
            else
            {
                temp[cnt++] = *right++; // use the value, increment the address
                r_len--;
            }
        }
    }
    for (int i = 0; i < len; i++)
        *nums++ = temp[i];
}

void display(int *nums, int len)
{
    int i;
    puts("Displaying the array:");
    for (i = 0; i < len; i++)
        printf(" %3d", *(nums + i));
    putchar('\n');
}
void populate(int *array, int len)
{
    int j;
    for (int i = 0; i < len; i++)
    {
        j = rand() % 100 + 1;
        *(array + i) = j;
    }
}


 // else if (*left <= *right)
    // {
    //     if (l_len == 1)
    //         ; // no action required
    //     else  // l_len > 1
    //         merge(left + 1, right, l_len - 1, r_len);
    // }
    // else // *left > *right
    // {
    //     int r = *right;
    //     if (l_len == 1)
    //     {
    //         *right = *left;
    //         *left = r;
    //         if (r_len > 1)
    //             merge(right, right + 1, 1, r_len - 1);
    //     }
    //     else // l_len > 1
    //     {
    //         for (int i = l_len; i > 0; --i)    // intentional pre-decrement
    //             *(left + i + 1) = *(left + i); // shift lefts by 1 to the right
    //         *left = r;                         // place r into *left
    //         merge(left + 1, right + 1, l_len - 1, r_len - 1);
    //     }
    // }