#include <algorithm>
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


class Solution {
public:
    string addBinary(string a, string b) {
        int m = max(a.size(), b.size()) + 1;
        string result(m, '0');
        m -= 1;
        int i = a.size() - 1;
        int j = b.size() - 1;
        bool hasExtra = false;
        while (i >= 0 && j >= 0) {
            if (a[i] == '1' && b[j] == '1') {
                if (hasExtra) {
                    result[m] = '1';
                } else {
                    result[m] = '0';
                    hasExtra = true;
                }
            } else if (a[i] == '1' || b[j] == '1') {
                if (hasExtra) {
                    result[m] = '0';
                } else {
                    result[m] = '1';
                    hasExtra = false;
                }
            } else {
                if (hasExtra) {
                    result[m] = '1';
                    hasExtra = false;
                }
            }
            i--;
            j--;
            m--;
        }

        if (i > j) {
            while (i >= 0) {
                if (hasExtra) {
                    if (a[i] == '1') {
                        result[m] = '0';
                    } else {
                        result[m] = '1';
                        hasExtra = false;
                    }
                } else {
                    result[m] = a[i];
                }
                --i;
                --m;
            }
        } else if (j > i){
            while (j >= 0) {
                if (hasExtra) {
                    if (b[j] == '1') {
                        result[m] = '0';
                    } else {
                        result[m] = '1';
                        hasExtra = false;
                    }
                } else {
                    result[m] = b[j];
                }
                --j;
                --m;
            }
        }

        if (hasExtra) {
            result[0] = '1';
        } else {
            result = result.substr(1, result.size());
        }
        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol= Solution();
    string a = "11";
    string b = "1";
    cout << sol.addBinary(a, b);

    return 0;
}
