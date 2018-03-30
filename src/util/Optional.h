//
// Created by Oleksandra Baukh on 3/25/18.
//

#ifndef MARKOS_MAIN_OPTIONAL_H
#define MARKOS_MAIN_OPTIONAL_H

namespace mark_os {
    namespace commons {

        template<typename T>
        class Optional {
            T value;
            bool present = false;
        public:
            Optional(T t) : value(t), present{true} {}

            Optional() : present{false} {}

            T &get() {
                return value;
            }

            bool isPresent() const {
                return present;
            }

            T operator()() {
                return value;
            }

            explicit operator bool() const {
                return isPresent();
            }

            bool operator==(const Optional &rhs) const {
                return value == rhs.value;
            }

            bool operator!=(const Optional &rhs) const {
                return !(rhs == *this);
            }
        };


        template<typename T>
        Optional<T> optional(T t) {
            return {t};
        }

        template<typename T>
        Optional<T> none() {
            return Optional<T>{};
        }
    }
}
#endif //MARKOS_MAIN_OPTIONAL_H
