class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = INT_MIN, candidate2 = INT_MAX, count1 = 0, count2 = 0;
        int n = nums.size();
        vector<int> num;
        for(int x : nums){
            if(x == candidate1 && x != candidate2){
                 count1++;
            }
            else if(x == candidate2 && x != candidate1){ 
                count2++;
            }
            else if(count1 == 0){
                candidate1 = x;
                count1 = 1;
            }
            else if(count2 == 0){
                candidate2 = x;
                count2 = 1;
            }
            else{
            count1--, count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
        }
        if(count1 > n/3) num.push_back(candidate1);
        if(count2 > n/3) num.push_back(candidate2);
        return num;
    }
};