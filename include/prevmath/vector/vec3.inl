
inline Vec3::Vec3() : x(static_cast<pvfloat>(0.0)), y(static_cast<pvfloat>(0.0)), z(static_cast<pvfloat>(0.0)) {}

inline Vec3::Vec3(const pvfloat & _val) : x(_val), y(_val), z(_val) {}

inline Vec3::Vec3(const pvfloat & _x, const pvfloat & _y, const pvfloat & _z) : x(_x), y(_y), z(_z) {}

inline Vec3::Vec3(const Vec3 & _vec) : x(_vec.x), y(_vec.y), z(_vec.z) {}

#if defined(ENABLE_VEC3_CHECK)
	#define VEC3_CHECK_THIS PREV_MATH_ASSERT(CheckVec3(*this))
	#define VEC3_CHECK(V) PREV_MATH_ASSERT(CheckVec3(V))
	#define VEC3_CHECK_CUSTOM(E) PREV_MATH_ASSERT(E)
#else
	#define VEC3_CHECK_THIS
	#define VEC3_CHECK(V)
	#define VEC3_CHECK_CUSTOM(E)
#endif


inline bool CheckVec3(const Vec3 & _vec) {
	return _vec.x <= std::numeric_limits<pvfloat>::max() && _vec.x >= -std::numeric_limits<pvfloat>::max()
		&& _vec.y <= std::numeric_limits<pvfloat>::max() && _vec.y >= -std::numeric_limits<pvfloat>::max()
		&& _vec.z <= std::numeric_limits<pvfloat>::max() && _vec.z >= -std::numeric_limits<pvfloat>::max();
}

inline void Vec3::operator=(const Vec3 & _vec) {
	x = _vec.x;
	y = _vec.y;
	z = _vec.z;
	VEC3_CHECK_THIS;
}

