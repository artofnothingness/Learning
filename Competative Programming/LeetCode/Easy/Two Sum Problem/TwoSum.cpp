#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:   
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        unordered_map<int, int> hashMap;
        hashMap.reserve(nums.size());
        for (int q = 0; q < nums.size(); q++) {
            if (hashMap.find(target - nums[q]) != hashMap.end()) {
                result[0] = q;
                result[1] = hashMap[target - nums[q]];
                return result;
            } else {
                hashMap[nums[q]] = q; 
            }
        }
        
        return result;  
    }
};

int main() {
   std::ios_base::sync_with_stdio(false);
   std::cin.tie(NULL);
   return 0;
}

