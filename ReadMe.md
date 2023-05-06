Waffle

The command to run the proxy is:
./bin/proxy_server  -l /home/svemula/traceFiles/0.99/workloada/proxy_server_command_line_input.txt  -b 2500 -r 1000 -f 500 -d 330000 -c 2 -n 1 -o test

-o specifies the output directory for alpha and beta. Example: alpha values for all requests will be logged in ./data/alpha_test/1 file. If the -o option is not specified, the default directories will be alpha_log and beta_log.

The duration of how long the benchmark runs for (which impacts the number of requests sent in an experiment) can be tweaked in the waffleClient/benchmark/src/proxy_benchmark.cpp file (line 164, invoking run_benchmark function). 
