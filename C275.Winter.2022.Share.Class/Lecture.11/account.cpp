#include "account.h"

int Account::count = 0;

Account::Account() {
   name = new char[5];
   strcpy(name, "void");
   balance = 0;
   count++;

   cout << "Account default constructor" << endl;
}

Account::Account(string acc_holder, double opening) {
   name = new char[acc_holder.size()+1];
   strcpy(name, acc_holder.c_str());

   balance = opening;
   count++;

   cout << "Account parameterized constructor" << endl;
}

Account::~Account() {
   delete [] name;
   count--;

   cout << "Account destructor" << endl;
}

double Account::getbalance() {
   return balance;
}

void Account::withdraw(double amt) {
   if(amt<=balance) 
      balance-=amt;

   cout << "Account::withdraw is called" << endl;
}

ostream& operator<< (ostream& out, const Account& acc)
{
   out << Account::count << " - account holder name: " << acc.name << ", balance: " << acc.balance << endl;
   return out;
}

Overdraft::Overdraft() {
   limit = 0;

   cout << "Overdraft default constructor" << endl;
}

Overdraft::Overdraft(string acc_holder, double opening, double over): Account(acc_holder, opening) {
   limit = over;

   cout << "Overdraft parameterized constructor" << endl;
}

Overdraft::~Overdraft() {
   cout << "Overdraft destructor" << endl;
}

void Overdraft::withdraw(double amt) { 
   if(amt<=balance+limit) 
      balance-=amt;

   cout << "Overdraft::withdraw is called" << endl;
}

double Overdraft::getlimit() {
   return limit;
}

int main() {
   Account first("Omid", 2000);
   Account *a_ptr = &first;
   cout << endl;

   a_ptr->withdraw(100);
   cout << first << endl;

   Overdraft second("Paul", 5000.0, 10.0);
   Account *a_ptr2 = &second;
   cout << endl;

   a_ptr2->withdraw(500);
   cout << second << endl;

   Account *a_ptr3 = new Overdraft("Zac", 3000, 0);
   cout << *a_ptr3 << endl;

   delete a_ptr3;
   cout << endl;

   Account a;
   cout << a << endl;

   return 0;
}
