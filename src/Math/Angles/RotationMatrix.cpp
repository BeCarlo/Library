#include "RotationMatrix.h"

namespace Math {
	template<typename T> FINLINE TRMatrix<T>::TRMatrix(const TQuaternion<T>& x, const TQuaternion<T>& y, const TQuaternion<T>& z, const TQuaternion<T>& w) {
		_matrix[0][0] = x.getX();	_matrix[0][1] = y.getX();	_matrix[0][2] = z.getX(); _matrix[0][3] = w.getX();
		_matrix[1][0] = x.getY();	_matrix[1][1] = y.getY();	_matrix[1][2] = z.getY(); _matrix[1][3] = w.getY();
		_matrix[2][0] = x.getZ();	_matrix[2][1] = y.getZ();	_matrix[2][2] = z.getZ(); _matrix[2][3] = w.getZ();
		_matrix[3][0] = x.getW();	_matrix[3][1] = y.getW();	_matrix[3][2] = z.getW(); _matrix[3][3] = w.getW();
	}

	template<typename T> FINLINE TRMatrix<T>::TRMatrix(const TQuaternion<T>& quaternion) {
		*this = quaternion.rotationMatrix();
	}

	template<typename T> FINLINE TQuaternion<T> TRMatrix<T>::quaternion() {
		const T trace = _matrix[0][0] + _matrix[1][1] + _matrix[2][2];

		if (trace > 0.0f) {

			const T divisor = T(1.0) / (Functions::tSqrt(T(1.0) + trace) * T(2.0));
			const T x = (_matrix[2][1] - _matrix[1][2]) * divisor;
			const T y = (_matrix[0][2] - _matrix[2][0]) * divisor;
			const T z = (_matrix[1][0] - _matrix[0][1]) * divisor;
			const T w = T(0.25) / divisor;
			return TQuaternion<T>(x, y, z, w);
		}

		char dElement = 0;
		dElement = _matrix[1][1] > _matrix[0][0];
		dElement = _matrix[2][2] > _matrix[dElement][dElement] ? 2 : dElement;

		const char next[3] = { 1, 2, 0 };
		const char i = next[dElement];
		const char j = next[i];
		const T sqrt = Functions::tSqrt(T(1.0) + _matrix[dElement][dElement] - _matrix[i][i] - _matrix[j][j]);

		T quaternion[4];
		quaternion[dElement] = T(0.5) * sqrt;

		const T divisor = (T(1.0) / sqrt) * T(0.5);

		quaternion[i] = (_matrix[i][dElement] + _matrix[dElement][i]) * divisor;
		quaternion[j] = (_matrix[j][dElement] + _matrix[dElement][j]) * divisor;
		quaternion[3] = (_matrix[i][j] - _matrix[j][i]) * divisor;

		return TQuaternion<T>(quaternion[0], quaternion[1], quaternion[2], quaternion[3]);
	}

	template<typename T> FINLINE T TRMatrix<T>::getElement(const MatrixElement elementPosition) const {
		const int row = elementPosition / 4;
		const int col = elementPosition % 4;
		return _matrix[row][col];
	}

	template<typename T> FINLINE TQuaternion<T> TRMatrix<T>::getElements(const MatrixElements elementsPosition) const {
		const bool isARow = elementsPosition < 4;
		if(isARow)
			return TQuaternion<T>(_matrix[elementsPosition][0], _matrix[elementsPosition][1], _matrix[elementsPosition][2], _matrix[elementsPosition][3]);
		const int col = elementsPosition % 4;
		return TQuaternion<T>(_matrix[0][col], _matrix[1][col], _matrix[2][col], _matrix[3][col]);
	}

	template<typename T> FINLINE TVector3D<T> TRMatrix<T>::getElements3D(const MatrixElements elementsPosition) const {
		const bool isARow = elementsPosition < 4;
		if (isARow)
			return TVector3D<T>(_matrix[elementsPosition][0], _matrix[elementsPosition][1], _matrix[elementsPosition][2]);
		const int col = elementsPosition % 4;
		return TVector3D<T>(_matrix[0][col], _matrix[1][col], _matrix[2][col]);
	}

	template<typename T> FINLINE void TRMatrix<T>::setElement(const MatrixElement elementPosition, T elemen) {
		const int row = elementPosition / 4;
		const int col = elementPosition % 4;
		_matrix[row][col] = elemen;
	}

	template<typename T> FINLINE void TRMatrix<T>::setElements(const MatrixElements elementsPosition, const TQuaternion<T>& elements) {
		const bool isARow = elementsPosition < 4;
		if (isARow) {
			_matrix[elementsPosition][0] = elements.getX();
			_matrix[elementsPosition][1] = elements.getY();
			_matrix[elementsPosition][2] = elements.getZ();
			_matrix[elementsPosition][3] = elements.getW();
			return;
		}
		const int col = elementsPosition % 4;
		_matrix[0][col] = elements.getX();
		_matrix[1][col] = elements.getY();
		_matrix[2][col] = elements.getZ();
		_matrix[3][col] = elements.getW();
	}



	template<typename T> FINLINE TVector3D<T> TRMatrix<T>::operator*(const TVector3D<T>& vector) const {
		return { getElements3D(ROW0).dot(vector),getElements3D(ROW1).dot(vector), getElements3D(ROW2).dot(vector) };

	}

	template<typename T> FINLINE bool TRMatrix<T>::operator==(const TRMatrix<T>& matrix) const {
		return equals(matrix);
	}

	template<typename T> FINLINE bool TRMatrix<T>::equals(const TRMatrix<T>& matrix, T tolerance) const {
		const bool isXEqual = getElements(COL0).equals(matrix.getElements(COL0));
		const bool isYEqual = getElements(COL1).equals(matrix.getElements(COL1));
		const bool isZEqual = getElements(COL2).equals(matrix.getElements(COL2));
		const bool isWEqual = getElements(COL3).equals(matrix.getElements(COL3));

		return isXEqual && isYEqual && isZEqual && isWEqual;
	}
}