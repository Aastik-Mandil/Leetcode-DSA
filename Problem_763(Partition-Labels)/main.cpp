class Solution {
public:
    vector<int> partitionLabels(string s) {
        // store each character last index
        vector<int> v(26, -1);
        for(int i=0; i<s.size(); i++){
            v[s[i]-'a'] = i;
        }

        // calculate the maxi idx based on the last index for characters
        vector<int> ans;
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            if(i > maxi){
                ans.push_back(maxi);
            }
            maxi = max(maxi, v[s[i]-'a']);
        }
        ans.push_back(maxi);

        // find the length based on consecutive values
        for(int i=ans.size()-1; i>0; i--){
            ans[i] = ans[i] - ans[i-1];
        }
        ans[0]++;
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/partition-labels/description/
