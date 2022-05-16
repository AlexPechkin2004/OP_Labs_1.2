from BankAccount import *

n = int(input("Enter the number of pairs of bank accounts: "))
currents_array, deposits_array=CreatePairOfAccounts(n)
BankOperations(n, currents_array, deposits_array)
AccountsOutput(n, currents_array, deposits_array)