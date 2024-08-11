#include "headers.h"

void initializeGame(){	
	system("clear");
	printf("Text Advanture \n\n");
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
