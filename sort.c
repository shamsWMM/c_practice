#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 10
void bsort(int *nums, int len);
int *sort(int *nums, int len); // modifies original array
int *render_sorted(int *nums, int len); // does not modify original array
void insert(int i, int *nums, int len);
void r_insert(int i, int *nums, int len, int *ptr);
void display(int *nums, int len);

int main()
{
    clock_t tic, toc, tec;
    int variable_len;
    for(variable_len=60000;variable_len<70000;variable_len+=1000)
    {
    // generate array to be sorted
    int numbers[variable_len];
    int nombres[variable_len];

	srand((unsigned)time(NULL)); 
    int i;
	for(i=0;i<variable_len;i++)
    {
        int j = rand() % 100 + 1;
        numbers[i] = j;
        nombres[i] = j;
    }  
    //display array
    //display(numbers, variable_len);
    
    //int *nums; // for the result of render_sorted()
    //nums = render_sorted(numbers,LEN);
    //display(nums,LEN);
    //display(numbers, variable_len); //dsiplay original array to show it has not changed
    
    tic = clock();
    sort(numbers,variable_len); //sort original array
    toc = clock();
    bsort(nombres,variable_len);
    tec = clock();
    printf("%d - sort: %f seconds\t bsort: %f\n", variable_len, (double)(toc - tic) / CLOCKS_PER_SEC, (double)(tec - toc) / CLOCKS_PER_SEC);
    }
    return(0);

}

int *sort(int *nums, int len)
// assume len is at least 1
{
    if(len==1) return(nums); //array contains only one integer
    insert(
        *nums, //separate the first number from the rest and use it in insert()
        sort(nums+1, len-1), //use the result of the recursion on the rest in insert()
        len-1        
        );
    return nums;
}

void insert(int i, int *nums, int len)
{ // assumes list is already sorted
    if(len==0)*(nums-1) = i;
    else
    {
        if(i>*nums) //number to be inserted is larger than first number
        {
            *(nums-1)=*nums;
            insert(i,nums+1,len-1); //use insert on the number and the rest of the array
        }
        else *(nums-1) = i; //number to be inserted is smaller than first number in the array
    }
}
//with malloc
int *render_sorted(int *nums, int len)
{
    int *res = (int *)malloc(len*sizeof(int));
    if(len==1) *res=*nums;
    else r_insert(*nums, render_sorted(nums+1, len-1), len-1, res);
    return res;
}
void r_insert(int i, int *nums, int len, int *res)
{ // assumes list is already sorted
    if(len==0)*res = i;
    else
    {
        if(i>*nums)
        {
            *res=*nums;
            r_insert(i,nums+1,len-1,res+1);
        }
        else 
        {
            *res = i;
            r_insert(*nums,nums+1,len-1,res+1); // sets the values in the allocated space
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