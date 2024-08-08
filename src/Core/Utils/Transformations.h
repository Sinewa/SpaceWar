#pragma once 

#include <cmath>

namespace SWGame {

	template<typename T>
	struct Vector2 {
		T x;
		T y;

		Vector2() = default;
		Vector2(T px, T py) :x(px), y(py){}

		Vector2<T> operator* (float num) {
			Vector2<T> result;
			result.x = x * num;
			result.y = y * num;
			return result;
		}

		Vector2<T> operator- (const Vector2& other) {
			Vector2<T> result;
			result.x = x - other.x;
			result.y = y - other.y;
			return result;
		}	
		Vector2<T>& operator-= (const Vector2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vector2<T> operator+ (const Vector2& other) {
			Vector2<T> result;
			result.x = x + other.x;
			result.y = y + other.y;
			return result;
		}	
		Vector2<T>& operator+= (const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		void Normalize() {
			float len = std::sqrt(x * x + y * y);
			x /= len;
			y /= len;
		}
	};

	typedef Vector2<float> VecF;
	typedef Vector2<int> VecI;
	typedef Vector2<unsigned int> VecU;
	
	struct Transformation {
		VecF m_position;
		//In degrees
		float m_rotation;

		const VecF& GetPosition() const { return m_position; }
		const float& GetRotation() const { return m_rotation; }
	};

}