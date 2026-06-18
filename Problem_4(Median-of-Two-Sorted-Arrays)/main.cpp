class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int mid = (n+m)/2;

        vector<int> idx;
        if((n+m)%2 == 0){
            idx.push_back(mid-1);
        }
        idx.push_back(mid);

        vector<double> values;
        int i = 0, j = 0, k = 0;
        while(k<idx.size()){
            if(i<n && j<m){
                if(i+j == idx[k]){
                    values.push_back(nums1[i]<=nums2[j] ? nums1[i]*1.00000 : nums2[j]*1.00000);
                    k++;
                }
                if(nums1[i]<=nums2[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            else if(i<n){
                if(i+j == idx[k]){
                    values.push_back(nums1[i]*1.00000);
                    k++;
                }
                i++;
            }
            else{
                if(i+j == idx[k]){
                    values.push_back(nums2[j]*1.00000);
                    k++;
                }
                j++;
            }
        }

        double val = 0.00000;
        for(double &value: values){
            val += value;
        }
        return val/values.size();
    }
};
// PROBLEM:- https://leetcode.com/problems/median-of-two-sorted-arrays/description/
