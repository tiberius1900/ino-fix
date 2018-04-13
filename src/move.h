#ifndef INO_FIX_MOVE_H
#define INO_FIX_MOVE_H

#include "stdfilesystem.h"

enum mode {
    POSIX,   //LF,    \n
    Windows, //CR+LF, \r
    Mac_OS,  //CR     \c
    local
} output_mode{ local }, input_mode{ POSIX };

void open_files(std::filesystem::path input_file_path,
    std::filesystem::path output_file_path);

void move_and_fix();

#endif //INO_FIX_MOVE_H