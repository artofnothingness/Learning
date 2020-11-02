/* Kadane Algorithm */

#include <iostream>
#include <vector>

template<typename T, typename Containter>
T getBestSubSum(const Containter& container) {
  T currPosBestSum = 0;
  T bestSum = 0;

  for(size_t q = 0; q < container.size(); q++) {
    currPosBestSum = std::max(container[q], currPosBestSum + container[q]);
    bestSum = std::max(currPosBestSum, bestSum);
  }
  return bestSum;
}


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  std::vector<int> sampleVec {1, 2, -2, 5, -9, 6};
  int bestSum = getBestSubSum<int, std::vector<int> >(sampleVec);
  std::cout << bestSum << std::endl;
  return 0;
}
