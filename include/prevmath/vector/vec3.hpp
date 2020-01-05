#pragma once

#include "vec2.hpp"
#include "../common.hpp"

namespace prevmath {

	struct Vec3 {
		pvfloat x;
		pvfloat y;
		pvfloat z;

		Vec3();
		explicit Vec3(const pvfloat & _val);
		Vec3(const pvfloat & _x, const pvfloat & _y, const pvfloat & _z);
		Vec3(const Vec3 & _vec);

		/*
		 * Operators
		 */

		pvfloat & operator[](size_t _index) { PREV_MATH_ASSERT(_index < 3); return (&x)[_index]; }
		const pvfloat & operator[](size_t _index) const { PREV_MATH_ASSERT(_index < 3); return (&x)[_index]; }

		void operator=(const Vec3 & _vec);

		Vec3 & operator+=(const Vec3 & _vec);
		Vec3 & operator-=(const Vec3 & _vec);
		Vec3 & operator*=(const Vec3 & _vec);
		Vec3 & operator/=(const Vec3 & _vec);

		Vec3 & operator+=(const pvfloat & _val);
		Vec3 & operator-=(const pvfloat & _val);
		Vec3 & operator*=(const pvfloat & _val);
		Vec3 & operator/=(const pvfloat & _val);

		Vec3 operator+(const Vec3 & _vec) const;
		Vec3 operator-(const Vec3 & _vec) const;
		Vec3 operator-() const;
		Vec3 operator*(const Vec3 & _vec) const;
		Vec3 operator/(const Vec3 & _vec) const;

		Vec3 operator*(pvfloat _val) const;
		Vec3 operator/(pvfloat _val) const;

		Vec2 xy() const;
		Vec2 yx() const;
		Vec2 yz() const;
		Vec2 zy() const;
		Vec2 xz() const;
		Vec2 zx() const;

		static pvfloat Length(const Vec3 & _vec);
		static pvfloat LengthSqr(const Vec3 & _vec);
		static pvfloat Dot(const Vec3 & _v1, const Vec3 & _v2);
		static pvfloat Distance(const Vec3 & _v1, const Vec3 & _v2);

		static Vec3 Cross(const Vec3 & _v1, const Vec3 & _v2);
		static Vec3 Normalize(const Vec3 & _vec);
		static Vec3 Max(const Vec3 & _v1, const Vec3 & _v2);
		static Vec3 Min(const Vec3 & _v1, const Vec3 & _v2);
		static Vec3 Abs(const Vec3 & _val);
		static Vec3 Lerp(const Vec3 & _v1, const Vec3 & _v2, const pvfloat & _factor);
		static Vec3 Clamp(const Vec3 & _val, const Vec3 & _min, const Vec3 & _max);
		static Vec3 Saturate(const Vec3 & _val);

		static Vec3 RotateAxisX(const Vec3 & _dir, pvfloat _angle);
		static Vec3 RotateAxisY(const Vec3 & _dir, pvfloat _angle);
		static Vec3 RotateAxisZ(const Vec3 & _dir, pvfloat _angle);
		static Vec3 RotateAxis(const Vec3 & _dir, pvfloat _angle, const Vec3 & _axis);
	};

	Vec3 operator*(const pvfloat & _val, const Vec3 & _vec);

	#include "vec3.inl"

}
