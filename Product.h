#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {

private:
    unsigned int id;
    std::string product_name;
    unsigned int price;
    unsigned int count;

public:
    Product();
    Product(unsigned int id, std::string product_name, unsigned int price, unsigned int count);

    unsigned int get_id();
    std::string get_product_name();
    unsigned int get_price();
    unsigned int get_count();

    void set_id(unsigned int id);
    void set_product_name(std::string product_name);
    void set_price(unsigned int price);
    void set_count(unsigned int count);
};

#endif

