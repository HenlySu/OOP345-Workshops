/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"

namespace sdds {

   template <typename T, unsigned int CAPACITY>
   class Queue {
      T client[CAPACITY]{};
      int numOfObj{};
   public:
      Queue();
      bool push(const T& item);
      T pop();
      int size();
      std::ostream& display(std::ostream& os = std::cout);
      T operator [] (int index);
   };

   //Constructor
   template <typename T, unsigned int CAPACITY>
   Queue<T, CAPACITY>::Queue() {
      numOfObj = 0;
   }

   template <typename T, unsigned int CAPACITY>
   bool Queue<T, CAPACITY>::push(const T& item) {
      if (numOfObj < CAPACITY) {
         client[numOfObj] = item;
         numOfObj++;
      }
      return (numOfObj < CAPACITY) ? true : false;
   }

   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::pop() {
      T temp{};
      temp = client[0];

      for (int i = 0; i < numOfObj - 1; i++) {
         client[i] = client[i + 1];
      }
      numOfObj--;
      return temp;
   }

   template <typename T, unsigned int CAPACITY>
   int Queue<T, CAPACITY>::size() {
      return numOfObj;
   }

   template <typename T, unsigned int CAPACITY>
   std::ostream& Queue<T, CAPACITY>::display(std::ostream& os) {

      os << "----------------------\n"
         "| Dictionary Content |\n"
         "----------------------\n";

      for (int i = 0; i < numOfObj; i++) {
         os << client[i] << std::endl;
      }
      os << "----------------------\n";
      return os;
   }

   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::operator [] (int index) {
      T temp{};
      if (index < numOfObj) {
         temp = client[index];
      }
      return temp;
   }
}
#endif // !SDDS_QUEUE_H
