#include <iostream>
#include "pugixml.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "XML file path not provided.\n";
        exit(1);
    }

    // Get command line arguments one by one
    std::string xmlFilePath = argv[1];
    
    pugi::xml_document doc;

    // read xml input from argument
    pugi::xml_parse_result result = doc.load_file(xmlFilePath.c_str());
    if (!result) {
        std::cout << "XML file not loaded successfully.\n";
    }
    else {
        std::cout << "XML file loaded successfully.\n";
        // cout node text
        std::cout << doc.child("Kingdom").child("Name").text().as_string() << std::endl;
    }

    return 0;
}
