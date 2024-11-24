#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Product class
class Product {
private:
    string name;
    double price;
    bool onPromotion;

public:
    Product(const string& name, double price, bool onPromotion = false) :
        name(name), price(price), onPromotion(onPromotion) {}

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    bool isOnPromotion() const {
        return onPromotion;
    }

    void setPromotion(bool promotion) {
        onPromotion = promotion;
    }
};

// Category class
class Category {
private:
    string name;
    vector<Product*> products;

public:
    Category(const string& name) : name(name) {}

    string getName() const {
        return name;
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void removeProduct(const string& productName) {
        auto it = find_if(products.begin(), products.end(),
            [productName](Product* p) { return p->getName() == productName; });
        if (it != products.end()) {
            products.erase(it);
        }
    }

    void updateProduct(const string& productName, double newPrice, bool newPromotion) {
        auto it = find_if(products.begin(), products.end(),
            [productName](Product* p) { return p->getName() == productName; });
        if (it != products.end()) {
            (*it)->setPromotion(newPromotion);
            (*it)->getPrice() = newPrice;
        }
    }

    vector<Product*> getProducts() const {
        return products;
    }
};

// OnlineShop class
class OnlineShop {
private:
    string name;
    vector<Category*> categories;

public:
    OnlineShop(const string& name) : name(name) {}

    string getName() const {
        return name;
    }

    void addCategory(Category* category) {
        categories.push_back(category);
    }

    void removeCategory(const string& categoryName) {
        auto it = find_if(categories.begin(), categories.end(),
            [categoryName](Category* c) { return c->getName() == categoryName; });
        if (it != categories.end()) {
            categories.erase(it);
        }
    }

    void displayAllProducts() const {
        cout << "Products in " << name << ":" << endl;
        for (Category* category : categories) {
            cout << "Category: " << category->getName() << endl;
            for (Product* product : category->getProducts()) {
                cout << "  - " << product->getName() << " (Price: " << product->getPrice()
                    << ", On Promotion: " << (product->isOnPromotion() ? "Yes" : "No") << ")" << endl;
            }
        }
    }

    void displayProductsOnPromotion() const {
        cout << "Products on promotion in " << name << ":" << endl;
        for (Category* category : categories) {
            for (Product* product : category->getProducts()) {
                if (product->isOnPromotion()) {
                    cout << "  - " << product->getName() << " (Price: " << product->getPrice() << ")" << endl;
                }
            }
        }
    }

    void searchProducts(const string& query, bool byName = true, bool byPrice = false, bool byCategory = false) const {
        cout << "Search results for '" << query << "':" << endl;
        for (Category* category : categories) {
            for (Product* product : category->getProducts()) {
                if ((byName && product->getName() == query) ||
                    (byPrice && product->getPrice() == stod(query)) ||
                    (byCategory && category->getName() == query)) {
                    cout << "  - " << product->getName() << " (Price: " << product->getPrice()
                        << ", Category: " << category->getName() << ")" << endl;
                }
            }
        }
    }
};

int main() {
    // Create products
    Product* product1 = new Product("Laptop", 1200.00, true);
    Product* product2 = new Product("Keyboard", 50.00);
    Product* product3 = new Product("Mouse", 25.00);
    Product* product4 = new Product("Monitor", 300.00);
    Product* product5 = new Product("Webcam", 75.00);

    // Create categories
    Category* category1 = new Category("Electronics");
    Category* category2 = new Category("Peripherals");

    // Create online shop
    OnlineShop* shop = new OnlineShop("TechMart");

    // Add products to categories
    category1->addProduct(product1);
    category1->addProduct(product4);
    category2->addProduct(product2);
    category2->addProduct(product3);
    category2->addProduct(product5);

    // Add categories to shop
    shop->addCategory(category1);
    shop->addCategory(category2);

    // Display all products in the shop
    shop->displayAllProducts();

    // Display products on promotion
    shop->displayProductsOnPromotion();

    // Search for a product by name
    shop->searchProducts("Laptop");

    // Search for a product by price
    shop->searchProducts("50.00", false, true);

    // Search for a product by category
    shop->searchProducts("Peripherals", false, false, true);

    // Update a product
    category1->updateProduct("Laptop", 1100.00, false);

    // Remove a product from a category
    category2->removeProduct("Mouse");

    // Remove a category from the shop
    shop->removeCategory("Peripherals");

    // Display all products again
    shop->displayAllProducts();

    // Clean up memory
    delete product1;
    delete product2;
    delete product3;
    delete product4;
    delete product5;
    delete category1;
    delete category2;
    delete shop;

    return 0;
}
