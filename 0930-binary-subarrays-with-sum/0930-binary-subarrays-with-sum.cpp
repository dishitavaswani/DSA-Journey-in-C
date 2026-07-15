class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, count = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int right = 0; right < nums.size(); right++){
            sum = sum + nums[right];
            count = count + mp[sum - goal];
            mp[sum]++;
        }
        return count;
    }
};