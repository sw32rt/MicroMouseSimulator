#include "pch.h"
#include "CMazeWall.h"
#include "CField.h"

CMazeWall::CMazeWall(size_t size)
{
	/* �P�ʂ�mm ���90mm, �ǌ���6mm �����`�Ȃ̂�x��y���� */
	floatPoint centerZeroOffset( (CELL_LENGTH * size) / 2.0, (CELL_LENGTH * size) / 2.0);

	hWallList.clear();
	vWallList.clear();
	pillarList.clear();
	hWallList.resize(size + 1);
	vWallList.resize(size);
	pillarList.resize(size + 1);

	for (int y = 0; y < size + 1; y++)
	{ /* �c */
		floatRect horizontalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_LENGTH, WALL_WIDTH)) - centerZeroOffset;
		hWallList[y].resize(size);
		for (int x = 0; x < size; x++)
		{ /* �� */
			hWallList[y][x].rect = horizontalWallRect + floatPoint((x * CELL_LENGTH) + (WALL_WIDTH / 2.0), (y * CELL_LENGTH) - (WALL_WIDTH / 2.0));
			hWallList[y][x].yes = true;
		}
	}

	for (int y = 0; y < size; y++)
	{ /* �c */
		floatRect verticalWallRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_LENGTH)) - centerZeroOffset;
		vWallList[y].resize(size + 1);
		for (int x = 0; x < size + 1; x++)
		{ /* �� */
			vWallList[y][x].rect = verticalWallRect + floatPoint((x * CELL_LENGTH) - (WALL_WIDTH / 2.0), (y * CELL_LENGTH) + (WALL_WIDTH / 2.0));
			vWallList[y][x].yes = true;
		}
	}

	for (int y = 0; y < size + 1; y++)
	{ /* �c */
		floatRect pillarRect = floatRect(floatPoint(0, 0), floatPoint(WALL_WIDTH, WALL_WIDTH)) - centerZeroOffset;
		pillarList[y].resize(size + 1);
		for (int x = 0; x < size + 1; x++)
		{ /* �� */
			pillarList[y][x].rect = pillarRect + floatPoint((x * CELL_LENGTH) - (WALL_WIDTH / 2.0), (y * CELL_LENGTH) - (WALL_WIDTH / 2.0));
			pillarList[y][x].yes = true;
		}
	}
}


CMazeWall::~CMazeWall()
{
}
