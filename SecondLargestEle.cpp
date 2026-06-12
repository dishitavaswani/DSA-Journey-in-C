#include<bits/stdc++.h>
using namespace std;

void secondLargestElement(vector<int>& nums) {
        int largest = nums[0];
        int secondLargest = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
            }else if(nums[i] < largest && nums[i] > secondLargest){
                secondLargest = nums[i];
            }
        }
        cout << "The second largest element in the array:" << secondLargest;
}

int main(){
    vector<int> nums = {3,4,1,5,8};
    secondLargestElement(nums);
    return 0;
}