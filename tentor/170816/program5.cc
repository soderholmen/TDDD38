#include <iomanip>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;


int main(){
  std::vector<int> values{std::istream_iterator<int>(cin),
      std::istream_iterator<int>()};
  cout << values.size() << " values read.\n";
  copy(begin(values), end(values), ostream_iterator<int>{cout, " "});
  return 0;
}
