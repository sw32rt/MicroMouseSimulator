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

    // 探索順リストクリア
    NextSearchVertexStack.clear();

    // 探索済み情報クリア
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

    // 仮想探索ステータス初期化
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
    { /* goal -> startに向かって最短経路を求める 幅優先探索で全探索する */
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
        { // ルート見つかった
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
    /* 現状壁がないことを確認したルートで最短距離を求める */
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
        { // ルート見つかった
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

    // 次の頂点を計算する
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
        // 仮想探索ステータス初期化
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
    { /* goal -> startに向かって最短経路を求める 幅優先探索で全探索する */
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
        { // ルート見つかった
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
    //     // 距離 = sqrt( (p1.x - p2.x)^2 + (p1.y - p2.y)^2 )
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

    // 次の頂点を計算する
    return returnNext;
}

bool AdachiHo::SearchNext(void)
{
    bool Finish = false;
    static int g = 0;
    if (CurrentVertexIndex == GoalVertexIndex)
    { // 現在地と目的地が一緒なら探索完了
        //int count = 0;
        //Coordinate shortRouteIndex = GoalVertexIndex;
        //while (shortRouteIndex != StartVertexIndex)
        //{ // ゴールからスタートまでたどる
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



