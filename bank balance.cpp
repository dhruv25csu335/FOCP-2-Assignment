#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<int, long long> accounts; // userID -> balance

public:
    // CREATE X Y
    bool create(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) {
            accounts[userID] = amount;
            return true; // new account created
        } else {
            accounts[userID] += amount; // add to existing account
            return false;
        }
    }

    // DEBIT X Y
    bool debit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) return false;
        if (accounts[userID] < amount) return false;
        accounts[userID] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(int userID, long long amount) {
        if (accounts.find(userID) == accounts.end()) return false;
        accounts[userID] += amount;
        return true;
    }

    // BALANCE X
    long long balance(int userID) {
        if (accounts.find(userID) == accounts.end()) return -1;
        return accounts[userID];
    }
};

int main() {
    int Q;
    cin >> Q;
    Bank bankSystem;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int X; long long Y;
            cin >> X >> Y;
            cout << (bankSystem.create(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "DEBIT") {
            int X; long long Y;
            cin >> X >> Y;
            cout << (bankSystem.debit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "CREDIT") {
            int X; long long Y;
            cin >> X >> Y;
            cout << (bankSystem.credit(X, Y) ? "true" : "false") << endl;
        }
        else if (query == "BALANCE") {
            int X;
            cin >> X;
            cout << bankSystem.balance(X) << endl;
        }
    }
    return 0;
}
