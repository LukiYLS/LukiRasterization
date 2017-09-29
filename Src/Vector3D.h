#pragma once
#include <math.h>
#include <algorithm>
#include "Vector2D.h"
#define math_tolerance 1e-14
#define math_tolerancef 1e-6
namespace Core {

	class Vector4D;
	class Matrix4D;
	class Vector3D
	{
	public:
		double x, y, z;
	public:
	
		inline Vector3D();
		Vector3D(const Vector4D& v4_);
		Vector3D(const double& x_, const double& y_, const double& z_);
		

		~Vector3D();

		void operator=(const Vector4D& vec);		

	public:
		inline explicit Vector3D(const int coord[3])
		{
			x = (double)coord[0];
			y = (double)coord[1];
			z = (double)coord[2];
		}

		inline explicit Vector3D(double* const r)
			: x(r[0]), y(r[1]), z(r[2])
		{
		}

		inline explicit Vector3D(const double scaler)
			: x(scaler)
			, y(scaler)
			, z(scaler)
		{
		}

		inline Vector2D xy() const
		{
			return Vector2D(x, y);
		}
		
		inline void swap(Vector3D& other)
		{
			std::swap(x, other.x);
			std::swap(y, other.y);
			std::swap(z, other.z);
		}

		inline double operator [] (const size_t i) const
		{
			return *(&x + i);
		}

		inline double& operator [] (const size_t i)
		{
			return *(&x + i);
		}		
		inline double* ptr()
		{
			return &x;
		}		
		inline const double* ptr() const
		{
			return &x;
		}

		inline Vector3D& operator = (const Vector3D& rhs)
		{
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}

		inline Vector3D& operator = (const double scale)
		{
			x = scale;
			y = scale;
			z = scale;

			return *this;
		}

		inline bool operator == (const Vector3D& rhs) const
		{
			return (x == rhs.x && y == rhs.y && z == rhs.z);
		}

		inline bool operator != (const Vector3D& rhs) const
		{
			return (x != rhs.x || y != rhs.y || z != rhs.z);
		}

		// arithmetic operations
		inline Vector3D operator + (const Vector3D& rhs) const
		{
			return Vector3D(
				x + rhs.x,
				y + rhs.y,
				z + rhs.z);
		}

		inline Vector3D operator - (const Vector3D& rhs) const
		{
			return Vector3D(
				x - rhs.x,
				y - rhs.y,
				z - rhs.z);
		}

		inline Vector3D operator * (const double scale) const
		{
			return Vector3D(
				x * scale,
				y * scale,
				z * scale);
		}

		inline Vector3D operator * (const Vector3D& rhs) const
		{
			return Vector3D(
				x * rhs.x,
				y * rhs.y,
				z * rhs.z);
		}

		inline Vector3D operator / (const double scale) const
		{		

			double fInv = 1.0f / scale;

			return Vector3D(
				x * fInv,
				y * fInv,
				z * fInv);
		}

		inline Vector3D operator / (const Vector3D& rhs) const
		{
			return Vector3D(
				x / rhs.x,
				y / rhs.y,
				z / rhs.z);
		}

		inline const Vector3D& operator + () const
		{
			return *this;
		}

		inline Vector3D operator - () const
		{
			return Vector3D(-x, -y, -z);
		}
		inline Vector3D& operator += (const Vector3D& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;

			return *this;
		}

		inline Vector3D& operator += (const double scale)
		{
			x += scale;
			y += scale;
			z += scale;
			return *this;
		}

		inline Vector3D& operator -= (const Vector3D& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;

			return *this;
		}

		inline Vector3D& operator -= (const double scale)
		{
			x -= scale;
			y -= scale;
			z -= scale;
			return *this;
		}

		inline Vector3D& operator *= (const double scale)
		{
			x *= scale;
			y *= scale;
			z *= scale;
			return *this;
		}

		inline Vector3D& operator *= (const Vector3D& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;

			return *this;
		}

		inline Vector3D& operator /= (const Vector3D& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;

			return *this;
		}

