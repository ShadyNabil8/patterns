#include <iostream>

class Book
{
private:
public:
    Book() {}
    ~Book() {}
    std::string m_name;
    // A pure virtual function implicitly makes the class it is defined for abstract
    // (unlike in Java where you have a keyword to explicitly declare the class abstract).
    // Abstract classes cannot be instantiated. Derived classes need to override/implement all
    // inherited pure virtual functions. If they do not, they too will become abstract.
    virtual void PrintBookName() const = 0;
};

class ConcreteBook1 : public Book
{
private:
public:
    ConcreteBook1() { m_name = "This is book1 name"; }
    ~ConcreteBook1() {}
    /* If you did not write const keywordm that will not br an override and this will be also an abstract class*/
    void PrintBookName() const override
    {
        std::cout << "I am inside the Book subclass and " << this->m_name << std::endl;
    }
};

class ConcreteBook2 : public Book
{
private:
public:
    ConcreteBook2() { m_name = "This is book2 name"; }
    ~ConcreteBook2() {}
    /* If you did not write const keywordm that will not br an override and this will be also an abstract class*/
    void PrintBookName() const override
    {
        std::cout << "I am inside the Book subclass and " << this->m_name << std::endl;
    }
};

class Factory
{
private:
public:
    Factory() {}
    ~Factory() {}
    virtual Book *FactoryMethod() const = 0;

    void ReleaseFunction() const
    {
        Book *book = this->FactoryMethod();
        book->PrintBookName();
        delete book;
    }
};

class ConcreteFactory1 : public Factory
{
private:
public:
    ConcreteFactory1() {}
    ~ConcreteFactory1() {}
    Book *FactoryMethod() const override
    {
        /* We can make our customization here before returning */
        return new ConcreteBook1();
    }
};

class ConcreteFactory2 : public Factory
{
private:
public:
    ConcreteFactory2() {}
    ~ConcreteFactory2() {}
    Book *FactoryMethod() const override
    {
        /* We can make our customization here before returning */
        return new ConcreteBook2();
    }
};

void MyCode(const Factory &factory)
{
    factory.ReleaseFunction();
}

int main()
{
    /* Factory is an abstract class but we can make a pointer to an instance to it */
    Factory *factory1 = new ConcreteFactory1;
    Factory *factory2 = new ConcreteFactory2;
    MyCode(*factory1);
    MyCode(*factory2);

    return 0;
}