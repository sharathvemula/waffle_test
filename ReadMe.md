# Waffle - Security Analysis branch

Please follow the same instructions as the main thread to compile the security_analysis branch. The following are the changes made in this branch. Note: this branch runs only on single core -- so n=1.

## Running

The command to run the proxy is:
```
./bin/proxy_server  -l <path-to-trace-file>  -b <b-val> -r <r-val> -f <f-val> -d <d-val> -c <c-val> -n 1 -o <director-path-for-output>
```

-o specifies the output directory where alpha and beta values will be logged. 
Example: if -o is named 'text', then alpha values for all requests will be logged in ./data/alpha_test/1 file
and beta values in ./data/beta_test/1 file. 

If the -o option is not specified, the default directories will be alpha_log and beta_log.

The duration of how long the benchmark runs for (which impacts the number of requests sent in an experiment) can be tweaked in the waffleClient/benchmark/src/proxy_benchmark.cpp file (line 164, invoking run_benchmark function). 

## Correlated queries experiment data

For correlated query experiment that uses iHop's trace, the trace files and the input file can be found in tracefiles/corr-queries directory.
