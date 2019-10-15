template<typename T, size_t N>
prevmath::Vector<T, N>::Vector() {
	std::memset(reinterpret_cast<void *>(_raw_vector), 0, sizeof(T) * N);
}

template<typename T, size_t N>
prevmath::Vector<T, N>::Vector(T * _elements) {
	std::memcpy(reinterpret_cast<void *>(_raw_vector), reinterpret_cast<const void *>(_elements), sizeof(T) * N);
}