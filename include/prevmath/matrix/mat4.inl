
inline Mat4::Mat4() :
	x(1.0f, 0.0f, 0.0f, 0.0f),
	y(0.0f, 1.0f, 0.0f, 0.0f),
	z(0.0f, 0.0f, 1.0f, 0.0f),
	w(0.0f, 0.0f, 0.0f, 1.0f) {}

inline Mat4::Mat4(Vec4 _x, Vec4 _y, Vec4 _z, Vec4 _w) :
	x(_x), y(_y), z(_z), w(_w) {}

inline Mat4::Mat4(const Mat4 & _mat) :
	x(_mat.x), y(_mat.y), z(_mat.z), w(_mat.w) {}

inline Mat4::Mat4(pvfloat _data[16]) :
	x(_data[0], _data[1], _data[2], _data[3]),
	y(_data[4], _data[5], _data[6], _data[7]),
	z(_data[8], _data[9], _data[10], _data[11]),
	w(_data[12], _data[13], _data[14], _data[15]) {}

inline Vec4 Mat4::operator*(const Vec4 _vec) const {
	Mat4 trasposed = Mat4::Transpose(*this);
	return Vec4(
		Vec4::Dot(trasposed.x, _vec),
		Vec4::Dot(trasposed.y, _vec),
		Vec4::Dot(trasposed.z, _vec),
		Vec4::Dot(trasposed.w, _vec)
	);
}

inline Mat4 Mat4::operator*(const Mat4 & _mat) const {
	Mat4 t = Mat4::Transpose(*this);

	Vec4 vecX = Vec4(Vec4::Dot(t.x, _mat.x), Vec4::Dot(t.y, _mat.x), Vec4::Dot(t.z, _mat.x), Vec4::Dot(t.w, _mat.x));
	Vec4 vecY = Vec4(Vec4::Dot(t.x, _mat.y), Vec4::Dot(t.y, _mat.y), Vec4::Dot(t.z, _mat.y), Vec4::Dot(t.w, _mat.y));
	Vec4 vecZ = Vec4(Vec4::Dot(t.x, _mat.z), Vec4::Dot(t.y, _mat.z), Vec4::Dot(t.z, _mat.z), Vec4::Dot(t.w, _mat.z));
	Vec4 vecW = Vec4(Vec4::Dot(t.x, _mat.w), Vec4::Dot(t.y, _mat.w), Vec4::Dot(t.z, _mat.w), Vec4::Dot(t.w, _mat.w));

	return Mat4(vecX, vecY, vecZ, vecW);
}

inline Mat4 Mat4::operator*(const pvfloat _val) const {
	return Mat4(x * _val, y * _val, z * _val, w * _val);
}

inline Mat4 Mat4::operator+(const Mat4 & _mat) const {
	return Mat4(x + _mat.x, y + _mat.y, z + _mat.z, w + _mat.w);
}

inline Mat4 Mat4::operator-(const Mat4 & _mat) const {
	return Mat4(x - _mat.x, y - _mat.y, z - _mat.z, w - _mat.w);
}

inline void Mat4::operator*=(const Mat4 & _mat) {
	*this = *this * _mat;
}

inline void Mat4::operator*=(const pvfloat _val) {
	*this = *this * _val;
}

inline void Mat4::operator+=(const Mat4 & _mat) {
	*this = *this + _mat;
}

inline void Mat4::operator-=(const Mat4 & _mat) {
	*this = *this - _mat;
}

inline Mat4 Mat4::Transpose(const Mat4 & _mat) {
	Mat4 result;
	result.x = Vec4(_mat.x.x, _mat.y.x, _mat.z.x, _mat.w.x);
	result.y = Vec4(_mat.x.y, _mat.y.y, _mat.z.y, _mat.w.y);
	result.z = Vec4(_mat.x.z, _mat.y.z, _mat.z.z, _mat.w.z);
	result.w = Vec4(_mat.x.w, _mat.y.w, _mat.z.w, _mat.w.w);
	return result;
}

inline Mat4 Mat4::Ortho(const float _left, const float _right, const float _bottom, const float _top, const float _near, const float _far) {
	const float r_minus_l_inv = 1.f / (_right - _left);
	const float t_minus_b_inv = 1.f / (_top - _bottom);
	const float n_minus_f_inv = 1.f / (_near - _far);

	return Mat4(
		Vec4(2.0f * r_minus_l_inv, 0.0f, 0.0f, 0.0f),
		Vec4(0.0f, 2.0f * t_minus_b_inv, 0.0f, 0.0f),
		Vec4(0.0f, 0.0f, 1.0f * n_minus_f_inv, 0.0f),
		Vec4(
			-(_right + _left) * r_minus_l_inv,
			-(_top + _bottom) * t_minus_b_inv,
			0.5f + (_far + _near) * n_minus_f_inv,
			1.0f
		)
	);
}