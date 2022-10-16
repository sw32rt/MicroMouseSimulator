#pragma once

#define MAZE_SIZE 32
#define CELL_TO_COORDINATE(x,y) (Coordinate(x*2, y*2))
#define MAZE_START (CELL_TO_COORDINATE(0,31)) 
#define MAZE_GOAL (CELL_TO_COORDINATE(26,3)) 
