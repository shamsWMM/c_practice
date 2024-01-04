#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
	char name[32];
	int age;
};

struct person *allocateStruct(void);
void fetchStruct(struct person *p, char *name, int age);
void showStruct(struct person *p);

int main()
{
    char name[32];
    int age;
    printf("Enter your name: ");
    fgets(name, 64, stdin);
    printf("Enter your age: ");
    scanf("%d",&age);

    struct person *p = allocateStruct();
    fetchStruct(p, name, age);
    showStruct(p);
}
struct person *allocateStruct(void)
{
	struct person *p;

	p = (struct person *)malloc(sizeof(struct person));
	if( p == NULL)
	{
		perror("Unable to allocate structure");
		exit(1);
	}
	return(p);
}
void showStruct(struct person *p)
{
	printf("Your name is %s.\n", p->name);
	printf("Your age is %d.\n", p->age);
}
void fetchStruct(struct person *p, char *name, int age)
{
    char n[32];
    if(strlen(name))
    {
        strncpy(n,name,strlen(name)-1);
        n[strlen(name)-1] = '\0';
        strcpy(p->name,n);
    }
	p->age = age;
}