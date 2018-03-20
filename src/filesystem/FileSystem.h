//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_FILESYSTEM_H
#define MARKOS_FILESYSTEM_H


#include <memory/Pointer.h>
#include <collections/List.h>
#include "File.h"
namespace mark_os {
    namespace filesystem {

        class FileSystem {
        public:
            virtual Pointer<File> openFile(const char *path)= 0;

            virtual void deleteFile(const char *path)= 0;

            virtual void createDirectory(const char *path)= 0;
        };
    }
}
#endif //MARKOS_FILESYSTEM_H
