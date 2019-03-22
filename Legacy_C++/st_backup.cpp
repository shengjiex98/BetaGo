

#include "players.h"

#include <cstdio>
#include <cstdlib>

#define REP(i, t) for (int i = 0; i < (t); i++)

const int INF = (int)2e9;

int score[15][15], tx_1, tx_2, ty_1, ty_2;


static inline long long min(long long a, long long b)
{
	return a < b ? a : b;
}

static inline bool out(int x, int y)
{
	return x < 0 || y < 0 || x > 15 || y > 15;
}

static inline int get(int map[15][15], int x, int y)
{
	if (out(x, y)) return -1;
	return map[x][y];
}

static inline void sav_score(int map[15][15], int x, int y, int v)
{
	if (!out(x, y) && map[x][y] == 0) {
		long long tmp = score[x][y] + v;
		score[x][y] = (int)min(tmp, (long long)INF);
	}
}

static inline int extra_score(int x, int y)
{
	return abs(x - 7) + abs(y - 7);
}

int mxs, mne, sx, sy;

static void pre_score()
{
	mxs = 0;
	mne = INF;
	REP(i, 15) REP(j, 15) {
		score[i][j] = 0;
	}
}

static void get_score(int map[15][15])
{
	REP(i, 15) REP(j, 15) {
		/*
		if (map[i][j] == 0) {
			continue;
		}
		*/
		REP(dir, 8) {
			int tmp = buff(map, i, j, dir);
			if (tmp == 4) {
				tx_1 = i - dx[dir]; tx_2 = i + 4 * dx[dir];
				ty_1 = j - dy[dir]; ty_2 = j + 4 * dy[dir];
				sav_score(map, tx_1, ty_1, 10000000);
				sav_score(map, tx_2, ty_2, 10000000);
			} else if (tmp == 3) {
				tx_1 = i - dx[dir]; tx_2 = i + 3 * dx[dir];
				ty_1 = j - dy[dir]; ty_2 = j + 3 * dy[dir];
				int tmp_2 = (get(map, tx_1, ty_1) == 0) + (get(map, tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_score(map, tx_1, ty_1, 1000000);
					sav_score(map, tx_2, ty_2, 1000000);
				} else if (tmp_2 == 1) {
					sav_score(map, tx_1, ty_1, 10000);
					sav_score(map, tx_2, ty_2, 10000);
				}
			} else if (tmp == 2) {
				tx_1 = i - dx[dir]; tx_2 = i + 2 * dx[dir];
				ty_1 = j - dy[dir]; ty_2 = j + 2 * dy[dir];
				int tmp_2 = (get(map, tx_1, ty_1) == 0) + (get(map, tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_score(map, tx_1, ty_1, 10000);
					sav_score(map, tx_2, ty_2, 10000);
				} else if (tmp_2 == 1) {
					sav_score(map, tx_1, ty_1, 1000);
					sav_score(map, tx_2, ty_2, 1000);
				}
			} else if (tmp == 1) {
				tx_1 = i - dx[dir]; tx_2 = i + dx[dir];
				ty_1 = j - dy[dir]; ty_2 = j + dy[dir];
				int tmp_2 = (get(map, tx_1, ty_1) == 0) + (get(map, tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_score(map, tx_1, ty_1, 1000);
					sav_score(map, tx_2, ty_2, 1000);
				} else if (tmp_2 == 1) {
					sav_score(map, tx_1, ty_1, 100);
					sav_score(map, tx_2, ty_2, 100);
				}
			}
		}
		if (score[i][j] > mxs || (score[i][j] == mxs && extra_score(i, j) < mne)) {
			mxs = score[i][j];
			mne = extra_score(i, j);
			sx = i;
			sy = j;
		}
	}
}

static void print_score(int map[15][15]);

void st(int map[15][15], int &x, int &y)
{
	pre_score();
	get_score(map);
	x = sx;
	y = sy;
//	print_score(map);
}


static void print_score(int map[15][15])
{
	printf("\n--- print_score ---\n");
	printf("  ");
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
			if (map[i][j] != 0) {
				printf(" ");
			} else printf("%d", score[i][j]);
			printf(" ");
		}
		if (map[i][14] != 0) {
			printf(" ");
		} else printf("%d", score[i][14]);
		printf("\n");
	}
	printf("\n");
	printf("--- print end -----\n\n");
}
