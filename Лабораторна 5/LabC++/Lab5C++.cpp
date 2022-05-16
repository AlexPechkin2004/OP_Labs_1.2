#include "Header.h"

int main()
{
    cout << "Enter the number of pairs of bank accounts: ";
    int n;
    cin >> n;
    cin.ignore();

    vector<CurrentAccount> currents;
    vector<DepositAccount> deposits;
    CreatePairOfAccounts(n, currents, deposits);
    BankOperations(n, currents, deposits);
    AccountsOutput(n, currents, deposits);

    return 0;
}