class Solution {
public:
    int characterReplacement(string s, int k) {
       int n = s.length();
       int left = 0, maxLen = 0, maxFreq = 0;
       unordered_map<char,int> mp;
       for(int right = 0; right < n; right++){
          mp[s[right]]++;
          maxFreq = max(maxFreq, mp[s[right]]);
        while((right - left + 1) - maxFreq > k){
            mp[s[left]]--;
            left++;
        }
        maxLen = max(maxLen,right - left + 1);
       }
    return maxLen;
    }
};