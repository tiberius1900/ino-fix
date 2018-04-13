#include "move.h"

#include "stdfilesystem.h"
#include <fstream>
#include <ios>

using std::ios_base;

std::ifstream input_file;
std::ofstream output_file;

ios_base::openmode determine_std_mode(mode my_mode, ios_base::openmode std_contender)
{
    if (my_mode == local)
        return std_contender;
    else
        return std::ios_base::binary;
}

void open_files(std::filesystem::path input_file_path,
    std::filesystem::path output_file_path)
{
    auto std_input_mode = determine_std_mode(input_mode, ios_base::in);
    auto std_output_mode = determine_std_mode(output_mode, ios_base::out);
    input_file.open(input_file_path, std_input_mode);
    output_file.open(output_file_path, std_output_mode);
}

void ignore_if_necessary()
{
    char trash;
    switch (input_mode) {
    case local:
    case POSIX:
    case Mac_OS:
        return;
    case Windows:
        input_file >> trash;
        return;
    }
}

void write_nl()
{
    switch(output_mode) {
        case local:
        case POSIX:
            output_file << '\n';
            return;
        case Windows:
            output_file << '\r' << '\n';
            return;
        case Mac_OS:
            output_file << '\r'; //I've been told this is what classic Mac OS uses.
            return;
    }
}

void move_and_fix()
{
    char trigger = determine_trigger();
    char nxt;
    while (!input_file.eof())
    {
        input_file >> nxt;
        if (nxt == trigger)
        {
            ignore_if_necessary();
            write_nl();
        }
        else
            output_file << nxt;
    }
}