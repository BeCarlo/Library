#ifndef ROTATION_MATRIX_H
#define ROTATION_MATRIX_H

#include <type_traits>
#include "CoreMacro.h"
#include "MathVariable.h"
#include "MathFuctions.h"

namespace Math {

	template<typename T> class TQuaternion;

	enum MatrixElement {
		E00, E01, E02, E03,
		E10, E11, E12, E13,
		E20, E21, E22, E23,
		E30, E31, E32, E33
	};

	enum MatrixElements {
		ROW0,
		ROW1,
		ROW2,
		ROW3,
		COL0,
		COL1,
		COL2,
		COL3
	};

	template<typename T> class TRMatrix {
		static_assert(std::is_floating_point_v<T>, "T must be floating point");

		T _matrix[4][4];

	public:

		TRMatrix() = default;

		/** @param Quaternions as Vectors4D */
		FINLINE TRMatrix(const TQuaternion<T>& x, const TQuaternion<T>& y, const TQuaternion<T>& z, const TQuaternion<T>& w);
		/** */
		FINLINE TRMatrix(const TQuaternion<T>& quaternion);

		FINLINE TQuaternion<T> quaternion();


		FINLINE T getElement(const MatrixElement elementPosition) const;
		/** @return Quaternion as Vector4D */
		FINLINE TQuaternion<T> getElements(const MatrixElements elementsPosition) const;

		FINLINE void setElement(const MatrixElement elementPosition, T element);
		/** @param Quaternion as a Vector4D */
		FINLINE void setElements(const MatrixElements elementsPosition, const TQuaternion<T>& elements);


		FINLINE bool operator ==(const TRMatrix<T>& matrix) const;
		FINLINE bool equals(const TRMatrix<T>& matrix, T tolerance = epsilon) const;
	};

}

#include "Quaternion.h"

#endif // !ROTATION_MATRIX_H

