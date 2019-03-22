#include "players.h"

#include <cstdio>
#include <cstdlib>

#define REP(i, t) for (int i = 0; i < (t); i++)

const int INF = (int)2e9;

int score[15][15], score_2[15][15], tx_1, tx_2, ty_1, ty_2;

int COLOR_MY, MAP[15][15];

static inline long long lmin(long long a, long long b)
{
	return a < b ? a : b;
}

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

static inline bool out(int x, int y)
{
	return x < 0 || y < 0 || x > 15 || y > 15;
}

static inline int get(int x, int y)
{
	if (out(x, y)) return -1;
	return MAP[x][y];
}

static inline void sav_score(int x, int y, int v, bool k)
{
	if (!out(x, y) && MAP[x][y] == 0) {
		score[x][y] += k ? 2 * v : v;
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

static int buff(int x, int y, int dir)
{
	if (MAP[x][y] == 0) {
		return 0;
	}
	int tx = x, ty = y, cnt = 0;
	while (!out(tx, ty) && MAP[tx][ty] == MAP[x][y] && cnt < 5) {
		cnt++;
		tx += dx[dir];
		ty += dy[dir];
	}
	return cnt;
}

static void set_tmp(int len, int x, int y, int dir)
{
	tx_1 = x - dx[dir]; tx_2 = x + len * dx[dir];
	ty_1 = y - dy[dir]; ty_2 = y + len * dy[dir];
}

static void sav_scr(int scr, bool k)
{
	sav_score(tx_1, ty_1, scr, k);
	sav_score(tx_2, ty_2, scr, k);
}

const int level[7] = {(int)1e8, (int)1e6, (int)1e4, (int)1e3, (int)1e2, (int)1e1, 1};

static void get_score()
{
	REP(i, 15) REP(j, 15) {
		REP(dir, 8) {
			int tmp = buff(i, j, dir);
			if (tmp == 4) {
				set_tmp(4, i, j, dir);
				sav_scr(level[0], MAP[i][j] == COLOR_MY);
			} else if (tmp == 3) {
				set_tmp(3, i, j, dir);
				int tmp_2 = (get(tx_1, ty_1) == 0) + (get(tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_scr(level[1], MAP[i][j] == COLOR_MY);
				} else if (tmp_2 == 1) {
					sav_scr(level[2], MAP[i][j] == COLOR_MY);
				}
			} else if (tmp == 2) {
				set_tmp(2, i, j, dir);
				int tmp_2 = (get(tx_1, ty_1) == 0) + (get(tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_scr(level[2], MAP[i][j] == COLOR_MY);
				} else if (tmp_2 == 1) {
					sav_scr(level[3], MAP[i][j] == COLOR_MY);
				}
			} else if (tmp == 1) {
				set_tmp(1, i, j, dir);
				int tmp_2 = (get(tx_1, ty_1) == 0) + (get(tx_2, ty_2) == 0);
				if (tmp_2 == 2) {
					sav_scr(level[3], MAP[i][j] == COLOR_MY);
				} else if (tmp_2 == 1) {
					sav_scr(level[4], MAP[i][j] == COLOR_MY);
				}
			}
		}
	}
	REP(i, 15) REP(j, 15) {
		if (MAP[i][j] != 0) {
			continue;
		}
		REP(dir, 4) {
			set_tmp(1, i, j, dir);
			if (out(tx_1, ty_1) || out(tx_2, ty_2)) {
				continue;
			}
			if (MAP[tx_1][ty_1] != MAP[tx_2][ty_2]) {
				continue;
			}
			int tmp_1 = buff(tx_1, ty_1, dir + 4);
			int tmp_2 = buff(tx_2, ty_2, dir);
			if (tmp_1 + tmp_2 >= 4) {
				score_2[i][j] += MAP[tx_1][tx_2] == COLOR_MY ? 2 * level[0] : level[0];
			} else if (tmp_1 + tmp_2 == 3) {
				score_2[i][j] += MAP[tx_1][tx_2] == COLOR_MY ? 2 * level[1] : level[1];
			} else if (tmp_1 + tmp_2 == 2) {
				score_2[i][j] += MAP[tx_1][tx_2] == COLOR_MY ? 2 * level[2] : level[2];
			}
		}
	}
}

void cal_score()
{
	REP(i, 15) REP(j, 15) {
		if (MAP[i][j] != 0) {
			continue;
		}
		score[i][j] = max(score[i][j], score_2[i][j]);
		if (score[i][j] > mxs || (score[i][j] == mxs && extra_score(i, j) < mne)) {
			mxs = score[i][j];
			mne = extra_score(i, j);
			sx = i;
			sy = j;
		}
	}
}

void st(int map[][15], int &x, int &y, int COLOR)
{
	REP(i, 15) REP(j, 15) {
		MAP[i][j] = map[i][j];
	}
	COLOR_MY = COLOR;
	pre_score();
	get_score();
	cal_score();
	x = sx;
	y = sy;
	printf("%c %c\n", x > 8 ? 'A' + x - 9 : '1' + x, y > 8 ? 'A' + y - 9 : '1' + y);
}
