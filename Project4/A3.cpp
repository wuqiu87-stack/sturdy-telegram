#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *p = (char*)malloc(10 * sizeof(char));
	if (p == NULL) {
		fprintf(stderr, "malloc failed\n");
		return 1;
	}

	/* Use safe copy on MSVC, fallback to strncpy elsewhere */
#ifdef _MSC_VER
	strcpy_s(p, 10, "jiehua");
#else
	strncpy(p, "jiehua", 9);
	p[9] = '\0';
#endif

	/* print string with proper newline */
	printf("%s\n", p);

	free(p);
	return 0;
}
