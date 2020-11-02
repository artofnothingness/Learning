#include <iostream>
#include <limits>
#include <map>
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

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int max = 0;
        int i = 0;
        string result = ""s;
        char currChar;
        if (strs.size() == 0) {
            return ""s;
        } else if (strs.size() == 1) {
            return strs[0];
        }
        while (true) {
            if (i < strs[0].size())
                currChar = strs[0][i];
            else
                break;

            for (int q = 0; q < strs.size(); q++) {
                if (i < strs[q].size()) {
                    if (currChar != strs[q][i]) {
                        goto endPoint;
                    }
                } else
                    goto endPoint;
                if (q == strs.size() - 1) {
                    i++;
                    result += currChar;
                }
            }
        }
    endPoint:
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution a = Solution();
    vector<string> vecStr = {"qwerty", "qwesdf", "qwezxc"};
    cout << a.longestCommonPrefix(vecStr);

    return 0;
}
