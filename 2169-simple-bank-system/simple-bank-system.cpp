class Bank {
public:
vector<long long> bal;
int n;
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > n || account2 < 1 || account2 > n || bal[account1-1] < money) {
            return false;
        }
        else{
            bal[account1-1] -= money;
            bal[account2-1] += money;
            return true;
        }
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > n || account-1 > bal.size()) {
            return false;
        }
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > n || bal[account-1] < money) {
            return false;
        }
        else{
            bal[account-1] -= money;
            return true;
        }
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */