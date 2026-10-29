#include <iostream>
#include <string>

#include "CommandList.h"
#include "Product.h"
#include "Filedriver.h"
#include "Cart.h"

command_code get_command(std::string const &command){
    if(command == "list") return clist;
    if(command == "add") return cadd;
    if(command == "remove") return cremove;
    if(command == "cart") return ccart;
    if(command == "checkout") return ccheckout;
    if(command == "exit") return cexit;
    return cexeption;
}

bool full_command_cycle(std::string const &command, unsigned int id, unsigned int count){
    switch(get_command(command)) {
        case cadd: add(id, count); break;
        case cremove: remove(id, count); break;
        default: std::cout << "Invalid command!" << std::endl; break;
    }
    return true;
}

bool part_command_cycle(std::string const &command){
    switch(get_command(command)){
        case clist: list(); break;
        case ccart: cart(); break;
        case ccheckout: checkout(); break;
        case cexit: return false; break;
        default: std::cout << "Invalid command!" << std::endl; break;
    }

    return true;
}


void list(){
    Product product;
    for(int i = 1; i < 5; i++){
        product = get_product(i);
        
        std::cout << product.get_id() << " | ";
        std::cout << product.get_product_name() << " | ";
        std::cout << product.get_price() << " UAH | ";
        std::cout << "available: " << product.get_count() << std::endl;
    }
}

void add(unsigned int id, unsigned int count){
    Cart::get_instance().add(id, count);
}

void remove(unsigned int id, unsigned int count){
    Cart::get_instance().remove(id, count);
}

void cart(){
    Cart::get_instance().cart();
}

void checkout(){
    Cart::get_instance().checkout();
}

