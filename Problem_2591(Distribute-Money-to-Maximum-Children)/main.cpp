class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children){
            return -1;
        }
        if(money > (children * 8)){
            return children-1;
        }

        int ans = 0;
        while(money > 0 && children > 0 && money-8 >= children-1){
            ans++;
            money -= 8;
            children--;
        }
        if(money == 4 && children == 1){
            ans--;
        }
        return ans;
    }
};
// PROBLEM:- https://leetcode.com/problems/distribute-money-to-maximum-children/description/
