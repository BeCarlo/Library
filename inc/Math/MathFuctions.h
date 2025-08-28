#ifndef MATH_FUCTIONS_H
#define MATH_FUCTIONS_H

#include <type_traits>
#include "CoreMacro.h"

namespace Math {
	namespace Functions {
		template< class T > static constexpr FINLINE T tClamp(const T number, const T min, const T max);

		template< class T > static constexpr FINLINE T tSqrt(const T number);
		template< class T > static constexpr FINLINE T tAbs(const T number);
		template< class T > static constexpr FINLINE T tSquare(const T number);

		template<typename T> static constexpr FINLINE T tSin(T number);
		template<typename T> static constexpr FINLINE T tCos(T number);
		template<typename T> static constexpr FINLINE T tACos(T number);
		template<typename T> static constexpr FINLINE T tAtan2(T x, T y); 


	}
}

//implementation

namespace Math {
	namespace Functions {
		template<class T> constexpr T tClamp(const T number, const T min, const T max) {
			const bool isMin = min > number;
			const bool isMax = max < number;
			const bool isBeteewn = !(isMin || isMax);

			return (isBeteewn * number) + (isMin * min) + (isMax * max);
		}
		template<class T> constexpr FINLINE T tSqrt(const T number) {
			static_assert(std::is_convertible_v<T, double>, "T must be castable to double");
			static_assert(std::is_convertible_v<double, T>, "T must be castabled from double");
			return static_cast<T>(sqrt(number));
		}

		template<class T> constexpr FINLINE T tAbs(const T number) {
			return (number < (T)0) ? -number : number;
		}

		template<class T> constexpr FINLINE T tSquare(const T number) {
			return number * number;
		}

		template<typename T> constexpr FINLINE T tSin(T number) {
			static_assert(std::is_convertible_v<T, double>, "T must be castable to double");
			static_assert(std::is_convertible_v<double, T>, "T must be castabled from double");
			return static_cast<T>(sin(number));
		}

		template<typename T> constexpr FINLINE T tCos(T number) {
			static_assert(std::is_convertible_v<T, double>, "T must be castable to double");
			static_assert(std::is_convertible_v<double, T>, "T must be castabled from double");
			return static_cast<T>(cos(number));
		}

		template<typename T> constexpr FINLINE T tACos(T number) {
			static_assert(std::is_convertible_v<T, double>, "T must be castable to double");
			static_assert(std::is_convertible_v<double, T>, "T must be castabled from double");
			return static_cast<T>(acos(number));
		}

		template<typename T> constexpr FINLINE T tAtan2(T x, T y) {
			static_assert(std::is_convertible_v<T, double>, "T must be castable to double");
			static_assert(std::is_convertible_v<double, T>, "T must be castabled from double");
			return static_cast<T>(atan2(x, y));
		}
	}
}


#endif // !MATH_FUCTIONS_H
