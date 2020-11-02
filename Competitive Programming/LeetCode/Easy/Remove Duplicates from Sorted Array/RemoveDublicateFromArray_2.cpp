#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <limits>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

using vecInt = vector<int>;
using vecPairInt = vector<pair<int,int>>;

using vecDb = vector<double>;
using vecPairDb = vector<pair<double,double>>;

template <class T> void pVec(vector<T> vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        return nums.size();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
