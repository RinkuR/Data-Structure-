#include <iostream>
#include <list>
#include <map>
using namespace std;
class LRU
{
 public:
 LRU(int args)
 {
  size = args;
 }
 void refer(int p);
 void display()
 {
  list<int>::iterator iter = links.begin();
  for(;iter != links.end(); iter++)
   cout << *iter << endl;
 }
 private:
 int size;
 map<int, list<int>::iterator> refr;
 list<int> links;
};

void LRU::refer(int p)
{
 if(refr.find(p) == refr.end()) // not found in map
 {
  if(links.size() == size)// cache is full
  {
   int last = links.back();
   links.pop_back();
  }
   links.push_front(p);
   refr[p] = links.begin();
 }
 else
 {
  links.erase(refr[p]);
  links.push_front(p);
  refr[p] = links.begin();
 }
}

int main()
{
 LRU lru(4);
 lru.refer(1);
 lru.refer(2);
 lru.refer(1);
 lru.refer(3);
 lru.refer(4);
 lru.refer(5);
 lru.refer(6);
 lru.refer(4);
 lru.refer(3);
 lru.refer(2);
 lru.display();
 return 0;
}
