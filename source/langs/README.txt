to implement a new language you need:
- copy the file "lang_it.h", rename it with an ending as desired (usually the abbreviation of your language for example "Italian" with "it")
- translate the content (leaving the name of the variables unchanged)
- change the include in the lang.c file to <<#include" lang_it.h" >>(or other language) in your <<#include "lang_XX.h">>