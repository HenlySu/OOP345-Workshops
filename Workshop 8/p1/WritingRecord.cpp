/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca
I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		for (size_t i = 0; i < emp.size(); i++) {
			for (size_t j = 0; j < sal.size(); j++) {

				if (emp[i].id == sal[j].id) {

					if (!activeEmp.validation_Luhn_ALgorithm(emp[i].id))
						throw std::string("Error!");

					EmployeeWage empWage(emp[i].name, sal[j].salary);
					empWage.rangeValidator();								

					activeEmp += &empWage;
				}
			}
		}

		return activeEmp;
	}
}