#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"
#include <string>
#include <iostream>

using namespace std;

//Output store information
void printInfo(Store &s) {
    cout << endl << "-------Store information-------" << endl << s;
}

// Let user select action and perform
void menuSelection(Store &s) {
    cout << "\nEnter a number as an option:" << endl
         << "1 - Change store name" << endl
         << "2 - Add a product" << endl
         << "3 - Add a customer" << endl
         << "4 - Take a shipment" << endl
         << "5 - Sell a product" << endl
         << "6 - Get store information" << endl;
    int choice;
    string name;
    int id;
    int pid;
    int cid;
    int quantity;
    double cost;
    cin >> choice;
    switch(choice) {
        case 1: // Change store name
            cout << "Enter new name: ";
            cin.get();
            getline(cin, name);
            s.setName(name);
            cout << "Name changed." << endl;
            break;
        case 2: // Add product
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin.get();
            getline(cin, name);
            if (s.addProduct(id, name)==1) {
                cout << "Product added." << endl;
            }
            break;
        case 3: // Add customer
            cout << "Enter customer ID: ";
            cin >> id;
            cout << "Enter customer name: ";
            cin.get();
            getline(cin, name);
            if (s.addCustomer(id, name)==1) {
                cout << "Customer added." << endl;
            }
            break;
        case 4: // Take shipment
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter total cost: ";
            cin >> cost;
            if (s.takeShipment(id, quantity, cost)==1) {
                cout << "Shipment taken." << endl;
            }
            break;
        case 5: // Sell product
            cout << "Enter customer ID: ";
            cin >> cid;
            cout << "Enter product ID: ";
            cin >> pid;
            cout << "Enter quantity: ";
            cin >> quantity;
            if (s.sellProduct(cid, pid, quantity)==1) {
                cout << "Product sold." << endl;
            }
            break;
        case 6: // Get store information
            printInfo(s);
            break;
    }
}

// Looping driver to show implementation of classes
int main() {
    cout << "Enter store name: ";
    string name;
    getline(cin, name);
    Store store(name);
    printInfo(store);
    while(1) {
        menuSelection(store);
    }
}
