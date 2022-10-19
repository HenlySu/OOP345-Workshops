#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_

#include <sstream>

namespace sdds {
   template <typename T>
   class Collection {

      std::string collectionName{};
      T* collectionItems{};
      size_t collectionSize{};
      auto (*observerFuncPtr)(const Collection<T>& collection, const T& item) -> void;

   public:
      Collection(const std::string& name) : collectionName(name) {
         collectionItems = nullptr;
         collectionSize = 0;
         observerFuncPtr = nullptr;
      }

      //Deleting Copy Constructor and Copy Assignment
      Collection (const Collection& obj) = delete;
      Collection& operator = (const Collection& obj) = delete;

      ~Collection() {
         delete[] collectionItems;
         collectionItems = nullptr;
      }

      const std::string& name() const{
         return collectionName;
      }

      size_t size() const {
         return collectionSize;
      }

      void setObserver(void (*observer)(const Collection<T>& collection, const T& item)) {
         observerFuncPtr = observer;
      }

      Collection<T>& operator += (const T& item) {
         bool inArray = false;

         for (size_t i = 0; i < collectionSize; i++) {
            if (collectionItems[i].title() == item.title()) {
               inArray = true;
            }
         }

         if (!inArray) {
            T* temp = new T[collectionSize + 1];

            for (size_t i = 0; i < collectionSize; i++) {
               temp[i] = collectionItems[i];
            }

            temp[collectionSize] = item;

            delete[] collectionItems;
            collectionItems = nullptr;
            collectionItems = temp;

            collectionSize++;

            if (observerFuncPtr != nullptr) {
               observerFuncPtr(*this, item);
            }
         }
         return *this;
      }

      T& operator [] (size_t index) const {
         if (index < 0 || index >= collectionSize) {
            throw std::out_of_range("Bad index [" + std::to_string(index) + "]. Collection has [" + std::to_string(collectionSize) + "] items.");
         }
         return collectionItems[index];
      }

      T* operator [](const std::string& title) const {

         T* item = nullptr;

         for (size_t i = 0; i < collectionSize; i++) {
            if (collectionItems[i].title() == title) {
               item = &collectionItems[i];
            }
         }
         return item;
      }

      friend std::ostream& operator << (std::ostream& os, Collection& col) {
         for (size_t i = 0; i < col.size(); i++) {
            os << col[i];
         }
         return os;
      }
   };
}
#endif // !_COLLECTION_H_
