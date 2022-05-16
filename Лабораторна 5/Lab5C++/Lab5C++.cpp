#include "Header.h"

int main()
{
    cout << "Enter the number of pairs of bank accounts: ";
    int n;
    cin >> n;
    cin.ignore();

    CurrentAccount **currents = new CurrentAccount*[n];
    DepositAccount **deposits = new DepositAccount*[n];
    CreatePairOfAccounts(n, currents, deposits);
    BankOperations(n, currents, deposits);
    AccountsOutput(n, currents, deposits);

    return 0;
}