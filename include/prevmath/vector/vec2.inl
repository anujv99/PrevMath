
inline Vec2::Vec2() : x(static_cast<pvfloat>(0.0)), y(static_cast<pvfloat>(0.0)) {}

inline Vec2::Vec2(const pvfloat & _val) : x(_val), y(_val) {}

inline Vec2::Vec2(const pvfloat & _x, const pvfloat & _y) : x(_x), y(_y) {}

inline Vec2::Vec2(const Vec2 & _vec) : x(_vec.x), y(_vec.y) {}

#if defined(ENABLE_VEC2_CHECK)
	#define VEC2_CHECK_THIS PREV_MATH_ASSERT(CheckVec2(*this))
	#define VEC2_CHECK(V) PREV_MATH_ASSERT(CheckVec2(V))
	#define VEC2_CHECK_CUSTOM(E) PREV_MATH_ASSERT(E)
#else
	#define VEC2_CHECK_THIS
	#define VEC2_CHECK(V)
	#define VEC2_CHECK_CUSTOM(E)
#endif


inline bool CheckVec2(const Vec2 & _vec) {
	return _vec.x <= std::numeric_limits<pvfloat>::max() && _vec.x >= -std::numeric_limits<pvfloat>::max()
		&& _vec.y <= std::numeric_limits<pvfloat>::max() && _vec.y >= -std::numeric_limits<pvfloat>::max();
}

inline void Vec2::operator=(const Vec2 & _vec) {
	x = _vec.x;
	y = _vec.y;
	VEC2_CHECK_THIS;
}

