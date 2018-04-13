#include "io.h"

#include <fstream>
#include "stdfilesystem.h" //replace this with <filesystem> when MSVC stops
                           //being awful or if you don't care about compiling
                           //this using MSVC
#include <ios>
#include <iostream>
#include <string>

using std::string;
using std::filesystem::exists;
using std::filesystem::path;

string get_name(string message)
{
    std::cout << message;
    getline(std::cin, message);
    return message;
}

path get_input_file_name()
{
    string answer = get_name("Input file name : ");
    
    while (answer.length() == 0 || !exists(static_cast<path>(answer)))
        get_name("Please input the name of an existing file: ");

    return static_cast<path>(answer);
}

bool can_exist(string answer) //also creates/empties the file
{
    std::ofstream file(answer.c_str());

    if (file.is_open())
        return true;
    else
        return false;
}

path get_output_file_name() 
{
    string answer = get_name("Output file name : ");

    while (answer.length() == 0 || !can_exist(answer))
        get_name("Please input a valid file name: ");

    return static_cast<path>(answer);
}