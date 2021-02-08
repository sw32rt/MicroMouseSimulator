#include "pch.h"
#include "CMazeWall.h"
#include "CField.h"

#define WALL_WIDTH  6.0
#define WALL_LENGTH 84.0

CMazeWall::CMazeWall(int size)
{
	vWallList.clear();
	hWallList.clear();
	pillarList.clear();
	vWallList.resize(size + 1);
	hWallList.resize(size);
	pillarList.resize(size + 1);

	for (int x = 0; x < size + 1; x++)
	{ /* ‰¡ */
		floatRect verticalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_LENGTH));
		vWallList[x].resize(size);
		for (int y = 0; y < size; y++)
		{ /* c */
			vWallList[x][y].rect = verticalWallRect + floatPoint((x * (WALL_LENGTH + WALL_WIDTH)) - (WALL_WIDTH / 2.0), (y * (WALL_LENGTH + WALL_WIDTH)) + (WALL_WIDTH / 2.0));
			vWallList[x][y].yes = true;
		}
	}

	for (int x = 0; x < size; x++)
	{ /* ‰¡ */
		floatRect horizontalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_LENGTH, WALL_WIDTH));
		hWallList[x].resize(size + 1);
		for (int y = 0; y < size + 1; y++)
		{ /* c */
			hWallList[x][y].rect = horizontalWallRect + floatPoint((x * (WALL_LENGTH + WALL_WIDTH)) + (WALL_WIDTH / 2.0), (y * (WALL_LENGTH + WALL_WIDTH)) - (WALL_WIDTH / 2.0));
			hWallList[x][y].yes = true;
		}
	}

	for (int x = 0; x < size + 1; x++)
	{ /* ‰¡ */
		floatRect pillarRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_WIDTH));
		pillarList[x].resize(size + 1);
		for (int y = 0; y < size + 1; y++)
		{ /* c */
			pillarList[x][y].rect = pillarRect + floatPoint((x * (WALL_LENGTH + WALL_WIDTH)) - (WALL_WIDTH / 2.0), (y * (WALL_LENGTH + WALL_WIDTH)) - (WALL_WIDTH / 2.0));
			pillarList[x][y].yes = true;
		}
	}
}

CMazeWall::~CMazeWall()
{
}
