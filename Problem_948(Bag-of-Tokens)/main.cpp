class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        // sort the tokens
        sort(tokens.begin(), tokens.end());

        int count = 0, ans = 0;
        int i = 0, j = n-1;
        while(i<=j){
            if(power >= tokens[i]){
                power -= tokens[i];
                count++;
                i++;
            }
            else{
                if(count == 0){
                    break;
                }
                power += tokens[j];
                count--;
                j--;
            }
            ans = max(ans, count);
        }
        return max(0, ans);
    }
};
// PROBLEM:- https://leetcode.com/problems/bag-of-tokens/description/
