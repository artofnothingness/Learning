#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>


struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x) 
      return x < p.x;
    else return y < p.y;
  }
};

bool comp(std::string a, std::string b) {
  if (a.size() != b.size()) 
    return a.size() < b.size();
  return a < b;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Vector sort
  std::vector<int> v = {4, 2, 5, 3, 5, 8, 3};
  std::vector<int> vr = {4, 2, 5, 3, 5, 8, 3};
  std::sort(v.begin(), v.end());
  std::sort(vr.rbegin(), vr.rend());

  // Ordinary array sort
  int n = 7; // array size
  int a[] = {4, 2, 5, 3, 5, 8, 3};
  std::sort(a, a + n);

  // String sort
  std::string s = "monkey";
  std::sort(s.begin(), s.end());
  return 0;

  // Pair sort
  std::vector<std::pair<int,int>> vp;
  vp.push_back({1,5});
  vp.push_back({2,3});
  vp.push_back({1,2});
  sort(vp.begin(), vp.end());

  std::vector<std::tuple<int,int,int>> vt;
  vt.push_back({2,1,4});
  vt.push_back({1,5,3});
  vt.push_back({2,1,3});
  sort(vt.begin(), vt.end());

}
