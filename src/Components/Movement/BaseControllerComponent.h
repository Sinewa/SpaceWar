#pragma once

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Transformations.h"

namespace SWGame {
	class BaseControllerComponent : public Component {
	protected:
		float m_fSpeed = 100.f;
		float m_fRotationSpeed = 90.f;
	public:
	protected:
		void SetTranslation(const VecF& translation);
		void SetTransform(const Transformation& transform);

		VecF GetFrontVector();
	};
}