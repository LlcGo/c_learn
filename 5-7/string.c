#include <stdio.h>
#include <string.h>

int main() {
	int len1, len2;
	char buffer[] = "25,142,330,Smith,J,239-4123";

	len1 = strspn(buffer, "0123456789");
	len2 = strspn(buffer, ",0123456789");

	printf("  len1为：%d；  len2为：%d", len1, len2);

	getchar();
	return 0;

}

