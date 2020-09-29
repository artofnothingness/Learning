#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
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
    bool isValid(string s) {
        unordered_map<char, char> chars({{'}', '{'}, {']', '['}, {')', '('}});
        stack<char> st;
        for (auto ch : s) {
            if (chars.find(ch) != chars.end()) {
                if (st.empty())
                    return false;
                else if (chars[ch] == st.top())
                    st.pop();
                else {
                    return false;
                }
            } else {
                st.push(move(ch));
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol = Solution();
    cout << sol.isValid("()");
    cout << sol.isValid("([])");
    cout << sol.isValid("([)]");

    return 0;
}
