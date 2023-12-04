#include <iostream>

class Singleton
{

private:
    Singleton();

public:
    /* Delete the copy constructor */
    Singleton(const Singleton &) = delete;
    ~Singleton();
    void DoSomeThing();
    static Singleton &Get();
    static void Help();
};

Singleton::~Singleton()
{
}
Singleton::Singleton()
{
}
void Singleton::DoSomeThing()
{
    std::cout << "Hello" << std::endl;
}

Singleton &Singleton::Get()
{
    static Singleton instance;
    return instance;
}

void Singleton::Help()
{
    Singleton::Get().DoSomeThing();
}

int main(int argc, char const *argv[])
{
    //////////////////////////////////////////////////////////////////
    // Deleting the copy constructor forces us to make this mistake //
    // Singleton i = Singleton::Get();                              //
    // By doing this we actually make aa instance of the class.     //
    //////////////////////////////////////////////////////////////////

    /* We can make like this */
    Singleton::Get().DoSomeThing(); 
    /* or like this */
    /* In this case make the DoSomeThing() private */
    Singleton::Help();
    return 0;
}
