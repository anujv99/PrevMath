#pragma once

#include <cassert>
#include <memory>
#include <type_traits>
#include <limits>
#include <cfloat>

#define PREV_MATH_ASSERT(E) assert(E)

/*
 * Version Check
 */

#if defined(_MSC_VER)
	#if  !defined(__cplusplus) || (_MSVC_LANG < 201703L)
		#error "Prev Math require C++17"
	#endif
#else
	#if !defined(__cplusplus) || (__cplusplus < 201703L)
		#error "Prev Math require C++17"
	#endif
#endif

#define ENABLE_VEC2_CHECK
