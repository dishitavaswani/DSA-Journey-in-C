#include <bits/stdc++.h>
using namespace std;

void largestElement(vector<int>& nums) {
    int Largest = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > Largest) {
            Largest = nums[i];
        }
    }

    cout << "Largest element in the array is: " << Largest;
}

int main() {
    vector<int> nums = {10,25,7,40,15};
    largestElement(nums);
    return 0;
}