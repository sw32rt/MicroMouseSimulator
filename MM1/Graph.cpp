#include "pch.h"
#include "Graph.h"
#include "CMazeWall.h"

WallStatus g_Nothing = WallStatus::E_KS_OutSide;
Vertex g_NothingVertex = Vertex();

static const MazeWall g_AnswewrMazeData[MAZE_SIZE][MAZE_SIZE] =
#if 1
{
	{ { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0},  },
	{ { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 0,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0},  },
	{ { 0,  0}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1},  },
	{ { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 0,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0},  },
	{ { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0},  },
	{ { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0},  },
	{ { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0},  },
	{ { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0},  },
	{ { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1},  },
};
#else

{ // 3 x 3 test
	{ {0, 0}, { 0, 0 }, { 0, 0 }, },
	{ {1, 0}, { 0, 0 }, { 0, 0 }, },
	{ {0, 0}, { 0, 0 }, { 0, 0 }, },
};
#endif

Vertex::Vertex()
	: mazeCoordinate(0, 0)
	, displayPoint(0, 0)
	, Wall_North(g_Nothing)
	, Wall_East(g_Nothing)
	, Wall_West(g_Nothing)
	, Wall_South(g_Nothing)
	, pVertex_North(this)
	, pVertex_East(this)
	, pVertex_West(this)
	, pVertex_South(this)
	, pVertex_NorthEast(nullptr)
	, pVertex_EastSouth(nullptr)
	, pVertex_WestNorth(nullptr)
	, pVertex_SouthWest(nullptr)
	, pSearchFromVertexIndex(-1, -1)
	, pSupposeSearchFromVertexIndex(-1, -1)
{
}

Vertex::Vertex(CPoint dispPoint, Coordinate mazeCoordinate, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS)
	: mazeCoordinate(mazeCoordinate)
	, displayPoint(dispPoint)
	, Wall_North(WN)
	, Wall_East(WE)
	, Wall_West(WW)
	, Wall_South(WS)
	, pVertex_North(nullptr)
	, pVertex_East(nullptr)
	, pVertex_West(nullptr)
	, pVertex_South(nullptr)
	, pVertex_NorthEast(nullptr)
	, pVertex_EastSouth(nullptr)
	, pVertex_WestNorth(nullptr)
	, pVertex_SouthWest(nullptr)
	, pSearchFromVertexIndex(-1, -1)
	, pSupposeSearchFromVertexIndex(-1, -1)
{
}

Vertex::Vertex(CPoint dispPoint, Coordinate mazeCoordinate, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS, WallStatus& WNE, WallStatus WES, WallStatus& WWN, WallStatus WSW)
	: mazeCoordinate(mazeCoordinate)
	, displayPoint(dispPoint)
	, Wall_North(WN)
	, Wall_East(WE)
	, Wall_West(WW)
	, Wall_South(WS)
	, pVertex_North(nullptr)
	, pVertex_East(nullptr)
	, pVertex_West(nullptr)
	, pVertex_South(nullptr)
	, pVertex_NorthEast(nullptr)
	, pVertex_EastSouth(nullptr)
	, pVertex_WestNorth(nullptr)
	, pVertex_SouthWest(nullptr)
	, pSearchFromVertexIndex(-1, -1)
	, pSupposeSearchFromVertexIndex(-1, -1)
{

}

void Vertex::SetReferVertex_N(Vertex* VN)
{
	pVertex_North = VN;
}
void Vertex::SetReferVertex_E(Vertex* VE)
{
	pVertex_East = VE;
}

void Vertex::SetReferVertex_W(Vertex* VW)
{
	pVertex_West = VW;
}

void Vertex::SetReferVertex_S(Vertex* VS)
{
	pVertex_South = VS;
}

void Vertex::SetReferVertex_NE(Vertex* VNE)
{
	pVertex_NorthEast = VNE;
}
void Vertex::SetReferVertex_ES(Vertex* VES)
{
	pVertex_EastSouth = VES;
}

void Vertex::SetReferVertex_WN(Vertex* VWN)
{
	pVertex_WestNorth = VWN;
}

void Vertex::SetReferVertex_SW(Vertex* VSW)
{
	pVertex_SouthWest = VSW;
}


