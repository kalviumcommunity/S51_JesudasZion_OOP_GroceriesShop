#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class User {
protected:
    string userName;  
    string email;  
    string password;
    bool logCheck;
    static unordered_map<string, string> users;
    static int lastUserID;  

public:
    int userID;  
    User() : logCheck(false) {}

    static bool validateCredentials(const string& uname, const string& pwd) {
        return users.find(uname) != users.end() && users[uname] == pwd;
    }

    bool login(string uname, string pwd , string email) {
        if (User::validateCredentials(uname, pwd)) {
            userName = uname;
            password = pwd;
            email = email;
            userID = ++lastUserID;
            logCheck = true;
            cout << "Login successful!" << endl;
            return true;
        } else {
            cout << "Login failed. Incorrect userName or password." << endl;
            return false;
        }
    }

    void logout() {
        if (logCheck) {
            userName = "";
            password = "";
            email = "";
            userID = -1;
            logCheck = false;
            cout << "Logout successful!" << endl;
        } else {
            cout << "No user is logged in." << endl;
        }
    }

    bool isLoggedIn() const {
        return logCheck;
    }

    string getUserName() const {
        return userName;
    }

    void setNewUserName(string name) {
        this->userName = name; 
    }

    virtual void viewRole() const = 0;
};

class Product {
private:
    string productID;
    string name;
    string category;
    double price;
    int quantity;

public:
    Product() : productID(""), name(""), category(""), price(0.0), quantity(0) {}

    ~Product() {}

    Product(string pID, string pName, string pCategory, double pPrice, int pQuantity) 
        : productID(pID), name(pName), category(pCategory), price(pPrice), quantity(pQuantity) {}

    void display() const {
        cout << "Product ID: " << productID << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
    }

    string getProductName() const {
        return this->name;
    }

    string getProductID() const {
        return this->productID;
    }
    double getPrice() const {
        return this->price;
    }

    void updateQuantity(int amount) {
        this->quantity = amount;
    }

    void updatePrice(double price) {
        this->price = price;
    }
};

// IInventory interface - Open/Closed Principle
class IInventory {
public:
    virtual void addProduct(const Product& product) = 0;
    virtual void removeProduct(const string& productID) = 0;
    virtual void updateProduct(const string& productID, double price = -1, int quantity = -1) = 0;
    virtual void viewInventory() const = 0;
    virtual ~IInventory() {}
};

// Shopkeeper class implements IInventory (Open/Closed Principle)
class Shopkeeper : public User, public IInventory {
private:
    string shopkeeperID;
    unordered_map<string, Product> inventory;

public:
    Shopkeeper(string shopID) : User(), shopkeeperID(shopID) {}

    void addProduct(const Product& product) override {
        inventory[product.getProductID()] = product;
        cout << "Product " << product.getProductName() << " added to inventory." << endl;
    }

    void removeProduct(const string& productID) override {
        if (inventory.find(productID) != inventory.end()) {
            inventory.erase(productID);
            cout << "Product with ID " << productID << " removed from inventory." << endl;
        } else {
            cout << "Product with ID " << productID << " not found in inventory." << endl;
        }
    }

    void updateProduct(const string& productID, double price = -1, int quantity = -1) override {
        if (inventory.find(productID) != inventory.end()) {
            if (price != -1) {
                inventory[productID].updatePrice(price);
                cout << "Product price updated." << endl;
            }
            if (quantity != -1) {
                inventory[productID].updateQuantity(quantity);
                cout << "Product quantity updated." << endl;
            }
        } else {
            cout << "Product with ID " << productID << " not found in inventory." << endl;
        }
    }

    void viewInventory() const override {
        if (inventory.empty()) {
            cout << "Inventory is empty." << endl;
        } else {
            for (const auto& item : inventory) {
                item.second.display();
                cout << "-------------------" << endl;
            }
        }
    }

    void viewRole() const override {
        cout << "User Role: Shopkeeper" << endl;
    }
};

class Customer : public User {
private:
    vector<Product> cart;

public:
    Customer() : User() {}
    ~Customer() {}

    void addToCart(const Product& product) {
        cart.push_back(product);
        std::cout << "Added " << product.getProductName() << " to the cart." << std::endl;
    }

    void viewRole() const override {
        cout << "User Role: Customer" << endl;
    }
};

class VIPCustomer : public Customer {
private:
    double discountRate;

public:
    VIPCustomer(double rate) : discountRate(rate) {}

    void applyDiscount(Product& product) {
        double newPrice = product.getPrice() * (1 - discountRate);
        product.updatePrice(newPrice);
        cout << "Discount applied. New price: $" << newPrice << endl;
    }

    void viewRole() const override {
        cout << "User Role: VIP Customer with Discount Rate: " << discountRate * 100 << "%" << endl;
    }
};

// Initialize static members
unordered_map<string, string> User::users = {
    {"user1", "password1"},
    {"user2", "password2"},
    {"shopkeeper", "admin123"}
};

int User::lastUserID = 0;

int main() {
    cout << "===== Shopkeeper Test =====" << endl;
    Shopkeeper shopkeeper1("S001");

    Product product1("P001", "Apple", "Fruit", 0.99, 100);
    Product product2("P002", "Banana", "Fruit", 0.50, 200);
    if (shopkeeper1.login("shopkeeper", "admin123", "shopkeeper@shop.com")) {
        shopkeeper1.addProduct(product1);
        shopkeeper1.addProduct(product2);
        shopkeeper1.viewInventory();
        shopkeeper1.updateProduct("P001", 1.10, 90);
        shopkeeper1.viewInventory();
        shopkeeper1.removeProduct("P002");
        shopkeeper1.viewInventory();
        shopkeeper1.logout();
    }

    cout << "\n===== Customer Test =====" << endl;
    Customer customer1;
    if (customer1.login("user1", "password1", "user1@email.com")) {
        customer1.addToCart(product1);
        customer1.viewRole();
        customer1.logout();
    }

    cout << "\n===== VIP Customer Test =====" << endl;
    VIPCustomer vip1(0.10);
    if (vip1.login("user2", "password2", "vipcustomer@email.com")) {
        vip1.addToCart(product1);
        vip1.applyDiscount(product1);
        vip1.viewRole();
        vip1.logout();
    }

    return 0;
}
