#include "funcs.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void DisplayMenu() {
  cout << "Menu" << endl;
  cout << "-----------" << endl;
  cout << "1. Generate single random integer" << endl;
  cout << "2. Generate a list of random interger" << endl;
  cout << "3. Generate a ramdon integer from a given list" << endl;
  cout << "4. Generate a random subset from a given list" << endl;
}

bool readFlag(bool &quit) {
  char c;
  bool ret;
  do {
    cin >> c;
    if (c == 'y' || c == 'Y') {
      ret = true;
      break;
    } else if (c == 'n' || c == 'N') {
      ret = false;
      break;
    } else if (c == 'q' || c == 'Q') {
      quit = true;
      break;
    }
  } while (1);
  return ret;
}

int main() {
  DisplayMenu();
  int option;
  cin >> option;
  int64_t _min, _max, res, _count;
  bool uniqueFlag, end = false;
  char c;
  std::vector<int64_t> v_in, v_out;
  switch (option) {
    end = false;
  case 1:
    cout << "Please input minimum and maximum integer" << endl;
    cout << "Min: ";
    cin >> _min;
    cout << "Max: ";
    cin >> _max;
    res = singleRandom(_min, _max);
    cout << res << endl;
    break;
  case 2:
    cout << "Please input minimum and maximum integer, and the count" << endl;
    cout << "Min: ";
    cin >> _min;
    cout << "Max: ";
    cin >> _max;
    cout << "Count: ";
    cin >> _count;
    cout << "Need to be unique?(y/n/q)";
    uniqueFlag = readFlag(end);
    if (end)
      break;
    v_out = listRandom(_min, _max, _count, uniqueFlag);
    for (auto v : v_out)
      cout << v << '\t';
    break;
  case 3:
    cout << "Please input the list" << endl;
    cout << "The size of the list" << endl;
    cin >> _count;
    cout << "Please input the list, seperated by space" << endl;
    v_in.clear();
    while (_count--) {
      cin >> res;
      v_in.emplace_back(res);
    }
    res = selectRandom(v_in);
    cout << res << endl;
    break;
  case 4:
    cout << "Please input the list, the number of elements you want" << endl;
    cout << "The size of the list" << endl;
    cin >> _count;
    cout << "The size of the results" << endl;
    cin >> _max;
    cout << "Please input the list, seperated by space" << endl;
    v_in.clear();
    while (_count--) {
      cin >> res;
      v_in.emplace_back(res);
    }
    cout << "Need to be unique?(y/n/q)";
    uniqueFlag = readFlag(end);
    if (end)
      break;
    if (end)
      break;
    v_out = selectRangeRandom(v_in, _max, uniqueFlag);
    for (auto v : v_out)
      cout << v << '\t';
    break;
  default:
    std::cerr << "Invalid option, please select again" << endl;
    break;
  }
}