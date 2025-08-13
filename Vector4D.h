#ifndef VECTOR_4D_H
#define VECTOR_4D_H

#include "CoreMacro.h"
#include "MathVariable.h"
#include <type_traits>

namespace Math {

	template<typename T> class TVector4D {
		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		struct {
			T _x;
			T _y;
			T _z;
			T _w;
		};

	public:

		TVector4D() = default;
		FINLINE TVector4D(T x, T y, T z, T w);

		FINLINE T getX() const;
		FINLINE T getY() const;
		FINLINE T getZ() const;
		FINLINE T getW() const;
		FINLINE T X() const { return getX(); }
		FINLINE T Y() const { return getY(); }
		FINLINE T Z() const { return getZ(); }
		FINLINE T W() const { return getW(); }

		FINLINE void setX(const T x);
		FINLINE void setY(const T y);
		FINLINE void setZ(const T z);
		FINLINE void setW(const T w);
		FINLINE void X(const T x) { setX(x); }
		FINLINE void Y(const T y) { setY(y); }
		FINLINE void Z(const T z) { setZ(z); }
		FINLINE void W(const T w) { setW(w); }

		/** @return Zero Vector (0,0,0,0) */
		static const TVector4D<T> zeroVector;
		/** @return One Vector (1,1,1,1) */
		static const TVector4D<T> oneVector;

		FINLINE T squaredNorm() const;

		FINLINE T norm() const;

		//in-place scaling
		FINLINE void operator *=(const T k);
		//out-of-place scaling
		FINLINE TVector4D<T> operator *(const T k) const;
		FINLINE friend TVector4D<T> operator *(const T k, const TVector4D<T>& vector);

		FINLINE TVector4D<T> lerp(const TVector4D<T>& vector, T k);
		inline static TVector4D<T> lerp(const TVector4D<T>& vectorA, const TVector4D<T>& vectorB, T k);

		//in-place
		FINLINE TVector4D<T> normalize();
		//out-of-place 
		FINLINE TVector4D<T> normalized() const;

		FINLINE T dot(const TVector4D<T>& vector) const;
		inline static T dot(const TVector4D<T>& vectorA, const TVector4D<T>& vectorB);

		//in-place operations
		FINLINE void operator +=(const TVector4D<T>& vector);
		FINLINE void operator -=(const TVector4D<T>& vector);

		//out-place operations
		FINLINE TVector4D<T> operator +(const TVector4D<T>& vector);
		FINLINE TVector4D<T> operator -(const TVector4D<T>& vector);

		FINLINE bool operator ==(const TVector4D<T>& vector);
		FINLINE bool equals(const TVector4D<T>& vector, T tolerance = epsilon);

		FINLINE void print();
	};

}



#endif // !VECTOR_4D_H

