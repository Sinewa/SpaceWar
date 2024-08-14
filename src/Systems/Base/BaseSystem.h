#pragma once

namespace SWGame {
	class BaseSystem {
	public:
		virtual void Update(float dt);
		virtual void OnDiag(float dt){}
	};
}