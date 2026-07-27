class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int j = 0;
        for(int i = 0; i < mp[0]; i++){
            nums[j] = 0;
            j++;
        }
        for(int i = 0; i < mp[1]; i++){
            nums[j] = 1;
            j++;
        }
        for(int i = 0; i < mp[2]; i++){
            nums[j] = 2;
            j++;
        }
    }
};