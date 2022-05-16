#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	void setYear(int);
	void setMonth(int);
	void setDay(int);
	int getYear();
	int getMonth();
	int getDay();
	Date(string);
	Date(int, int, int);
	string getString();
	friend int getMonthsBetweenDates(Date&, Date&);
};

class BankAccount {
private:
	string bankName;
	int account_number;
	bool isAvailable;
public:
	BankAccount(vector<string>);
	void setIsAvailable(bool);
	int getAccountNumber();
	bool getIsAvailable();
	string getBankName();
	virtual void addBalance(double) = 0;
	virtual void subBalance(double) = 0;
};

class CurrentAccount : public BankAccount {
private:
	Date lastOperationDate;
	double balance;
public:
	CurrentAccount(vector<string>);
	void setLastOperationDate(Date);
	double getBalance();
	Date getLastOperationDate();
	void addBalance(double);
	void subBalance(double);
};

class DepositAccount : public BankAccount {
private:
	Date openingDate;
	int period;
	double balance;
	double rate;
public:
	DepositAccount(vector<string>);
	Date getOpeningDate();
	int getPeriod();
	double getBalance();
	double getRate();
	void addBalance(double);
	void subBalance(double);
};

void CreatePairOfAccounts(int, vector<CurrentAccount>&, vector<DepositAccount>&);
void BankOperations(int, vector<CurrentAccount>&, vector<DepositAccount>&);
void AccountsOutput(int, vector<CurrentAccount>&, vector<DepositAccount>&);
Date getSystemDate();
vector<string> split(string, char);
