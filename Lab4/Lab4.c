#include <stdio.h>
#define SIZE 200

int main(){

	char *line = malloc(sizeof(char) * SIZE);
	fgets(line,100,stdin);

	free(line);
}
