#include "headers.h"

int currentFloor = 0;

position generateMap(tiletype map[HEIGHT][WIDTH]){
	srand(time(NULL));
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			map[y][x] = WALL;
		}
	}
	position pos = explore(map);
	currentFloor +=1;
	return pos;
}

void showMap(tiletype map[HEIGHT][WIDTH]){	
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			switch (map[y][x]){
			case EMPTY: printf(". "); break;
			case WALL: printf("# "); break;
			case FLOOR: printf("F "); break;
			case DOOR: printf("D "); break;
			case PLAYER: printf("P "); break;

			}
		}
		printf("\n");

	}
	printf("\nCURRENT FLOOR: %d! \n",currentFloor);		
}

void initializeGame(tiletype floor[HEIGHT][WIDTH], player *p){	
	system("clear");
	printf("Text Advanture \n\n");	
	position posi = generateMap(floor);
	floor[posi.x][posi.y] = PLAYER;
	showMap(floor);

	p->pos.x = posi.x;
	p->pos.y = posi.y;
	p->health = 100;
	printf("PLAYER POSITION X: %d, Y: %d, HEALTH: %d", p->pos.x,p->pos.y,p->health);
}

position explore(tiletype floor[HEIGHT][WIDTH])
{
	position posi;
	posi.x = rand() % HEIGHT;
	posi.y = rand() % WIDTH;
	printf("starting x: %d. starting y: %d\n", posi.x, posi.y);

	return posi;

}

int main()
{
	tiletype floor[HEIGHT][WIDTH];
	player p;
	initializeGame(floor, &p);
		return 0; 
}
