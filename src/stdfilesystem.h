#ifndef INO_FIX_STDFILESYSTEM_H
#define INO_FIX_STDFILESYSTEM_H

#ifdef _MSC_VER //Why be up to date on the latest ISO standard
                //when you can not?

#include <experimental\filesystem>

namespace std {
    namespace filesystem = std::experimental::filesystem::v1;
}

#else

#include <filesystem>

#endif //_WIN32

#endif //INO_FIX_STDFILESYSTEM_H