#include <vector>
#include <algorithm>
#include <iostream>
#include<array>

using namespace std;

int main()
{
   std::array<int, 10> a = { 1,1,1,1,2,2,2,3,3,4 };
   int m = count_if(a.begin(), a.end(), [](int val) {return val < 2; });

   cout << m;

   return 0;
}