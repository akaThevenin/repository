#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Product;
class Factory;

class Product {
public:
    virtual ~Product(){}
    virtual string GenerateResult() = 0;
};

class ProductA : public Product {
public:
    ~ProductA(){}
    string GenerateResult() {
        return "i am ProductA.";
    }
};

class ProductB : public Product {
public:
    ~ProductB(){}
    string GenerateResult() {
        return "i am ProductB.";
    }
};

class Factory {
public:
    ~Factory(){}
    virtual Product* GenerateProduct() = 0;
    void DoSomething(Product* product) {
        string str = product->GenerateResult();
        cout << "Some content " << str << endl;
    }
};

class FactoryA : public Factory {
public:
    ~FactoryA(){}
    Product* GenerateProduct() {
        return new ProductA();
    }
};

class FactoryB: public Factory {
public:
    ~FactoryB(){}
    Product* GenerateProduct() {
        return new ProductB();
    }

};

int main() {
    cout << "Start test" << endl;
    unique_ptr<Factory> factoryA = make_unique<FactoryA>();
    unique_ptr<Factory> factoryB = make_unique<FactoryB>();
    return 0;
}