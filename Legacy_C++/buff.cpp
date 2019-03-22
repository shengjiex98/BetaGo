

#include "alphago.h"
#include "players.h"

static inline bool out(int x, int y)
{
	return x < 0 || y < 0 || x >= 15 || y >= 15;
}

// return the number of the same color pieces.
int buff(int map[15][15], int x, int y, int dir)
{
	if (map[x][y] == 0) {
		return 0;
	}
	int tx = x, ty = y, cnt = 0;
	while (!out(tx, ty) && map[tx][ty] == map[x][y] && cnt < 5) {
		cnt++;
		tx += dx[dir];
		ty += dy[dir];
	}
	return cnt;
}

