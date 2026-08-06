class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int product = nums[0], maxProduct = nums[0], minProduct = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            if(curr < 0){
                swap(maxProduct, minProduct);
            }
            maxProduct = max(curr, curr * maxProduct);
            minProduct = min(curr, curr * minProduct);
            product = max(product, maxProduct);
        }
        return product;
    }
};