
#include <iostream>

#include <prevmath/vector/vector.hpp>

#include <prevmath/vector/vec2.hpp>
#include <prevmath/vector/vec2i.hpp>
#include <prevmath/vector/vec3.hpp>
#include <prevmath/vector/vec4.hpp>

namespace prevmath {

	template<typename T, size_t N>
	inline std::ostream & operator<<(std::ostream & _out_stream, const Vector<T, N> & _vec) {
		if (N <= 0)
			return _out_stream;
		_out_stream << "[Vec" << N << " : " << _vec[0];
		for (size_t i = 1ull; i < N; i++) {
			_out_stream << ", " << _vec[i];
		}
		_out_stream << "]";
		return _out_stream;
	}

	template<size_t N>
	inline std::ostream & operator<<(std::ostream & _out_stream, const Vector<pvint, N> & _vec) {
		if (N <= 0)
			return _out_stream;
		_out_stream << "[Vec" << N << "i : " << _vec[0];
		for (size_t i = 1ull; i < N; i++) {
			_out_stream << ", " << _vec[i];
		}
		_out_stream << "]";
		return _out_stream;
	}

	inline std::ostream & operator<<(std::ostream & _out_stream, const Vec2 & _vec) {
		_out_stream << "[Vec2 : " << _vec.x << ", " << _vec.y << "]";
		return _out_stream;
	}

	inline std::ostream & operator<<(std::ostream & _out_stream, const Vec2i & _vec) {
		_out_stream << "[Vec2i : " << _vec.x << ", " << _vec.y << "]";
		return _out_stream;
	}

	inline std::ostream & operator<<(std::ostream & _out_stream, const Vec3 & _vec) {
		_out_stream << "[Vec3 : " << _vec.x << ", " << _vec.y << ", " << _vec.z << "]";
		return _out_stream;
	}

	inline std::ostream & operator<<(std::ostream & _out_stream, const Vec4 & _vec) {
		_out_stream << "[Vec4 : " << _vec.x << ", " << _vec.y << ", " << _vec.z << ", " << _vec.w << "]";
		return _out_stream;
	}

}