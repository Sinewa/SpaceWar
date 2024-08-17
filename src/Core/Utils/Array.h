#pragma once

#include <vector>

namespace SWGame {
	template<typename T>
	class Array : public std::vector<T> {
	public:
		void FastErase(std::vector<T>::size_type n) {
			if (n < 0 || n > std::vector<T>::size() - 1) {
				return;
			}

			if (n == std::vector<T>::size() - 1) {
				std::vector<T>::pop_back();
				return;
			}

			std::vector<T>::at(n) = std::vector<T>::at(std::vector<T>::size() - 1);
			std::vector<T>::pop_back();

		}
	};
}