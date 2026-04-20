class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // 1. Sort the array to use two pointers and easily handle duplicates
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            // Optimization: If the current number is positive, 
            // no three numbers can sum to 0 anymore.
            if (nums[i] > 0) break;

            // 2. Skip duplicate elements for the first position
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // 3. Skip duplicate elements for the second and third positions
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++; // Need a larger value
                } 
                else {
                    right--; // Need a smaller value
                }
            }
        }
        return result;
    }
};