class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        set<int> num;
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/3){
                num.insert(nums[i]);
            }
        }
        return vector<int>(num.begin(),num.end());
    }
};