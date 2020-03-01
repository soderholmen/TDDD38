#include "smart_pointer.h"
#include <utility>
#include <iostream>
namespace IDA_Smart_Pointer
{


  smart_pointer::smart_pointer() : ptr_{nullptr}{
    //std::cout << "# Base constructor #" << std::endl;
  
  }

  smart_pointer::smart_pointer(int* p) : ptr_{p}{
    //std::cout << "# Pointer constructor #" << std::endl;
  }

  smart_pointer::smart_pointer(int&& p){
    ptr_ = new int{p};
    //std::cout << "# rvalue constructor #" << std::endl;
   }

  
  smart_pointer::smart_pointer(const smart_pointer& other){
    //std::cout << "# Copy constructor #" << std::endl;
  
    copy(other);
  }

  smart_pointer::smart_pointer(smart_pointer&& other) noexcept{
    //std::cout << "# Move constructor #" << std::endl;
  
    if (other.get() == nullptr){
      ptr_ = nullptr;
    }
    else{
      ptr_ = other.ptr_;
      other.ptr_ = nullptr;
    }
  }


  smart_pointer::~smart_pointer(){
    
    if (ptr_ != nullptr){
      //std::cout << "Deleting: " << *this->ptr_ << std::endl;
      delete ptr_;
    }
  }



  smart_pointer& smart_pointer::operator=(const smart_pointer& rhs) &{
    //std::cout << "# lvalue operator = #" << std::endl;
    copy(rhs);
    return *this;
  }

  smart_pointer& smart_pointer::operator=(smart_pointer&& rhs) & noexcept {
    //std::cout << "# rvalue operator = #" << std::endl;
    if(this == &rhs){
      return *this;
    }

    delete ptr_;
    ptr_ = rhs.ptr_;
    rhs.ptr_ = nullptr;
    
    return *this;
  }


  smart_pointer& smart_pointer::operator=(const int& rhs) &{
    ptr_ = new int;
    *ptr_ = rhs;
    return *this;
  }

    smart_pointer& smart_pointer::operator=(int* rhs) &{
    ptr_ = rhs;
    return *this;
  }

  
  smart_pointer& smart_pointer::operator=(int&& rhs) & noexcept{
    ptr_ = new int{rhs};
    return *this;
  }
	 
  
  bool smart_pointer::operator!(){
    if(ptr_ == nullptr){
      return true;
    }
    return false;
  }
  
  bool operator==(const smart_pointer& lhs, const smart_pointer& rhs)
  { 
    return lhs.ptr_ == rhs.ptr_;
  }
  
  bool operator==(const smart_pointer& lhs, const int* rhs)
  {
    return lhs.ptr_ == rhs;
  }
  
  bool operator==(const int* lhs, const smart_pointer& rhs)
  {
      return lhs == rhs.ptr_;
  }
  
  bool operator!=(const smart_pointer& lhs, const smart_pointer& rhs)
  {
    return lhs.ptr_ != rhs.ptr_;
  }
  
  bool operator!=(const smart_pointer& lhs, const int* rhs)
  {
    return lhs.ptr_ != rhs;
  }
  
  bool operator!=(const int* lhs, const smart_pointer& rhs)
  {
    return lhs != rhs.ptr_;
  }
  

  
  int &smart_pointer::operator*(){
    return *this->ptr_;
  }


  int *smart_pointer::operator->(){
    return this->ptr_;
  }
  

  void smart_pointer::copy(const smart_pointer& p){
    ptr_ = new int;
    *ptr_ = *p.ptr_;

  }

  int* smart_pointer::get(){
    return ptr_;
  }
} // namespace IDA_Smart_Pointer
















    /*
int main(){
    
    std::cout << "# Copy lvalue #" << std::endl;
    IDA_Smart_Pointer::smart_pointer ptr{new int{1}};
    IDA_Smart_Pointer::smart_pointer ptr2{};
    ptr2 = ptr;
    std::cout << *ptr.get() << std::endl;
    std::cout << *ptr2.get() << std::endl;
    

    std::cout << std::endl << "# Move rvalue #" << std::endl;;
    IDA_Smart_Pointer::smart_pointer ptr3{};
    ptr3 = std::move(ptr);
    std::cout << *ptr3.get() << std::endl;
    
    
    std::cout << std::endl << "# Dereference rvalue #" << std::endl;;
    IDA_Smart_Pointer::smart_pointer ptr4{2};
    std::cout << *ptr4 << std::endl;

    std::cout << std::endl << "# Equal rvalue #" << std::endl;;
    int* i = new int{3};
    IDA_Smart_Pointer::smart_pointer ptr5{i};
    std::cout << (ptr4==ptr5) << std::endl;
    std::cout << (ptr4!=ptr5) << std::endl;
    
    std::cout << (ptr5==i) << std::endl;
    std::cout << (ptr4==i) << std::endl;
    
    return 0;
  }
*/
