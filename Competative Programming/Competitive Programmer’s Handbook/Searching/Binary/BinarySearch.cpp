#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  std::vector<int> container{1, 2, 5, -2, -5, 10};
  std::sort(container.begin(), container.end());

  int x = 2;

  size_t l = 0;
  size_t r = container.size() - 1;

  size_t m = 0;
  int mEll = 0;
  while (l <= r) {
    m = (r + l) / 2;
    mEll = container[m];
    if (mEll == x ) {
      break;
    } else if(mEll < x) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  std::cout << mEll << " " << m;
  return 0;
}
