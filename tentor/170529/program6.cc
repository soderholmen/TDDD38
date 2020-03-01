#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Fruit{
  int mass_;

public:
  
  Fruit(int mass) : mass_{mass}{}

  virtual ~Fruit() = default;

  virtual const string name() const = 0;

  int vitamin_c_content(){
    return concentration()*mass_/100;
  }

  const int mass() const {
    return mass_;
  }

  virtual const bool dehiscent() = 0;


protected:
  virtual const int concentration() = 0;
  
};

class Berry : public Fruit{
protected:
  using Fruit::Fruit;
};

class Apple : public Fruit{
public:
  using Fruit::Fruit;
  const string name() const override{
    return "Apple";
  }
  const bool dehiscent() override{
    return false;
  }
  const int concentration() override{
    return 4.6;
  }
  
};

class Lemon : public Berry{
public:
  using Berry::Berry;
  const string name() const override{
    return "Lemon";
  }
  const int concentration() override{
    return 53;
  }
};

class Pea : public Fruit {
public:
  using Fruit::Fruit;
  const string name() const override{
    return "Pea";
  }
  const bool dehiscent() override{
    return false;
  }
  const int concentration() override{
    return 40;
  }
};

void print(Fruit const & f)
{
    // Print Berry if f is a berry or Fruit otherwise

    cout << f.name() << " with mass " << f.mass() << "g [";
    //if ( !f.dehiscent() )
    //{
    //    cout << "in";
    //}
    cout << "dehiscant]\n";

}

int main()
{
  // create a vector containing the following fruits:
    //  Apple, mass: 150g
    //  Lemon, mass: 75g
    //  Pea, mass: 25g
    //

    // Iterate through the vector and pass each fruit to print above, should give the following output
    // Fruit, Apple with mass 150g [indehiscant]
    // Berry, Lemon with mass 75g [indehiscant]
    // Fruit, Pea with mass 25g [dehiscant]

  vector<const Fruit*> v;

  //Pea* p = new Pea(100);
  v.push_back(new Pea{150});


  for (auto && fruit : v){
    print(*fruit);
   }
  
   int total_content {};
    // Calculate the total vitamin C content of all fruit

    cout << "Total vitamin C content: " << total_content << endl;
}
