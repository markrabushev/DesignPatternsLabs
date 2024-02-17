#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton* p_instance;

    Singleton() {}
    Singleton(const Singleton&);

public:
    static Singleton* getInstance() {
        if (!p_instance)
            p_instance = new Singleton();
        return p_instance;
    }
};

Singleton* Singleton::p_instance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << s1 << ' ' << s2 << endl;
}

