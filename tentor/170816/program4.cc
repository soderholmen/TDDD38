#include <vector>
#include <iostream>
#include <iomanip>

// Main function. The output should be
// true
// false
// false
// true






struct All{

  All() = default;
  bool startValue = true;
  bool endValue = false;
  template<typename T>
  bool prefix(T e){
    return static_cast<bool>(e);
  }
  bool combine(bool a, bool b){
    return a && b;
  }
  bool done(bool done){
    return !done;
  }
  
};
 
struct Any{

  Any() = default;
  bool startValue = false;
  bool endValue = true;
  template<typename T>
  bool prefix(T e){
    return static_cast<bool> (e);
  }
  bool combine(bool a, bool b){
    return a || b;
  }
  bool done(bool done){
    return done;
  }
};


struct AtLeast{

  int N; 
  AtLeast(int n) : N{n}  {}
  bool startValue = false;
  bool endValue = true;
  template<typename T>
  bool prefix(T const &e){
    bool res =  static_cast<bool>(e);
    if(res){
      --N;
    }
    return res;
  }
  bool combine(bool a, bool b){
    return false;
  }
  bool done(bool done){
    return (N==0);
  }
};

template<typename It, class Comp = All>
bool logic_combine(It start, It end, Comp comp = {}){

  bool result = comp.startValue;
  for (start; start != end; ++start){
    bool val = comp.prefix(*start);
      result = comp.combine(result, val);
      if (comp.done(result)){
	  return comp.endValue;
	}
  }
  return result;
  
}



int main()
{
    std::vector<int> vals {0,0,0,1};
    auto b { begin(vals) };
    auto e { end(vals) };
    using namespace std;
    cout << boolalpha
         << logic_combine(b,e, AtLeast{1}) << '\n'
         << logic_combine(b,e, AtLeast{8}) << '\n'
         << logic_combine(b,e, Any{}) << '\n'
         << logic_combine(b,e) << '\n';
}



