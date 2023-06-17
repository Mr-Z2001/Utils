#ifndef __CSR_HPP__
#define __CSR_HPP__

#include <iostream>
#include <vector>

typedef std::pair<int, int> pii;

template <class value_t> class CSR {
private:
  std::vector<value_t> v;
  std::vector<int> col;
  std::vector<int> row;

public:
  std::vector<pii> getCoordinate(value_t val) const {
    std::vector<int> indices;
    std::vector<int> cols;
    std::vector<int> rows;
    for (int i = 0; i < v.size(); ++i)
      if (val_i == val)
        indices.push_back(i);
    for (auto i : indices) {
      cols.push_back(col[i]);
      for (int j = 0; j < row.size(); ++j)
        if (i < row[j])
          rows.push_back(j);
    }
    std::vector<pii> ret;
    for (int i = 0; i < indices.size(); ++i)
      ret.push_back(pii(rows[i], cols[i]));
    return ret;
  }
  void add(value_t val, int i, int j) {
    if (i < 0 || i >= row.size() || j < 0 || j >= row.size())
      return;
    int new_pos = row[i];
    if (row[i] == row[i + 1] ||
        col[new_pos] > j) { // no element in this row or insert at the beginning
      col.insert(col.begin() + new_pos, j);
      v.insert(v.begin() + new_pos, val);
      for (int k = i + 1; k < row.size(); ++k)
        ++row[k];
    } else if (col[new_pos] == j) { // do nothing.
      return;
    } else {
      for (int k = row[i]; k < row[i + 1]; ++k)
        if (col[k] > j) {
          col.insert(col.begin() + k, j);
          v.insert(v.begin() + k, val);
          for (int l = i + 1; l < row.size(); ++l)
            ++row[l];
          break;
        }
    }
  }

  void update(value_t val, int i, int j) {
    if (i < 0 || i >= row.size() || j < 0 || j >= row.size())
      return;
    int index = row[i];
    for (int k = row[i]; k < row[i + 1]; ++k)
      if (col[k] == j) {
        index = k;
        break;
      }
    v[index] = val;
  }

  void remove(int i, int j) {
    if (i < 0 || i >= row.size() || j < 0 || j >= row.size())
      return;
    int index = row[i];
    for (int k = row[i]; k < row[i + 1]; ++k)
      if (col[k] == j) {
        index = k;
        break;
      }
    col.erase(col.begin() + index);
    v.erase(v.begin() + index);
    for (int k = i + 1; k < row.size(); ++k)
      --row[k];
  }

  value_t get(int i, int j) const {
    if (i < 0 || i >= row.size() || j < 0 || j >= row.size()) {
      std::cerr << "i: " << i << " j: " << j << std::endl;
      std::cerr << "row.size(): " << row.size() << std::endl;
      std::cerr << "col.size(): " << col.size() << std::endl;
      std::cerr << "Invalid index in CSR::get()" << std::endl;
      exit(EXIT_FAILURE);
    }
    for (int k = row[i]; k < row[i + 1]; ++k)
      if (col[k] == j)
        return v[k];
    std::cerr << "No value in " << i << " " << j << std::endl;
    exit(EXIT_FAILURE);
  }
};

#endif // __CSR_HPP__
