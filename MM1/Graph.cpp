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
{
	{ 1, 1}, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  0 },
	{ 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 0,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 },
	{ 0,  1 }, { 1,  0 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 0,  0 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 },
	{ 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 },
	{ 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 },
	{ 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  0 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 },
	{ 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  0 },
	{ 0,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  0 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 0,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 0,  1 }, { 1,  0 }, { 0,  1 }, { 1,  1 }, { 1,  0 }, { 0,  0 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  1 }, { 1,  0 }, { 1,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 },
	{ 1,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  0 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 1,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 1,  0 },
	{ 1,  0 }, { 0,  1 }, { 1,  0 }, { 0,  1 }, { 1,  0 }, { 0,  0 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  0 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 0,  0 }, { 0,  0 }, { 1,  0 }, { 1,  1 }, { 1,  1 }, { 0,  1 }, { 0,  1 }, { 1,  1 }, { 0,  1 }, { 1,  1 }, { 0,  0 }, { 1,  1 }, { 0,  0 }, { 1,  0 },
	{ 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  1 }, { 0,  0 },
};

#endif


Vertex::Vertex()
	: mazeCoordinate(0, 0)
	, displayPoint(0, 0)
	, Wall_North(g_Nothing)
	, Wall_East(g_Nothing)
	, Wall_West(g_Nothing)
	, Wall_South(g_Nothing)
	, Wall_NorthEast(g_Nothing)
	, Wall_EastSouth(g_Nothing)
	, Wall_WestNorth(g_Nothing)
	, Wall_SouthWest(g_Nothing)
	, pVertex_North(this)
	, pVertex_East(this)
	, pVertex_West(this)
	, pVertex_South(this)
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
	, Wall_NorthEast(g_Nothing)
	, Wall_EastSouth(g_Nothing)
	, Wall_WestNorth(g_Nothing)
	, Wall_SouthWest(g_Nothing)
	, pVertex_North(nullptr)
	, pVertex_East(nullptr)
	, pVertex_West(nullptr)
	, pVertex_South(nullptr)
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
	, Wall_NorthEast(WNE)
	, Wall_EastSouth(WES)
	, Wall_WestNorth(WWN)
	, Wall_SouthWest(WSW)
	, pVertex_North(nullptr)
	, pVertex_East(nullptr)
	, pVertex_West(nullptr)
	, pVertex_South(nullptr)
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
	pVertex_North = VNE;
}
void Vertex::SetReferVertex_ES(Vertex* VES)
{
	pVertex_East = VES;
}

void Vertex::SetReferVertex_WN(Vertex* VWN)
{
	pVertex_West = VWN;
}

