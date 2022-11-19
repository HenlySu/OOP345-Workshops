#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// TODO: Add your code here to build a list of employees
		//         using raw pointers

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id) {
					EmployeeWage ew(emp[i].name, sal[j].salary);
					ew.rangeValidator();
					if (!activeEmp.validation_Luhn_ALgorithm(emp[i].id))
						throw std::string("*** Wrong Salaries with SIN No's");
					EmployeeWage* p = &ew;
					activeEmp += p;
				}
			}
		}

		return activeEmp;
	}
}