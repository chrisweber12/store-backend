#include "Store.hpp"
#include <iostream>

using namespace std;

Store::Store() {}

Store::Store(std::string name) : name(name) {}

std::string Store::getName() const {
    return name;
}

void Store::setName(std::string name) {
    this->name = name;
}

int Store::addProduct(int productID, std::string productName) {
    for (int i = 0; i < products.size(); i++) {
        if (productID == products.at(i).getID()) {
            std::cout << "Product ID already belongs to another product." << endl;
            return -1;
        }
    }
    Product newProduct(productID, productName);
    products.push_back(newProduct);
    return 1;
}

int Store::addCustomer(int customerID, std::string customerName, bool credit) {
    for (int i = 0; i < customers.size(); i++) {
        if (customerID == customers.at(i).getID()) {
            std::cout << "Customer ID already belongs to another customer." << endl;
            return -1;
        }
    }
    Customer newCustomer(customerID, customerName, credit);
    customers.push_back(newCustomer);
    return 1;
}

int Store::takeShipment(int productID, int quantity, double cost) {
    for (int i=0; i < products.size(); i++) {
        if (products.at(i).getID() == productID) {
            products.at(i).addShipment(quantity, cost);
            netGains -= quantity * cost;
            return 1;
        }
    }
    cout << "Product ID not in products list" << endl;
    return -1;
}

int Store::takePayment(int customerID, double amount) {
    for (int i=0; i < customers.size(); i++) {
        if (customers.at(i).getID() == customerID) {
            customers.at(i).processPayment(amount);
            netGains += amount;
            return 1;
        }
    }
    std::cout << "Customer ID not in customers list." << endl;
    return -1;
}

int Store::sellProduct(int customerID, int productID, int quantity) {
    for (int i=0; i < customers.size(); i++) {
        if (customers.at(i).getID() == customerID) {
            for (int j=0; j < products.size(); j++) {
                if (products.at(j).getID() == productID) {
                    products.at(j).reduceInventory(quantity);
                    double amount = quantity * products.at(j).getPrice();
                    customers.at(i).processPurchase(amount, products.at(j));
                    netGains += amount;
                    return 1;
                }
            }
        std::cout << "Product ID not in products list." << endl;
        return -1;
        }
    }
    std::cout << "Customer ID not in customers list." << endl;
    return -1;
}

string Store::listProducts() const {
    stringstream ss;
    for (int i=0; i < products.size(); i++) {
        ss << products.at(i) << endl;
    }
    return ss.str();
}

string Store::listCustomers() const {
    if (customers.size()==0) {
        return "";
    }
    stringstream ss;
    for (int i=0; i < customers.size()-1; i++) {
        ss << customers.at(i) << endl;
    }
    ss << customers.at(customers.size()-1);
    return ss.str();
}

Product& Store::getProduct(int productID) {
    for (int i=0; i < products.size(); i++) {
        if (products.at(i).getID() == productID) {
            return products.at(i);
        }
    }
    throw runtime_error("Product not in products list.");
}

Customer& Store::getCustomer(int customerID) {
    for (int i=0; i < customers.size(); i++) {
        if (customers.at(i).getID() == customerID) {
            return customers.at(i);
        }
    }
    throw runtime_error("Customer not in customers list.");
}

std::ostream& operator<<(std::ostream& os, const Store& store) {
    os << "Name: " << store.getName() << endl;
    os << "Products: " << endl << store.listProducts();
    os << "Customers: " << endl << store.listCustomers();
    os << flush;
    return os;
}
