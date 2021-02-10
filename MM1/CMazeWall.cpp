#include "pch.h"
#include "CMazeWall.h"
#include "CField.h"

CMazeWall::CMazeWall(size_t size)
{
	/* íPà ÇÕmm ãÊâÊ90mm, ï«å˙Ç≥6mm ê≥ï˚å`Ç»ÇÃÇ≈xÇ∆yìØÇ∂ */
	floatPoint centerZeroOffset( (CELL_LENGTH * size) / 2.0, (CELL_LENGTH * size) / 2.0);

	vWallList.clear();
	hWallList.clear();
	pillarList.clear();
	vWallList.resize(size + 1);
	hWallList.resize(size);
	pillarList.resize(size + 1);

	for (int x = 0; x < size; x++)
	{ /* â° */
		floatRect horizontalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_LENGTH, WALL_WIDTH)) - centerZeroOffset;
		hWallList[x].resize(size + 1);
		for (int y = 0; y < size + 1; y++)
		{ /* èc */
			hWallList[x][y].rect = horizontalWallRect + floatPoint((x * CELL_LENGTH) + (WALL_WIDTH / 2.0), (y * CELL_LENGTH) - (WALL_WIDTH / 2.0));
			hWallList[x][y].yes = true;
		}
	}

	for (int x = 0; x < size + 1; x++)
	{ /* â° */
		floatRect verticalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_LENGTH)) - centerZeroOffset;
		vWallList[x].resize(size);
		for (int y = 0; y < size; y++)
		{ /* èc */
			vWallList[x][y].rect = verticalWallRect + floatPoint((x * CELL_LENGTH) - (WALL_WIDTH / 2.0), (y * CELL_LENGTH) + (WALL_WIDTH / 2.0));
			vWallList[x][y].yes = true;
		}
	}

	for (int x = 0; x < size + 1; x++)
	{ /* â° */
		floatRect pillarRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_WIDTH)) - centerZeroOffset;
		pillarList[x].resize(size + 1);
		for (int y = 0; y < size + 1; y++)
		{ /* èc */
			pillarList[x][y].rect = pillarRect + floatPoint((x * CELL_LENGTH) - (WALL_WIDTH / 2.0), (y * CELL_LENGTH) - (WALL_WIDTH / 2.0));
			pillarList[x][y].yes = true;
		}
	}
}


CMazeWall::~CMazeWall()
{
}
