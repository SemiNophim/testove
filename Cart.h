#ifndef CART_H
#define CART_H

#include <vector>
#include "Product.h"

class Cart {
private:
    std::vector<Product> cart_list;

    Cart();

public:
    Cart(const Cart&) = delete;
    Cart& operator=(const Cart&) = delete;

    static Cart& get_instance();

    void add(unsigned int id, unsigned int count);
    void remove(unsigned int id, unsigned int count);
    void cart();
    void checkout();
};

#endif

