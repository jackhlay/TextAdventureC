#ifndef headers_h
#define headers_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

#define WIDTH 10
#define HEIGHT 10
#define FLOORS 10
#define GRIDSIZE 10

typedef enum{
	EMPTY,
	WALL, 
	DOOR,
	TREASURE,
	TRAP,
	MAXTILE
}tileType;

typedef enum{
	UP,
	LEFT,
	RIGHT,
	DOWN
}direction;

typedef struct{
	int x,y;
}position;

typedef struct{
	position pos;
	int health;
}player;

position generateMap(tileType map[HEIGHT][WIDTH]);
void showMap(tileType map[HEIGHT][WIDTH]);
void initializeGame(tileType[HEIGHT][WIDTH], player *p);
position explore(tileType[HEIGHT][WIDTH]);

#endif
