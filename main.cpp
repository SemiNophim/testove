#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

#include "CommandList.h"
#include "Product.h"
#include "Filedriver.h"

void init_catalog(Product products[]){
    std::string catalog_location = "Catalog.txt";

    for(int i = 0; i < 4; i++){
        products[i] = get_product(i + 1);
    }
}

int main() {
    std::string command;
    unsigned int id;
    unsigned int count;
    bool cycle = true;
    Product products[4];
    std::string line;

    init_catalog(products);

    while (cycle){
        std::cout << "> ";
        if (!std::getline(std::cin, line)) break;

        std::stringstream ss(line);
        
        if (!(ss >> command)) {
            std::cout << "You didn't enter a command" << std::endl;
            continue;
        }

        else if(ss >> id >> count){
            cycle = full_command_cycle(command, id, count);
        }
        else {
            cycle = part_command_cycle(command);
        }
    }
    
    return 0;
}

