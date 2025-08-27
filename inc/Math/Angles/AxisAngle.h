#ifndef AXIS_ANGLE_H
#define AXIS_ANGLE_H

#include "CoreMacro.h"
#include "Vector3D.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {
	
	template<typename T> class TQuaternion;


	template<typename T> class TAxisAngle {
		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		TVector3D<T> _axis;
		T _angle;

	public:
		TAxisAngle() = default;
		FINLINE TAxisAngle(const TVector3D<T>& axis, T angle);
		FINLINE TAxisAngle(const TQuaternion<T>& quaternion);

		FINLINE TQuaternion<T> quaternion() const;

		FINLINE TVector3D<T> getAxis() const;
		FINLINE T getAngle() const;

		FINLINE void setAxis(const TVector3D<T>& axis);
		FINLINE void setAngle(T angle);
	};
}

#include "Quaternion.h"

#endif // !AXIS_ANGLE_H

