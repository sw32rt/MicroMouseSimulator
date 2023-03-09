#include "pch.h"
#include "AdachiHo.h"
#include <cmath>

AdachiHo::~AdachiHo()
{
}

void AdachiHo::init(Coordinate StartVertexIndex, Coordinate GoalVertexIndex)
{
    this->CurrentVertexIndex = StartVertexIndex;
    this->StartVertexIndex = StartVertexIndex;
    this->GoalVertexIndex = GoalVertexIndex;

    // �T�������X�g�N���A
    NextSearchVertexStack.clear();

    // �T���ςݏ��N���A
    //for (int i = 0; i < routelist.size(); i++)
    //{
    //    routelist.at(i) = -1;
    //}
    Initialize();
}

Coordinate AdachiHo::GetNextSearchVertex(Coordinate CurrentVertex)
{
    float dx = 0;
    float dy = 0;
    float distans = INFINITY;
    //Coordinate minimalNext = 0;
    Coordinate returnNext(0,0);
    std::vector<Coordinate> cv;

    Coordinate SupposeNext = GoalVertexIndex;
    Coordinate SupposeSearchCurrent = GoalVertexIndex;
    static std::deque<Coordinate> vSupposBFSstack;

    WallCheck(CurrentVertex);

    // ���z�T���X�e�[�^�X������
    for (auto& ylist : vlist)
    {
        for (auto& x : ylist)
        {
            x.SupposeSearchStatus = SearchStatus::E_Status_UnExplored;
            x.SStatus = SearchStatus::E_Status_UnExplored;
        }
    }

    vSupposBFSstack.clear();

    //while (1)
    do
    { /* goal -> start�Ɍ������čŒZ�o�H�����߂� ���D��T���őS�T������ */
        distans = INFINITY;
        cv = GetSupposeConnectionVertex(SupposeSearchCurrent);
        for (auto v : cv)
        {
            SupposeeRoutelist[v] = SupposeSearchCurrent;
            vlist[v.y][v.x].SupposeSearchStatus = SearchStatus::E_Status_Looked;
            vSupposBFSstack.push_back(v);
        }
        SupposeNext = vSupposBFSstack.front();
        vSupposBFSstack.pop_front();
        vlist[SupposeNext.y][SupposeNext.x].pSupposeSearchFromVertexIndex = vlist[SupposeSearchCurrent.y][SupposeSearchCurrent.x];
        SupposeSearchCurrent = SupposeNext;

        if (SupposeNext == CurrentVertex) // Current -> Goal
        { // ���[�g��������
            Coordinate SupposeShortestPathNext = CurrentVertex;
            while (1)
            {
                vlist[SupposeShortestPathNext.y][SupposeShortestPathNext.x].SupposeSearchStatus = SearchStatus::E_Status_ShortestPath;
                SupposeShortestPathNext = SupposeeRoutelist[SupposeShortestPathNext];
                if (SupposeShortestPathNext == GoalVertexIndex)
                {
                    break;
                }
            }
            break;
        }
    } while (1);

    if (CurrentVertex != GoalVertexIndex)
    {
        returnNext = SupposeeRoutelist[CurrentVertex];
    }
    else
    {
        returnNext = CurrentVertex;
    }


    Coordinate Next = GoalVertexIndex;
    Coordinate Current = GoalVertexIndex;
    vSupposBFSstack.clear();
    /* ����ǂ��Ȃ����Ƃ��m�F�������[�g�ōŒZ���������߂� */
    do
    {
        cv = GetConnectionVertex(Current);
        for (auto v : cv)
        {
            CurrentShortestRoutelist[v] = Current;
            vlist[v.y][v.x].SStatus = SearchStatus::E_Status_Looked;
            vSupposBFSstack.push_back(v);
        }
        if (vSupposBFSstack.empty() == true)
        {
            break;
        }
        Next = vSupposBFSstack.front();
        vSupposBFSstack.pop_front();
        Current = Next;

        if (Next == StartVertexIndex) // Current -> Goal
        { // ���[�g��������
            Coordinate CurrentShortestPathNext = StartVertexIndex;
            while (1)
            {
                vlist[CurrentShortestPathNext.y][CurrentShortestPathNext.x].SStatus = SearchStatus::E_Status_ShortestPath;
                CurrentShortestPathNext = CurrentShortestRoutelist[CurrentShortestPathNext];
                if (CurrentShortestPathNext == GoalVertexIndex)
                {
                    break;
                }
            }
            break;
        }
    } while (1);

    // ���̒��_���v�Z����
    return returnNext;
}


