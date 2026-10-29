#include "Cart.h"
#include "Filedriver.h"
#include <algorithm>
#include <iostream>

Cart::Cart() {
    cart_list.reserve(4);
}

Cart& Cart::get_instance() {
    static Cart instance;
    return instance;
}

void Cart::add(unsigned int id, unsigned int count) {
    if(id > 4 || id < 1) {
        std::cout << "Product with this id doesn't exist!" << std::endl;
        return;
    }

    Product catalog_product = get_product(id);
    if(count > catalog_product.get_count()) {
        std::cout << "We don't have this many amount of this product!" << std::endl;
        return;
    }

    if(!cart_list.empty()) {
        for(Product &product: cart_list) {
            if(product.get_id() == id && product.get_count() + count > catalog_product.get_count()) {
                std::cout << "We don't have this many amount of this product!" << std::endl;
                return;
            }
            else if(product.get_id() == id) {
                product.set_count(product.get_count() + count);
                std::cout << "Added " << product.get_product_name() << " x";
                std::cout << count << std::endl;
                return;
            }
        }
    }

    Product temp_product;
    
    // set id 
    temp_product.set_id(id);
    
    // set product_name
    temp_product.set_product_name(catalog_product.get_product_name());

    // set price 
    temp_product.set_price(catalog_product.get_price());

    // set count
    temp_product.set_count(count);

    cart_list.push_back(temp_product);

    std::cout << "Added " << temp_product.get_product_name() << " x";
    std::cout << count << std::endl;
   
}

void Cart::remove(unsigned int id, unsigned int count) {
    if(id > 4 || id < 1) {
        std::cout << "Product with this id doesn't exist!" << std::endl;
        return;
    }
    if(cart_list.empty()) {
        std::cout << "Cart is empty, you can't remove!" << std::endl;
        return;
    }

    int i = 0;
    bool found = false;

    for(Product product : cart_list) {
        if(product.get_id() == id) {
            found = true;
            break;
        }
        i++;
    }

    if(!found) {
        std::cout << "Cart doesn't have product with this id!" << std::endl;
        return;
    }    

    Product &cart_product = cart_list.at(i);

    if(count > cart_product.get_count()) {
        std::cout << "Cart doesn't have this many amount of this product!" << std::endl;
        return;
    }

    if(cart_product.get_count() == count) {
        std::cout << "Removed " << cart_product.get_product_name();
        std::cout << " x" << count << std::endl;
        cart_list.erase(cart_list.begin() + i);
        return;
    }
    cart_product.set_count(cart_product.get_count() - count);
    std::cout << "Removed " << cart_product.get_product_name();
    std::cout << " x" << count << std::endl;

}

void Cart::cart() {
    if(cart_list.empty()) {
        std::cout << "Your cart is empty!" << std::endl;
    }
    unsigned int total = 0;
    for(Product product: cart_list){
        total += product.get_price() * product.get_count();
        std::cout << product.get_product_name() << " x";
        std::cout << product.get_count() << " = ";
        std::cout << product.get_price() * product.get_count();
        std::cout << " UAH"<< std::endl;
    }
    std::cout << "Total: " << total << " UAH" << std::endl;
}

void Cart::checkout() {
    if(cart_list.empty()) {
        std::cout << "The cart is empty!" << std::endl;
        return;
    }

    unsigned int total = 0;
    Product catalog_product;
    for(Product product: cart_list) {
        catalog_product = get_product(product.get_id());
        catalog_product.set_count(catalog_product.get_count() - product.get_count());
        set_product(catalog_product);
        total += product.get_price() * product.get_count();
    }
    cart_list.clear();

    std::cout << "Order completed. Total: " << total << " UAH" << std::endl;
}

