#include <iostream> 
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(pInstance == nullptr){
            pInstance = new Singleton();
        }
        return pInstance;
    }

private:
    Singleton(){};
    Singleton(const Singleton & rhs) = delete;
    Singleton & operator= (const Singleton & rhs) = delete;
    static Singleton* pInstance;
};

Singleton* Singleton::pInstance = nullptr;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    if(s1 == s2){
        cout << "s1 == s2,是单例的\n";
    }else{
        cout << "s1 != s2,不是单例的\n";
    }

    return 0;
}
