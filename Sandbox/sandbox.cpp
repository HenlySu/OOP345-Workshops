#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> v1 = { 1,2,3 };
   v1.push_back(9);
   
   for (int i = 0; i < v1.size(); i++) {
      cout << v1[i] << endl;
   }

   v1.pop_back();
   cout << "Popping from vector" << endl;
   for (int i = 0; i < v1.size(); i++) {
      cout << v1[i] << endl;
   }

   v1.capacity(); //Returns the capacity of the vector. It doubles in size when it reaches its limits
                  //
}