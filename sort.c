#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
void bsort(int *nums, int len);
int *sort(int *nums, int len); // modifies original array
int *render_sorted(int *nums, int len); // does not modify original array
void insert(int i, int *nums, int len, int *ptr);
void insert_r(int i, int *nums, int len, int *ptr);
void display(int *nums, int len);

int main()
{
    // generate array to be sorted
    int numbers[10];
	srand((unsigned)time(NULL)); 
    int i;
	for(i=0;i<LEN;i++) numbers[i] = rand() % 100 + 1; 
    //display array
    display(numbers, LEN);
    
    int *nums; // for the result of render_sorted()
    nums = render_sorted(numbers,LEN);
    display(nums,LEN);

    display(numbers, LEN); //dsiplay original array to show it has not changed

//    bsort(numbers,LEN);
    sort(numbers,LEN); //sort original array
    display(numbers,LEN); //display original array  
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
            insert_r(i,nums+1,len-1,ptr+1);
        }
        else *ptr = i;
    }
}
//with malloc
int *render_sorted(int *nums, int len)
{
    int *res = (int *)malloc(len*sizeof(int));
    if(len==1) *res=*nums;
    else insert_r(*nums, render_sorted(nums+1, len-1), len-1, res);
    return res;
}
void insert_r(int i, int *nums, int len, int *res)
{ // assumes list is already sorted
    if(len==0)*res = i;
    else
    {
        if(i>*nums)
        {
            *res=*nums;
            insert_r(i,nums+1,len-1,res+1);
        }
        else 
        {
            *res = i;
            insert_r(*nums,nums+1,len-1,res+1);
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