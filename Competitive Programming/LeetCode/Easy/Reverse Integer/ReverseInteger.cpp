#include <iostream>
#include <limits>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}

class Solution {
public:
  int reverse(int x) {
    long long lx = x;
    long long result = 0;

    while (true) {
      result += lx % 10;
      lx /= 10;
      if (lx == 0)
        break;
      else
        result *= 10;
    }
    if (result >= numeric_limits<int>::max() ||
        result <= numeric_limits<int>::min())
      return 0;
    return result;
  }
};
