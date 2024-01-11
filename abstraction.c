#include <stdio.h>
#include <stdlib.h>
// int arrays are used here to simplify the work.
// recursion is used instead of iteration solely for more practice on recursion.
// iterative approach is preferable to the recursive approach used.

void map_ints(int (*fun)(int i), int *arr, int len);
void filter_ints(int (*fun)(int i), int *arr, int len);
int foldr_ints(int (*fun)(int i, int j), int b, int *arr, int len);
int andmap_ints(int (*fun)(int i), int *arr, int len);

int multiply(int i, int j);
int square(int i);
int is_even(int i);
void display(int *nums, int len);

int main(int argc, char **argv)
{
    int len = 4, ints[] = {1, 2, 3, 4};
    display(ints, 4);

    printf("foldr ints: %i \n", foldr_ints(multiply, 1, ints, len));

    int evens[] = {2, 4, 6, 4};
    printf("andmap ints: %i \n", andmap_ints(is_even, ints, len));
    printf("andmap evens: %i \n", andmap_ints(is_even, evens, len));

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
// foldr
int foldr_ints(int (*fun)(int i, int j), int b, int *arr, int len)
{
    if (len)
    {
        return fun(*arr, foldr_ints(fun, b, arr + 1, len - 1));
    }
    return b;
}
// consider associativity of fun when selecting fold variant
// this fold is is optimized for performance
int fold_ints_variant(int (*fun)(int i, int j), int b, int *arr, int len)
{
    if (len)
    {

        return foldr_ints(fun, fun(*arr, b), arr + 1, len - 1);
    }
    return b;
}
// andmap
int andmap_ints(int (*fun)(int i), int *arr, int len)
{
    if (len)
        return (fun(*arr) && andmap_ints(fun, arr + 1, len - 1));
    return 1;
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