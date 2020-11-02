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
    bool isSymmetricDouble(TreeNode *lhs, TreeNode *rhs) {
        if (lhs == nullptr && rhs == nullptr) {
            return true;
        } else if (lhs == nullptr || rhs == nullptr) {
            return false;
        } else if (lhs->val != rhs->val) {
            return false;
        }
        return isSymmetricDouble(lhs->left, rhs->right) &&
               isSymmetricDouble(lhs->right, rhs->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetricDouble(root->right, root->left);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
