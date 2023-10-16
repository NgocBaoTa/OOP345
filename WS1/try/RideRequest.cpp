#include <iostream>
#include <iomanip>
#include <cstring>
#include "RideRequest.h"

// Initialize global variables for tax rate and discount
double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds
{

  

    // Default constructor
    RideRequest::RideRequest()
    {
        customer_name[0] = '\0';
        ride_description[0] = '\0';
        price = 0.0;
        discount = false;
    }

    // read() function
    void RideRequest::read(std::istream& in)
    {
        if (in.good())
        {
            char temp[100]; // temporary buffer
            in.getline(temp, 100, ',');
            std::strncpy(customer_name, temp, 10);
            customer_name[10] = '\0';

            in.getline(temp, 100, ',');
            std::strncpy(ride_description, temp, 25);
            ride_description[25] = '\0';

            in >> price;
            in.ignore(); // skip the comma

            char disc;
            in >> disc;
            discount = (disc == 'Y');
            in.ignore(); // skip the newline if present
        }
    }

    // display() function
    void RideRequest::display() const
    {
        static int counter = 0; // local-to-function variable
        counter++;

        std::cout << std::setw(2) << std::left << counter << ". ";
        if (customer_name[0] == '\0')
        {
            std::cout << "No Ride Request" << std::endl;
        }
        else
        {
            double price_with_tax = price * (1 + g_taxrate);
            std::cout << std::setw(10) << std::left << customer_name << '|'
                << std::setw(25) << std::left << ride_description << '|'
                << std::setw(12) << std::left << std::fixed << std::setprecision(2) << price_with_tax;
            if (discount)
            {
                double price_with_discount = price_with_tax * g_discount;
                std::cout << '|' << std::setw(13) << std::right << std::fixed << std::setprecision(2) << price_with_discount;
            }

            if (discount)
            {
                double price_with_discount = price_with_tax * g_discount;
                std::cout << '|' << std::setw(13) << std::right << std::fixed << std::setprecision(2) << price_with_discount;
            }
            std::cout << std::endl;
        }
    }

}
