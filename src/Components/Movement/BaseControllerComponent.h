#pragma once

#include "src/Components/Base/Component.h"
#include "src/Core/Utils/Position.h"

namespace SWGame {
	class BaseControllerComponent : public Component {
	protected:
		float m_fSpeed = 10.f;
	public:
	protected:
		void SetTranslation(const PosF& translation);
	};
}