#include <iostream>
#include <vector>

using namespace std;

void shift(vector<int> &vec, int item, int idx)
{
 for(int i = idx+1; i < vec.size(); i++)
 {
  int temp = vec[i];
  vec[i] = item;
  item = temp;
 }
}

int main()
{
 vector<int> arr1 = {5,8,9,20,22,23};
 vector<int> arr2 = {1,2,15,16,25,35};

 int j = arr1.size() - 1 ;
 for(int i = arr2.size() -1 ;i >= 0 ;i--)
 {

      if(arr1[j] >= arr2[i])
      {
       int temp = arr2[i];
       arr2[i] = arr1[j];
       //arr1[j] = temp;
       int k;
       for(k = j; k  >= 0 ;k--)
       {
        if(temp >= arr1[k])
        {
         break;
        }
       }
       shift(arr1,temp, k);
      }
 }
 for(int i = 0; i < arr1.size() ; i++)
  cout << arr1[i] << " " ;
 
 cout << endl;
 for(int i = 0; i < arr2.size() ; i++)
  cout << arr2[i] << " " ;
 return 0;
}
