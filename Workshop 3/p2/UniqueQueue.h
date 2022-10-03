#pragma once 
#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
   template <typename T>
   class UniqueQueue : public sdds::Queue<T, 100u> {
   public:
      bool push(const T& item) override{
         
      }
   };

   //Specialization
   template <>
   bool UniqueQueue<double>::push(const double& num) {
      
   }

}
#endif // !SDDS_UNIQUEQUEUE_H
