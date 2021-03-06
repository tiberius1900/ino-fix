// Ino Fix.cpp : Defines the entry point for the console application.
//

#include "stdfilesystem.h" //replace this with <filesystem> when MSVC stops
                           //being awful or if you don't care about compiling
                           //this using MSVC
#include <ios>
#include <iostream>

#ifdef _WIN32

#include <conio.h>

#endif //_WIN32

#include "files.h"
#include "io.h"



int main()
{
    auto input_file_path = get_output_file_name();
    auto output_file_path = get_output_file_name();
 
    open_files(input_file, output_file);

    #ifdef _WIN32 // This is why we can't have nice things

    _getch();

    #endif //_WIN32

    return 0;
}

