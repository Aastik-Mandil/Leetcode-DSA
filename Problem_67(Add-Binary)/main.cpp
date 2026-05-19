class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string s = "";
        while(i>=0 || j>=0 || carry>0){
            int val = carry;
            if(i>=0){
                val += (a[i]-'0');
                i--;
            }
            if(j>=0){
                val += (b[j]-'0');
                j--;
            }

            if(val == 0){
                s = "0"+s;
                carry = 0;
            }
            else if(val == 1){
                s = "1"+s;
                carry = 0;
            }
            else if(val == 2){
                s = "0"+s;
                carry = 1;
            }
            else{
                s = "1"+s;
                carry = 1;
            }
        }
        return s;
    }
};
// PROBLEM:- https://leetcode.com/problems/add-binary/description
