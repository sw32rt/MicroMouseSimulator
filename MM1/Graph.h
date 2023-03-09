#pragma once
#include "pch.h"
#include <vector>
#include <map>
#include <array>
#include "setting.h"

// ���W
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
	E_Status_UnExplored = 0, // ���T��
	E_Status_Exploring, // �T����
	E_Status_Looked, // �m�[�h���������B�܂���ɉ����Ȃ����Ă��邩���Ă��Ȃ�
	E_Status_Searched, // �m�[�h�̐�ɉ����Ȃ����Ă��邩���ׂ�
	E_Status_ShortestPath, // �ŒZ�o�H
	E_Status_VirtualShortestPath, // ���z�ŒZ�o�H
};

enum class WallStatus : int {
	E_KS_Unknown = 0,
	E_KS_WallExists,
	E_KS_WallNothing,
	E_KS_OutSide,
};

// ���_�N���X
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

	// �E�Ɖ��͎��ϐ��A��ƍ��͑Ή�����m�[�h�̃����o���Q�Ƃ��鎖�ŏ㉺���E�̕ǂ𑀍�ł��A���m�[�h�̉E�ǂƉE�m�[�h�̍��ǂ����ʉ�����
	WallStatus& Wall_North;
	WallStatus Wall_East = WallStatus::E_KS_OutSide;
	WallStatus& Wall_West;
	WallStatus Wall_South = WallStatus::E_KS_OutSide;

	Coordinate pSearchFromVertexIndex; // �ǂ����猩����ꂽ�̂����
	Coordinate pSupposeSearchFromVertexIndex; // �ǂ����猩����ꂽ�̂����

private:
public:
	Vertex* pVertex_North; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_East; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_West; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_South; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_NorthEast; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_EastSouth; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_WestNorth; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
	Vertex* pVertex_SouthWest; // �������\�ɂ��邽�߃|�C���^�ɂ��Ă���
};

// �O���t
class Graph
{
public:
	Graph();
	virtual ~Graph();
	std::vector<std::vector<Vertex>> vlist;
	std::vector<std::vector<Vertex>> vAnswer;
	std::map<std::pair<int, int>, Coordinate> SupposeeRoutelist; // �\�z�ŒZ�o�H��������
	std::map<std::pair<int, int>, Coordinate> CurrentShortestRoutelist; // ���݊m��ŒZ�o�H��������
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