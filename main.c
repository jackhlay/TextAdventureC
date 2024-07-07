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
	position posit = generateMap(floor);
	showMap(floor);

	p->pos.x = posit.x;
	p->pos.y = posit.y;
	p->health = 100;
	printf("PLAYER POSITION X: %d, Y: %d, HEALTH: %d\n", p->pos.x,p->pos.y,p->health);
}

position explore(tiletype floor[HEIGHT][WIDTH])
{
	position posi;
	posi.x = rand() % HEIGHT;
	posi.y = rand() % WIDTH;
	printf("starting x: %d. starting y: %d\n", posi.x, posi.y);
	
	node* greaterStack = NULL;
	int rooms = 0;
	int startx = posi.x;
	int starty =  posi.y;
	floor[startx][starty] = FLOOR;
	
	while(rooms < 30)
	{
		printf("CURRENT X:%d. Y:%d\n", startx, starty);
		node* lesserStack = NULL;
		
		if(starty+1 < WIDTH){ push(&lesserStack, 0); }
		if(startx-1 >= 0){ push(&lesserStack, 1); }
		if(startx+1 < HEIGHT){ push(&lesserStack, 2); }
		if(starty-1 >= 0){ push(&lesserStack, 3); }
		
		int len = stackLength(lesserStack);
		if(len>0)
		{
			int* directions = (int*)malloc(len * sizeof(int));
			if (directions == NULL) {
				printf("Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}

			for(int i= 0; i<len; i++){
				directions[i] = pop(&lesserStack);
			}

			int chosenDir = directions[rand() % len];
			free(directions);

			switch(chosenDir){
				case 0: starty +=1;break;//up
				case 1: startx -=1;break;//left
				case 2: startx +=1;break;//right
				case 3: starty -=1;break;//down
			}

			if(startx < 0 || startx >= HEIGHT || starty<0 || starty > WIDTH){
				printf("OUT OF BOUNDS: x=%d. y=%d\n",startx, starty);
				continue;
			}

			printf("MOVING TO x;%d, y:%d MOVES: %d\n\n", startx, starty, rooms);

			push(&greaterStack, chosenDir);
			floor[startx][starty] = FLOOR;
			rooms++;

		} else{
			rooms++;
			continue;
		}
			
	}
	
	//printf("Freeing the stack\n")
	while(!isEmpty(&greaterStack))
	{	
		if(&greaterStack == NULL){break;}

		//printf("CURRENT STACK: %s", stackPrint(&greaterStack));
		int i = pop(&greaterStack);
	}

	return posi;

}

int main()
{
	tiletype floor[HEIGHT][WIDTH];
	player p;
	initializeGame(floor, &p);

	//node* stack = NULL;
	//push(&stack, 10);
	//push(&stack, 20);
	//push(&stack, 30);

	//printf("\nstack length: %d\n", stackLength(stack));
	//stackPrint(&stack);

	//printf("POPPED VAL: %d\n", pop(&stack));
	//stackPrint(&stack);
		return 0; 
}
