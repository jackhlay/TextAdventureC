#ifndef headers_h
#define headers_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"
#include "WFC.h"

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

void initializeGame(void);

#endif
