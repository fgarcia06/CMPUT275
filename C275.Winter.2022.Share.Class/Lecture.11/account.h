#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Account {
public:
   Account();
   Account(string acc_holder, double opening);
   ~Account();
   virtual void withdraw(double amt);
   double getbalance();
   static int count;

   friend ostream& operator<< (ostream& out, const Account& acc);

protected:
   double balance; 
   char * name;
};

class Overdraft: public Account {
public:
   Overdraft();
   Overdraft(string acc_holder, double opening, double over);
   ~Overdraft();
   void withdraw(double amt);
   double getlimit();

private:
   double limit;
};

#endif
