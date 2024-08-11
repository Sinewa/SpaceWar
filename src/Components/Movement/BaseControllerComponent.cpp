#include "BaseControllerComponent.h"

#include <cmath>

#include "src/Entities/Base/BaseEntity.h"
#include "src/Core/Game.h"

namespace SWGame {
	//-----------------------------------------------------------
	void BaseControllerComponent::SetTranslation(const VecF& translation) {
		auto size = Game::GetGame()->GetGameAreaSize();
		VecF actualTranslation = translation ;
		actualTranslation.x = std::fmod(actualTranslation.x > 0 ? actualTranslation.x : actualTranslation.x + size.x, size.x);
		actualTranslation.y = std::fmod(actualTranslation.y > 0 ? actualTranslation.y : actualTranslation.y + size.y, size.y);
		
		m_pOwner->SetTranslation(actualTranslation);
	}
	//-----------------------------------------------------------
	void BaseControllerComponent::SetTransform(const Transformation& transform){
		auto size = Game::GetGame()->GetGameAreaSize();
		VecF actualTranslation = transform.GetPosition();
		actualTranslation.x = std::fmod(actualTranslation.x > 0 ? actualTranslation.x : actualTranslation.x + size.x, size.x);
		actualTranslation.y = std::fmod(actualTranslation.y > 0 ? actualTranslation.y : actualTranslation.y + size.y, size.y);
		m_pOwner->SetTransform({actualTranslation, transform.GetRotation()});
	}
	//-----------------------------------------------------------
	VecF BaseControllerComponent::GetFrontVector() {
		auto transform = m_pOwner->GetTransform();
		float sRot = sinf(ToRadians(transform.m_rotation));
		float cRot = cosf(ToRadians(transform.m_rotation));

		return VecF{ -sRot, cRot };
	}
	//-----------------------------------------------------------
	void BaseControllerComponent::SetSpeed(float speed) {
		m_fSpeed = speed;
	}
	//-----------------------------------------------------------
	void BaseControllerComponent::SetRotationSpeed(float speed) {
		m_fRotationSpeed = speed;
	}
	//-----------------------------------------------------------


}