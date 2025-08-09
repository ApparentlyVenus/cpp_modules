# C++ Modules - 42 School

A comprehensive collection of C++ programming exercises designed to introduce Object-Oriented Programming concepts. These modules follow the C++98 standard and progressively build understanding of C++ fundamentals through practical implementation.

## 📚 Module Overview

### Module 00 - Fundamentals
**Topics:** Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and basic C++ concepts

This introductory module covers the essential building blocks of C++ programming:
- **Namespaces**: Understanding scope and organization
- **Classes and Objects**: Basic class definition and instantiation
- **Member Functions**: Methods and their implementation
- **I/O Streams**: Moving from C-style I/O to C++ streams
- **Initialization Lists**: Proper constructor initialization
- **Static and Const**: Understanding storage classes and immutability

*Key Learning: Transition from C to C++ paradigms and basic OOP concepts*

### Module 01 - Memory and References
**Topics:** Memory allocation, pointers to members, references, and switch statements

Building on the basics, this module introduces advanced pointer concepts:
- **Dynamic Memory Allocation**: Using `new` and `delete` operators
- **Pointers to Members**: Advanced pointer usage in class contexts
- **References**: Understanding reference types and their applications
- **Switch Statements**: Control flow in C++
- **Memory Management**: Avoiding memory leaks and proper resource handling

*Key Learning: Proper memory management and advanced pointer/reference usage*

### Module 02 - Operator Overloading
**Topics:** Ad-hoc polymorphism, operator overloading, and Orthodox Canonical Form

This module focuses on making classes behave like built-in types:
- **Operator Overloading**: Implementing custom operators for classes
- **Ad-hoc Polymorphism**: Function and operator overloading concepts
- **Orthodox Canonical Form**: The four essential member functions (constructor, destructor, copy constructor, assignment operator)
- **Copy Semantics**: Deep vs shallow copying
- **Resource Management**: RAII principles

*Key Learning: Creating robust, copyable classes with intuitive interfaces*

### Module 03 - Inheritance
**Topics:** Inheritance, class hierarchies, and derived classes

Exploring the "is-a" relationship through inheritance:
- **Base and Derived Classes**: Creating class hierarchies
- **Access Specifiers**: Public, protected, and private inheritance
- **Constructor/Destructor Chaining**: Order of construction and destruction
- **Method Overriding**: Redefining base class methods
- **Object Slicing**: Understanding polymorphic behavior limitations

*Key Learning: Building extensible class hierarchies and understanding inheritance mechanics*

### Module 04 - Polymorphism and Interfaces
**Topics:** Subtype polymorphism, abstract classes, and interfaces

The culmination of OOP concepts with runtime polymorphism:
- **Virtual Functions**: Enabling runtime polymorphism
- **Abstract Classes**: Classes with pure virtual functions
- **Interfaces**: Designing contracts for classes
- **Virtual Destructors**: Proper cleanup in inheritance hierarchies
- **Polymorphic Behavior**: Dynamic dispatch and late binding

*Key Learning: Advanced OOP design patterns and runtime polymorphism*

## 🛠️ Technical Requirements

- **Compiler**: `c++` with flags `-Wall -Wextra -Werror`
- **Standard**: C++98 compliant
- **Style**: Clean, readable code (no enforced coding standard)
- **Memory Management**: No memory leaks, proper resource cleanup
- **STL Usage**: Restricted until Modules 08-09 (containers and algorithms forbidden)

## 📁 Repository Structure

Each module is organized as follows:
```
cpp_module_XX/
├── ex00/
├── ex01/
├── ex02/
└── ...
```

Each exercise directory contains:
- Header files (`.hpp`)
- Implementation files (`.cpp`)
- Makefile
- Test files

## 🏗️ Building and Running

Each exercise includes a Makefile following 42 standards:

```bash
# Navigate to specific exercise
cd cpp_module_XX/exYY

# Compile
make

# Run
./executable_name

# Clean
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild from scratch
```

## 🎯 Learning Objectives

By completing these modules, you will understand:

1. **Object-Oriented Programming**: Core OOP principles and their C++ implementation
2. **Memory Management**: Proper resource allocation and deallocation
3. **Class Design**: Creating robust, maintainable class hierarchies
4. **Polymorphism**: Both compile-time and runtime polymorphic behavior
5. **C++ Best Practices**: Writing efficient, safe, and readable C++ code
