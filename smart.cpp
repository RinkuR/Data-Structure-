#include <iostream>
using namespace std;
template<class T>
class smart
{
 private:
  T *ptr;
  int reference;
 
 public:
 smart(T *p=NULL)
 {
  ptr = p;
  reference = 1;
 }
 ~smart()
 {
  
   cout << "smart dest called " << reference << endl;
  reference--;
  if( !reference )
  {
   cout << "smart dest called " << reference << endl;
   delete ptr;
  }
 }
 T& operator*(){return *ptr;}
 T* operator->(){ return ptr;}
 smart & operator=(const smart & obj);
 smart(const smart & obj);
};

template<class T>
smart<T> & smart<T>::operator= (const smart<T> &obj)
{
 cout << "assignment " << endl;
 delete this->ptr;
 this->ptr = obj.ptr;
 this->reference = obj.reference; 
 this->reference++;
 return *this; 
}

template <class T>
smart<T>::smart(const smart<T> &obj)
{
 cout << "Copy Const" << endl;
 ptr = obj.ptr;
 this->reference = obj.reference;
 this->reference++;
}

class B
{
 public:
 B( int a, int b):a(a), b(b)
 { 
 }
 ~B()
 {
  cout <<  this->a << endl;
  cout << "B desc" << endl;
 }

 int a;
 int b;
};

int main()
{
 smart<B> sptr(new B(1,2));
 smart<B> ptr2 = sptr;
 //smart<B> *ptr3 = ptr2;
 //B *obj2 =  new B(2,3);
 //sptr = new B(2,3);
 //sptr = obj2;
 //*sptr = 100;
 cout << sptr->a << endl;
 return 0;
}
