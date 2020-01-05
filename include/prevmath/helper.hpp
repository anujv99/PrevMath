
#include <iostream>

#include "vector/vec2.hpp"
#include "vector/vec2i.hpp"
#include "vector/vec3.hpp"
#include "vector/vec4.hpp"

namespace prevmath {

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