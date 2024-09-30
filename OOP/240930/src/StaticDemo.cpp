#include "StaticDemo.hpp"

StaticDemo::StaticDemo() {
    ++createdObjectsCount;
}

StaticDemo::~StaticDemo() {
    ++destroyedObjectsCount;
}

int StaticDemo::createdObjectsCount = 0;
int StaticDemo::destroyedObjectsCount = 0;

int StaticDemo::getCreatedObjectsCount() {
    return createdObjectsCount;
}
int StaticDemo::getDestroyedObjectsCount() {
    return destroyedObjectsCount;
}
