#pragma once
#include <vector>
#include "CFloatRect.h"

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
	std::vector<std::vector<wall_t>> vWallList; /* �ǃ��X�g */
	std::vector<std::vector<wall_t>> hWallList; /* �ǃ��X�g */
	std::vector<std::vector<pillar_t>> pillarList; /* �����X�g */
};
