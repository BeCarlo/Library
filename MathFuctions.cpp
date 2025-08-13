#include "MathFuctions.h"

#include "math.h"

namespace Math {
	namespace Fuctions {

		template<class T> constexpr FINLINE T abs(const T number) {
			return (number < (T)0) ? -number : number;
		}

		template<class T> constexpr FINLINE double tSin(const T number) {
			static_assert((double)number, "T must be castable to double");
			return sin(number);
		}
		template<class T> constexpr FINLINE double tCos(const T number) {
			static_assert((double)number, "T must be castable to double");
			return cos(number);
		}
	}
}