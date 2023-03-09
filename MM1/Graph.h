#pragma once
#include "pch.h"
#include <vector>
#include <map>
#include <array>
#include "setting.h"

// 座標
struct Coordinate
{
	Coordinate()
		: x(0)
		, y(0)
	{
	}

	Coordinate(int x, int y)
		: x(x)
		, y(y)
	{
	}

	int x;
	int y;
	bool operator ==(const Coordinate& b) const
	{
		return ((x == b.x) && (y == b.y));
	}

	bool operator !=(const Coordinate& b) const
	{
		return ((x != b.x) || (y != b.y));
	}

	operator std::pair<int, int>() const
	{
		return std::pair<int, int>(x, y);
	}

};

struct MazeWall
{
	int right;
	int bottom;
};

enum SearchStatus {
	E_Status_UnExplored = 0, // 未探索
	E_Status_Exploring, // 探索中
	E_Status_Looked, // ノードを見つけた。まだ先に何がつながっているか見ていない
	E_Status_Searched, // ノードの先に何がつながっているか調べた
	E_Status_ShortestPath, // 最短経路
	E_Status_VirtualShortestPath, // 仮想最短経路
};

enum class WallStatus : int {
	E_KS_Unknown = 0,
	E_KS_WallExists,
	E_KS_WallNothing,
	E_KS_OutSide,
};

// 頂点クラス
class Vertex
{
public:
	Vertex();
	Vertex(CPoint dispPoint, Coordinate mazeCoordinate, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS);
	Vertex(CPoint dispPoint, Coordinate mazeCoordinate, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS, WallStatus& WNE, WallStatus WES, WallStatus& WWN, WallStatus WSW);
	void SetReferVertex_N(Vertex* VN);
	void SetReferVertex_E(Vertex* VE);
	void SetReferVertex_W(Vertex* VW);
	void SetReferVertex_S(Vertex* VS);
	void SetReferVertex_NE(Vertex* VNE);
	void SetReferVertex_ES(Vertex* VES);
	void SetReferVertex_WN(Vertex* VWN);
	void SetReferVertex_SW(Vertex* VSW);
	Vertex* GetVertex_North(void);
	Vertex* GetVertex_East(void);
	Vertex* GetVertex_West(void);
	Vertex* GetVertex_South(void);
	Vertex* GetVertex_NorthEast(void);
	Vertex* GetVertex_EastSouth(void);
	Vertex* GetVertex_WestNorth(void);
	Vertex* GetVertex_SouthWest(void);
	WallStatus GetWall_North(void);
	WallStatus GetWall_East(void);
	WallStatus GetWall_West(void);
	WallStatus GetWall_South(void);
	WallStatus GetWall_NorthEast(void);
	WallStatus GetWall_EastSouth(void);
	WallStatus GetWall_SouthWest(void);
	WallStatus GetWall_WestNorth(void);
	void SetWall_North(WallStatus ws);
	void SetWall_East(WallStatus ws);
	void SetWall_West(WallStatus ws);
	void SetWall_South(WallStatus ws);

	operator CPoint();
	operator Coordinate();
	CPoint displayPoint;
	Coordinate mazeCoordinate;

	/*int Index = 0;*/
	SearchStatus SStatus = E_Status_UnExplored;
	SearchStatus SupposeSearchStatus = E_Status_UnExplored;

	// 右と下は実変数、上と左は対応するノードのメンバを参照する事で上下左右の壁を操作でき、左ノードの右壁と右ノードの左壁を共通化する
	WallStatus& Wall_North;
	WallStatus Wall_East = WallStatus::E_KS_OutSide;
	WallStatus& Wall_West;
	WallStatus Wall_South = WallStatus::E_KS_OutSide;

	Coordinate pSearchFromVertexIndex; // どこから見つけられたのか情報
	Coordinate pSupposeSearchFromVertexIndex; // どこから見つけられたのか情報

private:
public:
	Vertex* pVertex_North; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_East; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_West; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_South; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_NorthEast; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_EastSouth; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_WestNorth; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_SouthWest; // 後代入を可能にするためポインタにしている
};

// グラフ
class Graph
{
public:
	Graph();
	virtual ~Graph();
	std::vector<std::vector<Vertex>> vlist;
	std::vector<std::vector<Vertex>> vAnswer;
	std::map<std::pair<int, int>, Coordinate> SupposeeRoutelist; // 予想最短経路検索メモ
	std::map<std::pair<int, int>, Coordinate> CurrentShortestRoutelist; // 現在確定最短経路検索メモ
	const uint64_t m_MapSize = MAZE_SIZE;

	void Initialize(void);
	int Graph::WallCheck(Coordinate VertexIndex);
	virtual std::vector<Coordinate> GetConnectionVertex(Coordinate VertexIndex);
	virtual std::vector<Coordinate> GetSupposeConnectionVertex(Coordinate VertexIndex);
	void CreateMap(std::vector<std::vector<Vertex>>& vl);
	void SetAnswer(std::vector<std::vector<Vertex>>& vl);
};

extern WallStatus g_Nothing;
extern Vertex g_NothingVertex;