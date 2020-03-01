#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cctype>
using namespace std;

int main(){
  vector<string> s{istream_iterator<string>{cin},istream_iterator<string>{}};
  cout << s.size() << endl;
  for_each (begin(s), end(s), [](string & s){
    transform(begin(s), end(s), begin(s), ::tolower);
    });

  sort(begin(s), end(s));

  s.erase(unique(begin(s), end(s)), end(s));
  cout << s.size() << endl;

  copy(begin(s), end(s), ostream_iterator<string>(cout, " "));

  stable_sort(begin(s), end(s), [](string const & l, string const & r){
      return l.length() < r.length();
    });

  cout << endl;
  copy(begin(s), end(s), ostream_iterator<string>(cout, " "));
}
