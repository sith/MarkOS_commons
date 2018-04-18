//
// Created by Oleksandra Baukh on 4/15/18.
//

#ifndef MARKOS_MAIN_INMEMORYLIST_H
#define MARKOS_MAIN_INMEMORYLIST_H

#include <types.h>

namespace mark_os {
    namespace commons {
        template<typename T, uint16 MaxSize>
        class InMemoryList {
            T list[MaxSize];
            using iterator = const T *;
            uint16 currentSize = 0;
        public:
            void add(const T &t) {
                list[currentSize++] = t;
            }

            bool set(uint16 index, const T &t) {
                return false;
            }

            void remove(uint16 index) {

            }

            T get(uint16 index) {
                return list[index];
            }

            uint16 size() {
                return currentSize;
            }

            iterator begin() const {
                return &list[0];
            }

            iterator end() const {
                return &list[currentSize];
            }
        };
    }
}
#endif //MARKOS_MAIN_INMEMORYLIST_H
