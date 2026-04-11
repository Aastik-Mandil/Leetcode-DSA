class Solution {
    string num2Bin(int n){
        string z="";
        while(n>0){
            z=to_string(n%2)+z;
            n/=2;
        }
        return z;
    }
    char myXor(char a, char b){
        return a==b ? '0' : '1';
    }
    string bin2Gray(string s){
        if(s.size() == 0){
            return "";
        }
        string z="";
        z.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            z.push_back(myXor(s[i],s[i-1]));
        }
        return z;
    }
    int bin2Num(string s){
        int idx = 0;
        int num = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                num+=pow(2,idx);
            }
            idx++;
        }
        return num;
    }
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for(int i=0;i<pow(2,n);i++){
            ans.push_back(bin2Num(bin2Gray(num2Bin(i))));
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/gray-code/description/
