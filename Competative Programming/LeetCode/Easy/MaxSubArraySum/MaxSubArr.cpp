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
    int maxSubArray(vector<int> &nums) {
        int curMax = 0;
        int result = numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            curMax = max((curMax + nums[i]), nums[i]);
            result = max(result, curMax);
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
