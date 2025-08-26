#ifndef VECTOR_2D_H
#define VECTOR_2D_H

#include "CoreMacro.h"
#include "MathVariable.h"
#include <type_traits>

namespace Math {

	template<typename T> class TVector2D {

		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		struct {
			T _x;
			T _y;
		};

	public:

		TVector2D() = default;

		FINLINE TVector2D(T x, T y);

		FINLINE T getX() const;
		FINLINE T getY() const;
		FINLINE T X() const { return getX(); }
		FINLINE T Y() const { return getY(); }

		FINLINE void setX(const T x);
		FINLINE void setY(const T y);
		FINLINE void X(const T x) { setX(x); }
		FINLINE void Y(const T y) { setY(y); }

		/** @return Zero Vector (0,0) */
		static const TVector2D<T> zeroVector;

		/** @return One Vector (1,1) */
		static const TVector2D<T> oneVector;

		/** @return Right Vector (1,0) */
		static const TVector2D<T> rightVector;

		/** @return Left Vector (-1,0) */
		static const TVector2D<T> leftVector;

		/** @return Up Vector (0,1) */
		static const TVector2D<T> upVector;

		/** @return Down Vector (0,-1) */
		static const TVector2D<T> downVector;

		FINLINE static TVector2D<T> origin() { return zeroVector; }

		FINLINE T squaredNorm() const;

		FINLINE T norm() const;

		//in-place scaling
		FINLINE void operator *=(const T k);
		//out-of-place scaling
		FINLINE TVector2D<T> operator *(const T k) const;

		//in-place
		FINLINE TVector2D<T> normalize();
		//out-of-place 
		FINLINE TVector2D<T> normalized() const;

		FINLINE TVector2D<T> lerp(const TVector2D<T>& vector, T k);
		FINLINE static TVector2D<T> lerp(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB, T k);

		//out-of-place
		FINLINE T operator ^(const TVector2D<T>& vector) const;
		FINLINE T crossed(const TVector2D<T>& vector) const { return *this ^ vector; }
		FINLINE static T crossProduct(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB);

		FINLINE T dot(const TVector2D<T>& vector) const;
		FINLINE static T dot(const TVector2D<T>& vectorA, const TVector2D<T>& vectorB);

		//in-place operations
		FINLINE void operator +=(const TVector2D<T>& vector);
		FINLINE void operator -=(const TVector2D<T>& vector);

		//out-place operations
		FINLINE TVector2D<T> operator +(const TVector2D<T>& vector);
		FINLINE TVector2D<T> operator -(const TVector2D<T>& vector);

		FINLINE bool operator ==(const TVector2D<T>& vector) const;
		FINLINE bool equals(const TVector2D<T>& vector, T tolerance = epsilon) const;

		FINLINE void print();
	};

	template<typename T> inline static TVector2D<T> operator *(const T k, const TVector2D<T>& vector);

}
#endif // !VECTOR_2D_H
