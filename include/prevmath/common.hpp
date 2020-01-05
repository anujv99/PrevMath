#pragma once

#include <limits>
#include <memory>

#include <cmath>
#include <cfloat>
#include <cassert>
#include <algorithm>

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

#if !defined(PREV_MATH_DEGREES) && !defined(PREV_MATH_RADIANS)
	#define PREV_MATH_DEGREES
#endif

namespace prevmath {

	typedef float pvfloat;
	typedef int pvint;

	constexpr pvfloat PV_PI		= 3.1415926535897932384626433832795f;
	constexpr pvfloat PV_PI_180 = 0.0174532925199432957692369076848f;
	constexpr pvfloat PV_180_PI = 57.295779513082320876798154814105f;

	template<typename T, typename P>
	pvfloat Pow(const T & _val, const P & _power);

	template<typename T>
	pvfloat Sqrt(const T & _val);

	template<typename T>
	T Max(const T & _val1, const T & _val2);

	template<typename T>
	T Min(const T & _val1, const T & _val2);

	template<typename T>
	T Abs(const T & _val);

	template<typename T>
	pvfloat Lerp(const T & _val1, const T & _val2, const pvfloat & _factor);

	template<typename T>
	T Clamp(const T & _val, const T & _min, const T & _max);

	template<typename T>
	pvfloat ToDegrees(const T & _val);

	template<typename T>
	pvfloat ToRadians(const T & _val);

	template<typename T>
	pvfloat Sin(const T & _val);

	template<typename T>
	pvfloat Cos(const T & _val);

	template<typename T>
	pvfloat Saturate(const T & _val);

	#include "common.inl"

}

#define ENABLE_VEC2_CHECK
#define ENABLE_VEC2I_CHECK
#define ENABLE_VEC3_CHECK
#define ENABLE_VEC4_CHECK