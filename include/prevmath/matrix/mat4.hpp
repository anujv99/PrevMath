#pragma once

#include "../vector/vec4.hpp"
#include "../common.hpp"

namespace prevmath {

	struct Mat4 {
		Vec4 x, y, z, w;

		Mat4();
		Mat4(Vec4 _x, Vec4 _y, Vec4 _z, Vec4 _w);
		Mat4(const Mat4 & _mat);
		Mat4(pvfloat _data[16]);

		pvfloat * GetFloatPtr() { return &x[0]; }
		const pvfloat * GetFloatPtr() const { return &x[0]; }

		/*
		 * Operators
		 */

		Vec4 & operator[](pvint i) { PREV_MATH_ASSERT(i < 4); return (&x)[i]; }
		const Vec4 & operator[](pvint i) const { PREV_MATH_ASSERT(i < 4); return (&x)[i]; }

		Vec4 operator*(const Vec4 _vec) const;
		Mat4 operator*(const Mat4 & _mat) const;
		Mat4 operator*(const pvfloat _val) const;

		Mat4 operator+(const Mat4 & _mat) const;
		Mat4 operator-(const Mat4 & _mat) const;

		void operator*=(const Mat4 & _mat);
		void operator*=(const pvfloat _val);

		void operator+=(const Mat4 & _mat);
		void operator-=(const Mat4 & _mat);

		static Mat4 Transpose(const Mat4 & _mat);
		static Mat4 Ortho(const float _left, const float _right, const float _bottom, const float _top, const float _near, const float _far);
	};

	#include "mat4.inl"

}