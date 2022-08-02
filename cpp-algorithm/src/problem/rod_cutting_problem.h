#ifndef CPP_ALGORITHM_ROD_CUTTING_PROBLEM_H
#define CPP_ALGORITHM_ROD_CUTTING_PROBLEM_H

#include <map>
#include <vector>

namespace rodcutting
{
    int CutRod(const std::map<int, int>& price, const int length);
    int MemoizedCutRod(const std::map<int, int>& price, const int length);
    int MemoizedCutRodAux(const std::map<int, int>& price, const int length, std::vector<int>& memo);
    int BottomUpCutRod(const std::map<int, int>& price, const int length);
} // namespace rodcutting

#endif
