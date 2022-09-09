#include "pch.h"
#include "Graph.h"
#include "CMazeWall.h"

WallStatus g_Nothing = WallStatus::E_KS_OutSide;
Vertex g_NothingVertex = Vertex();

static const MazeWall g_AnswewrMazeData[] =
#if 1
{
{ 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1},
{ 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1},
{ 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1},
{ 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1},
{ 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1},
{ 1,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1},
{ 0,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1},
{ 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  1},
{ 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1},
{ 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1},
{ 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1},
{ 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  0}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1}, { 1,  0}, { 0,  0}, { 0,  1},
{ 0,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1},
{ 1,  1}, { 0,  0}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0},
{ 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1},
{ 1,  1}, { 0,  0}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 0,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1},
{ 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 0,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1},
{ 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 0,  1}, { 0,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  1},
{ 0,  1}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1},
{ 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  1}, { 0,  1}, { 1,  1}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  1},
{ 0,  1}, { 1,  1}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  1}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  1}, { 1,  0}, { 0,  1}, { 1,  0}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 0,  1}, { 0,  1}, { 0,  1}, { 1,  1}, { 1,  0}, { 1,  1}, { 0,  0}, { 1,  1}, { 0,  0}, { 0,  1},
{ 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 1,  0}, { 0,  0},
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
	: x(0)
	, y(0)
	, Index(0)
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
	, pSearchFromVertexIndex(-1)
	, pSupposeSearchFromVertexIndex(-1)
{
}

Vertex::Vertex(int x, int y, int Index, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS)
	: x(x)
	, y(y)
	, Index(Index)
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
	, pSearchFromVertexIndex(-1)
	, pSupposeSearchFromVertexIndex(-1)
{
}

Vertex::Vertex(int x, int y, int Index, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS, WallStatus& WNE, WallStatus WES, WallStatus& WWN, WallStatus WSW)
	: x(x)
	, y(y)
	, Index(Index)
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
	, pSearchFromVertexIndex(-1)
	, pSupposeSearchFromVertexIndex(-1)
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
	return CPoint(x, y);
}

Graph::Graph()
	// : vlist()
	// , vAnswer()
{
	CreateMap(vlist);
	CreateMap(vAnswer);
	SetAnswer(vAnswer);

	routelist.resize(vlist.size());
	for (auto& r : routelist)
	{
		r = 0;
	}
	int Index = 0;

	SupposeeRoutelist.resize(vlist.size());
	for (auto& r : SupposeeRoutelist)
	{
		r = 0;
	}

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

int Graph::WallCheck(int VertexIndex)
{
	int wall_x = (VertexIndex % ((m_MapSize * 2) - 1)) / 2;
	int wall_y = (VertexIndex / ((m_MapSize * 2) - 1)) / 2;
	bool IsHalf_x = wall_x % 2;
	bool IsHalf_y = wall_y % 2;
	auto to_1d = [](int x, int y) -> int { return x + (y * ((32 * 2) - 1)); };

	if (IsHalf_y)
	{
		vlist[VertexIndex].Wall_North = (vlist[VertexIndex].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_North);
		vlist[VertexIndex].Wall_South = (vlist[VertexIndex].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_South);
	}
	else
	{
		vlist[VertexIndex].Wall_North = (vlist[VertexIndex].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_North);
		vlist[VertexIndex].Wall_South = (vlist[VertexIndex].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_South);
	}

	if (IsHalf_x)
	{
		vlist[VertexIndex].Wall_East = (vlist[VertexIndex].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_East);
		vlist[VertexIndex].Wall_West = (vlist[VertexIndex].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_West);
	}
	else
	{
		vlist[VertexIndex].Wall_East = (vlist[VertexIndex].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_East);
		vlist[VertexIndex].Wall_West = (vlist[VertexIndex].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_West);
	}

	vlist[VertexIndex].Wall_NorthEast = (vlist[VertexIndex].Wall_NorthEast == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_NorthEast);
	vlist[VertexIndex].Wall_EastSouth = (vlist[VertexIndex].Wall_EastSouth == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_EastSouth);
	vlist[VertexIndex].Wall_WestNorth = (vlist[VertexIndex].Wall_WestNorth == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_WestNorth);
	vlist[VertexIndex].Wall_SouthWest = (vlist[VertexIndex].Wall_SouthWest == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[to_1d(wall_x, wall_y)].Wall_SouthWest);
	return 0;
}

std::vector<int> Graph::GetConnectionVertex(int VertexIndex)
{
	std::vector<int> VertexList;

	if (vlist[VertexIndex].Wall_North == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_North()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_North()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_East == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_East()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_East()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_West == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_West()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_West()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_South == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_South()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_South()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_NorthEast == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_NorthEast()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_NorthEast()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_EastSouth == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_EastSouth()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_EastSouth()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_WestNorth == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_WestNorth()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_WestNorth()->Index);
		}
	}

	if (vlist[VertexIndex].Wall_SouthWest == WallStatus::E_KS_Exists)
	{
		if (vlist[VertexIndex].pSearchFromVertexIndex != vlist[VertexIndex].GetVertex_SouthWest()->Index)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_SouthWest()->Index);
		}
	}

	return VertexList;
}

