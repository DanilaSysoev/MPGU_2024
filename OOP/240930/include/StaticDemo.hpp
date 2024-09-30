#pragma once
#ifndef STATICDEMO_HPP
#define STATICDEMO_HPP

class StaticDemo
{
private:
    static int createdObjectsCount;
    static int destroyedObjectsCount;

public:
    StaticDemo();
    ~StaticDemo();

    static int getCreatedObjectsCount();
    static int getDestroyedObjectsCount();
};

#endif
