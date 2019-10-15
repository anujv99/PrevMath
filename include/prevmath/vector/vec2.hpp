#pragma once

#include "vector.hpp"

namespace prevmath {

	template<typename T = float>
	struct Vec2 : public Vector<T, 2> {
		T & x;
		T & y;

		Vec2();
		explicit Vec2(typename std::common_type<T>::type _val);
		explicit Vec2(typename std::common_type<T>::type _x, typename std::common_type<T>::type _y);
		Vec2(const Vec2 & _vec);

		Vec2 & operator+=(const Vec2 & _vec);
		Vec2 & operator-=(const Vec2 & _vec);
		Vec2 & operator*=(const Vec2 & _vec);
		Vec2 & operator/=(const Vec2 & _vec);

		Vec2 & operator+=(T _val);
		Vec2 & operator-=(T _val);
		Vec2 & operator*=(T _val);
		Vec2 & operator/=(T _val);

		Vec2 operator+(const Vec2 & _vec) const;
		Vec2 operator-(const Vec2 & _vec) const;
		Vec2 operator-() const;
		Vec2 operator*(const Vec2 & _vec) const;
		Vec2 operator/(const Vec2 & _vec) const;

		Vec2 operator*(float _val) const;
		Vec2 operator/(float _val) const;

		bool operator==(const Vec2 & _vec) const;
		bool operator!=(const Vec2 & _vec) const;
	};

	#include "vec2.inl"

}