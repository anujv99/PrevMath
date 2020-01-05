#pragma once

#include "../common.hpp"

namespace prevmath {

	struct Vec2 {
		pvfloat x;
		pvfloat y;

		Vec2();
		explicit Vec2(const pvfloat & _val);
		Vec2(const pvfloat & _x, const pvfloat & _y);
		Vec2(const Vec2 & _vec);

		/*
		 * Operators
		 */

		pvfloat & operator[](size_t _index) { PREV_MATH_ASSERT(_index < 2); return (&x)[_index]; }
		const pvfloat & operator[](size_t _index) const { PREV_MATH_ASSERT(_index < 2); return (&x)[_index]; }

		void operator=(const Vec2 & _vec);

		Vec2 & operator+=(const Vec2 & _vec);
		Vec2 & operator-=(const Vec2 & _vec);
		Vec2 & operator*=(const Vec2 & _vec);
		Vec2 & operator/=(const Vec2 & _vec);

		Vec2 & operator+=(const pvfloat & _val);
		Vec2 & operator-=(const pvfloat & _val);
		Vec2 & operator*=(const pvfloat & _val);
		Vec2 & operator/=(const pvfloat & _val);

		Vec2 operator+(const Vec2 & _vec) const;
		Vec2 operator-(const Vec2 & _vec) const;
		Vec2 operator-() const;
		Vec2 operator*(const Vec2 & _vec) const;
		Vec2 operator/(const Vec2 & _vec) const;

		Vec2 operator*(pvfloat _val) const;
		Vec2 operator/(pvfloat _val) const;

		bool operator==(const Vec2 & _vec) const;
		bool operator!=(const Vec2 & _vec) const;

		static pvfloat Length(const Vec2 & _vec);
		static pvfloat LengthSqr(const Vec2 & _vec);
		static pvfloat Dot(const Vec2 & _v1, const Vec2 & _v2);
		static pvfloat Distance(const Vec2 & _v1, const Vec2 & _v2);

		static Vec2 Normalize(const Vec2 & _vec);
		static Vec2 Max(const Vec2 & _v1, const Vec2 & _v2);
		static Vec2 Min(const Vec2 & _v1, const Vec2 & _v2);
		static Vec2 Abs(const Vec2 & _val);
		static Vec2 Lerp(const Vec2 & _v1, const Vec2 & _v2, const pvfloat & _factor);
		static Vec2 Clamp(const Vec2 & _val, const Vec2 & _min, const Vec2 & _max);
		static Vec2 Saturate(const Vec2 & _val);
		static Vec2 Perpendicular(const Vec2 & _val);
		static Vec2 UnitCircle(pvfloat _angle);
		static Vec2 Bezier(const Vec2 & _anchor1, const Vec2 & _anchor2, const Vec2 & _control1, const Vec2 & _control2, const pvfloat & _factor);
		static Vec2 Rotate(const Vec2 & _dir, const pvfloat & _angle);
	};

	Vec2 operator*(const pvfloat & _val, const Vec2 & _vec);

	#include "vec2.inl"

}