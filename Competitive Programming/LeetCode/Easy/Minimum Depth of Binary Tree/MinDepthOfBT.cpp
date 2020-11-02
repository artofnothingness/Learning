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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepthRecursive(TreeNode *root, int level, int &minLevel) {
        if (level > minLevel || !root) {
            return numeric_limits<int>::max();
        }

        if (!root->left && !root->right) {
            minLevel = level;
            return level;
        }

        return min(minDepthRecursive(root->left, level + 1, minLevel),
                   minDepthRecursive(root->right, level + 1, minLevel));
    }

    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int minLimit = numeric_limits<int>::max();

        return minDepthRecursive(root, 1, minLimit);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
