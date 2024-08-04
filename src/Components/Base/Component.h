#pragma once 

namespace SWGame {
	class BaseEntity;

	class Component {
	public:
		virtual void Update(BaseEntity* owner, float dt);
	};
}