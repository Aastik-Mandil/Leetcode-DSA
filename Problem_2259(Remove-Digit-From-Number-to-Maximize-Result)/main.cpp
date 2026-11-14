class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i=0; i<number.size(); i++){
            if(number[i] == digit){
                if(i+1 >= number.size()){
                    return number.substr(0, i);
                }
                else if(number[i+1] > number[i]){
                    return number.substr(0, i) + number.substr(i+1, number.size());
                }
            }
        }
        for(int i=number.size()-1; i>=0; i--){
            if(number[i] == digit){
                return number.substr(0, i) + number.substr(i+1, number.size());
            }
        }
        return number;
    }
};
// PROBLEM:- https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/description/
