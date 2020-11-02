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

template <class T, template <class, class...> class Container>
void printCont(Container<T> cont) {
    for (auto i : cont) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution_0 {
public:
    int climbStairs(int n) { return climbRecursive(0, n); }

    int climbRecursive(int i, int n) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        return climbRecursive(i + 1, n) + climbRecursive(i + 2, n);
    }
};

class Solution_1 {
public:
    int climbStairs(int n) {
        vector<int> memo(n);
        return climbRecursive(0, n, memo);
    }

    int climbRecursive(int i, int n, vector<int> &memo) {
        if (i > n) {
            return 0;
        }

        if (i == n) {
            return 1;
        }

        if( memo[i] > 0 ) {
            return memo[i];
        }

        memo[i] = climbRecursive(i + 1, n, memo) + climbRecursive(i + 2, n, memo);
        return memo[i];
    }
};

class Solution_2 {
public:
    int climbStairs(int n) {
        int result = 0;
        int r1 = 0;
        int r2 = 1;
        for (int i = 0; i < n; ++i) {
            result = r1 + r2;
            r1 = r2;
            r2 = result;
        }

        return result;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
