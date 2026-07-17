class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         int sum = 0, count = 0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for (int right = 0; right < nums.size(); right++){
            sum = sum + nums[right]%2;
            count= count + mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};