#include "pch.h"
#include "AdachiHo.h"
#include <cmath>

AdachiHo::~AdachiHo()
{
}

void AdachiHo::init(int StartVertexIndex, int GoalVertexIndex)
{
    this->CurrentVertexIndex = StartVertexIndex;
    this->StartVertexIndex = StartVertexIndex;
    this->GoalVertexIndex = GoalVertexIndex;

    // �T�������X�g�N���A
    NextSearchVertexStack.clear();

    // �T���ςݏ��N���A
    for (int i = 0; i < routelist.size(); i++)
    {
        routelist.at(i) = -1;
    }
    Initialize();
}

int AdachiHo::GetNextSearchVertex(int CurrentVertex)
{
    float dx = 0;
    float dy = 0;
    float distans = INFINITY;
    int minimalNext = 0;
    int returnNext = 0;
    std::vector<int> cv;

    int SupposeNext = GoalVertexIndex;
    int SupposeSearchCurrent = GoalVertexIndex;
    static std::deque<int> vSupposBFSstack;

    WallCheck(CurrentVertex);

    // ���z�T���X�e�[�^�X������
    for (auto& v : vlist)
    {
        v.SupposeSearchStatus = SearchStatus::E_Status_UnExplored;
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
            vlist[v].SupposeSearchStatus = SearchStatus::E_Status_Looked;
            vSupposBFSstack.push_back(v);
        }
        SupposeNext = vSupposBFSstack.front();
        if (SupposeNext == 0xf41)
        {
            int debug = 0;
        }
        vSupposBFSstack.pop_front();
        vlist[SupposeNext].pSupposeSearchFromVertexIndex = vlist[SupposeSearchCurrent].Index;
        SupposeSearchCurrent = SupposeNext;

        if (SupposeNext == CurrentVertex) // Current -> Goal
        { // ���[�g��������
            int SupposeShortestPathNext = CurrentVertex;
            while (1)
            {
                vlist[SupposeShortestPathNext].SupposeSearchStatus = SearchStatus::E_Status_ShortestPath;
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


int AdachiHo::GetNextSearchStep(int CurrentVertex)
{
    float dx = 0;
    float dy = 0;
    int minimalNext = 0;
    int returnNext = 0;
    std::vector<int> cv;

    static int SupposeNext = GoalVertexIndex;
    static int SupposeSearchCurrent = GoalVertexIndex;
    static std::deque<int> vSupposBFSstack;

    WallCheck(CurrentVertex);

    static bool first = true;
    if (first)
    {
        first = false;
        // ���z�T���X�e�[�^�X������
        for (auto& v : vlist)
        {
            v.SupposeSearchStatus = SearchStatus::E_Status_UnExplored;
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
            vlist[v].SupposeSearchStatus = SearchStatus::E_Status_Looked;
            vSupposBFSstack.push_back(v);
        }
        SupposeNext = vSupposBFSstack.front();
        if (SupposeNext == 0xf41)
        {
            int debug = 0;
        }
        vSupposBFSstack.pop_front();
        vlist[SupposeNext].pSupposeSearchFromVertexIndex = vlist[SupposeSearchCurrent].Index;
        SupposeSearchCurrent = SupposeNext;

        if (SupposeNext == CurrentVertex) // Current -> Goal
        { // ���[�g��������
            int SupposeShortestPathNext = CurrentVertex;
            while (1)
            {
                vlist[SupposeShortestPathNext].SupposeSearchStatus = SearchStatus::E_Status_ShortestPath;
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
        //int shortRouteIndex = GoalVertexIndex;
        //while (shortRouteIndex != StartVertexIndex)
        //{ // �S�[������X�^�[�g�܂ł��ǂ�
        //    vlist[shortRouteIndex].SStatus = E_Status_ShortestPath;
        //    shortRouteIndex = routelist[shortRouteIndex];
        //    count++;
        //}
        //ShortestPathDistance = count;
        int swap = StartVertexIndex;
        StartVertexIndex = GoalVertexIndex;
        GoalVertexIndex = swap;
        vlist[CurrentVertexIndex].SStatus = E_Status_Searched;
        //CurrentVertexIndex = GetNextSearchVertex(CurrentVertexIndex);
        CurrentVertexIndex = GetNextSearchStep(CurrentVertexIndex);
        vlist[CurrentVertexIndex].SStatus = E_Status_Exploring;

        Finish = true;
    }
    else
    {
        vlist[CurrentVertexIndex].SStatus = E_Status_Searched;
        //CurrentVertexIndex = GetNextSearchVertex(CurrentVertexIndex);
        CurrentVertexIndex = GetNextSearchStep(CurrentVertexIndex);
        vlist[CurrentVertexIndex].SStatus = E_Status_Exploring;
    }

    return Finish;
}



