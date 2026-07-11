class Solution {
    string twosCompliment(string s){
        string z = "";
        for(int i=0; i<s.size(); i++){
            z.push_back(s[i] == '0' ? '1' : '0');
        }
        int carry = 1;
        for(int i=0; i<z.size(); i++){
            int val = z[i]-'0';
            val += carry;
            z[i] = (val%2)+'0';
            carry = val/2;
        }
        if(carry > 0){
            z.push_back('1');
        }
        return z;
    }
    string getBinary(long long n){
        string ans = "";
        bool neg = false;
        if(n < 0){
            neg = true;
            n = abs(n);
        }
        while(n > 0){
            ans.push_back((n%2) + '0');
            n /= 2;
        }
        while(ans.size() < 32){
            ans.push_back('0');
        }
        if(neg){
            ans = twosCompliment(ans);
        }
        return ans;
    }
public:
    int singleNumber(vector<int>& nums) {
        vector<int> v(33, 0);
        for(int &num: nums){
            string s = getBinary(num);
            for(int i=0; i<s.size(); i++){
                v[i] += (s[i]-'0');
            }
        }

        long long ans = 0;
        for(int i=0; i<33; i++){
            if(v[i]%3 != 0){
                ans += pow(2, i);
            }
        }

        int cnt = 0;
        for(int &num: nums){
            if(num == ans){
                cnt++;
            }
        }

        if(cnt == 1){
            return ans;
        }
        string temp = twosCompliment(getBinary(ans));
        ans = 0;
        for(int i=0; i<33; i++){
            if(v[i]%3 != 0){
                ans += pow(2, i);
            }
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/single-number-ii/description/
