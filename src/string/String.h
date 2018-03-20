//
// Created by Oleksandra Baukh on 2/24/18.
//

#ifndef MARKOS_STRING_H
#define MARKOS_STRING_H

namespace mark_os {
    namespace common {
        class String {
            unsigned long size;
            char *content;

            void copyInternal(const char *from, char *to, unsigned long startIndex = 0);

            void move(String &string);

            unsigned long length(const char *string);

        public:

            String(const char *content);

            String(String &&string) noexcept;

            virtual ~String();

            const char *get() const {
                return content;
            }

            String &operator=(String &&string) noexcept;

            explicit operator const char *() const;

            bool operator==(const char *string) const;

            String &operator+=(const char *string);
        };
    }
}

mark_os::common::String operator+(const mark_os::common::String &stringA, const mark_os::common::String &stringB);

mark_os::common::String operator+(const mark_os::common::String &&stringA, const mark_os::common::String &&stringB);

mark_os::common::String concatenate(const mark_os::common::String &stringA, const mark_os::common::String &stringB);


#endif //MARKOS_STRING_H
