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
    void isSameRecursive(TreeNode *p, TreeNode *q, bool &isEqual) {
        if (isEqual != false) {
            if (p == nullptr && q != nullptr) {
                isEqual = false;
            } else if (q == nullptr && p != nullptr) {
                isEqual = false;
            } else if (q == nullptr && p == nullptr) {
                return;
            } else if (q != nullptr && q != nullptr) {
                if (p->val != q->val) {
                    isEqual = false;
                }
            }
        }
        if (isEqual == false) {
            return;
        } else {
            isSameRecursive(p->left, q->left, isEqual);
            isSameRecursive(p->right, q->right, isEqual);
        }
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        bool isEqual = true;
        isSameRecursive(p, q, isEqual);
        return isEqual;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
