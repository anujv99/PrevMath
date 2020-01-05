#pragma once

#include "../common.hpp"

namespace prevmath {

	struct Vec2i {
		pvint x;
		pvint y;

		Vec2i();
		explicit Vec2i(const pvint & _val);
		Vec2i(const pvint & _x, const pvint & _y);
		Vec2i(const Vec2i & _vec);

		/*
		 * Operators
		 */

		pvint & operator[](size_t _index) { PREV_MATH_ASSERT(_index < 2); return (&x)[_index]; }
		const pvint & operator[](size_t _index) const { PREV_MATH_ASSERT(_index < 2); return (&x)[_index]; }

		Vec2i & operator+=(const Vec2i & _vec);
		Vec2i & operator-=(const Vec2i & _vec);
		Vec2i & operator*=(const Vec2i & _vec);
		Vec2i & operator/=(const Vec2i & _vec);

		Vec2i & operator+=(const pvint & _val);
		Vec2i & operator-=(const pvint & _val);
		Vec2i & operator*=(const pvint & _val);
		Vec2i & operator/=(const pvint & _val);

		Vec2i operator+(const Vec2i & _vec) const;
		Vec2i operator-(const Vec2i & _vec) const;
		Vec2i operator-() const;
		Vec2i operator*(const Vec2i & _vec) const;
		Vec2i operator/(const Vec2i & _vec) const;

		Vec2i operator*(pvint _val) const;
		Vec2i operator/(pvint _val) const;

		bool operator==(const Vec2i & _vec) const;
		bool operator!=(const Vec2i & _vec) const;

		static pvfloat Length(const Vec2i & _vec);
		static pvfloat Distance(const Vec2i & _v1, const Vec2i & _v2);

		static pvint LengthSqr(const Vec2i & _vec);
		static pvint Dot(const Vec2i & _v1, const Vec2i & _v2);

		static Vec2i Max(const Vec2i & _v1, const Vec2i & _v2);
		static Vec2i Min(const Vec2i & _v1, const Vec2i & _v2);
		static Vec2i Abs(const Vec2i & _val);
		static Vec2i Clamp(const Vec2i & _val, const Vec2i & _min, const Vec2i & _max);
		static Vec2i Perpendicular(const Vec2i & _val);
	};

	Vec2i operator*(const pvint & _val, const Vec2i & _vec);

	#include "vec2i.inl"

}