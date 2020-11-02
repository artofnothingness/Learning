#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  std::vector<int> container{1, 2, 5, -2, -5, 10};
  std::sort(container.begin(), container.end());
  int ellSearched = 2;

  size_t k = 0;
  size_t n = container.size();
  for(int b = n / 2; b >= 1; b /= 2) {
    while ((k + b) < n && (container[k + b] <= ellSearched)) {
      k += b;
    }
  }

  std::cout << k;
  return 0;
}
