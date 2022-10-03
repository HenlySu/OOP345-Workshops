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
      T obj[CAPACITY]{};
      unsigned int numOfObj{};
      static T emptyObj;
   public:
      //Constructor
      Queue();

      virtual bool push(const T& item);
      T pop();
      int size() const;
      std::ostream& display(std::ostream& os = std::cout);
      T operator [] (unsigned int index);

      //Destructor
      virtual ~Queue();
   };

   //Initializing Static Variable
   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::emptyObj = T{};

   //Specialization
   template <> 
   inline Dictionary Queue<Dictionary, 100u>::emptyObj = Dictionary{ "Empty substitute", "Empty Term" };

   //Constructor
   template <typename T, unsigned int CAPACITY>
   Queue<T, CAPACITY>::Queue() {
      numOfObj = 0;
   }

   template <typename T, unsigned int CAPACITY>
   bool Queue<T, CAPACITY>::push(const T& item) {
      if (numOfObj < CAPACITY) {
         obj[numOfObj] = item;
         numOfObj++;
      }
      return (numOfObj < CAPACITY) ? true : false;
   }

   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::pop() {
      T temp = obj[0];

      for (unsigned int i = 0; i < numOfObj - 1; i++) {
         obj[i] = obj[i + 1];
      }

      numOfObj--;

      return temp;
   }

   template <typename T, unsigned int CAPACITY>
   int Queue<T, CAPACITY>::size() const {
      return numOfObj;
   }

   template <typename T, unsigned int CAPACITY>
   std::ostream& Queue<T, CAPACITY>::display(std::ostream& os) {

      os << "----------------------\n"
         "| Dictionary Content |\n"
         "----------------------\n";

      for (unsigned int i = 0; i < numOfObj; i++) {
         os << obj[i] << std::endl;
      }
      os << "----------------------\n";
      return os;
   }

   template <typename T, unsigned int CAPACITY>
   T Queue<T, CAPACITY>::operator [] (unsigned int index) {
      T temp{};
      if (index < numOfObj) {
         temp = obj[index];
      }
      return temp;
   }

   template <typename T, unsigned int CAPACITY>
   Queue<T, CAPACITY>::~Queue(){}
}
#endif // !SDDS_QUEUE_H