Vertex* Vertex::GetVertex_North(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_North != nullptr ? pVertex_North : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_East(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_East != nullptr ? pVertex_East : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_West(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_West != nullptr ? pVertex_West : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_South(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_South != nullptr ? pVertex_South : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_NorthEast(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_NorthEast != nullptr ? pVertex_NorthEast : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_EastSouth(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_EastSouth != nullptr ? pVertex_EastSouth : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_WestNorth(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_WestNorth != nullptr ? pVertex_WestNorth : &g_NothingVertex);
}

Vertex* Vertex::GetVertex_SouthWest(void)
{
	// TODO: return ステートメントをここに挿入します
	return (pVertex_SouthWest != nullptr ? pVertex_SouthWest : &g_NothingVertex);
}

WallStatus Vertex::GetWall_North(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = Wall_North;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_South()->GetWall_North();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_East(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = Wall_East;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_West()->GetWall_East();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_West(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = Wall_West;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_East()->GetWall_West();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_South(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = Wall_South;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_North()->GetWall_South();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_NorthEast(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_East()->GetWall_North();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_North()->GetWall_East();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_EastSouth(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_East()->GetWall_South();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_South()->GetWall_East();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_SouthWest(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_West()->GetWall_South();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_South()->GetWall_West();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

WallStatus Vertex::GetWall_WestNorth(void)
{
	WallStatus ret = WallStatus::E_KS_OutSide;
	int x = mazeCoordinate.x;
	int y = mazeCoordinate.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		ret = this->GetVertex_West()->GetWall_North();
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		ret = this->GetVertex_North()->GetWall_West();
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
		ret = WallStatus::E_KS_OutSide;
	}
	return ret;
}

void Vertex::SetWall_North(WallStatus ws)
{
	Wall_North = ws;
}

void Vertex::SetWall_East(WallStatus ws)
{
	Wall_East = ws;
}

void Vertex::SetWall_West(WallStatus ws)
{
	Wall_West = ws;
}

void Vertex::SetWall_South(WallStatus ws)
{
	Wall_South = ws;
}

Vertex::operator CPoint()
{
	return displayPoint;
}

Vertex::operator Coordinate()
{
	return mazeCoordinate;
}

Graph::Graph()
{
	CreateMap(vlist);
	CreateMap(vAnswer);
	SetAnswer(vAnswer);
}

Graph::~Graph()
{
}

void Graph::Initialize(void)
{
}

int Graph::WallCheck(Coordinate VertexIndex)
{
	int x = VertexIndex.x;
	int y = VertexIndex.y;
	int IsOdd_x = x % 2;
	int IsOdd_y = y % 2;

	if ((IsOdd_x == 0) && (IsOdd_y == 0))
	{
		vlist[y][x].SetWall_North( (vlist[y][x].GetWall_North()== WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x].GetWall_North()) );
		vlist[y][x].SetWall_South( (vlist[y][x].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x].GetWall_South()) );
		vlist[y][x].SetWall_East( (vlist[y][x].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x].GetWall_East()) );
		vlist[y][x].SetWall_West( (vlist[y][x].GetWall_West() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x].GetWall_West()) );
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 0))
	{
		vlist[y][x + 1].SetWall_North( (vlist[y][x + 1].GetWall_North() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x + 1].GetWall_North()) );
		vlist[y][x + 1].SetWall_South( (vlist[y][x + 1].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x + 1].GetWall_South()) );
		vlist[y][x + 1].SetWall_East( (vlist[y][x + 1].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x + 1].GetWall_East()) );
		vlist[y][x + 1].SetWall_West( (vlist[y][x + 1].GetWall_West() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x + 1].GetWall_West()) );
		vlist[y][x - 1].SetWall_North( (vlist[y][x - 1].GetWall_North() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x - 1].GetWall_North()) );
		vlist[y][x - 1].SetWall_South( (vlist[y][x - 1].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x - 1].GetWall_South()) );
		vlist[y][x - 1].SetWall_East( (vlist[y][x - 1].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x - 1].GetWall_East()) );
		vlist[y][x - 1].SetWall_West( (vlist[y][x - 1].GetWall_West() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y][x - 1].GetWall_West()) );
	}
	else if ((IsOdd_x == 0) && (IsOdd_y == 1))
	{
		vlist[y + 1][x].SetWall_North( (vlist[y + 1][x].GetWall_North() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y + 1][x].GetWall_North()) );
		vlist[y + 1][x].SetWall_South( (vlist[y + 1][x].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y + 1][x].GetWall_South()) );
		vlist[y + 1][x].SetWall_East( (vlist[y + 1][x].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y + 1][x].GetWall_East()) );
		vlist[y + 1][x].SetWall_West( (vlist[y + 1][x].GetWall_West() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y + 1][x].GetWall_West()) );
		vlist[y - 1][x].SetWall_North( (vlist[y - 1][x].GetWall_North() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y - 1][x].GetWall_North()) );
		vlist[y - 1][x].SetWall_South( (vlist[y - 1][x].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y - 1][x].GetWall_South()) );
		vlist[y - 1][x].SetWall_East( (vlist[y - 1][x].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y - 1][x].GetWall_East()) );
		vlist[y - 1][x].SetWall_West( (vlist[y - 1][x].GetWall_West() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[y - 1][x].GetWall_West()) );
	}
	else if ((IsOdd_x == 1) && (IsOdd_y == 1))
	{
	}
	return 0;
}

std::vector<Coordinate> Graph::GetConnectionVertex(Coordinate VertexIndex)
{
	std::vector<Coordinate> VertexList;

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_North()== WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_East() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_West() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_South() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_NorthEast() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_EastSouth() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_WestNorth() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].GetWall_SouthWest() == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->mazeCoordinate);
		}
	}

	return VertexList;
}

std::vector<Coordinate> Graph::GetSupposeConnectionVertex(Coordinate VertexIndex)
{
	std::vector<Coordinate> VertexList;

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_North()== WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_North()== WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_East() == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_East() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_West() == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_West() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_South() == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_South() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_NorthEast() == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_NorthEast() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_EastSouth() == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_EastSouth() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_WestNorth() == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_WestNorth() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].GetWall_SouthWest() == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].GetWall_SouthWest() == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->mazeCoordinate);
		}
	}

	return VertexList;
}

