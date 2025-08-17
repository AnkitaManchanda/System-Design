#include <iostream>
#include <vector>
#include <string>

// The Product class is perfect as is.
class Product {
public:
    std::string name;
    double price;
    Product(std::string n, double p) : name(n), price(p) {}
};

// The ShoppingCart now holds actual Product objects, not pointers.
class ShoppingCart {
private:
    std::vector<Product> products; // No more pointers!
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Return a const reference to avoid unnecessary copies.
    const std::vector<Product>& getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0.0;
        for (const auto& product : products) { // Use . instead of ->
            total += product.price;
        }
        return total;
    }
};

// Invoice now takes a const reference to the cart.
class Invoice {
private:
    const ShoppingCart& cart;
public:
    Invoice(const ShoppingCart& c) : cart(c) {}

    void generateInvoice() {
        std::cout << "Invoice:" << std::endl;
        for (const auto& product : cart.getProducts()) { // Use . instead of ->
            std::cout << product.name << ": $" << product.price << std::endl;
        }
        std::cout << "Total: $" << cart.calculateTotal() << std::endl;
    }
};

class SaveToDB {
private:
    const ShoppingCart& cart;
public:
    SaveToDB(const ShoppingCart& c) : cart(c) {}
    void saveCart() {
        std::cout << "Saving cart to database..." << std::endl;
    }
};

int main() {
    // No more 'new'! Objects are created on the stack.
    ShoppingCart cart;
    cart.addProduct(Product("Apple", 0.99));
    cart.addProduct(Product("Banana", 0.59));

    Invoice invoice(cart);
    invoice.generateInvoice();

    SaveToDB dbSaver(cart);
    dbSaver.saveCart();

    // No need for 'delete', memory is managed automatically!
    return 0;
}