
template<typename T, typename P>
inline pvfloat Pow(const T & _val, const P & _power) {
	return static_cast<pvfloat>(std::pow(_val, _power));
}

template<typename T>
inline pvfloat Sqrt(const T & _val) {
	return static_cast<pvfloat>(std::sqrt(_val));
}

template<typename T>
inline T Max(const T & _val1, const T & _val2) {
	return std::max(_val1, _val2);
}

template<typename T>
inline T Min(const T & _val1, const T & _val2) {
	return std::min(_val1, _val2);
}

template<typename T>
inline T Abs(const T & _val) {
	return std::abs(_val);
}

template<typename T>
inline pvfloat Lerp(const T & _val1, const T & _val2, const pvfloat & _factor) {
	pvfloat _new_factor = Clamp<pvfloat>(_factor, 0.0f, 1.0f);
	return (_val1) + ((_val2 - _val1) * _new_factor);
}

template<typename T>
inline T Clamp(const T & _val, const T & _min, const T & _max) {
	return std::clamp(_val, _min, _max);
}

template<typename T>
inline pvfloat ToDegrees(const T & _val) {
	return static_cast<pvfloat>(_val) * PV_180_PI;
}

template<typename T>
inline pvfloat ToRadians(const T & _val) {
	return static_cast<pvfloat>(_val) * PV_PI_180;
}

template<typename T>
inline pvfloat Sin(const T & _val) {
	#ifdef PREV_MATH_DEGREES
		pvfloat _sine = std::sin(ToRadians(_val));
	#elif PREV_MATH_RADIANS
		pvfloat sine = std::sin(_val);
	#endif

	if (Abs(_sine) <= std::numeric_limits<pvfloat>::epsilon()) {
		return 0;
	} else if (static_cast<pvfloat>(1.0) - _sine <= std::numeric_limits<pvfloat>::epsilon()) {
		return static_cast<pvfloat>(1.0);
	} else if (static_cast<pvfloat>(1.0) + _sine <= std::numeric_limits<pvfloat>::epsilon()) {
		return static_cast<pvfloat>(-1.0);
	}

	return _sine;
}

template<typename T>
inline pvfloat Cos(const T & _val) {
	#ifdef PREV_MATH_DEGREES
		pvfloat _cosine = std::cos(ToRadians(_val));
	#elif PREV_MATH_RADIANS
		pvfloat cosine = std::cos(_val);
	#endif

	if (Abs(_cosine) <= std::numeric_limits<pvfloat>::epsilon()) {
		return 0;
	} else if (static_cast<pvfloat>(1.0) - _cosine <= std::numeric_limits<pvfloat>::epsilon()) {
		return static_cast<pvfloat>(1.0);
	} else if (static_cast<pvfloat>(1.0) + _cosine <= std::numeric_limits<pvfloat>::epsilon()) {
		return static_cast<pvfloat>(-1.0);
	}

	return _cosine;
}
