#include <iostream>
#include <vector>

void searchPermutation(int n) {
  std::vector<int> permutation; 
  std::vector

  if(permutation.size() == n) {
    for(auto q : permutation) {
      printf("%d", q);
    }
    printf("\n");
  } else {
     for (int i = 0; i < n; i ++) {
        if(chosen[i]) continue;
        chosen[i] = true;
        permutation.push_back(i);
        searchPermutation(n);
        chosen[i] = false;
        permutation.pop_back();
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> permutation;
  std::vector<bool> chosen(n, true);

  searchPermutation(5);

  return 0;
}
