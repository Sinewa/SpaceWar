#pragma once 

namespace SWGame {
	template<typename T>
	struct Position {
		T x;
		T y;
		T z;
	};

	typedef Position<float> PosF;
	typedef Position<int> PosI;
}