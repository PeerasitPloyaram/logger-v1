#include <iostream>
#include <string>
#include "../src/loggerv1.cpp"

using namespace std;

int main(){
    for (int i = 0; i < 200; i++){
        uint32_t total = (i + 1) * i;
        Logger(std::to_string(total));
    }
    endLogger();
    
    return 0;
}