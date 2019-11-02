
inline Vec4::Vec4() : x(static_cast<pvfloat>(0.0)), y(static_cast<pvfloat>(0.0)), z(static_cast<pvfloat>(0.0)), w(static_cast<pvfloat>(0.0)) {}

inline Vec4::Vec4(const pvfloat & _val) : x(_val), y(_val), z(_val), w(_val) {}

inline Vec4::Vec4(const pvfloat & _x, const pvfloat & _y, const pvfloat & _z, const pvfloat & _w) : x(_x), y(_y), z(_z), w(_w) {}

inline Vec4::Vec4(const Vec4 & _vec) : x(_vec.x), y(_vec.y), z(_vec.z), w(_vec.w) {}

#if defined(ENABLE_VEC4_CHECK)
	#define VEC4_CHECK_THIS PREV_MATH_ASSERT(CheckVec4(*this))
	#define VEC4_CHECK(V) PREV_MATH_ASSERT(CheckVec4(V))
	#define VEC4_CHECK_CUSTOM(E) PREV_MATH_ASSERT(E)
#else
	#define VEC4_CHECK_THIS
	#define VEC4_CHECK(V)
	#define VEC4_CHECK_CUSTOM(E)
#endif


inline bool CheckVec4(const Vec4 & _vec) {
	return _vec.x <= std::numeric_limits<pvfloat>::max() && _vec.x >= -std::numeric_limits<pvfloat>::max()
		&& _vec.y <= std::numeric_limits<pvfloat>::max() && _vec.y >= -std::numeric_limits<pvfloat>::max()
		&& _vec.z <= std::numeric_limits<pvfloat>::max() && _vec.z >= -std::numeric_limits<pvfloat>::max()
		&& _vec.w <= std::numeric_limits<pvfloat>::max() && _vec.w >= -std::numeric_limits<pvfloat>::max();
}

inline void Vec4::operator=(const Vec4 & _vec) {
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	w = _vec.w;
	VEC4_CHECK_THIS;
}