void Vertex::SetReferVertex_SW(Vertex* VSW)
{
	pVertex_South = VSW;
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

Vertex::operator CPoint()
{
	return displayPoint;
}

Vertex::operator Coordinate()
{
	return mazeCoordinate;
}

Graph::Graph()
	// : vlist()
	// , vAnswer()
{
	CreateMap(vlist);
	SetAnswer(vAnswer);

	//routelist.resize(vlist.size() * vlist[0].size());
	//for (auto& r : routelist)
	//{
	//	r = Coordinate(0, 0);
	//}

	//SupposeeRoutelist.resize(vlist.size() * vlist[0].size());
	//for (auto& r : SupposeeRoutelist)
	//{
	//	r = Coordinate(0, 0);
	//}

	//for (auto v : vlist)
	//{
	//	initialvlist.push_back(Vertex());
	//	initialvlist[Index].Wall_North = v.Wall_North ;
	//	initialvlist[Index].Wall_East  = v.Wall_East  ;
	//	initialvlist[Index].Wall_West  = v.Wall_West  ;
	//	initialvlist[Index].Wall_South = v.Wall_South ;
	//	Index++;
	//}
	//g_Nothing = WallStatus::E_KS_OutSide;
}

Graph::~Graph()
{
}

void Graph::Initialize(void)
{
	//int Index = 0;
	//for (auto v : initialvlist)
	//{
	//	vlist[Index].Wall_North = v.Wall_North;
	//	vlist[Index].Wall_East = v.Wall_East;
	//	vlist[Index].Wall_West = v.Wall_West;
	//	vlist[Index].Wall_South = v.Wall_South;
	//	Index++;
	//}
}

int Graph::WallCheck(Coordinate VertexIndex)
{
	int wall_x = VertexIndex.x;
	int wall_y = VertexIndex.y;
	int half_x = wall_x;
	int half_y = wall_y;
	bool IsODD_x = wall_x % 2;
	bool IsODD_y = wall_y % 2;

	if (IsODD_y)
	{
		vlist[wall_y][wall_x].Wall_North = (vlist[wall_y][wall_x].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_North);
		vlist[wall_y][wall_x].Wall_South = (vlist[wall_y][wall_x].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_South);
	}
	else
	{
		vlist[wall_y][wall_x].Wall_North = (vlist[wall_y][wall_x].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_North);
		vlist[wall_y][wall_x].Wall_South = (vlist[wall_y][wall_x].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_South);
	}

	if (IsODD_x)
	{
		vlist[wall_y][wall_x].Wall_East = (vlist[wall_y][wall_x].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_East);
		vlist[wall_y][wall_x].Wall_West = (vlist[wall_y][wall_x].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_West);
	}
	else
	{
		vlist[wall_y][wall_x].Wall_East = (vlist[wall_y][wall_x].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_East);
		vlist[wall_y][wall_x].Wall_West = (vlist[wall_y][wall_x].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_West);
	}

	vlist[wall_y][wall_x].Wall_NorthEast = (vlist[wall_y][wall_x].Wall_NorthEast == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_NorthEast);
	vlist[wall_y][wall_x].Wall_EastSouth = (vlist[wall_y][wall_x].Wall_EastSouth == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_EastSouth);
	vlist[wall_y][wall_x].Wall_WestNorth = (vlist[wall_y][wall_x].Wall_WestNorth == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_WestNorth);
	vlist[wall_y][wall_x].Wall_SouthWest = (vlist[wall_y][wall_x].Wall_SouthWest == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[half_y][half_x].Wall_SouthWest);
	return 0;
}

std::vector<Coordinate> Graph::GetConnectionVertex(Coordinate VertexIndex)
{
	std::vector<Coordinate> VertexList;

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_North == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_East == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_West == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_South == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_NorthEast == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_EastSouth == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_WestNorth == WallStatus::E_KS_WallNothing)
	{
		if (vlist[VertexIndex.y][VertexIndex.x].pSearchFromVertexIndex != vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate);
		}
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_SouthWest == WallStatus::E_KS_WallNothing)
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

	//vlist[VertexIndex.y][VertexIndex.x].Wall_North = (vlist[VertexIndex.y][VertexIndex.x].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex.y][VertexIndex.x].Wall_North);
	//vlist[VertexIndex.y][VertexIndex.x].Wall_East = (vlist[VertexIndex.y][VertexIndex.x].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex.y][VertexIndex.x].Wall_East);
	//vlist[VertexIndex.y][VertexIndex.x].Wall_West = (vlist[VertexIndex.y][VertexIndex.x].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex.y][VertexIndex.x].Wall_West);
	//vlist[VertexIndex.y][VertexIndex.x].Wall_South = (vlist[VertexIndex.y][VertexIndex.x].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex.y][VertexIndex.x].Wall_South);

#if 1
	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_North == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].Wall_North == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_East == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].Wall_East == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_West == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].Wall_West == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_South == WallStatus::E_KS_WallNothing)
	|| (vlist[VertexIndex.y][VertexIndex.x].Wall_South == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_NorthEast == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].Wall_NorthEast == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_NorthEast()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_EastSouth == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].Wall_EastSouth == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_EastSouth()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_WestNorth == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].Wall_WestNorth == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_WestNorth()->mazeCoordinate);
		}
	}

	if ((vlist[VertexIndex.y][VertexIndex.x].Wall_SouthWest == WallStatus::E_KS_WallNothing)
		|| (vlist[VertexIndex.y][VertexIndex.x].Wall_SouthWest == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_SouthWest()->mazeCoordinate);
		}
	}
#else

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_North == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_North()->mazeCoordinate);
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_East == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_East()->mazeCoordinate);
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_West == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_West()->mazeCoordinate);
	}

	if (vlist[VertexIndex.y][VertexIndex.x].Wall_South == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex.y][VertexIndex.x].GetVertex_South()->mazeCoordinate);
	}
#endif
	return VertexList;
}

