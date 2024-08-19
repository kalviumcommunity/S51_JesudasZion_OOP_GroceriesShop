#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class User {
    private:
        string userName;  
        string email;  
        string password;

        bool logCheck;

        static unordered_map<string , string> users;
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

        string getProductName() const {
            return this->name;
        }

        void updateQuantity(int amount){
            this->quantity = amount;
        }
        void updatePrice(double price){
            this->price = price;
        }
};

class Customer : public User {
    private :
        int customerID ;
        vector<Product> cart;

    public:
        Customer() : User(){
            customerID = userID;
        } 

        void addToCart(const Product& product){
            cart.push_back(product);
                    std::cout << "Added " << product.getProductName() << " to the cart." << std::endl;

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

    Customer* customer1 = new Customer;
    customer1->login("user1", "wrongpassword", "Zion@123");
    customer1->login("user1", "password1","Zion@134");

    if (customer1->isLoggedIn()) {
        cout << "Currently logged" << '\n';
    }

    Product product1("P001", "Apple", "Fruit", 0.99, 100);
    product1.display();

    customer1->addToCart(product1);
    customer1->logout();
    delete customer1;
    customer1 = nullptr;

    return 0;
}