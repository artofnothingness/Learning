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
    void hasPathSumRecursive(TreeNode *root, int sum, int currSum,
                             bool &hasPathSum) {
        if (hasPathSum) {
            return;
        }

        if (!root) {
            return;
        }

        currSum += root->val;
        if (currSum == sum && (!root->left && !root->right)) {
            hasPathSum = true;
            return;
        }

        hasPathSumRecursive(root->left, sum, currSum, hasPathSum);
        hasPathSumRecursive(root->right, sum, currSum, hasPathSum);
    }

    bool hasPathSum(TreeNode *root, int sum) {
        bool hasPS = false;
        hasPathSumRecursive(root, sum, 0, hasPS);
        return hasPS;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
