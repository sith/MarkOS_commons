//
// Created by Oleksandra Baukh on 4/15/18.
//

#ifndef MARKOS_MAIN_INMEMORYLIST_H
#define MARKOS_MAIN_INMEMORYLIST_H

#include <types.h>

namespace mark_os {
    namespace commons {
        template<typename T, uint16 Size>
        class InMemoryList {
            T list[Size];

            using iterator = T *;
        public:
            void add(const T &t) {

            }

            void remove(uint16 index) {

            }

            T get(uint16 index) {
                return list[index];
            }

            uint16 size() {
                return 0;
            }

            iterator begin() const {
                return nullptr;
            }

            iterator end() const {
                return nullptr;
            }


        };
    }
}
#endif //MARKOS_MAIN_INMEMORYLIST_H