		inline Vector3D& operator /= (const double scale)
		{
			//assert(fScalar != 0.0);

			double fInv = 1.0f / scale;

			x *= fInv;
			y *= fInv;
			z *= fInv;

			return *this;
		}

		inline bool operator < (const Vector3D& rhs) const
		{
			if (x < rhs.x && y < rhs.y && z < rhs.z)
				return true;
			return false;
		}

		inline bool operator > (const Vector3D& rhs) const
		{
			if (x > rhs.x && y > rhs.y && z > rhs.z)
				return true;
			return false;
		}


	public:
		inline double length() const
		{
			return sqrt(x * x + y * y + z * z);
		}

		inline double squaredLength() const
		{
			return x * x + y * y + z * z;
		}

		inline double distance(const Vector3D& rhs) const
		{
			return (*this - rhs).length();
		}

		inline double squaredDistance(const Vector3D& rhs) const
		{
			return (*this - rhs).squaredLength();
		}

		inline double dot(const Vector3D& vec) const
		{
			return x * vec.x + y * vec.y + z * vec.z;
		}
		inline double normalize()
		{
			double length = sqrt(x * x + y * y + z * z);			
			if (length > double(0.0f))
			{
				double fInvLength = 1.0f / length;
				x *= fInvLength;
				y *= fInvLength;
				z *= fInvLength;
			}

			return length;
		}
		inline Vector3D cross(const Vector3D& rhs) const
		{
			return Vector3D(
				y * rhs.z - z * rhs.y,
				z * rhs.x - x * rhs.z,
				x * rhs.y - y * rhs.x);
		}
		
		inline Vector3D midPoint(const Vector3D& vec) const
		{
			return Vector3D(
				(x + vec.x) * 0.5f,
				(y + vec.y) * 0.5f,
				(z + vec.z) * 0.5f);
		}
		
		inline void makeFloor(const Vector3D& cmp)
		{
			if (cmp.x < x) x = cmp.x;
			if (cmp.y < y) y = cmp.y;
			if (cmp.z < z) z = cmp.z;
		}
		
		inline void makeCeil(const Vector3D& cmp)
		{
			if (cmp.x > x) x = cmp.x;
			if (cmp.y > y) y = cmp.y;
			if (cmp.z > z) z = cmp.z;
		}

		inline Vector3D reflect(const Vector3D& normal) const
		{
			return Vector3D(*this - (2 * this->dot(normal) * normal));
		}

	public:
		 inline friend Vector3D operator * ( const double scale, const Vector3D& rhs )
        {
            return Vector3D(
				scale * rhs.x,
				scale * rhs.y,
				scale * rhs.z);
        }

        inline friend Vector3D operator / ( const double fScalar, const Vector3D& rkVector )
        {
            return Vector3D(
                fScalar / rkVector.x,
                fScalar / rkVector.y,
                fScalar / rkVector.z);
        }

        inline friend Vector3D operator + (const Vector3D& lhs, const double rhs)
        {
            return Vector3D(
                lhs.x + rhs,
                lhs.y + rhs,
                lhs.z + rhs);
        }

        inline friend Vector3D operator + (const double lhs, const Vector3D& rhs)
        {
            return Vector3D(
                lhs + rhs.x,
                lhs + rhs.y,
                lhs + rhs.z);
        }

        inline friend Vector3D operator - (const Vector3D& lhs, const double rhs)
        {
            return Vector3D(
                lhs.x - rhs,
                lhs.y - rhs,
                lhs.z - rhs);
        }

        inline friend Vector3D operator - (const double lhs, const Vector3D& rhs)
        {
            return Vector3D(
                lhs - rhs.x,
                lhs - rhs.y,
                lhs - rhs.z);
        }

		static Vector3D lerp(const Vector3D& pa, const Vector3D& pb, double scale) {
			double one_scale = 1.0 - scale;
			return Vector3D(
				pa.x * one_scale + pb.x * scale,
				pa.y * one_scale + pb.y * scale,
				pa.z * one_scale + pb.z * scale
			);
		}
	
	};
}

