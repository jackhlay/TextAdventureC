#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define FLOORS 10

typedef enum{	
	EMPTY, WALL, FLOOR, DOOR

} tiletype;

void generateMap(tiletype map[HEIGHT][WIDTH]){
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			map[y][x] = WALL;
		}
	}
	for (int i=0; i<WIDTH*HEIGHT / 3; i++){
		int x = rand() % WIDTH;
		int y = rand() % HEIGHT;
		map[x][y] = FLOOR;
	}
}

void showMap(tiletype map[HEIGHT][WIDTH]){
	for(int y=0; y<HEIGHT; y++){
		for(int x=0; x<WIDTH; x++){
			switch (map[x][y]){
			case EMPTY: printf(". "); break;
			case WALL: printf("# "); break;
			case FLOOR: printf("F "); break;
			case DOOR: printf("D "); break;

			}
		}
		printf("\n");

	}
}

int main()
{

	printf("Text Advanture \n");
	tiletype floor[HEIGHT][WIDTH];
	generateMap(floor);
	showMap(floor);

	return 0; 

}

