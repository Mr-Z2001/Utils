#ifndef __FUNCS_HPP__
#define __FUNCS_HPP__

#include <cctype>
#include <random>
#include <vector>

int64_t singleRandom(int64_t _min, int64_t _max);
std::vector<int64_t> listRandom(int64_t _min, int64_t _max, int64_t _count,
                                bool uniqueFlag);
int64_t selectRandom(std::vector<int64_t> &range);
std::vector<int64_t> selectRangeRandom(std::vector<int64_t> &range,
                                       int64_t _count, bool uniqueFlag);

#endif // __FUNCS_HPP__