inline Vec2 & Vec2::operator+=(const Vec2 & _vec) {
	x += _vec.x;
	y += _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator-=(const Vec2 & _vec) {
	x -= _vec.x;
	y -= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator*=(const Vec2 & _vec) {
	x *= _vec.x;
	y *= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator/=(const Vec2 & _vec) {
	VEC2_CHECK_CUSTOM(prevmath::Abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC2_CHECK_CUSTOM(prevmath::Abs(_vec.y) > std::numeric_limits<pvfloat>::min());
	x /= _vec.x;
	y /= _vec.y;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator+=(const pvfloat & _val) {
	x += _val;
	y += _val;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator-=(const pvfloat & _val) {
	x -= _val;
	y -= _val;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator*=(const pvfloat & _val) {
	x *= _val;
	y *= _val;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 & Vec2::operator/=(const pvfloat & _val) {
	VEC2_CHECK_CUSTOM(_val > std::numeric_limits<pvfloat>::min());
	x /= _val;
	y /= _val;
	VEC2_CHECK_THIS;
	return *this;
}

inline Vec2 Vec2::operator+(const Vec2 & _vec) const {
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 _temp(x + _vec.x, y + _vec.y);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator-(const Vec2 & _vec) const {
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 _temp(x - _vec.x, y - _vec.y);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator-() const {
	VEC2_CHECK_THIS;
	Vec2 _temp(-x, -y);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator*(const Vec2 & _vec) const {
	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 _temp(x * _vec.x, y * _vec.y);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator/(const Vec2 & _vec) const {
	VEC2_CHECK_CUSTOM(prevmath::Abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC2_CHECK_CUSTOM(prevmath::Abs(_vec.y) > std::numeric_limits<pvfloat>::min());

	VEC2_CHECK(_vec);
	VEC2_CHECK_THIS;
	Vec2 _temp(x / _vec.x, y / _vec.y);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator*(pvfloat _val) const {
	VEC2_CHECK_THIS;
	Vec2 _temp(x * _val, y * _val);
	VEC2_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec2::operator/(pvfloat _val) const {
	VEC2_CHECK_CUSTOM(prevmath::Abs(_val) > std::numeric_limits<pvfloat>::min());

	VEC2_CHECK_THIS;
	Vec2 _temp(x / _val, y / _val);
	VEC2_CHECK(_temp);
	return _temp;
}

inline bool Vec2::operator==(const Vec2 & _vec) const {
	VEC2_CHECK_THIS;
	VEC2_CHECK(_vec);

	return (x == _vec.x && y == _vec.y);
}

inline bool Vec2::operator!=(const Vec2 & _vec) const {
	VEC2_CHECK_THIS;
	VEC2_CHECK(_vec);

	return !(x == _vec.x && y == _vec.y);
}

inline pvfloat Vec2::Length(const Vec2 & _vec) {
	return prevmath::Sqrt<pvfloat>((_vec.x * _vec.x) + (_vec.y * _vec.y));
}

inline pvfloat Vec2::LengthSqr(const Vec2 & _vec) {
	return (_vec.x * _vec.x) + (_vec.y * _vec.y);
}

inline pvfloat Vec2::Dot(const Vec2 & _v1, const Vec2 & _v2) {
	return (_v1.x * _v2.x) + (_v1.y * _v2.y);
}

inline pvfloat Vec2::Distance(const Vec2 & _v1, const Vec2 & _v2) {
	return Length(_v2 - _v1);
}

inline Vec2 Vec2::Normalize(const Vec2 & _vec) {
	pvfloat _len = Length(_vec);
	VEC2_CHECK_CUSTOM(_len > std::numeric_limits<pvfloat>::min());
	pvfloat _div_len = static_cast<pvfloat>(1.0) / _len;
	return _vec * _div_len;
}

inline Vec2 Vec2::Max(const Vec2 & _v1, const Vec2 & _v2) {
	return Vec2(prevmath::Max<pvfloat>(_v1.x, _v2.x), prevmath::Max<pvfloat>(_v1.y, _v2.y));
}

inline Vec2 Vec2::Min(const Vec2 & _v1, const Vec2 & _v2) {
	return Vec2(prevmath::Min<pvfloat>(_v1.x, _v2.x), prevmath::Min<pvfloat>(_v1.y, _v2.y));
}

inline Vec2 Vec2::Abs(const Vec2 & _val) {
	return Vec2(prevmath::Abs<pvfloat>(_val.x), prevmath::Abs<pvfloat>(_val.y));
}

inline Vec2 Vec2::Lerp(const Vec2 & _v1, const Vec2 & _v2, const pvfloat & _factor) {
	return Vec2(prevmath::Lerp<pvfloat>(_v1.x, _v2.x, _factor), prevmath::Lerp<pvfloat>(_v1.y, _v2.y, _factor));
}

inline Vec2 Vec2::Clamp(const Vec2 & _val, const Vec2 & _min, const Vec2 & _max) {
	return Vec2(prevmath::Clamp(_val.x, _min.x, _max.x), prevmath::Clamp(_val.y, _min.y, _max.y));
}

inline Vec2 Vec2::Saturate(const Vec2 & _val) {
	return Vec2(prevmath::Clamp(_val.x, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)), 
		prevmath::Clamp(_val.y, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)));
}

inline Vec2 Vec2::Perpendicular(const Vec2 & _val) {
	return Vec2(-_val.y, _val.x);
}

inline Vec2 Vec2::UnitCircle(pvfloat _angle) {
	return Vec2(prevmath::Cos(_angle), prevmath::Sin(_angle));
}

inline Vec2 Vec2::CubicBezier(const Vec2 & _anchor1, const Vec2 & _anchor2, const Vec2 & _control1, const Vec2 & _control2, const pvfloat & _factor) {
	pvfloat _new_factor = prevmath::Clamp(_factor, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0));
	pvfloat _one_minus_factor = static_cast<pvfloat>(1.0) - _new_factor;

	pvfloat _a = prevmath::Pow<pvfloat, int>(_one_minus_factor, 3);
	pvfloat _b = static_cast<pvfloat>(3.0) * prevmath::Pow<pvfloat, int>(_one_minus_factor, 2) * _new_factor;
	pvfloat _c = static_cast<pvfloat>(3.0) * _one_minus_factor * prevmath::Pow<pvfloat, int>(_new_factor, 2);
	pvfloat _d = prevmath::Pow<float, int>(_new_factor, 3);

	return (_a * _anchor1) + (_b * _control1) + (_c * _control2) + (_d * _anchor2);
}

inline Vec2 Vec2::QuadraticBezier(const Vec2 & _anchor1, const Vec2 & _anchor2, const Vec2 & _control, const pvfloat & _factor) {
	pvfloat _new_factor = prevmath::Clamp(_factor, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0));

	Vec2 _p1 = _anchor1 + (_factor * (_control - _anchor1));
	Vec2 _p2 = _control + (_factor * (_anchor2 - _control));

	return (_p1 + (_factor * (_p2 - _p1)));
}

inline Vec2 Vec2::Rotate(const Vec2 & _dir, const pvfloat & _angle) {
	pvfloat _cosine = prevmath::Cos<pvfloat>(_angle);
	pvfloat _sine = prevmath::Sin<pvfloat>(_angle);

	pvfloat _new_x = _dir.x * _cosine - _dir.y * _sine;
	pvfloat _new_y = _dir.x * _sine + _dir.y * _cosine;

	return Vec2(_new_x, _new_y);
}

inline Vec2 operator*(const pvfloat & _val, const Vec2 & _vec) {
	return Vec2(_val * _vec.x, _val * _vec.y);
}