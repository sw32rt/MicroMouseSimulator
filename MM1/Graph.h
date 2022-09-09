#pragma once
#include "pch.h"
#include <vector>
#include <array>
#include "setting.h"

struct MazeWall
{
	int right;
	int bottom;
};

extern const MazeWall g_AnswewrMazeData[];

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
	E_KS_Exists,
	E_KS_NotExist,
	E_KS_OutSide,
};

// 頂点クラス
class Vertex
{
public:
	Vertex();
	Vertex(int x, int y, int Index, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS);
	Vertex(int x, int y, int Index, WallStatus& WN, WallStatus WE, WallStatus& WW, WallStatus WS, WallStatus& WNE, WallStatus WES, WallStatus& WWN, WallStatus WSW);
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
	operator CPoint();
	int x;
	int y;
	int Index = 0;
	SearchStatus SStatus = E_Status_UnExplored;
	SearchStatus SupposeSearchStatus = E_Status_UnExplored;

	// 右と下は実変数、上と左は対応するノードのメンバを参照する事で上下左右の壁を操作でき、左ノードの右壁と右ノードの左壁を共通化する
	WallStatus& Wall_North;
	WallStatus Wall_East = WallStatus::E_KS_OutSide;
	WallStatus& Wall_West;
	WallStatus Wall_South = WallStatus::E_KS_OutSide;
	WallStatus & Wall_NorthEast;
	WallStatus Wall_EastSouth = WallStatus::E_KS_OutSide;
	WallStatus Wall_SouthWest = WallStatus::E_KS_OutSide;
	WallStatus& Wall_WestNorth;

	int pSearchFromVertexIndex; // どこから見つけられたのか情報 後代入を可能にするためポインタにしている
	int pSupposeSearchFromVertexIndex; // どこから見つけられたのか情報 後代入を可能にするためポインタにしている

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
	std::vector<Vertex> vlist;
	std::vector<Vertex> vAnswer;
	std::vector<int> routelist;
	std::vector<int> SupposeeRoutelist;	
	const uint64_t m_MapSize = MAZE_SIZE;

	void Initialize(void);
	int Graph::WallCheck(int VertexIndex);
	virtual std::vector<int> GetConnectionVertex(int VertexIndex);
	virtual std::vector<int> GetSupposeConnectionVertex(int VertexIndex);
	void CreateMap(std::vector<Vertex>& vl);
	void SetAnswer(std::vector<Vertex>& vl);
};

extern WallStatus g_Nothing;
extern Vertex g_NothingVertex;