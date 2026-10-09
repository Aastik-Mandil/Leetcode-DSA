class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> odd, even;
        for(char &ch: s){
            if((ch-'0')%2 == 0){
                even.push_back(ch-'0');
            }
            else{
                odd.push_back(ch-'0');
            }
        }

        sort(even.begin(), even.end(), greater<int>());
        sort(odd.begin(), odd.end(), greater<int>());

        int x = 0, y = 0;
        for(int i=0; i<s.size(); i++){
            if((s[i]-'0')%2 == 0){
                s[i] = even[x++] + '0';
            }
            else{
                s[i] = odd[y++] + '0';
            }
        }
        return stoi(s);
    }
};
// PROBLEM:- https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/
