/* Kadane Algorithm */

#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> container {1, 2, -2, 5, -9, 6};

  int currPosBestSum = 0;
  int bestSum = 0;
  for(size_t q = 0; q < container.size(); q++) {
    currPosBestSum = std::max(container[q], currPosBestSum + container[q]);
    bestSum = std::max(currPosBestSum, bestSum);
  }

  std::cout << bestSum << std::endl;
  return 0;
}
