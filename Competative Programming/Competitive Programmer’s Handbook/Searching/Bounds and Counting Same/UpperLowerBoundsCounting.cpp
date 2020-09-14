#include <iostream>
#include <ostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::vector<int> vec {1, 2, 3, 4, 5, 2, 2};
  std::sort(vec.begin(), vec.end());

  int valueSearched = 2;

  auto k = std::lower_bound(vec.begin(), vec.end(), valueSearched);
  auto n = vec.size();
  if (k < vec.end() && *k == valueSearched) {
    std::cout << *k << " ";
    std::cout << "at position " << k - vec.begin() << std::endl;
  }

  auto a = std::lower_bound(vec.begin(), vec.end(), valueSearched);
  auto b = std::upper_bound(vec.begin(), vec.end(), valueSearched);
  std::cout << b - a << "\n";

  auto r = std::equal_range(vec.begin(), vec.end(), valueSearched);
  std::cout << r.second - r.first << "\n";

  return 0;
}
