#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class User {
    private:
        string userName;  
        string userID;  
        string email;  
        string password;

        bool logCheck;

        static unordered_map<string , string> users;
        static int lastUserID ;   

    public:
        User() : logCheck(false) {}

        bool login(const string& uname, const string& pwd) {
            if (users.find(uname) != users.end() && users[uname] == pwd) {
                userName = uname;
                password = pwd;
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
};

class Product {
    private:
        string productID;
        string name;
        string category;
        double price;
        int quantity;

    public:
        // Default constructor
        Product() : productID(""), name(""), category(""), price(0.0), quantity(0) {}

        // Parameterized constructor
        Product(string pID, string pName, string pCategory, double pPrice, int pQuantity) 
            : productID(pID), name(pName), category(pCategory), price(pPrice), quantity(pQuantity) {}

        void display() const {
            cout << "Product ID: " << productID << endl;
            cout << "Name: " << name << endl;
            cout << "Category: " << category << endl;
            cout << "Price: $" << price << endl;
            cout << "Quantity: " << quantity << endl;
        }
};

unordered_map<string, string> User::users = {
    {"user1", "password1"},
    {"user2", "password2"},
    {"shopkeeper", "admin123"}
};

int User::lastUserID = 0;



int main() {
    cout << "Hello, World!" << endl;

    User customer1;
    customer1.login("user1", "wrongpassword");
    customer1.login("user1", "password1");

    // Check if the user is logged in
    if (customer1.isLoggedIn()) {
        cout << "Currently logged" << '\n';
    }

    Product product1("P001", "Apple", "Fruit", 0.99, 100);
    product1.display();

    return 0;
}