#include <iostream>
#include <string>
#include <fstream>

#include "Filedriver.h"

#define catalog_path "Catalog.txt"

Product get_product(unsigned int id){
    std::ifstream file;
    std::string line;
    Product temp_product;
    
    file.open(catalog_path);

    for(int i = 0; i < id; i++){
        getline(file, line);
    }

    file.close();

    // set id 
    temp_product.set_id(id);

    // set product_name
    std::string product_name = "";
    size_t product_name_pos = line.find("product_name = ");
    for(int i = 15 + product_name_pos; i < line.size(); i++){
        if(line[i] == ',') break;
        product_name += line[i];
    }
    temp_product.set_product_name(product_name);

    // set price
    std::string price = "";
    size_t price_pos = line.find("price = ");
    for(int i = 8 + price_pos; i < line.size(); i++){
        if(line[i] == ',') break;
        price += line[i];
    }
    temp_product.set_price(std::stoi(price));

    // set count
    std::string count = "";
    size_t count_pos = line.find("count = ");
    for(int i = 8 + count_pos; i < line.size(); i++){
        if(line[i] == ',') break;
        count += line[i];
    }
    temp_product.set_count(std::stoi(count));

    return temp_product;
}

void set_product(Product product){
    unsigned int id = product.get_id();
    std::string product_name = product.get_product_name();
    unsigned int price = product.get_price();
    unsigned int count = product.get_count();

    std::ifstream output_file;
    std::string text = "";
    std::string line;
    
    // output file
    output_file.open(catalog_path);
    int i = 0;
    while(getline(output_file, line)){
        if(i == id - 1){
            text += "[id = " + std::to_string(id) + ", product_name = " + product_name + ", price = " + std::to_string(price) + ", count = " + std::to_string(count) + "]" + '\n';
        }
        else text += line + '\n';
        i++;
    }
    output_file.close();

    // input file
    std::ofstream input_file;
    input_file.open(catalog_path);
    input_file << text;
    input_file.close();
}

