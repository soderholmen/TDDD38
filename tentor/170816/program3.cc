#include <forward_list>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template<typename It, typename Comp = std::less<typename It::value_type>>
  void ssort(It start, It end, Comp comp = {})
{
  for (start; start != end; ++start){
    auto smallest_value_it = start;
    for (auto it = start; it != end; ++it){
      if (comp(*it, *smallest_value_it)){
	smallest_value_it = it;
      }
    }
    iter_swap(start, smallest_value_it);
  }
}


int main()
{
  vector<int> v {2, 5, 7, 1, 7, 34};
    ssort(begin(v), end(v));
    for ( auto i : v )
    {
        cout << i << endl;
    }
    forward_list<string> lst {"hello", "this", "is", "a", "test"};
    ssort(begin(lst), end(lst),
      [](string a, string b){ return a.length() < b.length();});
    while(!lst.empty()){
      cout << lst.front() << endl;
      lst.pop_front();
    }							 
 }
