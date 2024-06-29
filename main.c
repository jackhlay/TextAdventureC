#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int currentFloor = 0;

void generateMap(tiletype map[HEIGHT][WIDTH]){
	srand(time(NULL));
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			map[y][x] = WALL;
		}
	}
	for (int i=0; i<WIDTH*HEIGHT / 3; i++){
		int x = rand() % WIDTH;
		int y = rand() % HEIGHT;
		map[y][x] = FLOOR;
	}
	currentFloor +=1;
}

void showMap(tiletype map[HEIGHT][WIDTH]){	
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			switch (map[y][x]){
			case EMPTY: printf(". "); break;
			case WALL: printf("# "); break;
			case FLOOR: printf("F "); break;
			case DOOR: printf("D "); break;

			}
		}
		printf("\n");

	}
	printf("\nCURRENT FLOOR: %d! \n",currentFloor);		
}

void initializeGame(tiletype floor[HEIGHT][WIDTH], player *p){	
	system("clear");
	printf("Text Advanture \n\n");	
	generateMap(floor);
	showMap(floor);

	p->pos.x = rand()%WIDTH;
	p->pos.y = rand()%HEIGHT;
	p->health = 100;
	printf("PLAYER POSITION X: %d, Y: %d, HEALTH: %d", p->pos.x,p->pos.y,p->health);
}

int main()
{
	tiletype floor[HEIGHT][WIDTH];
	player p;
	initializeGame(floor, &p);
		return 0; 
}
