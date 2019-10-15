#pragma once

#include <prevmath/common.hpp>

namespace prevmath {

	template<typename T, size_t N>
	struct Vector {
	protected:
		T _raw_vector[N];
	public:
		Vector();
		Vector(T * _elements);
		Vector(const Vector & _vec) = delete;

		T & operator[](size_t _index) { PREV_MATH_ASSERT(_index < N); return _raw_vector[_index]; }
		const T & operator[](size_t _index) const { PREV_MATH_ASSERT(_index < N); return _raw_vector[_index]; }
	};

	#include "vector.inl"

}