inline Vec4 & Vec4::operator+=(const Vec4 & _vec) {
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	w += _vec.w;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator-=(const Vec4 & _vec) {
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator*=(const Vec4 & _vec) {
	x *= _vec.x;
	y *= _vec.y;
	z *= _vec.z;
	w *= _vec.w;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator/=(const Vec4 & _vec) {
	VEC4_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.z) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.w) > std::numeric_limits<pvfloat>::min());
	x /= _vec.x;
	y /= _vec.y;
	z /= _vec.z;
	w /= _vec.w;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator+=(const pvfloat & _val) {
	x += _val;
	y += _val;
	z += _val;
	w += _val;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator-=(const pvfloat & _val) {
	x -= _val;
	y -= _val;
	z -= _val;
	w -= _val;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator*=(const pvfloat & _val) {
	x *= _val;
	y *= _val;
	z *= _val;
	w *= _val;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 & Vec4::operator/=(const pvfloat & _val) {
	VEC4_CHECK_CUSTOM(_val > std::numeric_limits<pvfloat>::min());
	x /= _val;
	y /= _val;
	z /= _val;
	w /= _val;
	VEC4_CHECK_THIS;
	return *this;
}

inline Vec4 Vec4::operator+(const Vec4 & _vec) const {
	VEC4_CHECK(_vec);
	VEC4_CHECK_THIS;
	Vec4 _temp(x + _vec.x, y + _vec.y, z + _vec.z, w + _vec.w);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator-(const Vec4 & _vec) const {
	VEC4_CHECK(_vec);
	VEC4_CHECK_THIS;
	Vec4 _temp(x - _vec.x, y - _vec.y, z - _vec.z, w - _vec.w);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator-() const {
	VEC4_CHECK_THIS;
	Vec4 _temp(-x, -y, -z, -w);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator*(const Vec4 & _vec) const {
	VEC4_CHECK(_vec);
	VEC4_CHECK_THIS;
	Vec4 _temp(x * _vec.x, y * _vec.y, z * _vec.z, w * _vec.w);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator/(const Vec4 & _vec) const {
	VEC4_CHECK_CUSTOM(std::abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.y) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.z) > std::numeric_limits<pvfloat>::min());
	VEC4_CHECK_CUSTOM(std::abs(_vec.w) > std::numeric_limits<pvfloat>::min());

	VEC4_CHECK(_vec);
	VEC4_CHECK_THIS;
	Vec4 _temp(x / _vec.x, y / _vec.y, z / _vec.z, w / _vec.w);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator*(pvfloat _val) const {
	VEC4_CHECK_THIS;
	Vec4 _temp(x * _val, y * _val, z * _val, w * _val);
	VEC4_CHECK(_temp);
	return _temp;
}

inline Vec4 Vec4::operator/(pvfloat _val) const {
	VEC4_CHECK_CUSTOM(std::abs(_val) > std::numeric_limits<pvfloat>::min());

	VEC4_CHECK_THIS;
	Vec4 _temp(x / _val, y / _val, z / _val, w / _val);
	VEC4_CHECK(_temp);
	return _temp;
}

inline bool Vec4::operator==(const Vec4 & _vec) const {
	return x == _vec.x && y == _vec.y && z == _vec.z && w == _vec.w;
}

inline bool Vec4::operator!=(const Vec4 & _vec) const {
	return x != _vec.x || y != _vec.y || z != _vec.z || w != _vec.w;
}

inline pvfloat Vec4::Length(const Vec4 & _vec) {
	return prevmath::Sqrt<pvfloat>((_vec.x * _vec.x) + (_vec.y * _vec.y) + (_vec.z * _vec.z) + (_vec.w * _vec.w));
}

inline pvfloat Vec4::LengthSqr(const Vec4 & _vec) {
	return (_vec.x * _vec.x) + (_vec.y * _vec.y) + (_vec.z * _vec.z) + (_vec.w * _vec.w);
}

inline pvfloat Vec4::Dot(const Vec4 & _v1, const Vec4 & _v2) {
	return (_v1.x * _v2.x) + (_v1.y * _v2.y) + (_v1.z * _v2.z) +(_v1.w * _v2.w);
}

inline pvfloat Vec4::Distance(const Vec4 & _v1, const Vec4 & _v2) {
	return Length(_v2 - _v1);
}

inline Vec4 Vec4::Normalize(const Vec4 & _vec) {
	pvfloat _len = Length(_vec);
	VEC4_CHECK_CUSTOM(_len > std::numeric_limits<pvfloat>::min());
	pvfloat _div_len = static_cast<pvfloat>(1.0) / _len;
	return _vec * _div_len;
}

inline Vec4 Vec4::Max(const Vec4 & _v1, const Vec4 & _v2) {
	return Vec4(prevmath::Max<pvfloat>(_v1.x, _v2.x), prevmath::Max<pvfloat>(_v1.y, _v2.y),
		prevmath::Max<pvfloat>(_v1.z, _v2.z), prevmath::Max<pvfloat>(_v1.w, _v2.w));
}

inline Vec4 Vec4::Min(const Vec4 & _v1, const Vec4 & _v2) {
	return Vec4(prevmath::Min<pvfloat>(_v1.x, _v2.x), prevmath::Min<pvfloat>(_v1.y, _v2.y),
		prevmath::Min<pvfloat>(_v1.z, _v2.z), prevmath::Min<pvfloat>(_v1.w, _v2.w));
}

inline Vec4 Vec4::Abs(const Vec4 & _val) {
	return Vec4(prevmath::Abs<pvfloat>(_val.x), prevmath::Abs<pvfloat>(_val.y), prevmath::Abs<pvfloat>(_val.z), prevmath::Abs<pvfloat>(_val.w));
}

inline Vec4 Vec4::Lerp(const Vec4 & _v1, const Vec4 & _v2, const pvfloat & _factor) {
	return Vec4(prevmath::Lerp<pvfloat>(_v1.x, _v2.x, _factor), prevmath::Lerp<pvfloat>(_v1.y, _v2.y, _factor),
		prevmath::Lerp<pvfloat>(_v1.z, _v2.z, _factor), prevmath::Lerp<pvfloat>(_v1.w, _v2.w, _factor));
}

inline Vec4 Vec4::Clamp(const Vec4 & _val, const Vec4 & _min, const Vec4 & _max) {
	return Vec4(prevmath::Clamp(_val.x, _min.x, _max.x), prevmath::Clamp(_val.y, _min.y, _max.y),
		prevmath::Clamp(_val.z, _min.z, _max.z), prevmath::Clamp(_val.w, _min.w, _max.w));
}

inline Vec4 Vec4::Saturate(const Vec4 & _val) {
	return Vec4(
		prevmath::Clamp(_val.x, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)),
		prevmath::Clamp(_val.y, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)),
		prevmath::Clamp(_val.z, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)),
		prevmath::Clamp(_val.w, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)));
}

inline Vec4 operator*(const pvfloat & _val, const Vec4 & _vec) {
	return Vec4(_val * _vec.x, _val * _vec.y, _val * _vec.z, _val * _vec.w);
}