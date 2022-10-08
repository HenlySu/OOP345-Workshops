/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once 
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
   template <typename T>
   class UniqueQueue : public sdds::Queue<T, 100u> {
   public:
      bool push(const T& item) override;
   };

   template <typename T>
   bool UniqueQueue<T>::push(const T& item){
      
      bool value = false;

      for (int i = 0; i < this->size(); i++) {
         if ((*this)[i] == item) {
            value = true;
         }
      }
      if (!value) value = Queue<T, 100u>::push(item);      
      return value;
   }

   //Specialization
   template <>
   bool UniqueQueue<double>::push(const double& num) {
      bool value = false;

      for (int i = 0; i < this->size(); i++) {
         if (std::abs((*this)[i] - num) <= 0.005) {
            value = true;
         }
      }
      if (!value) value = Queue<double, 100>::push(num);
      return value;
   }

}
#endif // !SDDS_UNIQUEQUEUE_H
