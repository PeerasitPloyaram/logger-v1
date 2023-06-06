#include <string>
#include <cstdio>
#include <iostream>

std::string getCurrentTime(std::string s){
    time_t time_now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&time_now);

    if(s == "now")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if(s == "date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return  std::string(buf);
}

void logger(std::string s){
    
}
