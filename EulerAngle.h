#ifndef EULER_ANGLE_H
#define EULER_ANGLE_H

#include "Vector3D.h"
#include "MathAngle.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TEulerAngle : public TVector3D<T> {
	public:
		FINLINE T yaw() const { return this->getX(); }
		FINLINE T pitch() const { return this->getY(); }
		FINLINE T roll() const { return this->getZ(); }


		FINLINE TQuaternion<T> Quanternion() const;
	};


	template<typename T> FINLINE TQuaternion<T> TEulerAngle<T>::Quanternion() const {
		return TQuaternion<T>(
			tSin(roll() / 2) * tCos(pitch() / 2) * tCos(yaw() / 2)
			- tCos(roll() / 2) * tSin(pitch() / 2) * tSin(yaw() / 2),

			tCos(roll() / 2) * tSin(pitch() / 2) * tSin(yaw() / 2)
			+ tSin(roll() / 2) * tCos(pitch() / 2) * tCos(yaw() / 2),

			tCos(roll() / 2) * tCos(pitch() / 2) * tSin(yaw() / 2)
			- tSin(roll() / 2) * tSin(pitch() / 2) * tCos(yaw() / 2),

			tCos(roll() / 2) * tCos(pitch() / 2) * tCos(yaw() / 2)
			+ tSin(roll() / 2) * tSin(pitch() / 2) * tSin(yaw() / 2)
		);

	}
}
#endif // !EULER_ANGLE_H

