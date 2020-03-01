/*
 * smart_pointer.h     Smart pointer, given code.
 */
#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

namespace IDA_Smart_Pointer
{

   class smart_pointer
   {
      public:
         smart_pointer();
         explicit smart_pointer(int* p);
         smart_pointer(const smart_pointer& other);
         smart_pointer(smart_pointer&& other) noexcept;
	 smart_pointer(int&& p);
   	 ~smart_pointer();

	 smart_pointer& operator=(const smart_pointer& rhs) &;
         smart_pointer& operator=(smart_pointer&& rhs) & noexcept;
	 smart_pointer& operator=(const int& rhs) &;
	 smart_pointer& operator=(int* rhs) &;
         smart_pointer& operator=(int&& rhs) & noexcept;

	 friend bool operator==(const smart_pointer& lhs, const smart_pointer& rhs);
	 friend bool operator==(const smart_pointer& lhs, const int* rhs);
	 friend bool operator==(const int* lhs, const smart_pointer& rhs);
	 friend bool operator!=(const smart_pointer& lhs, const smart_pointer& rhs);
	 friend bool operator!=(const smart_pointer& lhs, const int* rhs);
	 friend bool operator!=(const int* lhs, const smart_pointer& rhs);
	 
	 bool operator!(); 
	 int &operator*();
         int *operator->();

	 int* get();

   private:
      int* ptr_;

      void copy(const smart_pointer& p);
   };

   bool operator==(const smart_pointer& lhs, const smart_pointer& rhs);
   bool operator==(const smart_pointer& lhs, const int* rhs);
   bool operator==(const int* lhs, const smart_pointer& rhs);
 
   bool operator!=(const smart_pointer& lhs, const smart_pointer& rhs);
   bool operator!=(const smart_pointer& lhs, const int* rhs);
   bool operator!=(const int* lhs, const smart_pointer& rhs);

} // namespace IDA_Smart_Pointer









#endif
