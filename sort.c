#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
void bsort(int *nums, int len);
int *sort(int *nums, int len); // modifies original array
void insert(int i, int *nums, int len, int *ptr);
void display(int *nums, int len);

int main()
{
    clock_t tic, toc;
    int *nums;

    int numbers[10];
    // populate the array with integers from 1 to 100
	srand((unsigned)time(NULL));
    int i;
	for(i=0;i<LEN;i++) numbers[i] = rand() % 100 + 1;
    //display array
    display(numbers, LEN);

	tic = clock();
//    bsort(numbers,LEN);
    sort(numbers,LEN);
    toc = clock();
    display(numbers,LEN);
	printf("Elapsed for function: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
	return(0);
}

int *sort(int *nums, int len)
// assume len is at least 1
{
    if(len==1) return(nums);
    insert(*nums, sort(nums+1, len-1), len-1, nums);
    return nums;
}
void insert(int i, int *nums, int len, int *ptr)
{ // assumes list is already sorted
    if(len==0)*ptr = i;
    else
    {
        if(i>*nums)
        {
            *ptr=*nums;
            insert(i,nums+1,len-1,ptr+1);
        }
        else *ptr = i;
    }
}

// the bubble sort function for comparison
void bsort(int *nums, int len)
{
    int i, j, temp;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len;j++)
        {
            if(*(nums+i)>*(nums+j))
            {
                temp=*(nums+i);
                *(nums+i)=*(nums+j);
                *(nums+j)=temp;

            }
        }
    }
}
void display(int *nums, int len)
{
    int i;
    puts("Displaying the array:");
	for(i=0;i<len;i++)
		printf(" %3d",*(nums+i));
	putchar('\n');
}