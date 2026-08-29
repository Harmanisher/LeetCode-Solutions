class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int low = 0;

        for (int high = 0; high < nums.size(); high++) {
            if (nums[high] != 0) {
                swap(nums[low], nums[high]);
                low++;
            }
        }
    }
};