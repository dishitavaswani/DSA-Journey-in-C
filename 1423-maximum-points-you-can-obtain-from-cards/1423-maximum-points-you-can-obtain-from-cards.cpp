class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();        
        int left, totalSum = 0, windowSum = 0;
        int windowSize = n - k;
            for(int i = 0; i < n; i++){
                totalSum += cardPoints[i];
            }
            for (int i = 0; i < windowSize; i++){
                windowSum += cardPoints[i];
            }
            int maxSum = totalSum - windowSum;

            for(int j = windowSize; j < n; j++){
                windowSum += cardPoints[j];
                windowSum -= cardPoints[j - windowSize];
                maxSum = max(maxSum, totalSum - windowSum);
            }
        return maxSum;
    }
};