#include "Product.hpp"
#include <string>

using namespace std;

Product::Product(int productID, string productName) :
    id(productID), name(productName) {
    if (productName == "") {
        throw runtime_error("Empty string for name");
    }
  }

int Product::getID() const {
    return id;
}

string Product::getName() const {
    return name;
}

void Product::setName(string productName) {
    if (productName == "") {
        throw runtime_error("Empty string for name");
    }
    name = productName;
}

string Product::getDescription() const {
    return description;
}

void Product::setDescription(string description) {
    this->description = description;
}

int Product::getNumberSold() const {
    return numSold;
}

double Product::getTotalPaid() const {
    return totalPaid;
}

double Product::getTotalMade() const {
    return totalMade;
}

int Product::getInventoryCount() const {
    return inventory;
}

void Product::addShipment(int shipmentQuantity, double shipmentCost) {
    if (shipmentCost < 0) {
        throw runtime_error("Negative shipment cost");
    }
    if (shipmentQuantity < 0) {
        throw runtime_error("Negative shipment quantity");
    }
    inventory += shipmentQuantity;
    totalPaid += shipmentCost;
}

void Product::reduceInventory(int purchaseQuantity) {
    if (purchaseQuantity > inventory) {
        throw runtime_error("Purchase quantity greater than inventory");
    }
    if (purchaseQuantity < 0) {
        throw runtime_error("Negative purchase quantity");
    }
    inventory -= purchaseQuantity;
    numSold += purchaseQuantity;
    totalMade += getPrice() * purchaseQuantity;
}

double Product::getPrice() const {
    double price;
    try {
        price = (totalPaid / (inventory + numSold)) * 1.25;
        if (totalPaid == 0 or (inventory + numSold) == 0) {
            throw runtime_error("Could not calculate price");
        }
    }
    catch (...) {
        throw runtime_error("Could not calculate price");
    }
    return price;
}




std::stringstream& operator<<(stringstream& ss, const Product& product) {
    ss << "\tProduct Name: " << product.getName() << endl;
    ss << "\tProduct ID: " << product.getID() << endl;
    ss << "\tDescription: " << product.getDescription() << endl;
    ss << "\tInventory: " << product.getInventoryCount() << endl;
    ss << "\tNumber Sold: " << product.getNumberSold() << endl;
    ss << "\tTotal Paid: " << product.getTotalPaid() << endl;
    ss << "\tTotal Made: " << product.getTotalMade() << endl;
    ss << "\tNet: " << product.getTotalPaid() - product.getTotalMade() << endl;
    ss << "\tPrice: ";
    try {
        ss << product.getPrice();
    }
    catch(...) {
        ss << "Unavailable";
    }
    ss << endl;
    return ss;
}
