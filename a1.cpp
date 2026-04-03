#include<stdio.h>
#include<windows.h>
void fun(int *a,int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	SetConsoleOutputCP(CP_UTF8);//system("chcp 65001");不可用SetConsoleCP(CP_UTF8);还是有乱码
	int x, y;
	printf("请输入两个整数：");
	scanf_s("%d%d", &x, &y);
	fun(&x, &y);
	printf("交换后的结果是：%d %d\n", x, y);
	return 0;
}