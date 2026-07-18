class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0, count = 0;
        unordered_map<char,int> mp;
        for(int right = 0; right < s.length(); right++){
            mp[s[right]]++;
            while(mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0){
                mp[s[left]]--;
                left++;
            }
            count = count + left;
        }
        return count;
    }
};