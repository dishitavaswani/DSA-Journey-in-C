#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {
    int breaks = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++){
        if(nums[i] > nums[(i + 1) % n]){
            breaks++;
        }
    }
    return breaks <= 1;
}

int main(){
    vector<int> nums = {2,1,3,4};
    if(check(nums)){
        cout << "Sorted";
    }else{
        cout << "Not Sorted";
    }
}
