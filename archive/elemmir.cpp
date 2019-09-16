

#include "players.h"

#include <cstdio>

static int trans(char c)
{
	if (c >= '0' && c <= '9') {
		return c - '0';
	} else {
		return c - 'A' + 10;
	}
}

void elemmir(int map[][15], int &x, int &y, int COLOR)
{
	char c_1, c_2;
	scanf(" %c %c", &c_1, &c_2);
	x = trans(c_1) - 1;
	y = trans(c_2) - 1;
}
