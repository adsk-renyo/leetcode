#include "LeetCode.h"
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>


LeetCode::LeetCode()
{
}


LeetCode::~LeetCode()
{
}

vector<int> LeetCode::twoSum(const vector<int>& nums, int target)
{
    unordered_map<int, int> matchMap; // <matchVal, thisValueId>
    matchMap[22]++;
    matchMap[24]++;
    for (size_t i = 0; i < nums.size(); ++i) {
        auto it = matchMap.find(nums[i]);
        if (it != matchMap.end()) {
            return{ it->second, (int)i };
        }
        else {
            matchMap[target - nums[i]] = i;
        }
    }
    return{};
}
