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
	E_Status_UnExplored = 0, // ���T��
	E_Status_Exploring, // �T����
	E_Status_Looked, // �m�[�h���������B�܂���ɉ����Ȃ����Ă��邩���Ă��Ȃ�
	E_Status_Searched, // �m�[�h�̐�ɉ����Ȃ����Ă��邩���ׂ�
	E_Status_ShortestPath, // �ŒZ�o�H
	E_Status_VirtualShortestPath, // ���z�ŒZ�o�H
};

enum class WallStatus : int {
	E_KS_Unknown = 0,
	E_KS_Exists,
	E_KS_NotExist,
	E_KS_OutSide,
};

// ���_�N���X
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

	// �E�Ɖ��͎��ϐ��A��ƍ��͑Ή�����m�[�h�̃����o���Q�Ƃ��鎖�ŏ㉺���E�̕ǂ𑀍�ł��A���m�[�h�̉E�ǂƉE�m�[�h�̍��ǂ����ʉ�����
	WallStatus& Wall_North;
	WallStatus Wall_East = WallStatus::E_KS_OutSide;
	WallStatus& Wall_West;
	WallStatus Wall_South = WallStatus::E_KS_OutSide;
	int pSearchFromVertexIndex; // �ǂ����猩����ꂽ�̂���� �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	int pSupposeSearchFromVertexIndex; // �ǂ����猩����ꂽ�̂���� �������\�ɂ��邽�߃|�C���^�ɂ��Ă���

private:
	Vertex* pVertex_North; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_East; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_West; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_South; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
};

// �O���t
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