# Groceries Shop Management System

Welcome to the Groceries Shop Management System! This project is designed to manage the operations of a grocery store using Object-Oriented Programming (OOP) principles. It supports two types of users: customers and shopkeepers, each with their own set of functionalities.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Class Structure](#class-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The Groceries Shop Management System leverages OOP principles to create a comprehensive solution for managing grocery store operations. It includes user authentication, product management, and order processing functionalities. This project demonstrates the four pillars of OOP: encapsulation, abstraction, inheritance, and polymorphism.

## Features

- User authentication for customers and shopkeepers.
- Customers can add products to their cart, view the cart, and checkout.
- Shopkeepers can manage the inventory by adding, updating, and removing products.
- Order management system to track orders placed by customers.

## Class Structure

### 1. User Class

#### Variables:
- `userID`: A unique identifier for the user.
- `username`: The username of the user.
- `password`: The password for the user account.
- `email`: The email address of the user.

#### Methods:
- `login()`: Allows the user to log into the system.
- `logout()`: Allows the user to log out of the system.

### 2. Customer Class (inherits from User)

#### Variables:
- `customerID`: A unique identifier for the customer.
- `cart`: A list containing products the customer intends to purchase.

#### Methods:
- `addToCart(product)`: Adds a product to the customer's cart.
- `removeFromCart(product)`: Removes a product from the customer's cart.
- `viewCart()`: Displays the contents of the customer's cart.
- `checkout()`: Finalizes the purchase of items in the cart, creating an order.

### 3. Shopkeeper Class (inherits from User)

#### Variables:
- `shopkeeperID`: A unique identifier for the shopkeeper.
- `inventory`: A dictionary containing products available in the shop, keyed by productID.

#### Methods:
- `addProduct(product)`: Adds a new product to the shop's inventory.
- `removeProduct(productID)`: Removes a product from the inventory using its productID.
- `updateProduct(productID, price=None, quantity=None)`: Updates the price and/or quantity of a product in the inventory.
- `viewInventory()`: Displays all products in the shop's inventory.

### 4. Product Class

#### Variables:
- `productID`: A unique identifier for the product.
- `name`: The name of the product.
- `category`: The category to which the product belongs.
- `price`: The price of the product.
- `quantity`: The quantity of the product available in stock.

#### Methods:
- `updateQuantity(new_quantity)`: Updates the quantity of the product in stock.
- `updatePrice(new_price)`: Updates the price of the product.

### 5. Order Class

#### Variables:
- `orderID`: A unique identifier for the order.
- `customerID`: The identifier of the customer who placed the order.
- `products`: A list of products included in the order.
- `totalAmount`: The total amount for the order.
- `orderStatus`: The current status of the order (e.g., "pending", "completed").

#### Methods:
- `updateOrderStatus(new_status)`: Updates the status of the order.

## Installation

To run this project, clone the repository and navigate to the project directory:

```bash
git clone https://github.com/yourusername/groceries-shop-management-system.git
cd groceries-shop-management-system
```

## Usage

### Customer Workflow

- Login as a customer.
- Browse products and add them to the cart.
- View the cart and proceed to checkout.
- Place an order and receive an order confirmation.

### Shopkeeper Workflow

- Login as a shopkeeper.
- Manage inventory by adding, updating, or removing products.
- View the current inventory status.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any enhancements or bug fixes.

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Commit your changes (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

