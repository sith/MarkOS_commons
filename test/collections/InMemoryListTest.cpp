//
// Created by Oleksandra Baukh on 4/15/18.
//

#include <collections/InMemoryList.h>
#include "InMemoryListTest.h"

TEST_F(InMemoryListTest, addAndGet) {

    mark_os::commons::InMemoryList<int, 3> list{};
    list.add(1);
    list.add(2);

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(list.get(0), 1);
    ASSERT_EQ(list.get(1), 2);
}

TEST_F(InMemoryListTest, iterator) {

    mark_os::commons::InMemoryList<int, 3> list{};
    list.add(1);
    list.add(2);

    mark_os::commons::InMemoryList<int, 3> copiedList{};
    for (auto &&item : list) {
        copiedList.add(item);
    }

    ASSERT_EQ(copiedList.size(), 2);
    ASSERT_EQ(copiedList.get(0), 1);
    ASSERT_EQ(copiedList.get(1), 2);
}

