#ifndef OAKFIRE_COMMON_H_
#define OAKFIRE_COMMON_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/un.h>
#include <string>
#include <sstream>
#include <queue>
#include <map>
#include <vector>

#include <iostream>
using namespace std;

#define NOW() ((int)::time(0))

#ifndef MAX_PATH
#define MAX_PATH 108
#endif

#define TRACE(fmt, args...) fprintf(stderr, "\e[0;1mLOG:\e[0m " fmt, ##args)

#endif
