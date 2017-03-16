#include <vector>
#include <sstream>
#include <regex>
#include <cmath>

#include "MinimalTimeDifference.h"


unsigned int ToMinutes(std::string time_HH_MM){
    int hour,min;
    std::string str1, str2;

    std::regex pattern {R"((\d{1,2})\:+(\d{1,2}))"};
    std::string line {time_HH_MM};
    std::smatch matches;
    if (regex_match(line, matches, pattern)) {

        str1 = matches[1];
        int i;
        std::istringstream iss(str1);
        iss >> i;

        str2 = matches[2];
        int j;
        std::istringstream iss2(str2);
        iss2 >> j;


        hour=i*60;
        min=j;

    }
    return hour + min;



}

unsigned int MinimalTimeDifference(std::vector<std::string> times) {
    int min=20000,min2=0;
    times.reserve(20000);

    for (int n = 0; n < times.size() - 1; n++) {
        for (int m = n+1; m < times.size(); m++) {
            if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) > 720) {
                if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) > min2) {
                    min2 = abs(ToMinutes(times[n]) - ToMinutes(times[m]));
                }
            }
            else {
                if (abs(ToMinutes(times[n]) - ToMinutes(times[m])) < min) {
                    min = abs(ToMinutes(times[n]) - ToMinutes(times[m]));
                }
            }
        }
    }
    min2=1440-min2;
    if(min<min2)
        return min;
    else
        return min2;

}