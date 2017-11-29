#include <iostream>
#include <thread>
#include "singleton.h"
using namespace std;

void foo() {
    Singleton* s1 = Singleton::getInstance();
    s1->name = "foo";
    cout << s1 << endl;
}

void bar() {
    Singleton* s1 = Singleton::getInstance();
    s1->name = "bar";
}

int main() {
    std::thread first(foo);
    std::thread second(bar);

    first.join();
    second.join();

    cout << Singleton::getInstance()->name << endl;

    return 0;
}
