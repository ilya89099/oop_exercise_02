#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include <limits>

#include "bottle.h"

int main() {
    std::vector<Bottle> bottles;
     std::string command;

    // я не знаю, как тут продемонстрировать пользовательский литерал, пусть будет что то такое
    Bottle literal_constructed = "22.5,0.56"_bottle;
    assert(std::abs(literal_constructed.GetVolume() - 22.5) <  std::numeric_limits<double>::epsilon());
    assert(std::abs(literal_constructed.GetFillPercent() - 0.56) < std::numeric_limits<double>::epsilon());

    while (std::cin >> command) {
        if (command == "create") {
            double size, percent;
            std::cin >> size >> percent;
            if (size < 0 || percent < 0 || percent > 1) {
                std::cout << "Incorrect parameters\n";
                continue;
            }
            bottles.emplace_back(size, percent);
            std::cout   << "You created bottle number " << bottles.size() << "\n"
                        << "Bottle size: " << bottles.back().GetVolume() << "\n"
                        << "Bottle fill percent: " << bottles.back().GetFillPercent() << "\n";
        } else if (command == "compare") {
            std::string compare_string;
            int lhs, rhs;
            std::cin >> compare_string >> lhs >> rhs;

            if ( lhs <= 0 || lhs > bottles.size() || rhs <= 0 || rhs > bottles.size() || compare_string.size() != 1
                    || (compare_string[0] != '=' && compare_string[0] != '>' && compare_string[0] != '<')) {
                std::cout << "Incorrect parameters" << "\n";
                continue;
            }

            char compare = compare_string[0];

            std::cout << lhs << " " << rhs << " " << compare << " ";

            lhs--;
            rhs--;

            if (compare == '<') {
                std::cout << std::boolalpha << (bottles[lhs] < bottles[rhs]) << "\n";
            } else if (compare == '=') {
                std::cout << std::boolalpha << (bottles[lhs] == bottles[rhs]) << "\n";
            } else if (compare == '>') {
                std::cout << std::boolalpha << (bottles[lhs] > bottles[rhs]) << "\n";
            }
        } else if (command == "operation") {
            std::string operation_string;
            int lhs, rhs;
            std::cin >> operation_string >> lhs >> rhs;
            if ( lhs <= 0 || lhs > bottles.size() || rhs <= 0 || rhs > bottles.size() || operation_string.size() != 1
                    || (operation_string[0] != '-' && operation_string[0] != '+')) {
                std::cout << "Incorrect parameters" << "\n";
                continue;
            }

            char operation = operation_string[0];

            std::cout << lhs << " " << rhs << " " << operation << " ";

            rhs--;
            lhs--;

            if (operation == '+') {
                std::cout << bottles[lhs] + bottles[rhs] << "\n";
            } else if (operation == '-') {
                std::cout << bottles[lhs] - bottles[rhs] << "\n";
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cin.ignore(32767,'\n');
            std::cout << "Unknown command\n";
        }
    }
    return 0;
}