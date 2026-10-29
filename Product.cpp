#include "Product.h"
#include <string>

Product::Product(){}
Product::Product(unsigned int id, std::string product_name, unsigned int price, unsigned int count){
    this->id = id;
    this->product_name = product_name;
    this->price = price;
    this->count = count;
}

unsigned int Product::get_id() { return id; }
std::string Product::get_product_name() { return product_name; }
unsigned int Product::get_price() { return price; }
unsigned int Product::get_count() { return count; }

void Product::set_id(unsigned int id) { this->id = id; }
void Product::set_product_name(std::string product_name) { this->product_name = product_name; }
void Product::set_price(unsigned int price) { this->price = price; }
void Product::set_count(unsigned int count) { this->count = count; }

