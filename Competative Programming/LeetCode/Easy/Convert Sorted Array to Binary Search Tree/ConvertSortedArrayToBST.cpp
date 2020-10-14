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
    void sortedArrayToBST(TreeNode *&node, vector<int> &nums, int l, int r) {
        if (l > r) {
            return;
        }
        int m = (r - l) / 2 + l;
        node = new TreeNode;
        node->val = nums[m];

        sortedArrayToBST(node->left, nums, l, m - 1);
        sortedArrayToBST(node->right, nums, m + 1, r);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 0) {
            return nullptr;
        }

        TreeNode *root;

        int l = 0;
        int r = nums.size() - 1;
        sortedArrayToBST(root, nums, l, r);
        return root;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
