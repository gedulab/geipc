# geipc
code to achive highest ipc (instructions per cyckle) by Raymond Zhang 

Result on YourLand code book (https://nanocode.cn/#/yl) with RK3588 SoC

geduer@ulan:~/projects/geipc$ perf stat taskset 0x10 ./geipc -p

 Performance counter stats for 'taskset 0x10 ./geipc -p':

          1,420.41 msec task-clock:u              #    0.998 CPUs utilized
                 0      context-switches:u        #    0.000 K/sec
                 0      cpu-migrations:u          #    0.000 K/sec
                82      page-faults:u             #    0.058 K/sec
     3,233,198,257      cycles:u                  #    2.276 GHz
    12,885,226,307      instructions:u            #    3.99  insn per cycle
   <not supported>      branches:u
             7,212      branch-misses:u

       1.423802735 seconds time elapsed

       1.418259000 seconds user
       0.003329000 seconds sys

Result on GDK7-60 (https://nanocode.cn/#/gdk7) with Intel i7-1165G7 @ 2.80GHz
gedu@gdbox:~/nanolabs/geipc$ sudo perf stat ./geipc -p

 Performance counter stats for './geipc -p':

         14,739.22 msec task-clock                       #    1.000 CPUs utilized
                56      context-switches                 #    3.799 /sec
                 0      cpu-migrations                   #    0.000 /sec
                51      page-faults                      #    3.460 /sec
    69,079,712,074      cycles                           #    4.687 GHz
   171,817,955,029      instructions                     #    2.49  insn per cycle
    34,362,830,387      branches                         #    2.331 G/sec
            12,156      branch-misses                    #    0.00% of all branches
   345,390,843,175      slots                            #   23.433 G/sec
   136,801,863,375      topdown-retiring                 #     39.6% Retiring
     2,708,947,789      topdown-bad-spec                 #      0.8% Bad Speculation
     5,417,895,579      topdown-fe-bound                 #      1.6% Frontend Bound
   200,583,618,914      topdown-be-bound                 #     58.1% Backend Bound

      14.740442675 seconds time elapsed

      14.739966000 seconds user
       0.000000000 seconds sys
