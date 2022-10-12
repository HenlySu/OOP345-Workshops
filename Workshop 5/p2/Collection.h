#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_

namespace sdds {
   template <typename T>
   class Collection {
      std::string collectionName{};
      T* collectionItems{};
      size_t collectionSize{};

      void (*funcPtr)(const Collection<T>&, const T&);
   public:
      Collection(const std::string& name) {

      }

      ~Collection() {

      }

      const std::string& name() const{
         return collectionName;
      }

      size_t size() const {
         return collectionSize;
      }

      void setObserver(void (*observer)(const Collection<T>& collection, const T& item)) {

      }

      Collection<T>& operator += (const T& item) {

      }

      T& operator [] (size_t index) const {

      }

      T* operator [](const std::string& title) const {

      }

      friend std::ostream& operator << (std::ostream& os, Collection& col) {

      }
   };
}
#endif // !_COLLECTION_H_
