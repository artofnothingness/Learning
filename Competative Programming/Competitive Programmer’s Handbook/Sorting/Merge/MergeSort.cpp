#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int> &vec, size_t l, size_t m, size_t r) {
  size_t lVecSize = m - l + 1;
  size_t rVecSize = r - m;

  std::vector<int> lVec(lVecSize);
  std::vector<int> rVec(rVecSize);

  for(int i; i < lVecSize; i++) {
    lVec[i] = vec[l + i];
  }

  for(int j; j < rVecSize; j++) {
    rVec[j] = vec[m + 1 + j];
  }

  int i = 0, j = 0, k = l;
  while (i < lVecSize && j < rVecSize) {
    if(lVec[i] <= rVec[j]) {
      vec[k] = lVec[i];
      i++;
    } else {
      vec[k] = rVec[j];
      j++;
    }
    k++;
  }

  while(i < lVecSize) {
    vec[k] = lVec[i];
    i++;
    k++;
  }

  while(j < rVecSize) {
    vec[k] = rVec[j];
    j++;
    k++;
  }
}

void mergeSort(std::vector<int> &vec, size_t l, size_t r) {
  if (l < r) {
    size_t m = (l + r) / 2;
    mergeSort(vec, l, m);
    mergeSort(vec, m + 1, r);

    merge(vec, l, m, r);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::vector<int> vec {1,5,2,1,5,8,2};

  for(auto q : vec) {
    printf("%d ", q);
  }
  printf("\n");

  mergeSort(vec, 0, vec.size() - 1);

  for(const auto &q : vec) {
    printf("%d ", q);
  }

  return 0;
}
