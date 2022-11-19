/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList() {}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }


		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's

		bool validation_Luhn_ALgorithm(const std::string& str) {

			bool valid = false;
			size_t total = 0;

			for (size_t i = 0; i < str.length(); i++) {

				size_t num = str[i] - '0';
				
				if (i % 2 != 0) {
					num *= 2;

					if (num > 9) {
						num -= 9;
					}
				}

				total += num;

				if ((total % 10) == 0) valid = true;
			}
			return valid;
		}
		//=================================================



		//TODO: Overload the += operator with a raw pointer
		// as a second operand.

		void operator += (T* obj) {
			list.push_back(*obj);
		}

		//=================================================


		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H