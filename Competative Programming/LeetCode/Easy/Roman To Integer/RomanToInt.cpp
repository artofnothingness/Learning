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
    int romanToInt(string s) {
        unordered_map<char, int> charMap{{'I', 1},   {'V', 5},   {'X', 10},
                                         {'L', 50},  {'C', 100}, {'D', 500},
                                         {'M', 1000}};
        int result = 0;
        int s2 = 0;
        int s1 = charMap[s[0]];
        int i = 0;
        while (i < s.size()) {
            s1 = charMap[s[i]];
            if (i + 1 < s.size()) {
                s2 = charMap[s[i + 1]];
                if (s1 < s2) {
                    result += s2 - s1;
                    i++;
                } else {
                    result += s1;
                }
            } else {
                result += s1;
            }
            i++;
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol = Solution();

    cout << sol.romanToInt("II"s);
    cout << sol.romanToInt("IV"s);
    cout << sol.romanToInt("IX"s);

    return 0;
}
