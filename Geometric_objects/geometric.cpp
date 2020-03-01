#include <iostream>
#include <math.h>

class geo_obj{


}

class Plane{

public:
  Plane() : area{0}, perimeter{0}{}
  Plane(double area, double perimeter) : area{area}, perimeter{perimeter}{}
  virtual double get_area(){} = 0;
  virtual double get_perimeter(){} = 0; 
};

class Solide{
public:
  Solide() : Plane{0,0}, volume{0} {}
  virtual double get_volume(){} = 0;

};


class Point{

public:
  Point() : x{0}, y{0} {}
  Point(double x, double y) : x{x}, y{y} {}
  double x;
  double y;
};

class Line{
public:
  Line() : start{Point()}, end{Point()} {}
  Line(Point start, Point end) : start{start}, end{end} {}
  double lenght(){
    return pow((pow((end.x - start.x),2) + pow((end.y - start.y),2)),0.5);
  }
  Point start;
  Point end;
				 
};

class Triangle: public Plane{
public:
  Triangle() : A{0}, B{0}, C{0} {Plane();}
  double get_perimeter(){}
  
  
private:
  double A;
  double B;
  double C;
};

int main(){
  Line l{Point{2,3}, Point{5,10}};
  std::cout << l.lenght() << std::endl;
  
  return 0;
}
