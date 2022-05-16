#include "Header.h"

void Date::setYear(int yr) { year = yr; };
void Date::setMonth(int mon) { month = mon; };
void Date::setDay(int d) { day = d; };
int Date::getYear() { return year; };
int Date::getMonth() { return month; };
int Date::getDay() { return day; };

Date::Date(string str) {
	vector<string> temp = split(str, '.');
	day = stoi(temp[0]);
	month = stoi(temp[1]);
	year = stoi(temp[2]);
}

Date::Date(int day = 1, int month = 1, int year = 1900) {
	this->year = year;
	this->month = month;
	this->day = day;
}

string Date::getString() {
	string strDay = to_string(day);
	string strMonth = to_string(month);
	if (day < 10) {
		strDay = '0' + to_string(day);
	}
	if (month < 10) {
		strMonth = '0' + to_string(month);
	}
	return strDay + '.' + strMonth + '.' + to_string(year);
}

int getMonthsBetweenDates(Date& date1, Date& date2) {
	return ((date1.year - date2.year) * 12) + date1.month - date2.month;
}





BankAccount::BankAccount(vector<string> attributes) {
	bankName = attributes[0];
	account_number = stoi(attributes[1]);
	isAvailable = true;
}

void BankAccount::setIsAvailable(bool isAvailable) { this->isAvailable = isAvailable; };
int BankAccount::getAccountNumber() { return account_number; };
bool BankAccount::getIsAvailable() { return isAvailable; };
string BankAccount::getBankName() { return bankName; };





CurrentAccount::CurrentAccount(vector<string> attributes) : BankAccount(attributes) {
	balance = stod(attributes[2]);
	lastOperationDate = Date();
}

void CurrentAccount::setLastOperationDate(Date date) { lastOperationDate = date; };
double CurrentAccount::getBalance() { return balance; };
Date CurrentAccount::getLastOperationDate() { return lastOperationDate; };

void CurrentAccount::addBalance(double sum) { balance += sum; };
void CurrentAccount::subBalance(double sum) { balance -= sum; };




DepositAccount::DepositAccount(vector<string> attributes) : BankAccount(attributes) {
	balance = stod(attributes[2]);
	rate = stod(attributes[3]);
	openingDate = Date(attributes[4]);
	period = stoi(attributes[5]);
}

Date DepositAccount::getOpeningDate() { return openingDate; };
int DepositAccount::getPeriod() { return period; };
double DepositAccount::getBalance() { return balance; };
double DepositAccount::getRate() { return rate; };

void DepositAccount::addBalance(double sum) { balance += sum; };
void DepositAccount::subBalance(double sum) { balance -= sum; };





void CreatePairOfAccounts(int size, CurrentAccount**& currents, DepositAccount**& deposits) {
	cout << "\nEnter info about accounts in following format:\n\n";
	cout << "1st line - current account: [bank name, account number, balance]\n";
	cout << "2nd line - deposit account: [bank name, account number, balance, monthly rate, start date, period]\n\n";

	for (int i = 0; i < size; i++)
	{
		cout << "Enter pair " << i + 1<<":\n";
		string str;
		vector<string> attributes;
		getline(cin, str);
		attributes = split(str, ',');
		currents[i]=new CurrentAccount(attributes);
		getline(cin, str);
		attributes = split(str, ',');
		deposits[i]=new DepositAccount(attributes);
		cout << endl;
	}
}

void BankOperations(int size, CurrentAccount**& currents, DepositAccount**& deposits) {
	Date now = getSystemDate();
	for (int i = 0; i < size; i++)
	{
		Date openDate = (*deposits[i]).getOpeningDate();
		int completedMonth = getMonthsBetweenDates(now, openDate);
		double percents;

		if (completedMonth >= (*deposits[i]).getPeriod())
		{
			percents = (*deposits[i]).getPeriod() * ((*deposits[i]).getBalance() * ((*deposits[i]).getRate())/100);
			(*currents[i]).addBalance((*deposits[i]).getBalance());
			(*deposits[i]).subBalance((*deposits[i]).getBalance());
			(*deposits[i]).setIsAvailable(false);
			openDate.setMonth(openDate.getMonth() + (*deposits[i]).getPeriod());
		}
		else
		{
			percents = completedMonth * ((*deposits[i]).getBalance() * ((*deposits[i]).getRate())/100);
			openDate.setMonth(openDate.getMonth() + completedMonth);
		}
		while (openDate.getMonth() > 12)
		{
			openDate.setYear(openDate.getYear() + 1);
			openDate.setMonth(openDate.getMonth() - 12);
		}
		(*currents[i]).addBalance(percents);
		(*currents[i]).setLastOperationDate(openDate);
	}
}

void AccountsOutput(int size, CurrentAccount**& currents, DepositAccount**& deposits) {
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		CurrentAccount c = (*currents[i]);
		DepositAccount d = (*deposits[i]);
		Date lastOp = c.getLastOperationDate();
		string status = d.getIsAvailable() ? "open" : "closed";

		cout << "Pair " << i + 1 << ": " << endl;

		cout << "Bank name: " << c.getBankName()
			<< "\nAccount number: " << c.getAccountNumber()
			<< "\nDate of last operation: " << lastOp.getString()
			<< "\nBalance: " << c.getBalance() << endl;

		cout << "\nBank name: " << d.getBankName()
			<< "\nAccount number: " << d.getAccountNumber()
			<< "\nStatus: " << status
			<< "\nBalance: " << d.getBalance() << endl << endl;
	}
}

Date getSystemDate()
{
	struct tm currentTime;
	time_t t = time(NULL);
	localtime_s(&currentTime, &t);

	return 	Date(currentTime.tm_mday, currentTime.tm_mon + 1, currentTime.tm_year + 1900);
}

vector<string> split(string str, char separator) {
	vector<string> res;
	string slice = "";
	str += " ";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == separator)
		{
			if (slice.length() > 0) {
				res.push_back(slice);
				slice = "";
			}
		}
		else {
			slice += str[i];
		}
	}
	res.push_back(slice);
	return res;
}