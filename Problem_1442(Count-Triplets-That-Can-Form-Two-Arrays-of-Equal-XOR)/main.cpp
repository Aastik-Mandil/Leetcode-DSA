class Solution {
public:
    int countTriplets(vector<int>& arr) {
        for(int i=1; i<arr.size(); i++){
            arr[i] ^= arr[i-1];
        }

        int count = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                for(int k=j; k<arr.size(); k++){
                    int left = arr[j-1];
                    if(i-1 >= 0){
                        left ^= arr[i-1];
                    }
                    int right = arr[k] ^ arr[j-1];
                    if(left == right){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
// PROBLEM:- https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
