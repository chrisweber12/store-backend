#ifndef STORE_HPP
#define STORE_HPP

#include "Customer.hpp"
#include "Product.hpp"
#include <vector>

class Store {

public:
  Store();
  Store(std::string name);
  std::string getName() const;
  void setName(std::string name);
  int addProduct(int productID, std::string productName);
  int addCustomer(int customerID, std::string customerName, bool credit=false);
  int takeShipment(int productID, int quantity, double cost);
  int takePayment(int customerID, double amount);
  int sellProduct(int customerID, int productID, int quantity);
  std::string listProducts() const;
  std::string listCustomers() const;
  Product& getProduct(int productID);
  Customer& getCustomer(int customerID);

private:
  std::string name;
  std::vector<Product> products;
  std::vector<Customer> customers;
  double netGains = 0;


};
std::ostream& operator<<(std::ostream& os, const Store& store);


#endif
