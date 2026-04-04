/*
 * A3.c
 * 简单示例：为字符串分配空间并拷贝文字后输出
 * 已做的改进：
 *  - 检查 malloc 返回值以避免空指针解引用
 *  - 在 MSVC 上使用 strcpy_s，其他编译器上使用 strncpy 并确保以 '\0' 终止
 *  - 使用正确的 printf 格式化输出并添加换行
 *  - 在结束前释放分配的内存
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	/* 为字符串分配 10 字节空间（包含终止符） */
	char *p = (char*)malloc(10 * sizeof(char));
	if (p == NULL) {
		/* malloc 失败时打印错误并退出 */
		fprintf(stderr, "malloc failed\n");
		return 1;
	}

	/*
	 * 拷贝字符串到分配的缓冲区：
	 * - 在 MSVC 上使用更安全的 strcpy_s，避免缓冲区溢出
	 * - 在其他编译器上使用 strncpy，并确保最后一位为 '\0'
	 */
#ifdef _MSC_VER
	strcpy_s(p, 10, "jiehua");
#else
	strncpy(p, "jiehua", 9);
	p[9] = '\0'; /* 确保以空字符结束 */
#endif

	/* 使用 %s 输出字符串并换行 */
	printf("%s\n", p);

	/* 释放动态分配的内存以避免内存泄漏 */
	free(p);
	return 0;
}