Coordinate AdachiHo::GetNextSearchStep(Coordinate CurrentVertex)
{
    Coordinate returnNext(0,0);
    std::vector<Coordinate> cv;

    static Coordinate SupposeNext = GoalVertexIndex;
    static Coordinate SupposeSearchCurrent = GoalVertexIndex;
    static std::deque<Coordinate> vSupposBFSstack;

    WallCheck(CurrentVertex);

    static bool first = true;
    if (first)
    {
        first = false;
        // ���z�T���X�e�[�^�X������
        for (auto& ylist : vlist)
        {
            for (auto& x : ylist)
            {
                x.SupposeSearchStatus = SearchStatus::E_Status_UnExplored;
            }
        }

        vSupposBFSstack.clear();
    }

    //while (1)
    do
    { /* goal -> start�Ɍ������čŒZ�o�H�����߂� ���D��T���őS�T������ */
        cv = GetSupposeConnectionVertex(SupposeSearchCurrent);
        for (auto v : cv)
        {
            SupposeeRoutelist[v] = SupposeSearchCurrent;
            vlist[v.y][v.x].SupposeSearchStatus = SearchStatus::E_Status_Looked;
            vSupposBFSstack.push_back(v);
        }
        SupposeNext = vSupposBFSstack.front();
        vSupposBFSstack.pop_front();
        vlist[SupposeNext.y][SupposeNext.x].pSupposeSearchFromVertexIndex = vlist[SupposeSearchCurrent.y][SupposeSearchCurrent.x];
        SupposeSearchCurrent = SupposeNext;

        if (SupposeNext == CurrentVertex) // Current -> Goal
        { // ���[�g��������
            Coordinate SupposeShortestPathNext = CurrentVertex;
            while (1)
            {
                vlist[SupposeShortestPathNext.y][SupposeShortestPathNext.x].SupposeSearchStatus = SearchStatus::E_Status_ShortestPath;
                SupposeShortestPathNext = SupposeeRoutelist[SupposeShortestPathNext];
                if (SupposeShortestPathNext == GoalVertexIndex)
                {
                    break;
                }
            }
            break;
        }
    } while (0);
    returnNext = SupposeSearchCurrent;

    //if (CurrentVertex != GoalVertexIndex)
    //{
    //    returnNext = SupposeeRoutelist[CurrentVertex];
    //}
    //else
    //{
    //    returnNext = CurrentVertex;
    //}

    // cv = GetConnectionVertex(CurrentVertex);
    // distans = INFINITY;
    // for (auto v : cv)
    // {
    //     // ���� = sqrt( (p1.x - p2.x)^2 + (p1.y - p2.y)^2 )
    //     dx = vlist[v].x - vlist[GoalVertexIndex].x;
    //     dy = vlist[v].y - vlist[GoalVertexIndex].y;
    //     float tempDist = std::sqrtf((dx * dx) + (dy * dy));
    //     if (distans > tempDist)
    //     {
    //         distans = tempDist;
    //         minimalNext = v;
    //     }
    // }
    // returnNext = minimalNext;

    // vlist[returnNext].pSearchFromVertexIndex = vlist[CurrentVertex].Index;

    // ���̒��_���v�Z����
    return returnNext;
}

bool AdachiHo::SearchNext(void)
{
    bool Finish = false;
    static int g = 0;
    if (CurrentVertexIndex == GoalVertexIndex)
    { // ���ݒn�ƖړI�n���ꏏ�Ȃ�T������
        //int count = 0;
        //Coordinate shortRouteIndex = GoalVertexIndex;
        //while (shortRouteIndex != StartVertexIndex)
        //{ // �S�[������X�^�[�g�܂ł��ǂ�
        //    vlist[shortRouteIndex.y][shortRouteIndex.x].SStatus = E_Status_ShortestPath;
        //    shortRouteIndex = GetNextSearchVertex(shortRouteIndex);
        //    count++;
        //}
        //ShortestPathDistance = count;
        Coordinate swap = StartVertexIndex;
        StartVertexIndex = GoalVertexIndex;
        GoalVertexIndex = swap;
        vlist[CurrentVertexIndex.y][CurrentVertexIndex.x].SStatus = E_Status_Searched;
        CurrentVertexIndex = GetNextSearchVertex(CurrentVertexIndex);
        vlist[CurrentVertexIndex.y][CurrentVertexIndex.x].SStatus = E_Status_Exploring;

        Finish = true;
    }
    else
    {
        vlist[CurrentVertexIndex.y][CurrentVertexIndex.x].SStatus = E_Status_Searched;
        CurrentVertexIndex = GetNextSearchVertex(CurrentVertexIndex);
        vlist[CurrentVertexIndex.y][CurrentVertexIndex.x].SStatus = E_Status_Exploring;
    }

    return Finish;
}



