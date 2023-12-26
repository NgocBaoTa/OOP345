// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 29/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
using namespace std;

namespace sdds {
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations)
	{
		std::ifstream f(file);
		if (!f) {
			throw "ERROR: Unable to open file";
		}

		Utilities utils;
		std::string record;
		size_t next_pos = 0;
		size_t next_copy = next_pos;
		bool more = true;

		std::vector<std::string> currentStations;
		std::vector<std::string> nextStations;

		while (std::getline(f, record)) {
			next_pos = next_copy;
			std::string tempCurrent, tempNext;
			tempCurrent = utils.extractToken(record, next_pos, more);

			if (!(next_pos == next_copy)) {
				tempNext = utils.extractToken(record, next_pos, more);
				currentStations.push_back(tempCurrent);
				nextStations.push_back(tempNext);
			}

			auto currStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
				return station->getItemName() == tempCurrent;
				});

			m_activeLine.push_back(*currStation);

			if (tempNext.length() > 0) {
				auto nextStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
					return station->getItemName() == tempNext;
					});
				(*currStation)->setNextStation(*nextStation);
			}
		}

		size_t count;
		std::string st;
		for (const auto& current : currentStations) {
			count = 0;
			for (const auto& next : nextStations) {
				if (current == next) {
					count++;
				}
			}
			if (count == 0) {
				st = current;
				break;
			}
		}

		auto firstStation = std::find_if(stations.begin(), stations.end(), [&](Workstation* station) {
			return station->getItemName() == st;
			});
		m_firstStation = *firstStation;
		m_cntCustomerOrder = g_pending.size();
	}

	void LineManager::reorderStations()
	{
		std::vector<Workstation*> reorderedLine;
		Workstation* currentStation = m_firstStation;

		while (currentStation)
		{
			reorderedLine.push_back(currentStation);
			currentStation = currentStation->getNextStation();
		}

		m_activeLine = reorderedLine;
	}



	bool LineManager::run(std::ostream& os)
	{
		static size_t iterationCount = 1;

		os << "Line Manager Iteration: " << iterationCount << "\n";

		if (!g_pending.empty())
		{
			m_firstStation->operator+=(std::move(g_pending.front()));
			g_pending.pop_front();
		}

		for (auto station : m_activeLine)
		{
			station->fill(os);
		}

		for (auto station : m_activeLine)
		{
			station->attemptToMoveOrder();
		}

		bool allOrdersFilledOrIncomplete = g_completed.size() + g_incomplete.size() == m_cntCustomerOrder;
		iterationCount++;

		return allOrdersFilledOrIncomplete;
	}

	void LineManager::display(std::ostream& os) const
	{
		for (const auto& station : m_activeLine)
		{
			station->display(os);
		}
	}

}