std::vector<int> Graph::GetSupposeConnectionVertex(int VertexIndex)
{
	std::vector<int> VertexList;

	//vlist[VertexIndex].Wall_North = (vlist[VertexIndex].Wall_North == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex].Wall_North);
	//vlist[VertexIndex].Wall_East = (vlist[VertexIndex].Wall_East == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex].Wall_East);
	//vlist[VertexIndex].Wall_West = (vlist[VertexIndex].Wall_West == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex].Wall_West);
	//vlist[VertexIndex].Wall_South = (vlist[VertexIndex].Wall_South == WallStatus::E_KS_OutSide ? WallStatus::E_KS_OutSide : vAnswer[VertexIndex].Wall_South);

#if 1
	if ((vlist[VertexIndex].Wall_North == WallStatus::E_KS_Exists)
	|| (vlist[VertexIndex].Wall_North == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_North()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_North()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_East == WallStatus::E_KS_Exists)
	|| (vlist[VertexIndex].Wall_East == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_East()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_East()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_West == WallStatus::E_KS_Exists)
	|| (vlist[VertexIndex].Wall_West == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_West()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_West()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_South == WallStatus::E_KS_Exists)
	|| (vlist[VertexIndex].Wall_South == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_South()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_South()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_NorthEast == WallStatus::E_KS_Exists)
		|| (vlist[VertexIndex].Wall_NorthEast == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_NorthEast()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_NorthEast()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_EastSouth == WallStatus::E_KS_Exists)
		|| (vlist[VertexIndex].Wall_EastSouth == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_EastSouth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_EastSouth()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_WestNorth == WallStatus::E_KS_Exists)
		|| (vlist[VertexIndex].Wall_WestNorth == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_WestNorth()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_WestNorth()->Index);
		}
	}

	if ((vlist[VertexIndex].Wall_SouthWest == WallStatus::E_KS_Exists)
		|| (vlist[VertexIndex].Wall_SouthWest == WallStatus::E_KS_Unknown))
	{
		if (SearchStatus::E_Status_UnExplored == vlist[VertexIndex].GetVertex_SouthWest()->SupposeSearchStatus)
		{
			VertexList.push_back(vlist[VertexIndex].GetVertex_SouthWest()->Index);
		}
	}
#else

	if (vlist[VertexIndex].Wall_North == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex].GetVertex_North()->Index);
	}

	if (vlist[VertexIndex].Wall_East == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex].GetVertex_East()->Index);
	}

	if (vlist[VertexIndex].Wall_West == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex].GetVertex_West()->Index);
	}

	if (vlist[VertexIndex].Wall_South == WallStatus::E_KS_Unknown)
	{
		VertexList.push_back(vlist[VertexIndex].GetVertex_South()->Index);
	}
