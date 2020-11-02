#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
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

template <class T, template <class, class...> class Container>
void printCont(Container<T> cont) {
    for (auto i : cont) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        string curResult = "";

        for (int i = 1; i < n; ++i) {
            int j = 0;
            int k = 0;
            for (; j < result.size();) {
                char sym = result[j];
                int counter = 1;
                for (k = j + 1; k < result.size(); ++k) {
                    if (result[k] == sym) {
                        counter++;
                        j++;
                    } else {
                        break;
                    }
                }
                curResult += to_string(counter) + sym;
                j = k;
            }
            result = curResult;
            curResult = "";
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol = Solution();

    cout << sol.countAndSay(1) << endl;
    cout << sol.countAndSay(2) << endl;
    cout << sol.countAndSay(3) << endl;
    cout << sol.countAndSay(4) << endl;
    cout << sol.countAndSay(5) << endl;
    cout << sol.countAndSay(6) << endl;

    return 0;
}
