#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

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
    void levelOrderRecursive(TreeNode *root, vector<vector<int>> &result,
                             int level) {
        if (root == nullptr) {
            return;
        }

        while (level > result.size() - 1) {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);

        levelOrderRecursive(root->left, result, level + 1);
        levelOrderRecursive(root->right, result, level + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;

        if (root == nullptr) {
            return result;
        } else {
            vector<int> currVec;
            currVec.push_back(root->val);
            result.push_back(currVec);
        }

        levelOrderRecursive(root->left, result, 1);
        levelOrderRecursive(root->right, result, 1);
        reverse(result.begin(), result.end());

        return result;
    }
};

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return 0;
    }
