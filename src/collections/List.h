//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef CPP_PLAYGROUND_LIST_H
#define CPP_PLAYGROUND_LIST_H

#include <memory/Pointer.h>
#include "Iterator.h"

template<class T>
class List {

public:

    virtual ~List() {};

    virtual void add(T *e)= 0;

    virtual T *remove(int index)= 0;

    virtual bool removeByPointer(T *e)= 0;

    virtual T *get(int index)= 0;

    virtual int size()=0;

    virtual bool contains(T *e)=0;

    virtual Pointer<Iterator<T>> iterator()=0;
};

#endif //CPP_PLAYGROUND_LIST_H
