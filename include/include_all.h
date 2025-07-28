#pragma once
// "vld.h" must be included first, in any every other header file (except for stdafx.h). F5 (debug mode) to analise memory leaks.
//#include "vld.h" // included in VS2010 instalation include folder (as long as with vld.lib in lib folder)
#include <windows.h> // SetConsoleTitle()
#include <iostream>  // cout, getchar()
#include <conio.h>   // getche()
#include <cstring>   // memset()
#include <cstdlib>   // random()
#include <ctime>     // time()
#include <iterator>
#include <algorithm>  // std::sort
#include <functional>
#include <vector>
#include <sstream>
#include <string>
#include <new>

#include <stdlib.h>
#include <locale.h>  // setlocale(LC_ALL, "Portuguese"); 
#include <math.h>    // pow(), sqrt()
#include <stdio.h>   // printf
#include <assert.h>  // assert(bool);
#include <stdarg.h>  // va_list, va_start, va_arg, va_end 

#include "utils.h"   // chronometer/ sorting/ console/ tokenizer, etc