#include <iostream>
#include "pugixml.hpp"
#include "Kingdom.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "XML file path not provided.\n";
        exit(1);
    }

    // Get command line arguments one by one
    std::string xmlFilePath = argv[1];

    // Load the XML file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(xmlFilePath.c_str());

    // Check for errors
    if (!result)
    {
        std::cout << "Error: " << result.description() << "\n";
        exit(1);
    }
    else{
        std::cout << "XML file loaded successfully.\n";
        std::cout << doc.child("Kingdom").child("Name").text().as_string() << "\n";

        Kingdom kingdom(xmlFilePath);
    }

    return 0;
}
