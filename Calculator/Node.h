#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>


/*
  Implement the classes:
  - Node
  - Number
  - Operator
  - Addition
  - Subtraction
  - Multiplication
  - Division

  Node should have the following (pure virtual) members:
  - double evaluate()
    + Calculate the expression stored in 'this'
  - void print(std::ostream& os)
    + print the expression represented in 'this'
  - void print_tree(std::ostream& os, int depth)
    + print a textual representation of the expression tree
  - Node* clone()
    + return a a new instance of the expression stored in 'this'
 */
using namespace std;

struct Node
{
  virtual double evaluate() = 0;
  virtual void print_tree(ostream& os, int depth) = 0;
  virtual Node* clone() = 0;
};


struct Operator : public Node
{
 Operator(Node* left, Node* right) : left{left}, right{right} {}
  virtual double evaluate() = 0;
  virtual void print_tree(ostream& os, int depth) = 0;
  virtual Node* clone() = 0;
 protected:
  Node* left;
  Node* right;
};
  
class Number : public Node{

  double value;
 public:

 Number() : value{0}{}
 Number(double value) : value{value}{}
 
 /*
 Number() : value{new double{0}} {}
 Number(double value) : value{new double{value}} {}
 Number(Number& number) : value{new double{number.value}} {}
  
  Number(Number&& number){
    value = nullptr;
    swap(this, number);
    }
  ~Number(){ delete value; }
  */
  virtual double evaluate() final override;
  virtual void print_tree(ostream& os, int depth) final override;
  virtual Node* clone() final override;

};

struct Addition : public Operator
{
  Addition(Node* left, Node* right) : Operator(left, right) {} 
 virtual double evaluate() final override;
  virtual void print_tree(ostream& os, int depth) final override;
  virtual Node* clone() final override;
};


struct Subtraction : public Operator
{
  Subtraction(Node* left, Node* right) : Operator(left, right) {} 
 virtual double evaluate() final override;
  virtual void print_tree(ostream& os, int depth) final override;
  virtual Node* clone() final override;
};


struct Multiplication : public Operator
{
  Multiplication(Node* left, Node* right) : Operator(left, right) {} 
  virtual double evaluate() final override;
  virtual void print_tree(ostream& os, int depth) final override;
  virtual Node* clone() final override;
};


struct Division : public Operator
{
 Division(Node* left, Node* right) : Operator(left, right) {} 
  virtual double evaluate() final override;
  virtual void print_tree(ostream& os, int depth) final override;
  virtual Node* clone() final override;
};
