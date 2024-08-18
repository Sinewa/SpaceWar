#pragma once

namespace SWGame {
	class World;

	class BaseSystem {
		World* m_pWorld;
	public:
		virtual void Init(World* world);
		virtual void Update(float dt);
		virtual void OnDiag(float dt){}

		World* GetWorld() const;
	};
}