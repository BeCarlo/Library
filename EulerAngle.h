#ifndef EULER_ANGLE_H
#define EULER_ANGLE_H

#include "CoreMacro.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TQuaternion;
	template<typename T> class TRMatrix;
	template<typename T> class TVector3D;

	template<typename T> class TEulerAngle : public TVector3D<T> {
	public:
		FINLINE T pitch() const { return this->getX(); }
		FINLINE T yaw() const { return this->getY(); }
		FINLINE T roll() const { return this->getZ(); }

		FINLINE TEulerAngle(const T x, const T y, const T z);
		FINLINE TEulerAngle(const TVector3D<T>& vector);
		FINLINE TEulerAngle(const TQuaternion<T>& quaternion);

		FINLINE TQuaternion<T> quaternion() const;

		FINLINE operator TVector3D<T>() const;
	};


}

#include "Quaternion.h"
#include "RotationMatrix.h"
#endif // !EULER_ANGLE_H

