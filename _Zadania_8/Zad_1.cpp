#include "iostream"
#include "fstream"
#include"string"
#include "cctype"

int main(void) 
{
    int sum = 0;
    std::ifstream infile("input.txt");
    std::string line;
    while (infile >> line){
        int first = -1;
        int firstindex = 9999;
        int last = -1;
        int lastindex = -1;
        
        for (int i = 0; i < line.length(); ++i) {
            if(isdigit(line[i])){
                last = line[i] - '0';
                lastindex = i;
                if(first == -1){
                    first = (int)line[i] - '0';
                    firstindex = i;
                }
            }
        }
        std::string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i){
            size_t found = line.find(nums[i]);
            if (found != std::string::npos) {
                if (found < firstindex) {
                    first = i;
                    firstindex = found;
                }
                if (found > lastindex) {
                    last = i;
                    lastindex = found;
                }
            }
        }
        if (lastindex == 9999)
            last = first;
        std::string concatenated = std::to_string(first) + std::to_string(last);
        int result = std::stoi(concatenated);
        sum+=result;
        //printf("\n%d", result);
    }
    printf("\n%d\n", sum);
    return 0;
}