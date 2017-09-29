#pragma once
#include <string.h>
namespace Core {
	class Vector3D;
	class Matrix3D{

	public:
		inline Matrix3D() = default;
		inline Matrix3D(const Matrix3D& matrix) {
			memcpy(m, matrix.m, 9 * sizeof(double));
		}
		inline Matrix3D(double m00, double m01, double m02,
			double m10, double m11, double m12,
			double m20, double m21, double m22)
		{
			m[0][0] = m00;
			m[0][1] = m01;
			m[0][2] = m02;
			m[1][0] = m10;
			m[1][1] = m11;
			m[1][2] = m12;
			m[2][0] = m20;
			m[2][1] = m21;
			m[2][2] = m22;
		}
		inline const double* operator[] (size_t row) const
		{
			return m[row];
		}
		inline double* operator[] (size_t row)
		{
			return m[row];
		}

		inline Vector3D getColumn(size_t col) const;
		inline void setColumn(size_t col, const Vector3D& vec);
		inline void fromAxes(const Vector3D& xAxis, const Vector3D& yAxis, const Vector3D& zAxis);
		
		inline Matrix3D& operator= (const Matrix3D& rkMatrix)
		{
			memcpy(m, rkMatrix.m, 9 * sizeof(double));
			return *this;
		}
		
		inline bool operator== (const Matrix3D& rkMatrix) const;
		inline bool operator!= (const Matrix3D& rkMatrix) const
		{
			return !operator==(rkMatrix);
		}
		
		inline Matrix3D operator+ (const Matrix3D& rkMatrix) const;
		inline Matrix3D operator- (const Matrix3D& rkMatrix) const;
		inline Matrix3D operator* (const Matrix3D& rkMatrix) const;
		inline Matrix3D operator- () const;
		inline Vector3D operator* (const Vector3D& rkVector) const;
		inline friend Vector3D operator* (const Vector3D& vec, const Matrix3D& matrix);
		inline friend Matrix3D operator* (double scale, const Matrix3D& rhs);
		inline Matrix3D operator* (double scale) const;

		Matrix3D transpose() const;
		bool inverse(Matrix3D& rkInverse, double fTolerance = 1e-06) const;
		Matrix3D inverse(double fTolerance = 1e-06) const;
		double determinant() const;		
		
		void toAngleAxis(Vector3D& rkAxis, float& rfAngle) const;
		void toAngleAxis(Vector3D& rkAxis, float& rfAngle) const {
			float r;
			toAngleAxis(rkAxis, r);
			rfAngle = r;
		}
		void fromAngleAxis(const Vector3D& rkAxis, const double& fRadians);
		static const Matrix3D Zero;
		static const Matrix3D Identity;
	protected:
		friend class Matrix4D;
		friend class Quaternion;
		double m[3][3];
	};
}