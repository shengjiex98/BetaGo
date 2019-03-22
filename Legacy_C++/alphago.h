

#ifndef ALPHAGO_H_
#define ALPHAGO_H_


#define BLACK 1
#define WHITE 2

#define PLAYER_1 BLACK
#define PLAYER_2 WHITE

// return the winner code
int judge(int map[15][15]);

// reset the random seed
void reset_rand_seed();

// make the move (by reference)
void go(int map[15][15], int &x, int &y, int PLAYER);

// return the number of the same color in a line
int buff(int map[15][15], int x, int y, int dir);

// print the map
void print_map(int map[15][15]);

#endif
