#include<iostream>
#include<memory>
#include <stdexcept>
#include "MovieSubtitles.h"

using namespace std;
using namespace moviesubs;


int main() {

    auto subs =make_unique<MicroDvdSubtitles>();
    int delay=300;
    int fps=25;
    stringstream in {"{10}{250}TEXT\n{260}{300}NEWLINE\n"};
    stringstream out;
    subs->ShiftAllSubtitlesBy(delay, fps, &in, &out);
    cout<<out.str();

    return 0;
}
