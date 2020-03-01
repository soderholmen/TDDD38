using namespace std;
#include <string>
#include <vector>
#include <iostream>
class Slab {
  
public:
  string get_color() const {return color;}
  string get_size() const {return size;};
  double get_weight() const {return weight;};
  virtual Slab* clone() const = 0;
private:
  string size;
  string color;
  double weight;
protected:
  Slab(Slab const &) = default;
  Slab(string size, string color, double weight) : size{size}, color{color}, weight{weight} {}
  
};

class Concrete : public Slab {
  const bool tumbled_;
public:
  Concrete(string size, string color, double weight, bool tumbled = false) :
    Slab(size, color, weight), tumbled_{tumbled}{}
  const bool tumbled(){return tumbled_;}
  Concrete* clone() const override { return new Concrete{*this};}
};

class Brick : public Slab{

public:
  Brick(string size, string color, double weight) :
    Slab(size, color, weight){}
  Brick* clone() const override {return new Brick(*this);}

};


class Rock : public Slab{
  const string type;
public:
  Rock(string size, double weight, string type) : Slab(size, "Nature", weight), type{type}{}
  string get_type(){return type;}
  Rock* clone() const override {return new Rock(*this);}

};
  
void test(Slab const & s)
{
    // Create a copy of the object that s refers to
    //
    // Print the information about the copy. With objects constructed according to the
    // comments in main, the printout should be:
    // Concrete: Gray, 25x12x4, 2.8kg
    // Rock: Granite, Nature, 12x15x10, 10.5kg
    // Brick: Red, 25x10x10, 3.2kg
    // Concrete: Graphite, 20x20x6, 3.9kg, tumbled
    //
    // Destroy the copy
  
  Slab const * p = s.clone();
  if(auto r = dynamic_cast<Brick const*>(p)){
    cout << "Color: " << r->get_color() << endl;;
  
  }
}

int main()
{
    // Create the following objects dynamically and store in some kind of container:
    // Type      Color    Size      Weight   type/tumbled
    // --------------------------------------------------
    // Concrete  Gray     25x12x4   2.8
    // Rock               12x15x10  10.5     Granite
    // Brick     Red      25x10x10  3.2
    // Concrete  Graphite 20x20x6   3.9      true

    // pass each object to test.

  vector<Slab const *> slabs;
  slabs.push_back(new Brick("25x12x4", "Gray", 2.8));
  for (auto&& p : slabs){
    test(*p);
  }
   return 0;
}

