/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#pragma once
#ifndef SDDS_QUEUE_H

namespace sdds {
  
   template <class T, int CAPACITY>
   class Queue {
      T type;
      
   public:
      bool push(const T& item);
      Queue pop();
      int size();
      std::ostream& display(std::ostream& os = std::cout);
      Queve operator [] (int index);
   };
}
#endif // !SDDS_QUEUE_H
