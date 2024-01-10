#include <stdio.h>
#include <stdlib.h>

void map_ints(int (*fun)(int i), int *arr, int len);
void filter_ints(int (*fun)(int i), int *arr, int len);
int foldr_ints(int (*fun)(int i, int j), int b, int *arr, int len);
int multiply(int i, int j);
int square(int i);
int is_even(int i);
void display(int *nums, int len);

int main(int argc, char **argv)
{
    int len = 4, ints[] = {1, 2, 3, 4};
    display(ints, 4);

    printf("foldr result: %i \n", foldr_ints(multiply, 1, ints, len));

    map_ints(square, ints, len);
    display(ints, 4);

    filter_ints(is_even, ints, len);
    display(ints, 4);

    return 0;
}
// map
void map_ints(int (*fun)(int i), int *arr, int len)
{
    while (len)
    {
        *arr = fun(*arr);
        arr++;
        len--;
    }
}
// filter
void filter_ints(int (*fun)(int i), int *arr, int len)
{
    if (len)
    {
        if (!fun(*arr))
            *arr = 0;
        filter_ints(fun, arr + 1, len - 1);
    }
}
int foldr_ints(int (*fun)(int i, int j), int b, int *arr, int len)
{
    if (len)
    {
        return fun(*arr, foldr_ints(fun, b, arr + 1, len - 1));
    }
    return b;
}
int multiply(int i, int j)
{
    return (i * j);
}
int square(int i)
{
    return i *= i;
}
int is_even(int i)
{
    return !(i % 2);
}
void display(int *nums, int len)
{
    int i;
    //    puts("Displaying the array:");
    for (i = 0; i < len; i++)
        printf(" %3d", *(nums + i));
    putchar('\n');
}