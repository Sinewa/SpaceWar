#include "BaseControllerComponent.h"

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	//-----------------------------------------------------------
	void BaseControllerComponent::SetTranslation(const VecF& translation) {
		m_pOwner->SetTranslation(translation);
	}
	//-----------------------------------------------------------
	void BaseControllerComponent::SetTransform(const Transformation& transform){
		m_pOwner->SetTransform(transform);
	}
	//-----------------------------------------------------------
	VecF BaseControllerComponent::GetFrontVector() {
		auto transform = m_pOwner->GetTransform();
		float sRot = sinf(ToRadians(transform.m_rotation));
		float cRot = cosf(ToRadians(transform.m_rotation));

		return transform.m_position + VecF{ cRot, sRot };
	}
	//-----------------------------------------------------------


}