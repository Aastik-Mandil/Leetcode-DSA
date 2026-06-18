class Solution {
    vector<int> fillValue(int n){
        vector<int> ans(150, 0);
        int idx = 0;
        while(n>0){
            ans[idx++] = n%2;
            n /= 2;
        }
        return ans;
    }
public:
    int minFlips(int a, int b, int c) {
        vector<int> v1 = fillValue(a);
        vector<int> v2 = fillValue(b);
        vector<int> v3 = fillValue(c);

        int count = 0;
        for(int i=0; i<150; i++){
            if(v3[i] == 0){
                if(v1[i] == 1){
                    count++;
                }
                if(v2[i] == 1){
                    count++;
                }
            }
            else{
                if(v1[i] == 0 && v2[i] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};
// PROBLEM:-https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description
