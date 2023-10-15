#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <stdio.h>
#include <cstring>

using namespace std;

int main() {
    std::string input_file_name = "/home/svemula/traceFiles/0.85/workloada/runKeys.txt";
    std::string output_file_name = "/home/svemula/traceFiles/0.85/workloada/proxy_benchmark_command_line_input.txt";
    std::ifstream input_file(input_file_name);
    std::ofstream output_file(output_file_name, std::ios::out);

    if (input_file.is_open() && output_file.good()) {
        std::string line;
        while (std::getline(input_file, line)) {
            std::istringstream iss(line);
    	    std::string type;
    	    std::string value = "";
            std::string key;
            while(1) {
                iss >> type;
                //cout << "Type is " << type << endl;
                if(strcmp(type.c_str(),"\"HMSET\"") == 0) {
                    iss >> key;
                    key.pop_back();
                    key.erase(0, 1);
                    value = "test_value";
                    output_file << "SET " << key << " " << value << "\n";
                    break;
                } else if(strcmp(type.c_str(),"\"HGETALL\"") == 0) {
                    iss >> key;
                    key.pop_back();
                    key.erase(0, 1);
                    output_file << "GET " << key << "\n";
                    break;
                }
            }

        }
        input_file.close();
        output_file.close();
        std::cout << "File copy successful!" << std::endl;
    } else {
        std::cout << "Failed to open files!" << std::endl;
    }

    return 0;
}
