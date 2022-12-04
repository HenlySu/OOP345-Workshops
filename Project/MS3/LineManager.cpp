/*
Name:			Henly Su
Student ID:	143334183
Email:		hsu31@myseneca.ca

I have done all the coding by myself and only copied the code that my professor
provided to complete the workshops and assignments.
*/

#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

#include "LineManager.h"

namespace sdds {
   LineManager::LineManager(const std::string& fileName, const std::vector<Workstation*>& stations) {
		
		std::ifstream file(fileName);
		std::string line{};

		while (std::getline(file, line)) {
			std::string currentStation = line.substr(0, line.find_first_of('|'));
			std::string nextStation = line.erase(0, currentStation.size() + 1);

			auto sortedStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* wStation) {
				return wStation->getItemName() == currentStation;
			});

			m_activeLine.push_back(*sortedStation);
	
			if (nextStation.empty()) {
				m_activeLine.back()->setNextStation(nullptr);
			}
			else {
				auto matchNextStation = [&](Workstation* wStation) {
					if (wStation->getItemName() == nextStation)
						m_activeLine.back()->setNextStation(wStation);
				};

				for_each(stations.begin(), stations.end(), matchNextStation);
			}
		}

		auto matchLastStation = [&](Workstation* wStation) {
			auto matchNextStation = std::find_if(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* wStationn) {
				return wStation == wStationn->getNextStation(); 
			});

			if (matchNextStation == m_activeLine.end()) {
				m_firstStation = wStation;
			}
		};

		for_each(m_activeLine.begin(), m_activeLine.end(), matchLastStation);
		m_cntCustomerOrder = g_pending.size();
		file.close();
   }

   void LineManager::reorderStations() {

		Workstation* station = m_firstStation;
		std::vector<Workstation*> updatedStations;

		while (station) {
			updatedStations.push_back(station);
			station = station->getNextStation();
		}
		m_activeLine = updatedStations;
   }

   bool LineManager::run(std::ostream& os) {
      static size_t counter = 0u;

      os << "Line Manager Iteration: " << ++counter << std::endl;

      if (!g_pending.empty()) {
         *m_firstStation += std::move(g_pending.front());
         g_pending.pop_front();
      }

		auto fillLambda = [&os](Workstation* ws) { ws->fill(os); };
      std::for_each(m_activeLine.begin(), m_activeLine.end(), fillLambda);

		auto moveLambda = [](Workstation* ws) { ws->attemptToMoveOrder(); };
      std::for_each(m_activeLine.begin(), m_activeLine.end(), moveLambda);

      return g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
   }

   void LineManager::display(std::ostream& os) const {
		auto displayActiveStations = [&](Workstation* workstation) {workstation->display(os); };
      std::for_each(m_activeLine.begin(), m_activeLine.end(), displayActiveStations);
   }
}