#pragma once
#include "pch.h"
#include <vector>
#include <array>

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
	void SetReferVertex_N(Vertex* VN);
	void SetReferVertex_E(Vertex* VE);
	void SetReferVertex_W(Vertex* VW);
	void SetReferVertex_S(Vertex* VS);
	Vertex* GetVertex_North(void);
	Vertex* GetVertex_East(void);
	Vertex* GetVertex_West(void);
	Vertex* GetVertex_South(void);
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
	int pSearchFromVertexIndex; // どこから見つけられたのか情報 後代入を可能にするためポインタにしている
	int pSupposeSearchFromVertexIndex; // どこから見つけられたのか情報 後代入を可能にするためポインタにしている

private:
	Vertex* pVertex_North; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_East; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_West; // 後代入を可能にするためポインタにしている
	Vertex* pVertex_South; // 後代入を可能にするためポインタにしている
};

// グラフ
class Graph
{
public:
	Graph();
	std::vector<Vertex> vlist;
	std::vector<Vertex> vAnswer;
	std::vector<int> routelist;
	std::vector<int> SupposeeRoutelist;	
	const uint64_t m_MapSize = 32;

	void Initialize(void);
	int Graph::WallCheck(int VertexIndex);
	virtual std::vector<int> GetConnectionVertex(int VertexIndex);
	virtual std::vector<int> GetSupposeConnectionVertex(int VertexIndex);
	void CreateMap(std::vector<Vertex>& vl);
	void SetAnswer(std::vector<Vertex>& vl);
	int to_1d(int x, int y)
	{
		return y + (x * 32);
	};
};

extern WallStatus g_Nothing;
extern Vertex g_NothingVertex;