#include <cstddef>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;

using vecInt = vector<int>;
using vecPairInt = vector<pair<int, int>>;

using vecDb = vector<double>;
using vecPairDb = vector<pair<double, double>>;

class Solution {
public:
  bool isPalindrome(int x) {
    vector<int> numbers;
    numbers.reserve(31);
    if (x < 0) {
      return false;
    }

    while (x != 0) {
      numbers.push_back(x % 10);
      x /= 10;
    }

    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
      if (numbers[i] != numbers[j]) {
        return false;
      } else {
        i++;
        j--;
      }
    }
    return true;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  Solution sol = Solution();
  cout << sol.isPalindrome(121);
  cout << sol.isPalindrome(122);
  cout << sol.isPalindrome(-122);
  cout << sol.isPalindrome(-121);

  return 0;
}
