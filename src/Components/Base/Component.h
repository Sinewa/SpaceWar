#pragma once 

namespace SWGame {
	class CoreEntity;

	class Component {
	public:
		virtual void Update(CoreEntity* owner, float dt);
	};
}