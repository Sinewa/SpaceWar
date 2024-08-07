#pragma once 

namespace SWGame {

	template<typename T>
	struct Vector2 {
		T x;
		T y;

		Vector2<T>& operator* (float num) {
			x *= num;
			y *= num;
			return *this;
		}

		Vector2<T>& operator- (const Vector2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}	
		Vector2<T>& operator-= (const Vector2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}
		Vector2<T>& operator+ (const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}	
		Vector2<T>& operator+= (const Vector2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}
	};

	typedef Vector2<float> VecF;
	
	struct Transformation {
		VecF m_position;
		//In degrees
		float m_rotation;

		const VecF& GetPosition() const { return m_position; }
		const float& GetRotation() const { return m_rotation; }
	};

}