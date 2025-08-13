#ifndef QUATERNION_H
#define QUATERNION_H
	
#include "Vector4D.h"
#include "MathAngle.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TQuaternion : public TVector4D<T> {
	public:
		explicit TQuaternion(const TVector4D<T>& vector);

		explicit TQuaternion(const TEulerAngle<T>& eulerAngle);
	};

	template<typename T> TQuaternion<T>::TQuaternion(const TEulerAngle<T>& eulerAngle) {
		*this = eulerAngle.Quanternion();
	}
}

#endif // !QUATERNION_H
