#include <stdexcept>
#include <iostream>
#include <fstream>
#include<memory>
#include <sstream>
#include<regex>

#include "MovieSubtitles.h"

namespace moviesubs {

    int stringToint(string str1) {
        int i;
        std::istringstream iss(str1);
        iss >> i;
        return i;
    }

    string turnIntToString(int value) {
        string result;
        if (value < 10) {
            stringstream ss;
            ss << value;
            string str = ss.str();
            result = "0" + str;
        } else {
            stringstream ss;
            ss << value;
            string str = ss.str();
            result = str;
        }
        return result;
    }

    string turnMilisecToString(int value) {
        string result;
        if (value < 10) {
            stringstream ss;
            ss << value;
            string str = ss.str();
            result = "00" + str;
        } else if (value < 100) {
            stringstream ss;
            ss << value;
            string str = ss.str();
            result = "0" + str;
        } else {
            stringstream ss;
            ss << value;
            string str = ss.str();
            result = str;
        }
        return result;
    }


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {

        if (fps<0){
            throw std::invalid_argument("NegativeFrameRate");
        }

        double change = (double) delay / 1000 * fps;
        int changeToInt = (int) change;

        int lineNumber=0;
        std::string line;
        while (std::getline(*in, line)) {
            std::istringstream iss(line);
            lineNumber++;
            regex pattern{R"(\{(\d+)\}\{(\d+)\}(.*))"};

            smatch matches;
            if (regex_match(line, matches, pattern)) {

                if(stringToint(matches[1])>stringToint(matches[2])){
                    std::string error_str = "{" + matches[1].str() + "}{" + matches[2].str() + "}" + matches[3].str();
                    throw SubtitleEndBeforeStart(lineNumber, error_str);
                }

                int NewStart = stringToint(matches[1]) + changeToInt;
                int NewEnd = stringToint(matches[2]) + changeToInt;

                if(NewStart<0 || NewEnd<0){
                    throw NegativeFrameAfterShift();
                }

                *out << "{" << NewStart << "}{" << NewEnd << "}" << matches[3] << endl;
            }
            else{
                throw InvalidSubtitleLineFormat();
            }
        }
    }

    void SubRipSubtitles::ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out) {
        int lineNumber = 0;
        int lineNumberToCheck = 0;
        std::string line;

        if(fps<0){
            throw std::invalid_argument("NegativeFrameRate");
        }

        while (std::getline(*in, line)) {
            std::istringstream iss(line);

            lineNumberToCheck++;
            if (stringToint(line) != lineNumberToCheck) {
                throw OutOfOrderFrames();
            }

            std::getline(*in, line);
            regex pattern{R"((\d{2}):(\d{2}):(\d{2}),(\d{1,3})\s-->\s(\d{2}):(\d{2}):(\d{2}),(\d{1,3}))"};
            smatch matches;
            if (regex_match(line, matches, pattern)) {
                std::string text;
                lineNumber++;

                int HourStart= stringToint(matches[1])*3600000;
                int MinStart =stringToint(matches[2])*60000;
                int SecStart =stringToint(matches[3])*1000;
                int MiliSecStart =stringToint(matches[4]);
                int DelSumStart= HourStart + MinStart + SecStart + MiliSecStart + delay;

                int NewHourStart=DelSumStart/3600000;
                int NewMinStart =(DelSumStart-(NewHourStart*3600000))/60000;
                int NewSecStart = (DelSumStart-(NewHourStart*3600000)-(NewMinStart*60000))/1000;
                int NewMiliSecStart = DelSumStart-(NewHourStart*3600000)-(NewMinStart*60000)-NewSecStart*1000;

                int HourEnd= stringToint(matches[5])*3600000;
                int MinEnd =stringToint(matches[6])*60000;
                int SecEnd =stringToint(matches[7])*1000;
                int MiliSecEnd =stringToint(matches[8]);
                int DelSumEnd= HourEnd + MinEnd + SecEnd + MiliSecEnd + delay;

                int NewHourEnd=DelSumEnd/3600000;
                int NewMinEnd =(DelSumEnd-(NewHourEnd*3600000))/60000;
                int NewSecEnd = (DelSumEnd-(NewHourEnd*3600000)-(NewMinEnd*60000))/1000;
                int NewMiliSecEnd = DelSumEnd-(NewHourEnd*3600000)-(NewMinEnd*60000)-NewSecEnd*1000;


                if(DelSumStart <0 || DelSumEnd < 0){
                    throw NegativeFrameAfterShift();
                }
                if(DelSumStart>DelSumEnd){
                    std::string error_str = matches[1].str() +":" + matches[2].str()+ ":" + matches[3].str()+"," + matches[4].str()+ " --> " + matches[5].str()+ ":" + matches[6].str()+ ":" +matches[7].str()+ "," + matches[8].str();
                    throw SubtitleEndBeforeStart(lineNumber, error_str);
                }

                *out << lineNumber << "\n" << turnIntToString(NewHourStart) << ":" << turnIntToString(NewMinStart) << ":"
                     << turnIntToString(NewSecStart) << "," << turnMilisecToString(NewMiliSecStart) << " --> "
                     << turnIntToString(NewHourEnd) << ":" << turnIntToString(NewMinEnd) << ":"
                     << turnIntToString(NewSecEnd) << "," << turnMilisecToString(NewMiliSecEnd) << '\n';

              std::getline(*in, text);
                *out << text;
                if (!in->eof()) {
                    *out << "\n";

                }
                while (text != "") {
                    getline(*in, text);
                    *out << text;
                    if (!in->eof()) {
                        *out << "\n";
                    }
                }

            }
           else{
                throw InvalidSubtitleLineFormat();
            }
        }
    }

}