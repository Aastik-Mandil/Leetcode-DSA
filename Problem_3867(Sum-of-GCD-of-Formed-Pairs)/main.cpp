class Solution {
    long long hcf(long long a, long long b){
        if(a == 0){
            return b;
        }
        if(b == 0){
            return a;
        }
        if(a == b){
            return a;
        }
        if(a > b){
            return hcf(a%b, b);
        }
        return hcf(a, b%a);
    }
public:
    long long gcdSum(vector<int>& nums) {
        // update the maximum and calculate the gcd of all pairs
        int maxi = 0;
        vector<int> v;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            v.push_back(hcf(nums[i], maxi));
        }

        // sort the gcd values list
        sort(v.begin(), v.end());

        // create the pair and calculate the sum of gcf of all the pairs
        long long ans = 0;
        int i = 0, j = v.size() - 1;
        while(i < j){
            ans += hcf(v[i], v[j]);
            i++;
            j--;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/sum-of-gcd-of-formed-pairs/description/
