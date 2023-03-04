/*
		"pass by value" and "pass by reference".

		
	In C programming language, when you pass a struct to a function, you can pass it by value or by reference. The difference between passing a struct by value and by reference is in how the struct is accessed and modified within the function.

When you pass a struct by value, a copy of the entire struct is made and passed to the function. This means that any changes made to the struct within the function will only affect the copy of the struct, not the original struct passed to the function. This approach is useful when you want to manipulate the data of the struct within the function without affecting the original struct outside of the function.

On the other hand, when you pass a struct by reference, you pass a pointer to the struct. This means that the function can access and modify the original struct directly, rather than making a copy of it. Any changes made to the struct within the function will affect the original struct outside of the function. This approach is useful when you want to modify the contents of the struct or when you want to avoid the overhead of copying large structs.
*/

#include <stdio.h>
#include <unistd.h>
                                                   

struct test
{
	int i;
};

void pass_by_value(struct test a)
{
	a.i = 17;
	// printf("-------------by value = %d\n", a.i);
}

void pass_by_reference(struct test *a)
{
	a->i = 999999999;
	// printf("------------by reference = %d\n", a->i);
}

int main ()
{
	struct test a = {1};
	printf(" %d\n", a.i);
	
	// pass_by_value(a);
	// printf(" %d\n", a.i);

	// pass_by_reference(&a);
	// printf(" %d\n", a.i);


	 a.i = 536;
	printf(" %d\n", a.i);

	struct test *p;
	p = &a;
	p->i = 53635;
	printf(" %d\n", p->i);


}





/* What is you changer the function name *?????


struct example
{
	int i;
};
void ft_1(struct example x)
{
	x.i  = 1;
	printf("--- inside %d\n", x.i);

}

void ft_2(struct example y)
{
	y.i = 2;
	printf("--- inside %d\n", y.i);

}

int main ()
{
	struct example x;
	x.i = 9;
	ft_1(x);
	printf("%d\n", x.i);
	ft_2(x);
	printf("%d\n", x.i);
}

/*