#include <iostream>

class A {
protected:
    void Private() { std::cout << "1"; }
};

class B : private A {
public:
    void IsItPrivate() { Private(); }
};

int main() {
    B b;
    b.IsItPrivate();
}

