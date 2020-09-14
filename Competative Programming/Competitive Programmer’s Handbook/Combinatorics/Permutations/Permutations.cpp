#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> vec{1,2,3,4,5,6};

  do {
    for(int q : vec) {
      printf("%d ", q);
    }
    printf("\n");
  } while (std::next_permutation(vec.begin(), vec.end()));

  return 0;
}
