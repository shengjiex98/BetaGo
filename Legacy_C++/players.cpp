

#include "alphago.h"
#include "players.h"

#include <cstdlib>
#include <ctime>

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

/*
static inline int get_rand()
{
	int tmp = rand() * rand() % 15;
	return max(tmp, -tmp);
}
*/

void reset_rand_seed()
{
	srand(time(0));
}

void go(int map[15][15], int &x, int &y, int PLAYER)
{
	if (PLAYER == PLAYER_st) {
		st(map, x, y, PLAYER_st);
	} else {
		elemmir(map, x, y, PLAYER_el);
	}
}

