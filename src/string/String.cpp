//
// Created by Oleksandra Baukh on 2/24/18.
//
#include <memory/move.h>
#include "String.h"

namespace mark_os {
    namespace common {
        String::String(const char *string) : size{length(string)} {
            content = new char[size];
            copyInternal(string, content);
        }

        String::operator const char *() const {
            return content;
        }

        bool String::operator==(const char *someValue) const {
            if (content == someValue) {
                return true;
            }
            int i = 0;
            for (; content[i] != '\0'; i++) {
                if (content[i] != someValue[i])
                    return false;
            }
            return someValue[i] == '\0';
        }

        String &String::operator+=(const char *string) {
            unsigned long startIndex = size;
            size += length(string);

            auto *tmp = new char[size];
            copyInternal(content, tmp, 0);
            copyInternal(string, tmp, startIndex);
            delete[] content;
            content = tmp;
            return *this;
        }

        String::~String() {
            delete[] content;
            content = nullptr;
        }

        void String::copyInternal(const char *from, char *to, unsigned long startIndex) {
            for (int i = 0; from[i] != '\0'; i++) {
                to[startIndex++] = from[i];
            }
            to[startIndex] = '\0';
        }

        String::String(String &&string) noexcept {
            move(string);
        }

        String &String::operator=(String &&string) noexcept {
            move(string);
            return *this;
        }

        void String::move(String &string) {
            size = string.size;
            content = string.content;

            //TODO do I need to clean it?
            string.size = 0;
            string.content = nullptr;
        }

        unsigned long String::length(const char *string) {
            unsigned long i = 0;
            for (; string[i] != '\0'; i++) {}
            return i;
        }
    }
}

mark_os::common::String operator+(const mark_os::common::String &stringA, const mark_os::common::String &stringB) {
    return concatenate(stringA, stringB);
}

mark_os::common::String operator+(const mark_os::common::String &&stringA, const mark_os::common::String &&stringB) {
    return concatenate(stringA, stringB);
}

mark_os::common::String concatenate(const mark_os::common::String &stringA, const mark_os::common::String &stringB) {
    mark_os::common::String result{stringA.get()};
    result += stringB.get();
    return mark_os::memory::move(result);
}