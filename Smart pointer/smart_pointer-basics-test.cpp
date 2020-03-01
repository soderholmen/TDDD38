/*
 * smart_pointer-basics-test.cpp    Smart pointer, Step 1
 *
 * Testing constructors, destructor, dereferencing, indirection and
 * assignment.
 */
#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace IDA_Smart_Pointer;

int main()
{
   cout << "Default constructor initialize to null pointer:\n";
   cout << "smart_pointer sp0;\n\n";
   smart_pointer sp0;

   cout << "Using operator-> with ordinary member function call syntax:\n";
   cout << "sp0.operator->(): " << sp0.operator->() << "\n\n";

   // operator* applies the built-in operator* on the raw pointer ptr_, which
   // gives execution error for sp0, since its ptr_ ia a raw null pointer.

   cout << "Constructor initializing with pointer to int object:\n";
   cout << "smart_pointer sp1{ new int{ 1 } };\n\n";
   smart_pointer sp1{ new int{ 1 } };

   cout << "Using operator-> with ordinary member function call syntax:\n";
   cout << "sp1.operator->(): " << sp1.operator->() << "\n\n";

   cout << "Using operator* with ordinary member function call syntax:\n";
   cout << "sp1.operator*(): " << sp1.operator*() << "\n\n";

   cout << "operator* applied the ordinary way (dereferencing)\n";
   cout << "*sp1: " << *sp1 << "\n\n";

   *sp1 = 11147;
   cout << "*sp1 = 11147 done:\n*sp1: " << *sp1 << "\n\n";

   cout << "Copy constructor used:\nsmart_pointer sp2{ sp1 };\n";
   smart_pointer sp2{ sp1 };
   cout << "*sp2: " << *sp2 << "\n\n";

   cout << "Copy assigment operator used:\nsp0 = sp2;\n";
   sp0 = sp2;
   cout << "*sp0: " << *sp0 << "\n\n";

   cout << "Move constructor used:\nsmart_pointer sp3{ std::move(sp2);\n";
   smart_pointer sp3{ std::move(sp2) };
   // Ska gå att göra men inte med nuvarande implementering:
//   cout << "*sp2: " << *sp2 << "\n\n";
   cout << "*sp3: " << *sp3 << "\n\n";

   cout << "Move assignment operator used:\nsp2 = std::move(sp3);\n";
   sp2 = std::move(sp3);
   cout << "*sp2: " << *sp2 << "\n\n";
   // Shall be possible, but not with the current implementation:
//   cout << "*sp3: " << *sp3 << "\n\n";

   cout << "Declaring and initializing a raw pointer:\n";
   cout << "int* px = new int{ 2 };\n";
   int* p = new int{ 2 };
   cout << "\nAssigning raw pointer:\nsp2 = p;\n";
   sp2 = p;
   cout << "*sp2: " << *sp2 << "\n\n";

   cout << "Declaring const smart_pointer\n";
   cout << "const smart_pointer csp{ new int{ 0xC1 } };\n";
   const smart_pointer csp{ new int{ 0xC1 } };
   // Shall be possible, but not with the current implementation:
   // cout << "*csp: " << *csp << "\n\n";

   // Shall not be possible, and is not with the current implementation:
   // csp = sp0;
   // *csp = nullptr;

   cout << "Copy assignment operatorn used:\nsp0 = csp;\n";
   sp0 = csp;
   cout << "*sp0: " << *sp0 << "\n\n";

   return 0;
}
