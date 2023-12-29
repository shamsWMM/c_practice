#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
void bsort(int *nums, int len);
int *sort(int *nums, int len); // does not modify original array
void insert(int i, int *nums, int len, int *res); 
int *sortv(int *nums, int len); // modifies original array
void insertv(int i, int *nums, int len, int *ptr);
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
//    nums = sort(numbers,LEN);
    sortv(numbers,LEN);
    toc = clock();
    display(numbers,LEN);
//    display(nums,LEN);
	printf("Elapsed for function: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
    
	return(0);
}

// trying without malloc() - this modifies original int array values
int *sortv(int *nums, int len)
// assume len is at least 1
{
    if(len==1) return(nums);
    insertv(*nums, sort(nums+1, len-1), len-1, nums);
    return(nums);
}
void insertv(int i, int *nums, int len, int *ptr)
{
    if(len==0)
    {
        *ptr = i;
    }
    else
    {
        if(i<*nums)
        {
            *ptr = i;
            insertv(*nums,nums+1,len-1,ptr+1); //?
        }
        else
        {
            *ptr = *nums;
            insertv(i,nums+1,len-1,ptr+1);
        }
    }
}


// trying with malloc()
int *sort(int *nums, int len)
// assume len is at least 1
{
    if(len==1) return(nums);
    //allocate memory for the sorted result
    int *res = (int *)malloc(len*sizeof(int));
    //if (result == NULL) {
    //    // Handle memory allocation failure
    //    fprintf(stderr, "Memory allocation failed.\n");
    //    exit(EXIT_FAILURE);
    //}
    insert(*nums, sort(nums+1, len-1), len-1, res);
    return(res);
}
void insert(int i, int *nums, int len, int *res)
{
    if(len==0)
    {
        *res = i;
    }
    else 
    {
        if(i>*nums)
        {
            *res = *nums;
            insert(i,nums+1,len-1,res+1);
        }
        else
        {
            *res = i;
            insert(*nums,nums+1,len-1,res+1);
        }
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