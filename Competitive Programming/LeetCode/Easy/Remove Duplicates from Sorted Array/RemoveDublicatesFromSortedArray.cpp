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

template <class T> void pVec(vector<T> vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int count = 0;
        int i = 0;
        for (int j = 1; j < nums.size(); ++j) {

        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol = Solution();
    vector<int> arg = {1, 2, 2, 3, 3, 4, 5, 7};
    cout << sol.removeDuplicates(arg);

    return 0;
}
