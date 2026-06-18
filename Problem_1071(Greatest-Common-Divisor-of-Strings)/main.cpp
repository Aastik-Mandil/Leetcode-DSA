class Solution {
    bool canDivides(string s, string t){
        for(int i=0; i<s.size(); i+=t.size()){
            if(t != s.substr(i, t.size())){
                return false;
            }
        }
        return true;
    }
    string solve1(string &str1, string &str2){
        int st = str2.size()-1;
        for(int i=st; i>=0; i--){
            string z = str2.substr(0, i+1);
            if(canDivides(str2, z) && canDivides(str1, z)){
                return z;
            }
        }
        return "";
    }

    int hcf(int a, int b){
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
    string solve2(string &str1, string &str2){
        if((str1+str2) != (str2+str1)){
            return "";
        }
        int val = hcf(str1.size(), str2.size());
        return str1.substr(0, val);
    }
public:
    string gcdOfStrings(string str1, string str2) {
        // return solve1(str1, str2);

        return solve2(str1, str2);
    }
};
// PROBLEM:- https://leetcode.com/problems/greatest-common-divisor-of-strings/description
