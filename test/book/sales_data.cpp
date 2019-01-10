#include "sales_data.h"
#include <iostream>
using namespace std;

Sales_data::Sales_data(std::istream& is) {
     read(is, *this);
}

Sales_data& Sales_data:: combine(const Sales_data& rhs){
    units_sold +=rhs.units_sold;
    revenue+=rhs.units_sold;
    return *this;
}

double Sales_data:: avg_price()const{
    if (units_sold)
        return revenue / units_sold;
    else 
        return 0;
}

istream &read(istream &is, Sales_data & item) {
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;

}

ostream &print(ostream& os, const Sales_data& item ) {
    os << "ISBN: "<<item.isbn() << "\nSold: " << item.units_sold << "\nRevenue: " 
       << item.revenue << "\nAvg Price: " << item.avg_price() << endl;
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}