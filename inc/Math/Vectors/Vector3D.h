#ifndef VECTOR_3D_H
#define VECTOR_3D_H

#include <type_traits>
#include "CoreMacro.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TQuaternion;

	template<typename T> class TVector3D {
		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		struct {
			T _x;
			T _y;
			T _z;
		};

	public:

		TVector3D() = default;
		FINLINE TVector3D(T x, T y, T z);


		FINLINE T getX() const;
		FINLINE T getY() const;
		FINLINE T getZ() const;
		FINLINE T X() const { return getX(); }
		FINLINE T Y() const { return getY(); }
		FINLINE T Z() const { return getZ(); }

		FINLINE void setX(const T x);
		FINLINE void setY(const T y);
		FINLINE void setZ(const T z);
		FINLINE void X(const T x) { setX(x); }
		FINLINE void Y(const T y) { setY(y); }
		FINLINE void Z(const T z) { setZ(z); }

		/** @return Zero Vector (0,0,0) */
		static const TVector3D<T> zeroVector;

		/** @return One Vector (1,1,1) */
		static const TVector3D<T> oneVector;

		/** @return Right Vector (1,0,0) */
		static const TVector3D<T> rightVector;

		/** @return Left Vector (-1,0,0) */
		static const TVector3D<T> leftVector;

		/** @return Up Vector (0,1,0) */
		static const TVector3D<T> upVector;

		/** @return Down Vector (0,-1,0) */
		static const TVector3D<T> downVector;

		/** @return Forward Vector (0,0,1) */
		static const TVector3D<T> forwardVector;

		/** @return Backward Vector (0,0,-1) */
		static const TVector3D<T> backwardVector;

		FINLINE static TVector3D<T> origin() { return zeroVector; }

		FINLINE T squaredNorm() const;

		FINLINE T norm() const;

		//in-place scaling
		FINLINE void operator *=(const T k);
		//out-of-place scaling
		FINLINE TVector3D<T> operator *(const T k) const;

		//in-place
		FINLINE TVector3D<T> normalize();
		//out-of-place 
		FINLINE TVector3D<T> normalized() const;

		FINLINE TVector3D<T> lerp(const TVector3D<T>& vector, T k);
		FINLINE static TVector3D<T> lerp(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB, T k);

		//in-place
		FINLINE void operator ^=(const TVector3D<T>& vector);
		FINLINE void cross(const TVector3D<T>& vector) { *this ^= vector; }
		//out-of-place
		FINLINE TVector3D<T> operator ^(const TVector3D<T>& vector) const;
		FINLINE TVector3D<T> crossed(const TVector3D<T>& vector) const { return *this ^ vector; }
		FINLINE static TVector3D<T> crossProduct(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB);

		FINLINE T dot(const TVector3D<T>& vector) const;
		FINLINE static T dot(const TVector3D<T>& vectorA, const TVector3D<T>& vectorB);

		//in-place operations
		FINLINE void operator +=(const TVector3D<T>& vector);
		FINLINE void operator -=(const TVector3D<T>& vector);

		//out-place operations
		FINLINE TVector3D<T> operator +(const TVector3D<T>& vector);
		FINLINE TVector3D<T> operator -(const TVector3D<T>& vector);

		FINLINE bool operator ==(const TVector3D<T>& vector) const;
		FINLINE bool equals(const TVector3D<T>& vector, T tolerance = epsilon) const;

		FINLINE void print();

	};

	template<typename T> inline static TVector3D<T> operator *(const T k, const TVector3D<T>& vector);
}

#endif // !VECTOR_3D_H
