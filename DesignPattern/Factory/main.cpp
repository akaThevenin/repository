#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
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
    virtual unique_ptr<Product> GenerateProduct() = 0;
    void DoSomething() {
        shared_ptr<Product>product = GenerateProduct();
        string str = product->GenerateResult();
        cout << "Some content, " << str << endl;
    }
};

class FactoryA : public Factory {
public:
    ~FactoryA(){}
    unique_ptr<Product> GenerateProduct() {
        return make_unique<ProductA>();
    }
};

class FactoryB: public Factory {
public:
    ~FactoryB(){}
    unique_ptr<Product> GenerateProduct() {
        return make_unique<ProductB>();
    }

};

int main() {
    cout << "Start test" << endl;
    unique_ptr<Factory> factoryA = make_unique<FactoryA>();
    unique_ptr<Factory> factoryB = make_unique<FactoryB>();
    factoryA->DoSomething();
    factoryB->DoSomething();

    return 0;
}