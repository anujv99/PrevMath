#pragma once

#include "vec2.hpp"
#include "vec3.hpp"

namespace prevmath {

	struct Vec4 {
		pvfloat x;
		pvfloat y;
		pvfloat z;
		pvfloat w;

		Vec4();
		explicit Vec4(const pvfloat & _val);
		Vec4(const pvfloat & _x, const pvfloat & _y, const pvfloat & _z, const pvfloat & _w);
		Vec4(const Vec4 & _vec);

		/*
		 * Operators
		 */

		pvfloat & operator[](size_t _index) { PREV_MATH_ASSERT(_index < 4); return (&x)[_index]; }
		const pvfloat & operator[](size_t _index) const { PREV_MATH_ASSERT(_index < 4); return (&x)[_index]; }

		void operator=(const Vec4 & _vec);

		Vec4 & operator+=(const Vec4 & _vec);
		Vec4 & operator-=(const Vec4 & _vec);
		Vec4 & operator*=(const Vec4 & _vec);
		Vec4 & operator/=(const Vec4 & _vec);

		Vec4 & operator+=(const pvfloat & _val);
		Vec4 & operator-=(const pvfloat & _val);
		Vec4 & operator*=(const pvfloat & _val);
		Vec4 & operator/=(const pvfloat & _val);

		Vec4 operator+(const Vec4 & _vec) const;
		Vec4 operator-(const Vec4 & _vec) const;
		Vec4 operator-() const;
		Vec4 operator*(const Vec4 & _vec) const;
		Vec4 operator/(const Vec4 & _vec) const;

		Vec4 operator*(pvfloat _val) const;
		Vec4 operator/(pvfloat _val) const;

		bool operator==(const Vec4 & _vec) const;
		bool operator!=(const Vec4 & _vec) const;

		Vec2 xy() const { return Vec2(x, y); };
		Vec2 yx() const { return Vec2(y, x); };

		Vec2 xz() const { return Vec2(x, z); };
		Vec2 zx() const { return Vec2(z, x); };

		Vec2 xw() const { return Vec2(x, w); };
		Vec2 wx() const { return Vec2(w, x); };

		Vec2 yz() const { return Vec2(y, z); };
		Vec2 zy() const { return Vec2(z, y); };

		Vec2 yw() const { return Vec2(y, w); };
		Vec2 wy() const { return Vec2(w, y); };

		Vec2 zw() const { return Vec2(z, w); };
		Vec2 wz() const { return Vec2(w, z); };

		Vec3 xyz() const { return Vec3(x, y, z); }
		Vec3 xzy() const { return Vec3(x, z, y); }
		Vec3 yxz() const { return Vec3(y, x, z); }
		Vec3 yzx() const { return Vec3(y, z, x); }
		Vec3 zxy() const { return Vec3(z, x, y); }
		Vec3 zyx() const { return Vec3(z, y, x); }

		Vec3 xyw() const { return Vec3(x, y, w); }
		Vec3 xwy() const { return Vec3(x, w, y); }
		Vec3 yxw() const { return Vec3(y, x, w); }
		Vec3 ywx() const { return Vec3(y, w, x); }
		Vec3 wxy() const { return Vec3(w, x, y); }
		Vec3 wyx() const { return Vec3(w, y, x); }

		Vec3 xzw() const { return Vec3(x, z, w); }
		Vec3 xwz() const { return Vec3(x, w, z); }
		Vec3 zxw() const { return Vec3(z, x, w); }
		Vec3 zwx() const { return Vec3(z, w, x); }
		Vec3 wxz() const { return Vec3(w, x, z); }
		Vec3 wzx() const { return Vec3(w, z, x); }

		Vec3 yzw() const { return Vec3(y, z, w); }
		Vec3 ywz() const { return Vec3(y, w, z); }
		Vec3 zyw() const { return Vec3(z, y, w); }
		Vec3 zwy() const { return Vec3(z, w, y); }
		Vec3 wyz() const { return Vec3(w, y, z); }
		Vec3 wzy() const { return Vec3(w, z, y); }

		static pvfloat Length(const Vec4 & _vec);
		static pvfloat LengthSqr(const Vec4 & _vec);
		static pvfloat Dot(const Vec4 & _v1, const Vec4 & _v2);
		static pvfloat Distance(const Vec4 & _v1, const Vec4 & _v2);

		static Vec4 Normalize(const Vec4 & _vec);
		static Vec4 Max(const Vec4 & _v1, const Vec4 & _v2);
		static Vec4 Min(const Vec4 & _v1, const Vec4 & _v2);
		static Vec4 Abs(const Vec4 & _val);
		static Vec4 Lerp(const Vec4 & _v1, const Vec4 & _v2, const pvfloat & _factor);
		static Vec4 Clamp(const Vec4 & _val, const Vec4 & _min, const Vec4 & _max);
		static Vec4 Saturate(const Vec4 & _val);
	};

	Vec4 operator*(const pvfloat & _val, const Vec4 & _vec);

	#include "vec4.inl"

}