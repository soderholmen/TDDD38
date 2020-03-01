#include "Node.h"

using namespace std;

double Number::evaluate(){
  return value;
}

void Number::print_tree(ostream& os, int depth){
  os << setw(depth);
  os << value << endl;
}

Node* Number::clone(){

}


double Addition::evaluate(){
  return left->evaluate() + right->evaluate();
}

void Addition::print_tree(ostream& os, int depth){

}

Node* Addition::clone(){

}


double Subtraction::evaluate(){
  return left->evaluate() + right->evaluate();
}

void Subtraction::print_tree(ostream& os, int depth){
  setw(depth);
  right->print_tree(os, depth+1);
  os << "-" << endl;
  left->print_tree(os, depth+1);

}

Node* Subtraction::clone(){

}


double Division::evaluate(){
  return left->evaluate() + right->evaluate();
}

void Division::print_tree(ostream& os, int depth){
  setw(depth);
  right->print_tree(os, depth+1);
  os << "/" << endl;
  left->print_tree(os, depth+1) ;

}

Node* Division::clone(){

}


double Multiplication::evaluate(){
  return left->evaluate() + right->evaluate();
}

void Multiplication::print_tree(ostream& os, int depth){
  os << setw(depth);
  right->print_tree(os, depth+1);
  os << "*" << endl;
  left->print_tree(os, depth+1) ;

}

Node* Multiplication::clone(){

}

int main(){

  Number i{2};
  Number j{2};
  Multiplication k{&i, &j};
  k.print_tree(cout, 1);
  return 0;
}
