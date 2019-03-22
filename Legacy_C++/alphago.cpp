

#include "alphago.h"

#include <cstdio>

int map[15][15];

int main()
{
	int x, y, current_PLAYER = PLAYER_1;
	
	while (!judge(map)) {
		
		print_map(map);
		printf("It's %s's turn:\n", current_PLAYER == PLAYER_1 ? "PLAYER_1" : "PLAYER_2");
		
S:		if (current_PLAYER == PLAYER_1) {
			go(map, x, y, PLAYER_1);
			if (map[x][y] != 0) {
				printf("This Position is Invalid!\n");
				goto S;
			}
			map[x][y] = BLACK;
			current_PLAYER = PLAYER_2;
		} else {
			go(map, x, y, PLAYER_2);
			if (map[x][y] != 0) {
				printf("This Position is Invalid!\n");
				goto S;
			}
			map[x][y] = WHITE;
			current_PLAYER = PLAYER_1;
		}

		printf("\n");
	}

	print_map(map);
	printf("Game Over.\n\n");

	int WINNER = judge(map);

	printf("=======================\n\n");
	printf("The Winner is %s!\n\n", WINNER == PLAYER_1 ? "PLAYER_1" : "PLAYER_2");
	printf("=======================\n\n");

	return 0;
}

