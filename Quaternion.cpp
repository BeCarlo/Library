#include "Quaternion.h"
#include "MathAngle.h"

namespace Math {
	template<typename T> TQuaternion<T>::TQuaternion(const TVector4D<T>& vector) {
		*this = vector;
	}


}