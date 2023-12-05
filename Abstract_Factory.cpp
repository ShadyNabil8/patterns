#include <iostream>

class Gpu
{
private:
public:
    Gpu() {}
    ~Gpu() {}
    virtual void assemble() = 0;
};

class MsiGpu : public Gpu
{
private:
public:
    MsiGpu() { std::cout << "MsiGpu is Created!" << std::endl; }
    ~MsiGpu() {}
    void assemble() override
    {
        std::cout << "MsiGpu is assembled" << std::endl;
    }
};

class AsusGpu : public Gpu
{
private:
public:
    AsusGpu() { std::cout << "AsusGpu is Created!" << std::endl; }
    ~AsusGpu() {}
    void assemble() override
    {
        std::cout << "AsusGpu is assembled" << std::endl;
    }
};

class Monitor
{
private:
public:
    Monitor() {}
    ~Monitor() {}
    virtual void assemble() = 0;
};

class MsiMonitor : public Monitor
{
private:
public:
    MsiMonitor() { std::cout << "MsiMonitor is Created!" << std::endl; }
    ~MsiMonitor() {}
    void assemble() override
    {
        std::cout << "MsiMonitor is assembled" << std::endl;
    }
};

class AsusMonitor : public Monitor
{
private:
public:
    AsusMonitor() { std::cout << "AsusMonitor is Created!" << std::endl; }
    ~AsusMonitor() {}
    void assemble() override
    {
        std::cout << "AsusMonitor is assembled" << std::endl;
    }
};

class Factory
{
private:
public:
    Factory() {}
    ~Factory() {}
    /* Must be pointer because Monitor is an abstract class */
    virtual Monitor *CreateMonitor() = 0;
    /* Must be pointer because Gpu is an abstract class */
    virtual Gpu *CreateGpu() = 0;
};

class AsusFactory : public Factory
{
private:
public:
    AsusFactory() {}
    ~AsusFactory() {}
    Monitor *CreateMonitor()
    {
        return new AsusMonitor();
    }
    Gpu *CreateGpu()
    {
        return new AsusGpu();
    }
};

class MsiFactory : public Factory
{
private:
public:
    MsiFactory() {}
    ~MsiFactory() {}
    Monitor *CreateMonitor()
    {
        return new MsiMonitor();
    }
    Gpu *CreateGpu()
    {
        return new MsiGpu();
    }
};

int main(int argc, char const *argv[])
{
    Factory *msi = new MsiFactory();
    Gpu *msiGpu = msi->CreateGpu();
    Monitor *msiMonitor = msi->CreateMonitor();
    delete msi;

    Factory *asus = new AsusFactory();
    Gpu *asusGpu = asus->CreateGpu();
    Monitor *asusMonitor = asus->CreateMonitor();
    delete asus;

    // MsiGpu is Created!
    // MsiMonitor is Created!
    // AsusGpu is Created!
    // AsusMonitor is Created!

    return 0;
}