void Graph::CreateMap(std::vector<std::vector<Vertex>>& vl)
{
	int maxNodes = (((m_MapSize * 2) - 1));
	int nodeTerm = maxNodes - 1;
	vl.resize((uint64_t)maxNodes);
	for (int y = 0; y < maxNodes; y++)
	{
		vl[y].reserve((uint64_t)maxNodes);
		for (int x = 0; x < maxNodes; x++)
		{
			CPoint point;
			point.x = ((x * CELL_LENGTH) / 2) - (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			point.y = ((y * CELL_LENGTH) / 2)- (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			Coordinate cord(x, y);
			if (x == 0)
			{ // 左
				if (y == 0)
				{ // 左上
					vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
				}
				else if (y == (nodeTerm))
				{ // 左下
					vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
				}
				else
				{ // 左中
					if (y % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						vl[y][x].SetReferVertex_NE(&vl[y - 1][x + 1]);
						vl[y - 1][x + 1].SetReferVertex_SW(&vl[y][x]);
					}
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする

				}
			}
			else if (x == (nodeTerm))
			{ // 右
				if (y == 0)
				{ // 右上
					vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, vl[y][x - 2].Wall_East, WallStatus::E_KS_Unknown));
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 右下
					vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, g_Nothing, vl[y][x - 2].Wall_East, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 右中
					if (y % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, g_Nothing, vl[y][x - 2].Wall_East, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						vl[y][x].SetReferVertex_WN(&vl[y - 1][x - 1]);
						vl[y - 1][x - 1].SetReferVertex_ES(&vl[y][x]);
					}
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
				}
			}
			else
			{ // 中
				if (y == 0)
				{ // 中上
					if (x % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 2].Wall_East, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
					}
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 中下
					if (x % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 2].Wall_East, g_Nothing));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						vl[y][x].SetReferVertex_NE(&vl[y - 1][x + 1]);
						vl[y - 1][x + 1].SetReferVertex_SW(&vl[y][x]);
						vl[y][x].SetReferVertex_WN(&vl[y - 1][x - 1]);
						vl[y - 1][x - 1].SetReferVertex_ES(&vl[y][x]);
					}
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 中中
					if ((x % 2 == 0) && (y % 2 == 0))
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 2][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 2].Wall_East, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 0) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
						vl[y][x].SetReferVertex_NE(&vl[y - 1][x + 1]);
						vl[y - 1][x + 1].SetReferVertex_SW(&vl[y][x]);
						vl[y][x].SetReferVertex_WN(&vl[y - 1][x - 1]);
						vl[y - 1][x - 1].SetReferVertex_ES(&vl[y][x]);
					}
					else if ((x % 2 == 1) && (y % 2 == 0))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
						vl[y][x].SetReferVertex_NE(&vl[y - 1][x + 1]);
						vl[y - 1][x + 1].SetReferVertex_SW(&vl[y][x]);
						vl[y][x].SetReferVertex_WN(&vl[y - 1][x - 1]);
						vl[y - 1][x - 1].SetReferVertex_ES(&vl[y][x]);
					}
					else if ((x % 2 == 1) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
					}
				}
			}

			// test
			Vertex& tempVertex = vl[y].back();
			if (tempVertex.GetWall_North()!= WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_North()->GetVertex_South() == &tempVertex);
			}
			if (tempVertex.GetWall_West() != WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_West()->GetVertex_East() == &tempVertex);
			}
			if (tempVertex.GetWall_WestNorth() != WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_WestNorth()->GetVertex_EastSouth() == &tempVertex);
			}
			if (tempVertex.GetWall_NorthEast() != WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_NorthEast()->GetVertex_SouthWest() == &tempVertex);
			}
		} // for (int y = 0; y < m_MapSize; y++)
	} // for (int x = 0; x < m_MapSize; x++)
}

void Graph::SetAnswer(std::vector<std::vector<Vertex>>& vl)
{
	for (int y = 0; y < MAZE_SIZE; y++)
	{
		for(int x = 0; x < MAZE_SIZE; x++)
		{	
			vl[y * 2][x * 2].SetWall_East( (vl[y * 2][x * 2].GetWall_East() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].right ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing)));
			vl[y * 2][x * 2].SetWall_South( (vl[y * 2][x * 2].GetWall_South() == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].bottom ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing)) );

			//if (x < MAZE_SIZE - 1)
			//{
			//	auto& Er = vl[y * 2][(x * 2) + 1].GetWall_East();
			//	Er = (Er == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].right ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));
			//	auto& SW = vl[y * 2][(x * 2) + 1].GetWall_SouthWest();
			//	SW = WallStatus::E_KS_OutSide;
			//}

			//if (y < MAZE_SIZE - 1)
			//{
			//	auto& Sb = vl[(y * 2) + 1][x * 2].GetWall_South();
			//	Sb = (Sb == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].bottom ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));
			//}
		}
	}
}