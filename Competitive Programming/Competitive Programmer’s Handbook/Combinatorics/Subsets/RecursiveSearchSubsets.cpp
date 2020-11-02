#include <iostream>
#include <vector>

void searchSubsets(std::vector<int> vec, int k, int n) {
  if (k == n) {
    for(auto x : vec) {
      printf("%d ", x);
    }
    printf("\n");
  }
  else {
    searchSubsets(vec, k + 1, n);
    vec.push_back(k);
    searchSubsets(vec, k + 1, n);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> v;
  searchSubsets(v, 0, 5);

  return 0;
}
