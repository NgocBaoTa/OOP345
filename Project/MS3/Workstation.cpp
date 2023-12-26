// Name: Bao Ngoc Ta
// Seneca Student ID: 116038225
// Seneca email: bta@myseneca.ca
// Date of completion: 29/11/2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "Workstation.h"
using namespace std;

namespace sdds {
    std::deque<CustomerOrder> g_pending;
    std::deque<CustomerOrder> g_completed;
    std::deque<CustomerOrder> g_incomplete;

    void Workstation::fill(std::ostream& os)
    {
        if (!m_orders.empty())
        {
            m_orders.front().fillItem(*this, os);
        }
    }


    bool Workstation::attemptToMoveOrder() {
        bool moved{};
        if (!m_orders.empty()) {
            if (getQuantity() == 0 || m_orders.front().isItemFilled(getItemName())) {
                if (!m_pNextStation) {
                    if (m_orders.front().isOrderFilled()) {
                        g_completed.push_back(std::move(m_orders.front()));
                    }
                    else {
                        g_incomplete.push_back(std::move(m_orders.front()));
                    }
                }
                else {
                    *m_pNextStation += std::move(m_orders.front());
                }
                m_orders.pop();
                moved = true;
            }
        }
        return moved;
    }


    void Workstation::setNextStation(Workstation* station)
    {
        m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const
    {
        return m_pNextStation;
    }

    void Workstation::display(std::ostream& os) const
    {
        os << getItemName() << " --> ";
        if (m_pNextStation)                          
        {
            os << m_pNextStation->getItemName();
        }
        else
        {
            os << "End of Line";
        }
        os << "\n";
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
    {
        m_orders.push(std::move(newOrder));
        return *this;
    }
}
