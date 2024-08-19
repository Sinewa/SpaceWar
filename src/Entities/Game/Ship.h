#pragma once

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	class Ship : public BaseEntity {
	protected:
	public:
		virtual void OnDelete() override;

		void Destroy();
	};
}