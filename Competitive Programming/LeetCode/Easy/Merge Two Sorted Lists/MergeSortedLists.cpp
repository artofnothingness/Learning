#include <iostream>
#include <limits>
#include <map>
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

struct ListNode {
  public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    int val;
    ListNode *next;
};

class Solution {
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if (l1 == nullptr)  {
          return l2;
        } else if (l2 == nullptr) {
          return l1;
        } else if (l1 == nullptr && l2 == nullptr) {
          return nullptr;
        }

        ListNode *curNode;
        if (l1->val < l2->val) {
            curNode = l1;
            l1 = l1->next;
        } else {
            curNode = l2;
            l2 = l2->next;
        }
        ListNode *firstNode = curNode;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curNode->next = l1;
                curNode = l1;
                l1 = l1->next;
            } else {
                curNode->next = l2;
                curNode = l2;
                l2 = l2->next;
            }
        }

        while (l1 != nullptr) {
            curNode->next = l1;
            curNode = l1;
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            curNode->next = l2;
            curNode = l2;
            l2 = l2->next;
        }

        return firstNode;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol = Solution();

    return 0;
}
