#ifndef headers_h
#define headers_h

#define WIDTH 19
#define HEIGHT 10
#define FLOORS 10

typedef enum{
	EMPTY,
	WALL,
	FLOOR,
	DOOR
}tiletype;

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

void generateMap(tiletype map[HEIGHT][WIDTH]);
void showMap(tiletype map[HEIGHT][WIDTH]);
void initializeGame(tiletype[HEIGHT][WIDTH], player *p);

#endif
