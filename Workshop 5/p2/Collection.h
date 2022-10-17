#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_

namespace sdds {
   template <typename T>
   class Collection {

      std::string collectionName{};
      T* collectionItems{};
      size_t collectionSize{};
      auto (*funcPtr)(const Collection<T>& collection, const T& item) -> void;

   public:
      Collection(const std::string& name) {
         collectionName = name;
         collectionItems = nullptr;
         collectionSize = 0;
         funcPtr = nullptr;
      }

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
         funcPtr = observer;
      }

      Collection<T>& operator += (const T& item) {

      }

      T& operator [] (size_t index) const {
                  
         if (index < 0 && index >= collectionSize) {
            throw std::out_of_range("Bad index[" + index + "]. Collection has [" + collectionSize + "] items.";
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

      template <typename T>
      friend std::ostream& operator << (std::ostream& os, Collection& col) {
         for (size_t i = 0; i < col.size(); i++) {
            os << col[i];
         }
         return os;
      }
   };
}
#endif // !_COLLECTION_H_
