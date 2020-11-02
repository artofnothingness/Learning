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
    int isBalancedRecursive(TreeNode *root, bool &isBT, int level) {
        if (!isBT)
            return 0;

        if (root == nullptr) {
            return level;
        }

        int left = isBalancedRecursive(root->left, isBT, level + 1);
        int right = isBalancedRecursive(root->right, isBT, level + 1);

        if (abs(left - right) > 1)
            isBT = false;

        return max(left, right);
    }

    bool isBalanced(TreeNode *root) {
        bool isBal = true;
        int level = 1;

        isBalancedRecursive(root, isBal, level);

        return isBal;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
