#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string input_file_name = "/home/svemula/traceFiles/0.99/workloada/proxyServerTraceFile.txt";
    std::string output_file_name = "/home/svemula/traceFiles/0.99/workloada/proxy_server_command_line_input.txt";
    std::ifstream input_file(input_file_name);
    std::ofstream output_file(output_file_name, std::ios::out);

    if (input_file.is_open() && output_file.good()) {
        std::string line;
        while (std::getline(input_file, line)) {
            output_file << "SET " << line << " test" << "\n";
        }
        input_file.close();
        output_file.close();
        std::cout << "File copy successful!" << std::endl;
    } else {
        std::cout << "Failed to open files!" << std::endl;
    }

    return 0;
}
