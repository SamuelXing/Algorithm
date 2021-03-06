/*

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        
        int left = 0, right = nums.size()-1;
        while(left + 1 < right)
        {
            int mid = (right-left)/2 + left;
            if(nums[mid] == target)
                return mid;
            if(nums[left] < nums[mid])
            {
                if(nums[mid] >= target && nums[left] <= target)
                {
                    right = mid;
                }
                else
                {
                    left = mid;
                }
            }
            else // nums[left] >= nums[mid]
            {
                if(nums[right]>=target && nums[mid] <= target)
                {
                    left = mid;
                }
                else
                {
                    right = mid;
                }
            }
        }
        
        if(nums[left] == target)
            return left;
        if(nums[right] == target)
            return right;
        
        return -1;
    }
};