template<typename T>
inline Vec2<T>::Vec2() : x(_raw_vector[0]), y(_raw_vector[1]) {}

template<typename T>
inline Vec2<T>::Vec2(typename std::common_type<T>::type _val) : x(_raw_vector[0]), y(_raw_vector[1]) { x = _val; y = _val; }

template<typename T>
inline Vec2<T>::Vec2(typename std::common_type<T>::type _x, typename std::common_type<T>::type _y) : x(_raw_vector[0]), y(_raw_vector[1]) { x = _x; y = _y; }

template<typename T>
inline Vec2<T>::Vec2(const Vec2 & _vec) : x(_raw_vector[0]), y(_raw_vector[1]) { x = _vec.x; y = _vec.y; }

#if defined(ENABLE_VEC2_CHECK)
	#define VEC2_CHECK_THIS PREV_MATH_ASSERT(CheckVec2(*this))
	#define VEC2_CHECK(V) PREV_MATH_ASSERT(CheckVec2(V))
	#define VEC2_CHECK_CUSTOM(E) PREV_MATH_ASSERT(E)
#else
	#define VEC2_CHECK_THIS
	#define VEC2_CHECK(V)
	#define VEC2_CHECK_CUSTOM(E)
#endif

template<typename T>
inline bool CheckVec2(const Vec2<T> & _vec) {
	return _vec.x <= std::numeric_limits<T>::max() && _vec.x >= -std::numeric_limits<T>::max()
		&& _vec.y <= std::numeric_limits<T>::max() && _vec.y >= -std::numeric_limits<T>::max();
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator+=(const Vec2 & _vec) {
	x += _vec.x;
	y += _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator-=(const Vec2 & _vec) {
	x -= _vec.x;
	y -= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator*=(const Vec2 & _vec) {
	x *= _vec.x;
	y *= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator/=(const Vec2 & _vec) {
	VEC2_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<T>::min());
	VEC2_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<T>::min());
	x /= _vec.x;
	y /= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator+=(T _val) {
	x += _val;
	y += _val;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator-=(T _val) {
	x -= _val;
	y -= _val;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator*=(T _val) {
	x *= _val;
	y *= _val;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> & Vec2<T>::operator/=(T _val) {
	VEC2_CHECK_CUSTOM(_val > std::numeric_limits<T>::min());
	x /= _val;
	y /= _val;
	VEC2_CHECK_THIS;
	return *this;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator+(const Vec2 & _vec) const {
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 temp(x + _vec.x, y + _vec.y);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-(const Vec2 & _vec) const {
	if (!std::numeric_limits<T>::is_signed()) {
		VEC2_CHECK_CUSTOM(
			(x > _vec.x) && (y > _vec.y)
		);
	}
	
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 temp(x - _vec.x, y - _vec.y);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator-() const {
	if (!std::numeric_limits<T>::is_signed) {
		VEC2_CHECK_CUSTOM(false);
	}
	VEC2_CHECK_THIS;
	Vec2 temp(-x, -y);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(const Vec2 & _vec) const {
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 temp(x * _vec.x, y * _vec.y);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(const Vec2 & _vec) const {
	VEC2_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<T>::min());
	VEC2_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<T>::min());

	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 temp(x / _vec.x, y / _vec.y);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator*(float _val) const {
	VEC2_CHECK_THIS;
	Vec2 temp(x * _val, y * _val);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline Vec2<T> Vec2<T>::operator/(float _val) const {
	VEC2_CHECK_CUSTOM(std::abs(_val) > std::numeric_limits<T>::min());

	VEC2_CHECK_THIS;
	Vec2 temp(x / _val, y / _val);
	VEC2_CHECK(temp);
	return temp;
}

template<typename T>
inline bool prevmath::Vec2<T>::operator==(const Vec2 & _vec) const {
	return x == _vec.x && y == _vec.y;
}

template<typename T>
inline bool prevmath::Vec2<T>::operator!=(const Vec2 & _vec) const {
	return x != _vec.x || y != _vec.y;
}