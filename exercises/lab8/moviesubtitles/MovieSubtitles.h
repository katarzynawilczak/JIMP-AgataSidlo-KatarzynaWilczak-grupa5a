#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <ostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;
namespace moviesubs {

    class MovieSubtitles{
    public:
        virtual void  ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *outt)=0;

    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void  ShiftAllSubtitlesBy(int delay, int fps, stringstream *in, stringstream *out);

    };
    class SubRipSubtitles : public MovieSubtitles{
    public:
        void  ShiftAllSubtitlesBy(int delay, int fps,stringstream *in, stringstream *out);
    };


    class NegativeFrameAfterShift : public runtime_error{
    public:
        NegativeFrameAfterShift() : runtime_error("NegativeFrameAfterShift"){}
    };

    class SubtitleEndBeforeStart : public runtime_error{
    public:
        SubtitleEndBeforeStart(int line, std::string error_str): runtime_error("At line " + std::to_string(line) + ": " + error_str),line_{line}{}
        int LineAt() const{
            return line_;
        }
    private:
        int line_;
    };

    class InvalidSubtitleLineFormat : public runtime_error{
    public:
        InvalidSubtitleLineFormat() : runtime_error("InvalidSubtitleLineFormat"){}
    };

    class OutOfOrderFrames : public runtime_error{
    public:
        OutOfOrderFrames() : runtime_error("OutOfOrderFrames"){}
    };

    class MissingTimeSpecification : public runtime_error{
    public:
        MissingTimeSpecification() : runtime_error("MissingTimeSpecification"){}
    };

}
#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
