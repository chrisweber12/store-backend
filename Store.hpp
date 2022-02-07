#ifndef STORE_H
#define STORE_H

#include "Customer.h"
#include <vector>

class Store {

public:
  Store();
  Store(std::string name);
  std::string getName() const;
  void setName(std::string name);
  void addProduct(int productID, std::string productName);
  void addCustomer(int customerID, std::string customerName, bool credit=false);
  void takeShipment(int productID, int quantity, double cost);
  void takePayment(int customerID, double amount);
  void sellProduct(int customerID, int productID, int quantity);
  std::string listProducts();
  std::string listCustomers();
  Product& getProduct(int productID);
  Customer& getCustomer(int customerID);

private:
  std::string name;
  std::vector<Product> products;
  std::vector<Customer> customers;


};

#endif
