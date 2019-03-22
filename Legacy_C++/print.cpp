

#include "alphago.h"

#include <cstdio>

void print_map(int map[15][15])
{
	printf("& ");
	for (int i = 0; i < 14; i++) {
		if (i + 1 > 9) {
			printf("%c ", 'A' + i - 9);
		} else {
			printf("%d ", i + 1);
		}
	}
	printf("F\n");
	
	for (int i = 0; i < 15; i++) {
		if (i + 1 > 9) {
			printf("%c ", 'A' + i - 9);
		} else {
			printf("%d ", i + 1);
		}
		for (int j = 0; j < 14; j++) {
			printf("%c ", map[i][j] == 0 ? ' ' : map[i][j] == 1 ? 'X' : 'O');
		}
		printf("%c\n", map[i][14] == 0 ? ' ' : map[i][14] == 1 ? 'X' : 'O');
	}
//	printf("\n");
}
