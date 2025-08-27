#ifndef QUATERNION_H
#define QUATERNION_H

#include <type_traits>
#include "CoreMacro.h"
#include "AxisAngle.h"
#include "EulerAngle.h"
#include "RotationMatrix.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TQuaternion {
		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		struct {
			T _x;
			T _y;
			T _z;
			T _w;
		};

	public:

		TQuaternion() = default;
		FINLINE TQuaternion(T x, T y, T z, T w);
		FINLINE TQuaternion(const TVector3D<T>& vector, T w);

		FINLINE TQuaternion(const TAxisAngle<T>& axisAngle);
		FINLINE TQuaternion(const TEulerAngle<T>& eulerAngle);
		FINLINE TQuaternion(const TRMatrix<T>& matrix);

		FINLINE TVector3D<T> vector3D() const;
		FINLINE TAxisAngle<T> axisAngle() const;
		FINLINE TEulerAngle<T> eulerAngle() const;
		FINLINE TRMatrix<T> rotationMatrix() const;

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

		/**  @return right direction after it has been rotated */
		FINLINE TVector3D<T> getAxisX() const;

		/**  @return up direction after it has been rotated */
		FINLINE TVector3D<T> getAxisY() const;

		/**  @return forward direction after it has been rotated */
		FINLINE TVector3D<T> getAxisZ() const;

		/**  @return right direction after it has been rotated */
		FINLINE TVector3D<T> getRightVector() const { return getAxisX(); }

		/**  @return up direction after it has been rotated */
		FINLINE TVector3D<T> getUpVector() const { return getAxisY(); }

		/**  @return forward direction after it has been rotated */
		FINLINE TVector3D<T> getForwardVector() const { return getAxisZ(); }

		FINLINE TVector3D<T> operator *(const TVector3D<T>& vector) const;
		FINLINE TVector3D<T> rotate(const TVector3D<T>& vector) const;
		FINLINE TVector3D<T> unRotate(const TVector3D<T>& vector) const;

		FINLINE T squaredNorm() const;

		FINLINE T norm() const;

		//in-place scaling
		FINLINE void operator *=(const T k);
		//out-of-place scaling
		FINLINE TQuaternion<T> operator *(const T k) const;

		FINLINE TQuaternion<T> lerp(const TQuaternion<T>& vector, T k) const;
		FINLINE static TQuaternion<T> lerp(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB, T k);
		FINLINE TQuaternion<T> nLerp(const TQuaternion<T>& vector, T k) const { return this->lerp(vector, k).normalized(); }
		FINLINE static TQuaternion<T> nLerp(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB, T k) { return vectorA.lerp(vectorB, k).normalized(); }
		FINLINE TQuaternion<T> slerp(const TQuaternion<T>& vector, T k) const { return this->nLerp(vector, k); }
		FINLINE static TQuaternion<T> slerp(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB, T k) { return vectorA.nLerp(vectorB, k); }

		//in-place
		FINLINE TQuaternion<T> normalize();
		//out-of-place 
		FINLINE TQuaternion<T> normalized() const;

		//in-place
		FINLINE TQuaternion<T> conjugate();
		//out-place
		FINLINE TQuaternion<T> conjugated() const;

		FINLINE T dot(const TQuaternion<T>& vector) const;
		FINLINE static T dot(const TQuaternion<T>& vectorA, const TQuaternion<T>& vectorB);

		//in-place operations
		FINLINE void operator *=(const TQuaternion<T>& vector);

		//out-place operations
		FINLINE TQuaternion<T> operator *(const TQuaternion<T>& vector) const;

		FINLINE bool operator ==(const TQuaternion<T>& vector) const;
		FINLINE bool equals(const TQuaternion<T>& vector, T tolerance = epsilon) const;

		FINLINE void print() const;
	};

	template<typename T> FINLINE static TQuaternion<T> operator *(const T k, const TQuaternion<T>& vector);

}

#endif // !QUATERNION_H
