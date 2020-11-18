//LEETCODE

//Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

//The order of elements can be changed. It doesn't matter what you leave beyond the new length.

//Return the new length
class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int begin = 0;
        for(int i = 0;i < nums.size();i++)
            if(nums[i] != val)
                nums[begin++] = nums[i];
        return begin;
    }
};