void Graph::CreateMap(std::vector<std::vector<Vertex>>& vl)
{
	int Index = 0;
#if 0 // 1マス1ノード
	auto to_1d = [](int x, int y) -> int {return x + (y * (31)) ; };
	vl.reserve((uint64_t)m_MapSize * (uint64_t)m_MapSize);
	for (int x = 0; x < m_MapSize; x++)
	{
		for (int y = 0; y < m_MapSize; y++)
		{
			int xpoint = (x * CELL_LENGTH) - (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			int ypoint = (y * CELL_LENGTH) - (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			if (x == 0)
			{ // 左
				if (y == 0)
				{ // 左上
					vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
				}
				else if (y >= (m_MapSize - 1))
				{ // 左下
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, g_Nothing));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
				}
				else
				{ // 左中
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする
				}
			}
			else if (x >= (m_MapSize - 1))
			{ // 右
				if (y == 0)
				{ // 右上
					vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, g_Nothing, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする
				}
				else if (y >= (m_MapSize - 1))
				{ // 右下
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, g_Nothing, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 右中
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, g_Nothing, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
				}
			}
			else
			{ // 中
				if (y == 0)
				{ // 中上
					vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする
				}
				else if (y >= (m_MapSize - 1))
				{ // 中下
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 中中
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
				}
			}
			Index++;
		} // for (int y = 0; y < m_MapSize; y++)
	} // for (int x = 0; x < m_MapSize; x++)

#else

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
					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
				}
				else
				{ // 左中
					if (y % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
					else if (y % 2 == 1)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
					}
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする
				}
			}
			else if (x == (nodeTerm))
			{ // 右
				if (y == 0)
				{ // 右上
					vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 右下
					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, vl[y][x - 1].Wall_East, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 右中

					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
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
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
					}
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 中下
					if (x % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
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
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 0) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					}
					else if ((x % 2 == 1) && (y % 2 == 0))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 1) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
				}
			}

			Vertex& tempVertex = vl[y].back();
			if (tempVertex.Wall_North != WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_North()->GetVertex_South() == &tempVertex);
			}
			//if (tempVertex.Wall_East != WallStatus::E_KS_OutSide)
			//{
			//	assert(tempVertex.GetVertex_East()->GetVertex_West() == &tempVertex);
			//}
			if (tempVertex.Wall_West != WallStatus::E_KS_OutSide)
			{
				assert(tempVertex.GetVertex_West()->GetVertex_East() == &tempVertex);
			}
			//if (tempVertex.Wall_South != WallStatus::E_KS_OutSide)
			//{
			//	assert(tempVertex.GetVertex_South()->GetVertex_North() == &tempVertex);
			//}


			Index++;
		} // for (int y = 0; y < m_MapSize; y++)
	} // for (int x = 0; x < m_MapSize; x++)
#endif
}

void Graph::SetAnswer(std::vector<std::vector<Vertex>>& vl)
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
			point.y = ((y * CELL_LENGTH) / 2) - (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			Coordinate cord(x, y);
			if (x == 0)
			{ // 左
				if (y == 0)
				{ // 左上
					vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
				}
				else if (y == (nodeTerm))
				{ // 左下
					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
				}
				else
				{ // 左中
					if (y % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
					else if (y % 2 == 1)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
					}
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする
				}
			}
			else if (x == (nodeTerm))
			{ // 右
				if (y == 0)
				{ // 右上
					vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 右下
					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, vl[y][x - 1].Wall_East, g_Nothing));
					vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 右中

					vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
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
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
					}
					vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
					vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 中下
					if (x % 2 == 0)
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
					}
					else
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
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
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 0) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, vl[y - 1][x].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_N(&vl[y - 1][x]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[y - 1][x].SetReferVertex_S(&vl[y][x]); // 上のノードにこのノードを紐づけする North <-> Soouth
					}
					else if ((x % 2 == 1) && (y % 2 == 0))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, g_Nothing));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, vl[y][x - 1].Wall_East, WallStatus::E_KS_Unknown));
						vl[y][x].SetReferVertex_W(&vl[y][x - 1]); // このノードに左のノードを紐づけする East <-> West
						vl[y][x - 1].SetReferVertex_E(&vl[y][x]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 1) && (y % 2 == 1))
					{
						vl[y].push_back(Vertex(point, cord, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						//vl[y].push_back(Vertex(point, cord, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
				}
			}
		} // for (int y = 0; y < m_MapSize; y++)
	} // for (int x = 0; x < m_MapSize; x++)



	//vl.resize((uint64_t)MAZE_SIZE);
	for (int y = 0; y < MAZE_SIZE; y++)
	{
		//vl[y].resize((uint64_t)MAZE_SIZE);
		for(int x = 0; x < MAZE_SIZE; x++)
		{	
			auto &E = vl[y * 2][x * 2].Wall_East;
			auto &S = vl[y * 2][x * 2].Wall_South;
			E = (E == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].right ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));
			S = (S == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].bottom ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));

			if (x < MAZE_SIZE - 1)
			{
				auto& Er = vl[y * 2][(x * 2) + 1].Wall_East;
				Er = (Er == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].right ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));
			}

			if (y < MAZE_SIZE - 1)
			{
				auto& Sb = vl[(y * 2) + 1][x * 2].Wall_South;
				Sb = (Sb == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : (g_AnswewrMazeData[y][x].bottom ? WallStatus::E_KS_WallExists : WallStatus::E_KS_WallNothing));
			}
		}
	}
}