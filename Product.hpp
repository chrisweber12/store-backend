#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <sstream>

class Product {

public:
    Product(int productID, std::string productName);
    int getID() const;
    std::string getName() const;
    void setName(std::string productName);
    std::string getDescription() const;
    void setDescription(std::string description);
    int getNumberSold() const;
    double getTotalMade() const;
    double getTotalPaid() const;
    int getInventoryCount() const;
    void addShipment(int shipmentQuantity, double shipmentCost);
    void reduceInventory(int purchaseQuantity);
    double getPrice() const;

private:
    int id;
    std::string name;
    std::string description;
    int inventory = 0;
    int numSold = 0;
    double totalPaid = 0;
    double totalMade = 0;
};

std::stringstream& operator<<(std::stringstream& ss, const Product& product);

#endif
