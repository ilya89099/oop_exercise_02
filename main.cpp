#include <iostream>
#include "bottle.h"
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include <limits>

int main() {
    std::vector<Bottle> bottles;
     std::string command;

    // я не знаю, как тут продемонстрировать пользовательский литерал, пусть будет что то такое
    Bottle literal_constructed = (22.5_bottle).SetPercent(0.56);
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
        } else if (command == "edit") {
            int pos;
            double new_percent;
            std::cin >> pos >> new_percent;
            if (pos <= 0 || pos > bottles.size() || new_percent < 0 || new_percent > 1) {
                std::cout << "Incorrect parameters\n";
                continue;
            }

            pos--;

            bottles[pos].SetPercent(new_percent);
            std::cout   << "Bottle number " << pos + 1 << "\n"
                        << "Bottle size: " << bottles[pos].GetVolume() << "\n"
                        << "Bottle fill percent: " << bottles[pos].GetFillPercent() << "\n";
        } else if (command == "exit") {
            break;
        } else {
            std::cin.ignore(32767,'\n');
            std::cout << "Unknown command\n";
        }
    }
    return 0;
}