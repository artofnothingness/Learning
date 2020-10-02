#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

using vecInt = vector<int>;
using vecPairInt = vector<pair<int, int>>;

using vecDb = vector<double>;
using vecPairDb = vector<pair<double, double>>;

template <typename T> void pVec(vector<T> vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        int l = 1;
        int r = x;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (m <= 1.0 * x / m) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
