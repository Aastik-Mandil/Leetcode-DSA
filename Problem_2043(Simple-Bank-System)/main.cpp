class Bank {
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 <= 0 || account1 > bal.size()){
            return false;
        }
        if(account2 <= 0 || account2 > bal.size()){
            return false;
        }
        if(bal[account1-1] < money){
            return false;
        }
        bal[account1-1] -= money;
        bal[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account <= 0 || account > bal.size()){
            return false;
        }
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account <= 0 || account > bal.size()){
            return false;
        }
        if(bal[account-1] < money){
            return false;
        }
        bal[account-1] -= money;
        return true;
    }
};
// 36: withdraw ->
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
// PROBLEM:- https://leetcode.com/problems/simple-bank-system/description/
