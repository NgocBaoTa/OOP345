#pragma once
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>
// Global variables for tax rate and discount
extern double g_taxrate;
extern double g_discount;
namespace sdds
{

  

    class RideRequest
    {
    private:
        char customer_name[11];    // up to 10 characters
        char ride_description[26]; // up to 25 characters
        double price;              // price of the ride
        bool discount;             // flag for discount

    public:
        // Default constructor
        RideRequest();

        // Public member functions
        void read(std::istream& in); // read data from an istream reference
        void display() const;        // display the content of a RideRequest instance
    };

}

#endif // SDDS_RIDEREQUEST_H

//#pragma once
//#include <iostream>
//#ifndef SDDS_RIDEREQUEST_H
//#define SDDS_RIDEREQUEST_H
//#include <iostream>
//#include <iomanip>
//
//extern double g_taxrate;
//extern double g_discount;
//
//namespace sdds {
//    class RideRequest {
//        char m_name[10]{};
//        char m_ride[25]{};
//        double m_price;
//        bool m_isDiscounted;
//    public:
//        RideRequest();
//        ~RideRequest() {};
//
//        std::istream& read(std::istream& is);
//        void display() const;
//    };
//}
//
//#endif // !SDDS_RIDEREQUEST_H