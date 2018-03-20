//
// Created by Oleksandra Baukh on 1/8/18.
//

#include "LinkedListTest.h"


TEST(LinkedListTest, addElement) {
    LinkedList<int> list;
    int five = 5;
    list.add(&five);
    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(*list.get(0), five);

    int seven = 7;
    list.add(&seven);
    ASSERT_EQ(*list.get(0), five);
    ASSERT_EQ(*list.get(1), seven);
    ASSERT_EQ(list.size(), 2);
}

TEST(LinkedListTest, indexOutOfBounds) {
    LinkedList<int> list;
    int e = 5;
    list.add(&e);

    ASSERT_EQ(list.get(1), nullptr);
}

TEST(LinkedListTest, removeElement) {
    LinkedList<int> list;
    int five = 5;
    list.add(&five);
    ASSERT_EQ(*list.get(0), five);
    list.remove(list.size() - 1);
    ASSERT_EQ(list.size(), 0);
    ASSERT_EQ(list.get(0), nullptr);
}


TEST(LinkedListTest, iterator) {

    LinkedList<int> list;
    int two = 2;
    list.add(&two);
    int four = 4;
    list.add(&four);
    int five = 5;
    list.add(&five);
    int six = 6;
    list.add(&six);

    Iterator<int> &iterator = *list.iterator().get();
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), two);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), four);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), five);
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), six);
    ASSERT_FALSE(iterator.hasNext());
}


TEST(LinkedListTest, iteratorSingleRemove) {
    LinkedList<int> list;
    int two = 2;
    list.add(&two);
    int *value = list.iterator().get()->remove();

    ASSERT_EQ(*value, two);
    ASSERT_EQ(list.size(), 0);

}

TEST(LinkedListTest, iteratorRemove) {

    LinkedList<int> list;
    int two = 2;
    list.add(&two);
    int four = 4;
    list.add(&four);
    int five = 5;
    list.add(&five);
    int six = 6;
    list.add(&six);

    auto iteratorPointer = list.iterator();
    Iterator<int> &iterator = *iteratorPointer.get();
    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), two);

    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.remove(), two);

    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), four);

    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), five);

    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.remove(), five);

    ASSERT_TRUE(iterator.hasNext());
    ASSERT_EQ(*iterator.next(), six);

    ASSERT_FALSE(iterator.hasNext());

    ASSERT_EQ(list.size(), 2);
    ASSERT_EQ(*list.get(0), four);
    ASSERT_EQ(*list.get(1), six);
}

TEST(LinkedListTest, removeWorksForIterator) {
    LinkedList<int> list;
    int one = 1;
    list.add(&one);
    int two = 2;
    list.add(&two);

    Iterator<int> &iterator = *list.iterator().get();
    iterator.remove();
    auto &newIterator = *list.iterator().get();
    ASSERT_TRUE(newIterator.hasNext());
    ASSERT_EQ(*newIterator.next(), two);
}

class Dummy {

};

TEST(LinkedListTest, removeObjectByPointer) {
    LinkedList<Dummy> list;

    Dummy dummy1;
    Dummy dummy2;

    list.add(&dummy1);
    list.add(&dummy2);

    ASSERT_TRUE(list.removeByPointer(&dummy1));

    ASSERT_EQ(list.size(), 1);
    ASSERT_EQ(list.get(0), &dummy2);
}

TEST(LinkedListTest, contains) {
    int two{2};
    int five{5};

    LinkedList<int> list;

    list.add(&two);

    ASSERT_TRUE(list.contains(&two));
    ASSERT_FALSE(list.contains(&five));
}
