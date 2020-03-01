/*
 * smart_pointer-test-compare.cpp    Smart pointer, Step 2.
 */
#include "smart_pointer.h"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace IDA_Smart_Pointer;

int main()
{
   cout << "Declaring two smart poinmters, sp1 and sp2:\n";
   cout << "smart_pointer sp1{ new int{ 1 } };\n";
   cout << "smart_pointer sp2{ new int{ 2 } };\n";
   smart_pointer sp1{ new int{ 1 } };
   smart_pointer sp2{ new int{ 2 } };

   cout << "\nComparing two smart pointers using == and !=\n";
   if (sp1 == sp1) cout << "sp1 == sp1: true\n"; else cout << "sp1 == sp1: false\n";
   if (sp1 == sp2) cout << "sp1 == sp2: true\n"; else cout << "sp1 == sp2: false\n";
   if (sp1 != sp1) cout << "sp1 != sp1: true\n"; else cout << "sp1 != sp1: false\n";
   if (sp1 != sp2) cout << "sp1 != sp2: true\n"; else cout << "sp1 != sp2: false\n";

   cout << "Declaring a raw pointer:\n";
   cout << "int* p = new int{ 3 };\n";
   int* p = new int{ 3 };

   cout << "\nComparing smart pointers with raw pointer using == and !=\n";
   if (sp1 == p) cout << "sp1 == p: true\n";   else cout << "sp1 == p: false\n";
   if (p == sp1) cout << "p == sp1: true\n"; else cout << "p == sp1: false\n";
   if (sp1 != p) cout << "sp1 != p: true\n";   else cout << "sp1 != p: false\n";
   if (p != sp1) cout << "p != sp1: true\n"; else cout << "p != sp1: false\n";

   cout << "\nDeklaring an empty smart pointer, sp0\n";
   cout << "smart_pointer sp0;\n";
   smart_pointer sp0;

   // Direct null pointer test is not allowed; there is no conversion to bool
// if (sp0)     cout << "sp0    : true\n"; else cout << "sp0    : false\n";
// if (sp1)     cout << "sp1    : true\n"; else cout << "sp1    : false\n";

   cout << "\nNegated direct null pointer test (sp0 is a null pointer, sp1 is not)\n";
   if (!sp0)     cout << "!sp0    : true\n"; else cout << "!sp0    : false\n";
   if (!sp1)     cout << "!sp1    : true\n"; else cout << "!sp1    : false\n";

   cout << "\nExplicit equality test for null pointer (sp0 is a null pointer)\n";
   if (sp0 == nullptr) cout << "sp0 == nullptr: true\n"; else cout << "sp0 == nullptr: false\n";
   if (nullptr == sp0) cout << "nullptr == sp0: true\n"; else cout << "nullptr == sp0: false\n";
   if (sp1 == nullptr) cout << "sp1 == nullptr: true\n"; else cout << "sp1 == nullptr: false\n";
   if (nullptr == sp1) cout << "nullptr == sp1: true\n"; else cout << "nullptr == sp1: false\n";

   cout << "\nExplicit inequality test for null pointer (sp0 is a null pointer, sp1 is not)\n";
   if (sp0 != nullptr) cout << "sp0 != nullptr: true\n"; else cout << "sp0 != nullptr: false\n";
   if (nullptr != sp0) cout << "nullptr != sp0: true\n"; else cout << "nullptr != sp0: false\n";
   if (sp1 != nullptr) cout << "sp1 != nullptr: true\n"; else cout << "sp1 != nullptr: false\n";
   if (nullptr != sp1) cout << "nullptr != sp1: true\n"; else cout << "nullptr != sp1: false\n";

   // delete is not allowed, as it should not be
  // delete sp0;
}
