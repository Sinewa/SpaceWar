#pragma once

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseControllerComponent : public Component {
	protected:
		float m_fSpeed = 200.f;
		float m_fRotationSpeed = 180.f;
	public:
		void SetSpeed(float speed);
		void SetRotationSpeed(float speed);
	protected:
		void SetTranslation(const VecF& translation);
		void SetTransform(const Transformation& transform);

		VecF GetFrontVector();
	};
}