inline Vec3 & Vec3::operator+=(const Vec3 & _vec) {
	x += _vec.x;
	y += _vec.y;
	z += _vec.z;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator-=(const Vec3 & _vec) {
	x -= _vec.x;
	y -= _vec.y;
	z -= _vec.z;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator*=(const Vec3 & _vec) {
	x *= _vec.x;
	y *= _vec.y;
	z *= _vec.z;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator/=(const Vec3 & _vec) {
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.y) > std::numeric_limits<pvfloat>::min());
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.z) > std::numeric_limits<pvfloat>::min());
	x /= _vec.x;
	y /= _vec.y;
	z /= _vec.z;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator+=(const pvfloat & _val) {
	x += _val;
	y += _val;
	z += _val;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator-=(const pvfloat & _val) {
	x -= _val;
	y -= _val;
	z -= _val;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator*=(const pvfloat & _val) {
	x *= _val;
	y *= _val;
	z *= _val;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 & Vec3::operator/=(const pvfloat & _val) {
	VEC3_CHECK_CUSTOM(_val > std::numeric_limits<pvfloat>::min());
	x /= _val;
	y /= _val;
	z /= _val;
	VEC3_CHECK_THIS;
	return *this;
}

inline Vec3 Vec3::operator+(const Vec3 & _vec) const {
	VEC3_CHECK(_vec);
	VEC3_CHECK_THIS;
	Vec3 _temp(x + _vec.x, y + _vec.y, z + _vec.z);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator-(const Vec3 & _vec) const {
	VEC3_CHECK(_vec);
	VEC3_CHECK_THIS;
	Vec3 _temp(x - _vec.x, y - _vec.y, z - _vec.z);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator-() const {
	VEC3_CHECK_THIS;
	Vec3 _temp(-x, -y, -z);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator*(const Vec3 & _vec) const {
	VEC3_CHECK(_vec);
	VEC3_CHECK_THIS;
	Vec3 _temp(x * _vec.x, y * _vec.y, z * _vec.z);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator/(const Vec3 & _vec) const {
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.x) > std::numeric_limits<pvfloat>::min());
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.y) > std::numeric_limits<pvfloat>::min());
	VEC3_CHECK_CUSTOM(prevmath::Abs(_vec.z) > std::numeric_limits<pvfloat>::min());

	VEC3_CHECK(_vec);
	VEC3_CHECK_THIS;
	Vec3 _temp(x / _vec.x, y / _vec.y, z / _vec.z);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator*(pvfloat _val) const {
	VEC3_CHECK_THIS;
	Vec3 _temp(x * _val, y * _val, z * _val);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec3 Vec3::operator/(pvfloat _val) const {
	VEC3_CHECK_CUSTOM(prevmath::Abs(_val) > std::numeric_limits<pvfloat>::min());

	VEC3_CHECK_THIS;
	Vec3 _temp(x / _val, y / _val, z / _val);
	VEC3_CHECK(_temp);
	return _temp;
}

inline Vec2 Vec3::xy() const {
	return Vec2(x, y);
}

inline Vec2 Vec3::yx() const {
	return Vec2(y, x);
}

inline Vec2 Vec3::yz() const {
	return Vec2(y, z);
}

inline Vec2 Vec3::zy() const {
	return Vec2(z, y);
}

inline Vec2 Vec3::xz() const {
	return Vec2(x, z);
}

inline Vec2 Vec3::zx() const {
	return Vec2(z, x);
}

inline pvfloat Vec3::Length(const Vec3 & _vec) {
	return prevmath::Sqrt<pvfloat>((_vec.x * _vec.x) + (_vec.y * _vec.y) + (_vec.z * _vec.z));
}

inline pvfloat Vec3::LengthSqr(const Vec3 & _vec) {
	return (_vec.x * _vec.x) + (_vec.y * _vec.y) + (_vec.z * _vec.z);
}

inline pvfloat Vec3::Dot(const Vec3 & _v1, const Vec3 & _v2) {
	return (_v1.x * _v2.x) + (_v1.y * _v2.y) + (_v1.z * _v2.z);
}

inline pvfloat Vec3::Distance(const Vec3 & _v1, const Vec3 & _v2) {
	return Length(_v2 - _v1);
}

inline Vec3 Vec3::Cross(const Vec3 & _v1, const Vec3 & _v2) {
	Vec3 _res(_v1.y * _v2.z - _v1.z * _v2.y, _v1.z * _v2.x - _v1.x * _v2.z, _v1.x * _v2.y - _v1.y * _v2.x);
	VEC3_CHECK(_res);
	return _res;
}

inline Vec3 Vec3::Normalize(const Vec3 & _vec) {
	pvfloat _len = Length(_vec);
	VEC3_CHECK_CUSTOM(_len > std::numeric_limits<pvfloat>::min());
	pvfloat _div_len = static_cast<pvfloat>(1.0) / _len;
	return _vec * _div_len;
}

inline Vec3 Vec3::Max(const Vec3 & _v1, const Vec3 & _v2) {
	return Vec3(prevmath::Max<pvfloat>(_v1.x, _v2.x), prevmath::Max<pvfloat>(_v1.y, _v2.y), prevmath::Max<pvfloat>(_v1.z, _v2.z));
}

inline Vec3 Vec3::Min(const Vec3 & _v1, const Vec3 & _v2) {
	return Vec3(prevmath::Min<pvfloat>(_v1.x, _v2.x), prevmath::Min<pvfloat>(_v1.y, _v2.y), prevmath::Min<pvfloat>(_v1.z, _v2.z));
}

inline Vec3 Vec3::Abs(const Vec3 & _val) {
	return Vec3(prevmath::Abs<pvfloat>(_val.x), prevmath::Abs<pvfloat>(_val.y), prevmath::Abs<pvfloat>(_val.z));
}

inline Vec3 Vec3::Lerp(const Vec3 & _v1, const Vec3 & _v2, const pvfloat & _factor) {
	return Vec3(prevmath::Lerp<pvfloat>(_v1.x, _v2.x, _factor), prevmath::Lerp<pvfloat>(_v1.y, _v2.y, _factor), prevmath::Lerp<pvfloat>(_v1.z, _v2.z, _factor));
}

inline Vec3 Vec3::Clamp(const Vec3 & _val, const Vec3 & _min, const Vec3 & _max) {
	return Vec3(prevmath::Clamp(_val.x, _min.x, _max.x), prevmath::Clamp(_val.y, _min.y, _max.y), prevmath::Clamp(_val.z, _min.z, _max.z));
}

inline Vec3 Vec3::Saturate(const Vec3 & _val) {
	return Vec3(prevmath::Clamp(_val.x, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)),
		prevmath::Clamp(_val.y, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)),
		prevmath::Clamp(_val.z, static_cast<pvfloat>(0.0), static_cast<pvfloat>(1.0)));
}

inline Vec3 Vec3::RotateAxisX(const Vec3 & _dir, pvfloat _angle) {
	pvfloat _cosine = prevmath::Cos(_angle);
	pvfloat _sine = prevmath::Sin(_angle);

	pvfloat _new_y = _dir.y * _cosine - _dir.z * _sine;
	pvfloat _new_z = _dir.y * _sine + _dir.z * _cosine;
	pvfloat _new_x = _dir.x;

	return Vec3(_new_x, _new_y, _new_z);
}

inline Vec3 Vec3::RotateAxisY(const Vec3 & _dir, pvfloat _angle) {
	pvfloat _cosine = prevmath::Cos(_angle);
	pvfloat _sine = prevmath::Sin(_angle);

	pvfloat _new_z = _dir.z * _cosine - _dir.x * _sine;
	pvfloat _new_x = _dir.z * _sine + _dir.x * _cosine;
	pvfloat _new_y = _dir.y;

	return Vec3(_new_x, _new_y, _new_z);
}

inline Vec3 Vec3::RotateAxisZ(const Vec3 & _dir, pvfloat _angle) {
	pvfloat _cosine = prevmath::Cos(_angle);
	pvfloat _sine = prevmath::Sin(_angle);

	float _new_x = _dir.x * _cosine - _dir.y * _sine;
	float _new_y = _dir.x * _sine + _dir.y * _cosine;
	float _new_z = _dir.z;

	return Vec3(_new_x, _new_y, _new_z);
}

inline Vec3 Vec3::RotateAxis(const Vec3 & _dir, pvfloat _angle, const Vec3 & _axis) {
	/* http://inside.mines.edu/~gmurray/ArbitraryAxisRotation/ */

	pvfloat _cosine = prevmath::Cos(_angle);
	pvfloat _one_minus_cosine = 1.0f - _cosine;
	pvfloat _sine = prevmath::Sin(_angle);

	pvfloat _x = _dir.x;
	pvfloat _y = _dir.y;
	pvfloat _z = _dir.z;

	pvfloat _u = _axis.x;
	pvfloat _v = _axis.y;
	pvfloat _w = _axis.z;

	pvfloat _axis_length_square = Vec3::LengthSqr(_axis);
	pvfloat _axis_length = prevmath::Sqrt(_axis_length_square);
	pvfloat _c0 = _u * _x + _v * _y + _w * _z;

	pvfloat _x_val = _u * _c0 * _one_minus_cosine + _axis_length_square * _x * _cosine + _axis_length * (-_w * _y + _v * _z) * _sine;
	pvfloat _y_val = _v * _c0 * _one_minus_cosine + _axis_length_square * _y * _cosine + _axis_length * ( _w * _x - _u * _z) * _sine;
	pvfloat _z_val = _w * _c0 * _one_minus_cosine + _axis_length_square * _z * _cosine + _axis_length * (-_v * _x + _u * _y) * _sine;

	Vec3 _result = Vec3(_x_val, _y_val, _z_val) / _axis_length_square;
	return _result;
}

inline Vec3 operator*(const pvfloat & _val, const Vec3 & _vec) {
	return Vec3(_val * _vec.x, _val * _vec.y, _val * _vec.z);
}