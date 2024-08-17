#pragma once

#include "src/Core/Utils/Array.h"

#include "src/Systems/Base/BaseSystem.h"


namespace SWGame {

	class PhysicsComponent;

	class PhysicsSystem : public BaseSystem {
	protected:
		Array<PhysicsComponent*> m_aPhysicsComps;
		bool m_bDebugActive = false;
	public:
		virtual void Update(float dt) override;
		virtual void OnDiag(float dt) override;
		
		void Register(PhysicsComponent* comp);
		void UnRegister(PhysicsComponent* comp);

	protected:
		bool CheckCollision(PhysicsComponent* lpc, PhysicsComponent* rpc);
	};
}