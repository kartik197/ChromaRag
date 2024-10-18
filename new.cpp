#include <iostream>
#include <string>
#include <bitset>
using namsepace std;
std::string dateToBinary(const std::string& date) {
    // Extract year, month, and day from the date string
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    // Convert each to binary using std::bitset and remove leading zeroes
    std::string year_bin = std::bitset<12>(year).to_string();
    std::string month_bin = std::bitset<4>(month).to_string();
    std::string day_bin = std::bitset<5>(day).to_string();

    // Remove leading zeros from the binary strings
    year_bin = year_bin.substr(year_bin.find('1'));
    month_bin = month_bin.substr(month_bin.find('1'));
    day_bin = day_bin.substr(day_bin.find('1'));

    // Concatenate the results with '-' as separator
    return year_bin + "-" + month_bin + "-" + day_bin;
}

int main() {
    // Test cases
    std::string date1;
    cin>>date1;

    std::cout << dateToBinary(date1) << std::endl;  // Output: "100000100000-10-11101"
    

    return 0;
}
