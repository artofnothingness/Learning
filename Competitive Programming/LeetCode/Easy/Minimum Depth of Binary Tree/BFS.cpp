#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <limits>

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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int level = 1;
		
        if(root == nullptr)     //prevents pushing null node
            return 0;
		
        q.push(root);
        while(!q.empty())
        {
            int nodes = q.size();
            while(nodes)        //while nodes != 0
            {
                TreeNode* front = q.front();
                q.pop();
				
                if(front->left == nullptr && front->right == nullptr)//if left && right = null, leaf node
                    return level;           //return level of first leaf node    
                if(front->left)     //prevents pushing a null node for processing
                    q.push(front->left);
                if(front->right)    //prevents pushing a null node for processing
                    q.push(front->right);               
					
                nodes--;
            }  
            level++;
        } 
        return level;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}
