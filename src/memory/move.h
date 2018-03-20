//
// Created by Oleksandra Baukh on 2/24/18.
//

#ifndef MARKOS_MOVE_H
#define MARKOS_MOVE_H
namespace mark_os {
    namespace memory {
        template<typename T>
        struct remove_reference {
            using type = T;
        };
        template<typename T>
        struct remove_reference<T &> {
            using type = T;
        };
        template<typename T>
        struct remove_reference<T &&> {
            using type = T;
        };

        template<typename T>
        constexpr typename remove_reference<T>::type &&
        move(T &&x) noexcept { return (typename remove_reference<T>::type &&) x; }
    }
}

#endif //MARKOS_MOVE_H
