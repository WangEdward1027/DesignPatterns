//单例模式:懒加载

#include <iostream> 
using std::cout;
using std::endl;

//单例模式:要通过给的接口来创造唯一实例。
//因此，要将构造函数私有化，并且删除拷贝构造和赋值运算符函数

class Singleton
{
public:
    //静态方法,用于获取唯一的实例。静态方法属于类，而非实例对象
    //懒加载、懒汉式、延迟实例化
    static Singleton* getInstance()
    {
        if(pInstance == nullptr){
            pInstance = new Singleton(); 
        }
        return pInstance;
    }

    void display()
    {
        cout << "This is the Singleton instance." << "\n";
    }
private:
    //构造函数私有化，防止外部创建对象
    Singleton()
    {
        cout << "Singleton instance created.\n";
    }

    //禁用拷贝构造和赋值运算符函数
    Singleton(const Singleton & ) = delete;
    Singleton & operator=(const Singleton &) = delete;

    //静态成员变量，存储唯一的实例
    static Singleton* pInstance;
};

//类外初始化静态成员变量
Singleton* Singleton::pInstance = nullptr;

int main()
{
    //获取单例对象的唯一实例
    Singleton* s1 = Singleton::getInstance();
    s1->display();

    //再次获取单例对象的实例
    Singleton* s2 = Singleton::getInstance();
    s2->display();

    //验证两个指针是否指向同一个实例
    if(s1 == s2){
        cout << "Both pointer point to the same instance.\n";
    }

    return 0;
}
