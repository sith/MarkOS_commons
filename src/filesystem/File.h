//
// Created by Oleksandra Baukh on 2/23/18.
//

#ifndef MARKOS_FILE_H
#define MARKOS_FILE_H


#include <memory/Pointer.h>
#include <types.h>

namespace mark_os {
    namespace filesystem {
        class File {
        public:
            virtual ~File() {
            }
            virtual int8 readNextInt8()= 0;

            virtual int16 readNextInt16()= 0;

            virtual char readNextChar()= 0;

            virtual void writeInt8(const int8 number)= 0;

            virtual void writeInt16(const int16 number)= 0;

            virtual void writeChar(const char aChar)= 0;

            virtual void writeString(const char *aChar)= 0;
        };
    }
}
#endif //MARKOS_FILE_H
