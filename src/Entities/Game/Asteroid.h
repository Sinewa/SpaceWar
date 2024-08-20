#pragma once 

#include "src/Entities/Base/BaseEntity.h"

namespace SWGame {
	class Asteroid : public BaseEntity {
	protected:
		int m_size = 1;
	public:
		virtual void OnDelete() override;
		void SetSize(float size);
	};
}