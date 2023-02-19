#include  <cstdio>

typedef int(*PF)(int, int); //定义一个函数指针

int reduce(int a, int b)
{
	return a - b;
}

int *func1(int a, int b); //声明一个指针函数
int (*func2)(int a, int b);// 声明一个函数指针



int add(int a, int b)
{
	return a + b;
}


int main()
{
	PF pfunc = NULL;
	pfunc = add;
	printf("add:%d\n", pfunc(3, 4));
	pfunc = reduce;
	printf("reduce:%d\n", pfunc(3, 4));
	/*getchar是用VS编写方便查看输出*/
	getchar();
	return 0;
}