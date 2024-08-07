#include "BaseControllerComponent.h"

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	void BaseControllerComponent::SetTranslation(const PosF& translation) {
		m_pOwner->SetTranslation(translation);
	}
	//-----------------------------------------------------------
}