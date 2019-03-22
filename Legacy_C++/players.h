

#ifndef PLAYERS_H_
#define PLAYERS_H_

#define PLAYER_st PLAYER_2
#define PLAYER_el PLAYER_1

#ifndef PLAYER_1

#define PLAYER_1 1
#define PLAYER_2 2

#define BLACK PLAYER_1
#define WHITE PLAYER_2

#endif

/*
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
*/

const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

// The AI of st
void st(int[15][15], int &, int &, int);

// The AI of Elemmir
void elemmir(int[15][15], int &, int &, int);

#endif
