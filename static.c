#include <stdio.h>
// Note how f retains the value of static variable x below but g does not
void f(void)
{
    // declaration and initialization in the same statement
	static int x = 0;
	printf("Value of x is %d\n",x);
	x++;
}
void g(void)
{
    // declaration and initialization done separately
	static int x;
    x = 0;
	printf("Value of x is %d\n",x);
	x++;
}

int main()
{
    puts("Initialization done with declaration:");
	f();
	f();
    puts("Initialization done separately:");
	g();
    g();
	return(0);
}

