#include "Store.h"

using namespace std;

Store::Store() {}

Store::Store(std::string name) : name(name) {}

std::string Store::getName() const {
  return name;
}

void Store::setName(std::string name) {
  this->name = name;
}

void Store::addProduct(int productID, std::string productName) {
  for (int i = 0; i < products.size(); i++) {
    if (productID == products.at(i).getID()) {
      throw runtime_error("Product ID already belongs to another product");
    }
  }
  Product newProduct(productID, productName);
  products.push_back(newProduct);
}

void Store::addCustomer(int customerID, std::string customerName, bool credit) {
  for (int i = 0; i < customers.size(); i++) {
    if (customerID == customers.at(i).getID()) {
      throw runtime_error("Customer ID already belongs to another customer");
    }
  }
  Customer newCustomer(customerID, customerName, credit);
  customers.push_back(newCustomer);
}

void Store::takeShipment(int productID, int quantity, double cost) {
  for (int i=0; i < products.size(); i++) {
    if (products.at(i).getID() == productID) {
      products.at(i).addShipment(quantity, cost);
      return;
    }
  }
  throw runtime_error("Product ID not in products list");
}

void Store::takePayment(int customerID, double amount) {
  for (int i=0; i < customers.size(); i++) {
    if (customers.at(i).getID() == customerID) {
      customers.at(i).processPayment(amount);
      return;
    }
  }
  throw runtime_error("Customer ID not in customers list");
}

void Store::sellProduct(int customerID, int productID, int quantity) {
  for (int i=0; i < customers.size(); i++) {
    if (customers.at(i).getID() == customerID) {
      for (int j=0; j < products.size(); j++) {
        if (products.at(j).getID() == productID) {
          products.at(j).reduceInventory(quantity);
          double amount = quantity * products.at(j).getPrice();
          customers.at(i).processPurchase(amount, products.at(j));
          return;
        }
      }
    throw runtime_error("Product ID not in products list");
    }
  }
  throw runtime_error("Customer ID not in customers list");
}

string Store::listProducts() {
  stringstream ss;
  for (int i=0; i < products.size(); i++) {
    ss << products.at(i) << endl;
  }
  return ss.str();
}

string Store::listCustomers() {
  stringstream ss;
  for (int i=0; i < customers.size(); i++) {
    ss << customers.at(i) << endl;
  }
  return ss.str();
}

Product& Store::getProduct(int productID) {
  for (int i=0; i < products.size(); i++) {
    if (products.at(i).getID() == productID) {
      return products.at(i);
    }
  }
  throw runtime_error("Product not in products list");
}

Customer& Store::getCustomer(int customerID) {
  for (int i=0; i < customers.size(); i++) {
    if (customers.at(i).getID() == customerID) {
      return customers.at(i);
    }
  }
  throw runtime_error("Customer not in customers list");
}
