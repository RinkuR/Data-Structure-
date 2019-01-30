#include <iostream>
using namespace std;

int find( int A[], int size, int k)
{
 int si = 0;
 int ei = size - 1;
 int mid;
 while( si <= ei)
 {
  int mid = (si+ei)/2;
  if( A[mid] ==  k)
  {
   return mid;
  }
  if( A[si] <= A[mid] ) // left side is sorted
  {
   if( k <= A[mid] && k >= A[si])
   {
    ei = mid - 1; 
   }
   else
   {
    si = mid + 1;
   }
  }
  else // right side is sorted
  {
   if( k >= A[mid] && k <= A[ei])
   {
    si = mid + 1;
   }
   else
   {
    ei = mid - 1;
   }
  }
  
 }
 return -1;
}

int main()
{
 int A[10] = {7,8,9,10,11,12,22,3,4,5};
 int size = 10;
 int k;
 cin >> k;
 if( (k = find(A, size, k)) == -1)
  cout << "Not Found" << endl;
 else
  cout << k << " " << A[k] << endl;

}
