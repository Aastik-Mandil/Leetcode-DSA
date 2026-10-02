class Solution {
    bool isPalindrome(string &nums, int st, int ed){
        int i=st,j=ed;
        while(i<j){
            if(nums[i] != nums[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void traverse(string &nums, int last, int idx, vector<vector<string>> &res, vector<string> z){
        if(idx == nums.size()){
            if(idx-last>0 && isPalindrome(nums,last+1,idx)){
                res.push_back(z);
            }
            return;
        }
        string t = nums.substr(last+1,idx-last);
        if(idx-last>0 && isPalindrome(nums,last+1,idx)){
            z.push_back(nums.substr(last+1,idx-last));
            traverse(nums, idx, idx+1, res, z);
            z.pop_back();
        }
        traverse(nums, last, idx+1, res, z);
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> z;
        traverse(s, -1, 0, res, z);
        return res;
    }
};
// PROBLEM:- https://leetcode.com/problems/palindrome-partitioning/description/
