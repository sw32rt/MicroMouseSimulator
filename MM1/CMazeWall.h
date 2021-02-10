#pragma once
#include <vector>
#include "CFloatRect.h"

#define WALL_WIDTH  6.0
#define WALL_LENGTH 84.0
#define CELL_LENGTH (WALL_LENGTH + WALL_WIDTH)

typedef struct stWall
{
	floatRect rect;
	bool yes = false;
}wall_t;

typedef struct stPillar
{
	floatRect rect;
	bool yes;
}pillar_t;

class CMazeWall
{

	CMazeWall() = delete;
public:
	CMazeWall(size_t size);
	~CMazeWall();
	std::vector<std::vector<wall_t>> vWallList; /* 壁リスト */
	std::vector<std::vector<wall_t>> hWallList; /* 壁リスト */
	std::vector<std::vector<pillar_t>> pillarList; /* 柱リスト */
};
