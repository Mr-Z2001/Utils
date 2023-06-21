#include "funcs.hpp"
#include <cassert>
#include <unordered_map>

std::mt19937_64 rng(std::random_device{}());

int64_t singleRandom(int64_t _min, int64_t _max) {
  int64_t mod = _max - _min + 1;
  int64_t ret = rng() % mod + _min;
  return ret;
}

std::vector<int64_t> listRandom(int64_t _min, int64_t _max, int64_t _count,
                                bool uniqueFlag) {
  std::unordered_map<int, int> um;
  std::vector<int64_t> ret;
  int64_t x;
  int64_t mod = _max - _min + 1;
  while (ret.size() < _count) {
    x = rng() % mod + _min;
    if (uniqueFlag)
      if (um.find(x) == um.end())
        ret.emplace_back(x);
      else
        ;
    else
      ret.emplace_back(x);
    um[x]++;
  }
  return ret;
}

int64_t selectRandom(std::vector<int64_t> &range) {
  int64_t mod = range.size();
  int64_t idx = rng() % mod;
  assert(idx >= 0 && idx < range.size());
  return range[idx];
}

std::vector<int64_t> selectRangeRandom(std::vector<int64_t> &range,
                                       int64_t _count, bool uniqueFlag) {
  std::unordered_map<int, int> um, distinctValueCount;
  int64_t mod = range.size();
  int64_t idx = -1;
  std::vector<int64_t> ret;

  for (auto v : range)
    distinctValueCount[v]++;

  if (uniqueFlag)
    assert(_count >= distinctValueCount.size());

  while (ret.size() < _count) {
    idx = rng() % mod;
    if (uniqueFlag)
      if (um.find(idx) == um.end())
        ret.emplace_back(range[idx]);
      else
        ;
    else
      ret.emplace_back(range[idx]);
    um[idx]++;
  }
  return ret;
}
