

#include "alphago.h"

int judge(int map[15][15])
{
	int ans = 0;
	for (int dir = 0; dir < 8; dir++)
		for (int i = 0; i < 15; i++)
			for (int j = 0; j < 15; j++) {
				int counter = buff(map, i, j, dir);
				if (counter == 5) {
					ans = map[i][j];
					break;
				}
			}
	
	return ans;
}

