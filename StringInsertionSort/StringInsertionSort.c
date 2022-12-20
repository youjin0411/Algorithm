#include <stdio.h>
#include <string.h>

int main(void) {
	char* str[5] = { "structure", "information", "technology", "science", "communication" };
	int i, j, n = sizeof(str) / sizeof(char*);

	for (i = 1; i < n; i++) {
		char* key = str[i];
		for (j = i - 1; j >= 0; j--) {
			if (strcmp(key, str[j]) >= 0)break;
			else str[j + 1] = str[j];
		}
		str[j + 1] = key;
	}

	for (i = 0; i < n; i++)printf("%s\n", str[i]);

	return 0;
}