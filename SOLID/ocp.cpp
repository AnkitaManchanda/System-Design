#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
public:
    string name;
    double price;
    Product(string n, double p) : name(n), price(p) {}
};

class ShoppingCart {
private:
    vector<Product*> products; 
public:
    void addProduct(Product* product) {
        products.push_back(product);
    }
    const vector<Product*>getProducts()  {
        return products;
    }

    double calculateTotal(){
        double total = 0.0;
        for (auto product : products) { 
            total += product->price;
        }
        return total;
    }
};

class Invoice {
private:
     ShoppingCart* cart;
public:
    Invoice(ShoppingCart* c) : cart(c) {}

    void generateInvoice() {
        cout << "Invoice:" << endl;
        for (auto product : cart->getProducts()) {
            cout << product->name << ": " << product->price << endl;
        }
        cout << "Total: " << cart->calculateTotal() << endl;
    }
};

class SaveToDB {
private:
    ShoppingCart* cart;
public:
    //SaveToDB(ShoppingCart* c) : cart(c) {}
    virtual void save(ShoppingCart* c)=0;
};
class SaveToSQL:public SaveToDB{
public:
  	void save(ShoppingCart* c) override{
  		cout<<"Save to SQL "<<endl;
	  }
};
class SaveToFile:public SaveToDB{
public:
  	void save(ShoppingCart* c) override{
  		cout<<"Save to File "<<endl;
	  }
};
class SaveToMongoDB:public SaveToDB{
public:
  	void save(ShoppingCart* c) override{
  		cout<<"Save to MongoDB "<<endl;
	  }
};
int main() {
    ShoppingCart* cart=new ShoppingCart();
    cart->addProduct(new Product("Apple", 0.99));
    cart->addProduct(new Product("Banana", 0.59));

    Invoice* invoice=new Invoice(cart);
    invoice->generateInvoice();

    SaveToDB* dbSaver=new SaveToFile();
    dbSaver->save(cart);
    return 0;
}