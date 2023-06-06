#include <string>
#include <cstdio>
#include <fstream>

std::string getCurrentTime(std::string s){
    time_t time_now = time(0);
    struct tm  tstruct;
    char  buf[80];
    tstruct = *localtime(&time_now);

    if(s == "all")
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
    else if(s == "date")
        strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    else if (s == "year"){
        strftime(buf,sizeof(buf), "%Y", &tstruct);
    }
    else if (s == "month")
        strftime(buf,sizeof(buf), "%m", &tstruct);
    
    return  std::string(buf);
}

inline void Logger(std::string logMsg){
    std::string filePath = "./log_"+getCurrentTime("date")+".txt";
    std::string now = getCurrentTime("all");
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << " ❯ " <<logMsg << '\n';
    ofs.close();
}

inline void endLogger(){
    std::string filePath = "./log_"+getCurrentTime("date")+".txt";
    std::string now = getCurrentTime("all");
    std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app );
    ofs << now << " ❯ " << "End log ..." << '\n';
    ofs.close();
}
