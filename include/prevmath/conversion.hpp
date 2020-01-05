#pragma once

#include "vector/vec2.hpp"
#include "vector/vec2i.hpp"

namespace prevmath {

	inline Vec2 ToVec2(const Vec2i & _vec) {
		return Vec2(static_cast<pvfloat>(_vec.x), static_cast<pvfloat>(_vec.y));
	}

	inline Vec2i ToVec2i(const Vec2 & _vec) {
		return Vec2i(static_cast<pvint>(_vec.x), static_cast<pvint>(_vec.y));
	}

}