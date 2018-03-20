//
// Created by Oleksandra Baukh on 2/24/18.
//

#include <string/String.h>
#include <memory/move.h>
#include "StringTest.h"

using mark_os::common::String;

TEST_F(StringTest, simpleTest) {
    String string{"Hello world"};

    ASSERT_EQ(string, "Hello world");
}

TEST_F(StringTest, append) {
    String string{"Hello world"};
    string += "!";
    ASSERT_EQ(string, "Hello world!");
}

TEST_F(StringTest, concatenateStrings) {
    String a{"Hello"};
    String b{" world"};

    String c = a + b;

    ASSERT_EQ(a, "Hello");
    ASSERT_EQ(b, " world");
    ASSERT_EQ(c, "Hello world");
}
