#include <iostream>
#include <algorithm>

#include <vector>
#include <set>
#include <unordered_set>


int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  std::vector<int> v1 {1, -2, 3, -5, 7};
  std::vector<int> v2 {1, 2, 3, 5, 7};


  std::set<int> s1 {1, -2, 3, -5, 7};
  std::set<int> s2 {1, 2, 3, 5, 7};

  std::unordered_set<int> us1 {1, -2, 3, -5, 7};
  std::unordered_set<int> us2 {1, 2, 3, 5, 7};

  int count1 = 0;
  for (auto x : s1) {
    if(s2.find(x) != s2.end())  {
      count1++;
    }
  }

  int count2 = 0;
  for (auto x : us1) {
    if(us2.find(x) != us2.end()) {
      count2++;
    }
  }

  int count3 = 0;
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  int minSize = std::min(v1.size(), v2.size());
  int q = 0, w = 0; 
  while (q < minSize || w < minSize) {
    if(v1[q] == v2[w])  {
      count3++;
      q++;
      w++;
    } else if (v1[q] > v2[w]) {
      w++;
    } else {
      q++;
    }
  }

  std::cout << count1 << " " << count2 << " " << count3 << std::endl;
  return 0;
}