#endif
	return VertexList;
}

void Graph::CreateMap(std::vector<Vertex>& vl)
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

	auto to_1d = [](int x, int y) -> int { return x + (y * ((32 * 2) - 1)); };
	int maxNodes = (((m_MapSize * 2) - 1));
	int nodeTerm = maxNodes - 1;
	vl.reserve((uint64_t)maxNodes * (uint64_t)maxNodes);
	for (int y = 0; y < maxNodes; y++)
	{
		for (int x = 0; x < maxNodes; x++)
		{
			int xpoint = ((x * CELL_LENGTH) / 2) - (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			int ypoint = ((y * CELL_LENGTH) / 2)- (((CELL_LENGTH * m_MapSize) + WALL_WIDTH) / 2.0) + ((WALL_WIDTH + CELL_LENGTH) / 2);
			if (x == 0)
			{ // 左
				if (y == 0)
				{ // 左上
					vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
				}
				else if (y == (nodeTerm))
				{ // 左下
					vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, g_Nothing));
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
				}
				else
				{ // 左中
					if (y % 2 == 0)
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
					else if (y % 2 == 1)
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
					}
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする
				}
			}
			else if (x == (nodeTerm))
			{ // 右
				if (y == 0)
				{ // 右上
					vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, g_Nothing, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
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
					if (x % 2 == 0)
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
					}
					else
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
					}
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする
				}
				else if (y == (nodeTerm))
				{ // 中下
					if (x % 2 == 0)
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
					}
					else
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
					}
					vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
					vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
					vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
				}
				else
				{ // 中中
					if ((x % 2 == 0) && (y % 2 == 0))
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
						vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
						vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
						vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 0) && (y % 2 == 1))
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, g_Nothing, g_Nothing, WallStatus::E_KS_Unknown));
						//vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl.push_back(Vertex(xpoint, ypoint, Index, vl[to_1d(x, y - 1)].Wall_South, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						vl[to_1d(x, y)].SetReferVertex_N(&vl[to_1d(x, y - 1)]); // このノードに上のノードを紐づけする North <-> Soouth
						vl[to_1d(x, y - 1)].SetReferVertex_S(&vl[to_1d(x, y)]); // 上のノードにこのノードを紐づけする North <-> Soouth
					}
					else if ((x % 2 == 1) && (y % 2 == 0))
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, g_Nothing));
						//vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
						//vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, vl[to_1d(x - 1, y)].Wall_East, WallStatus::E_KS_Unknown));
						vl[to_1d(x, y)].SetReferVertex_W(&vl[to_1d(x - 1, y)]); // このノードに左のノードを紐づけする East <-> West
						vl[to_1d(x - 1, y)].SetReferVertex_E(&vl[to_1d(x, y)]); // 左のノードにこのノードを紐づけする East <-> West
					}
					else if ((x % 2 == 1) && (y % 2 == 1))
					{
						vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, g_Nothing, g_Nothing, g_Nothing));
						//vl.push_back(Vertex(xpoint, ypoint, Index, g_Nothing, WallStatus::E_KS_Unknown, g_Nothing, WallStatus::E_KS_Unknown));
					}
				}
			}

			Vertex& tempVertex = vl.back();
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

void Graph::SetAnswer(std::vector<Vertex>& vl)
{
	int index = 0;
	for (auto &a : vl)
	{	
		//a.Wall_East = (g_AnswewrMazeData[index].right ? WallStatus::E_KS_Exists : WallStatus::E_KS_NotExist);
		//a.Wall_South = (g_AnswewrMazeData[index].bottom ? WallStatus::E_KS_Exists : WallStatus::E_KS_NotExist);
		a.Wall_East = (g_AnswewrMazeData[index].right ? WallStatus::E_KS_NotExist : WallStatus::E_KS_Exists);
		a.Wall_South = (g_AnswewrMazeData[index].bottom ? WallStatus::E_KS_NotExist : WallStatus::E_KS_Exists);
		index++;
	}
}