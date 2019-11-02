
inline Vec2i::Vec2i() : x(static_cast<pvint>(0)), y(static_cast<pvint>(0)) {}

inline Vec2i::Vec2i(const pvint & _val) : x(_val), y(_val) {}

inline Vec2i::Vec2i(const pvint & _x, const pvint & _y) : x(_x), y(_y) {}

inline Vec2i::Vec2i(const Vec2i & _vec) : x(_vec.x), y(_vec.y) {}

#if defined(ENABLE_VEC2I_CHECK)
	#define VEC2I_CHECK_THIS PREV_MATH_ASSERT(CheckVec2i(*this))
	#define VEC2I_CHECK(V) PREV_MATH_ASSERT(CheckVec2i(V))
	#define VEC2I_CHECK_CUSTOM(E) PREV_MATH_ASSERT(E)
#else
	#define VEC2I_CHECK_THIS
	#define VEC2I_CHECK(V)
	#define VEC2I_CHECK_CUSTOM(E)
#endif


inline bool CheckVec2i(const Vec2i & _vec) {
	return _vec.x <= std::numeric_limits<pvint>::max() && _vec.x >= -std::numeric_limits<pvint>::max()
		&& _vec.y <= std::numeric_limits<pvint>::max() && _vec.y >= -std::numeric_limits<pvint>::max();
}

inline Vec2i & Vec2i::operator+=(const Vec2i & _vec) {
	x += _vec.x;
	y += _vec.y;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator-=(const Vec2i & _vec) {
	x -= _vec.x;
	y -= _vec.y;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator*=(const Vec2i & _vec) {
	x *= _vec.x;
	y *= _vec.y;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator/=(const Vec2i & _vec) {
	VEC2I_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<pvint>::min());
	VEC2I_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<pvint>::min());
	x /= _vec.x;
	y /= _vec.y;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator+=(const pvint & _val) {
	x += _val;
	y += _val;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator-=(const pvint & _val) {
	x -= _val;
	y -= _val;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator*=(const pvint & _val) {
	x *= _val;
	y *= _val;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i & Vec2i::operator/=(const pvint & _val) {
	VEC2I_CHECK_CUSTOM(_val > std::numeric_limits<pvint>::min());
	x /= _val;
	y /= _val;
	VEC2I_CHECK_THIS;
	return *this;
}

inline Vec2i Vec2i::operator+(const Vec2i & _vec) const {
	VEC2I_CHECK(_vec);
	VEC2I_CHECK_THIS;
	Vec2i _temp(x + _vec.x, y + _vec.y);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator-(const Vec2i & _vec) const {
	VEC2I_CHECK(_vec);
	VEC2I_CHECK_THIS;
	Vec2i _temp(x - _vec.x, y - _vec.y);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator-() const {
	VEC2I_CHECK_THIS;
	Vec2i _temp(-x, -y);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator*(const Vec2i & _vec) const {
	VEC2I_CHECK(_vec);
	VEC2I_CHECK_THIS;
	Vec2i _temp(x * _vec.x, y * _vec.y);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator/(const Vec2i & _vec) const {
	VEC2I_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<pvint>::min());
	VEC2I_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<pvint>::min());

	VEC2I_CHECK(_vec);
	VEC2I_CHECK_THIS;
	Vec2i _temp(x / _vec.x, y / _vec.y);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator*(pvint _val) const {
	VEC2I_CHECK_THIS;
	Vec2i _temp(x * _val, y * _val);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline Vec2i Vec2i::operator/(pvint _val) const {
	VEC2I_CHECK_CUSTOM(std::abs(_val) > std::numeric_limits<pvint>::min());

	VEC2I_CHECK_THIS;
	Vec2i _temp(x / _val, y / _val);
	VEC2I_CHECK(_temp);
	return _temp;
}

inline bool Vec2i::operator==(const Vec2i & _vec) const {
	return x == _vec.x && y == _vec.y;
}

inline bool Vec2i::operator!=(const Vec2i & _vec) const {
	return x != _vec.x || y != _vec.y;
}

inline pvfloat Vec2i::Length(const Vec2i & _vec) {
	return prevmath::Sqrt<pvint>((_vec.x * _vec.x) + (_vec.y * _vec.y));
}

inline pvint Vec2i::LengthSqr(const Vec2i & _vec) {
	return (_vec.x * _vec.x) + (_vec.y * _vec.y);
}

inline pvint Vec2i::Dot(const Vec2i & _v1, const Vec2i & _v2) {
	return (_v1.x * _v2.x) + (_v1.y * _v2.y);
}

inline pvfloat Vec2i::Distance(const Vec2i & _v1, const Vec2i & _v2) {
	return Length(_v2 - _v1);
}

inline Vec2i Vec2i::Max(const Vec2i & _v1, const Vec2i & _v2) {
	return Vec2i(prevmath::Max<pvint>(_v1.x, _v2.x), prevmath::Max<pvint>(_v1.y, _v2.y));
}

inline Vec2i Vec2i::Min(const Vec2i & _v1, const Vec2i & _v2) {
	return Vec2i(prevmath::Min<pvint>(_v1.x, _v2.x), prevmath::Min<pvint>(_v1.y, _v2.y));
}

inline Vec2i Vec2i::Abs(const Vec2i & _val) {
	return Vec2i(prevmath::Abs<pvint>(_val.x), prevmath::Abs<pvint>(_val.y));
}

inline Vec2i Vec2i::Clamp(const Vec2i & _val, const Vec2i & _min, const Vec2i & _max) {
	return Vec2i(prevmath::Clamp(_val.x, _min.x, _max.x), prevmath::Clamp(_val.y, _min.y, _max.y));
}

inline Vec2i Vec2i::Perpendicular(const Vec2i & _val) {
	return Vec2i(-_val.y, _val.x);
}

inline Vec2i operator*(const pvint & _val, const Vec2i & _vec) {
	return Vec2i(_val * _vec.x, _val * _vec.y);
}