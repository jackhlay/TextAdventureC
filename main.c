#include "headers.h"

void initializeGame(){	
	system("clear");
	printf("Text Advanture \n\n");
	srand(time(NULL));
	init_Grid();
	WFC();
	printGrid();
}

int main()
{
	player p;
	initializeGame();
		return 0; 
}
