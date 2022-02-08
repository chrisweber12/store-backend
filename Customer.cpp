#include "Customer.hpp"
#include <string>

using namespace std;

Customer::Customer(int customerID, string name, bool credit) :
  id(customerID), name(name), credit(credit) {
    if (name == "") {
      throw runtime_error("Empty string for name");
    }
  }

int Customer::getID() const {
  return id;
}

string Customer::getName() const {
  return name;
}

void Customer::setName(string name) {
  if (name == "") {
    throw runtime_error("Empty string for name");
  }
  this->name = name;
}

bool Customer::getCredit() const {
  return credit;
}

void Customer::setCredit(bool hasCredit) {
  credit = hasCredit;
}

double Customer::getBalance() const {
  return balance;
}

void Customer::processPayment(double amount) {
  if (amount < 0) {
    throw runtime_error("Negative payment amount");
  }
  balance += amount;
}

void Customer::processPurchase(double amount, Product product) {
  if (credit == false && balance < amount) {
    throw runtime_error("No credit and balance less than purchase amount");
  }
  if (amount < 0) {
    throw runtime_error("Negative purchase amount");
  }
  balance -= amount;
  productsPurchased.push_back(product);
}

string Customer::getProductsPurchased() const {
  string productsString = "";
  for (int i=0; i<productsPurchased.size(); i++) {
    string line1 = "\tProduct Name: " + productsPurchased.at(i).getName();
    string line2 = "\tProduct ID: " + to_string(productsPurchased.at(i).getID());
    productsString = productsString + line1 + "\n" + line2 + "\n";
  }
  return productsString;
}


stringstream& operator<<(stringstream& ss, const Customer& customer) {
  ss << "\tCustomer Name: " << customer.getName() << endl;
  ss << "\tCustomer ID: " << customer.getID() << endl;
  if (customer.getCredit() == true) {
    ss << "\tHas Credit: true" << endl;
  }
  else if (customer.getCredit() == false) {
    ss << "\tHas Credit: false" << endl;
  }
  ss << "\tBalance: " << customer.getBalance() << endl;
  ss << "\tProducts Purchased:" << endl << customer.getProductsPurchased();
  return ss;
}
