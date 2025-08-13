#ifndef MATH_FUCTIONS_H
#define MATH_FUCTIONS_H

#include "CoreMacro.h"

namespace Math {
	namespace Funtions {

		template< class T > static constexpr FINLINE T abs(const T number);

		template<class T> static constexpr FINLINE double tSin(const T number);
		template<class T> static constexpr FINLINE double tCos(const T number);
	}
}


#endif // !MATH_FUCTIONS_H
