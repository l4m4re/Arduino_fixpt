#ifndef _LIBFIXMATH_CONF_H
#define _LIBFIXMATH_CONF_H

/* Compile time options

https://code.google.com/archive/p/libfixmath/wikis/CompilationOptions.wiki


The following options can be given to compiler to customize libfixmath for a
particular application. They are usually defined by giving e.g. the command
line switch -DFIXMATH_NO_ROUNDING to the compiler.

Accuracy

FIXMATH_NO_ROUNDING: Disable rounding. Results may round randomly up or down,
i.e. their accuracy is +-1. Runs slightly faster.  

FIXMATH_NO_OVERFLOW: Disable overflow detection and saturating arithmetic
support. Overflowing computations will give garbage results. Runs slightly
faster.  

Platform

FIXMATH_NO_64BIT: Disable use of uint64_t in the code. Meant for compilers that
do not have 64-bit support. Runs the same speed or slightly slower.

FIXMATH_OPTIMIZE_8BIT: Use variants of the functions that are suitable for
small 8- and 16-bit processors. Much faster on those processors, much slower on
32-bit processors.  FIXMATH_NO_CACHE: Do not use cache for exp etc. function
results. Uses less RAM, runs slightly slower.  

Algorithms

FIXMATH_SIN_LUT: This uses a look-up table generated by the fixsingen tool from
svn, it is faster on some devices but the lookup table takes up ~200KiB (205376
bytes) in memory and can be slower dependant on usage.

FIXMATH_FAST_SIN: This enables a faster but less accurate approximation of the
sin function, for code where accuracy isn't as important such as games logic
or graphics rendering then this is often a worthwhile tradeoff. The most
accurate version is accurate to ~2.1%. The fast implementation runs at 159%
the speed of the 'accurate' version with a slightly lower accuracy of ~2.3%.

*/

#if defined(__arm__) 

//#define FIXMATH_NO_64BIT
//#define FIXMATH_OPTIMIZE_8BIT
//#define FIXMATH_NO_CACHE
#define FIXMATH_NO_OVERFLOW
//#define FIXMATH_NO_ROUNDING
#define FIXMATH_FAST_SIN

#elif defined(__AVR__) 

// AVR Architecture is 8bit & limited in memory
//#define FIXMATH_NO_64BIT
#define FIXMATH_OPTIMIZE_8BIT
#define FIXMATH_NO_CACHE
#define FIXMATH_NO_OVERFLOW
//#define FIXMATH_NO_ROUNDING
#define FIXMATH_FAST_SIN

#else
#error Architecture or board not supported.
#endif

#endif
