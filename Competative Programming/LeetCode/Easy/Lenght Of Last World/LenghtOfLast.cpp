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
    int lengthOfLastWord(string s) {
        int count = 0;
        bool isEntered = false;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                count++;
                isEntered = true;
            } else if (isEntered) {
                return count;
            }
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
