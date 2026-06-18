class Solution {
    vector<int> solutionBF(vector<int> &nums){
        vector<int> ans(nums.size(),-1);
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size();j++){
                if(nums[(j+i)%nums.size()]>nums[i]){
                    ans[i] = nums[(j+i)%nums.size()];
                    break;
                }
            }
        }
        return ans;
    }

    vector<int> solutionO(vector<int> &nums){
        int n = nums.size();
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i=(2*n)-1;i>=0;i--){
            while(st.size()>0 && nums[i%n]>=st.top()){
                st.pop();
            }
            if(i<n){
                ans[i] = st.size() > 0 ? st.top() : -1;
            }
            st.push(nums[i%n]);
        }
        return ans;
    }
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // return solutionBF(nums);

        return solutionO(nums);
    }
};
// PROBLEM:- https://leetcode.com/problems/next-greater-element-ii/description/
