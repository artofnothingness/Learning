#include <iostream>
#include <vector>


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  // Go through subsets of set of n ellements
  int b;
  int n = 5;
  for (b = 0; b < (1 << n); b++) {
    std::cout << b << std::endl;
  }

  // Create Vec with ells corresponding bit mask
  for (int b = 0; b < (1 << n); b++) {
    std::vector<int> subset;
    for(int i = 0; i < n; i++) {
      if (b & (1 << i)) 
        subset.push_back(i);
    }

    for (auto x : subset) {
      printf("%d ", x);
    }
    printf("\n");
  }
  

  return 0;
}
