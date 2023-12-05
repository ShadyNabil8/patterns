# Singleton

This pattern is used when we want to create only one instance from a class.

Signleton in C++ is just a way to organize a bunsh of global variables and static functions into a block under a name space.

Singleton:

1. Can't have a constructor
2. provides a way to access the ckass staticly.

# Factory

Factory method is a creational design pattern which solves the problem of creating product objects without specifying their concrete classes.

The Factory Method defines a method, which should be used for creating objects instead of using a direct constructor call (```new``` operator). Subclasses can override this method to change the class of objects that will be created (customization).

1. Solves the problem of creating product objects without specifying their concrete classes.
2. Provide making customization before creating an object.
3. Makes it easy to extend the number of classes (Books in our example) without affecting the rest of the application.