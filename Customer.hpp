#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Product.hpp"
#include <string>
#include <vector>

class Customer {

public:
  Customer(int customerID, std::string name, bool credit=false);
  int getID() const;
  std::string getName() const;
  void setName(std::string name);
  bool getCredit() const;
  void setCredit(bool hasCredit);
  double getBalance() const;
  void processPayment(double amount);
  void processPurchase(double amount, Product product);
  std::string getProductsPurchased() const;

private:
  int id;
  std::string name;
  bool credit;
  double balance = 0;
  std::vector<Product> productsPurchased;

};


std::stringstream& operator<<(std::stringstream& ss, const Customer& customer);

#endif
