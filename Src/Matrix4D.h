#pragma once
namespace Core {	
	class Vector4D;
	class Vector3D;
	class Matrix3D;
	class Quaternion;
	class Matrix4D
	{
	public:
		Matrix4D();
		Matrix4D(const Vector4D& a0_, const Vector4D& a1_, const Vector4D& a2_, const Vector4D& a3_);
		Matrix4D(double a00_, double a10_, double a20_, double a30_, double a01_, double a11_, double a21_, double a31_, double a02_, double a12_, double a22_, double a32_, double a03_, double a13_, double a23_, double a33_);
		~Matrix4D();

	public:
		static const Matrix4D Zero;
		static const Matrix4D Identity;
		inline Matrix4D(const Matrix3D& m3x3)
		{
			operator=(Identity);
			operator=(m3x3);
		}
		inline double& operator[] (int index_) {
			return _m[index_];
		}
		inline const double& operator[] (int index_) const {
			return _m[index_];
		}
		inline double& operator() (int row_, int col_) {
			return _m[col_ * 4 + row_];
		}
		inline const double& operator() (int row_, int col_) const {
			return _m[col_ * 4 + row_];
		}

		inline Matrix4D operator*(double scalar_) const {
			return Matrix4D(
				scalar_*_m[0],
				scalar_*_m[1],
				scalar_*_m[2],
				scalar_*_m[3],
				scalar_*_m[4],
				scalar_*_m[5],
				scalar_*_m[6],
				scalar_*_m[7],
				scalar_*_m[8],
				scalar_*_m[9],
				scalar_*_m[10],
				scalar_*_m[11],
				scalar_*_m[12],
				scalar_*_m[13],
				scalar_*_m[14],
				scalar_*_m[15]
			);
		}
		inline Matrix4D operator + (const Matrix4D &m2) const
		{
			Matrix4D r;

			r.m[0][0] = m[0][0] + m2.m[0][0];
			r.m[0][1] = m[0][1] + m2.m[0][1];
			r.m[0][2] = m[0][2] + m2.m[0][2];
			r.m[0][3] = m[0][3] + m2.m[0][3];

			r.m[1][0] = m[1][0] + m2.m[1][0];
			r.m[1][1] = m[1][1] + m2.m[1][1];
			r.m[1][2] = m[1][2] + m2.m[1][2];
			r.m[1][3] = m[1][3] + m2.m[1][3];

			r.m[2][0] = m[2][0] + m2.m[2][0];
			r.m[2][1] = m[2][1] + m2.m[2][1];
			r.m[2][2] = m[2][2] + m2.m[2][2];
			r.m[2][3] = m[2][3] + m2.m[2][3];

			r.m[3][0] = m[3][0] + m2.m[3][0];
			r.m[3][1] = m[3][1] + m2.m[3][1];
			r.m[3][2] = m[3][2] + m2.m[3][2];
			r.m[3][3] = m[3][3] + m2.m[3][3];

			return r;
		}
		
		inline Matrix4D operator - (const Matrix4D &m2) const
		{
			Matrix4D r;
			r.m[0][0] = m[0][0] - m2.m[0][0];
			r.m[0][1] = m[0][1] - m2.m[0][1];
			r.m[0][2] = m[0][2] - m2.m[0][2];
			r.m[0][3] = m[0][3] - m2.m[0][3];

			r.m[1][0] = m[1][0] - m2.m[1][0];
			r.m[1][1] = m[1][1] - m2.m[1][1];
			r.m[1][2] = m[1][2] - m2.m[1][2];
			r.m[1][3] = m[1][3] - m2.m[1][3];

			r.m[2][0] = m[2][0] - m2.m[2][0];
			r.m[2][1] = m[2][1] - m2.m[2][1];
			r.m[2][2] = m[2][2] - m2.m[2][2];
			r.m[2][3] = m[2][3] - m2.m[2][3];

			r.m[3][0] = m[3][0] - m2.m[3][0];
			r.m[3][1] = m[3][1] - m2.m[3][1];
			r.m[3][2] = m[3][2] - m2.m[3][2];
			r.m[3][3] = m[3][3] - m2.m[3][3];

			return r;
		}
	
		inline bool operator == (const Matrix4D& m2) const
		{
			if (
				m[0][0] != m2.m[0][0] || m[0][1] != m2.m[0][1] || m[0][2] != m2.m[0][2] || m[0][3] != m2.m[0][3] ||
				m[1][0] != m2.m[1][0] || m[1][1] != m2.m[1][1] || m[1][2] != m2.m[1][2] || m[1][3] != m2.m[1][3] ||
				m[2][0] != m2.m[2][0] || m[2][1] != m2.m[2][1] || m[2][2] != m2.m[2][2] || m[2][3] != m2.m[2][3] ||
				m[3][0] != m2.m[3][0] || m[3][1] != m2.m[3][1] || m[3][2] != m2.m[3][2] || m[3][3] != m2.m[3][3])
				return false;
			return true;
		}
		inline void operator = (const Matrix3D& mat3);		
		inline Vector4D operator*(const Vector4D& vec_) const;		
		inline Vector3D operator*(const Vector3D& vec_) const;			
		inline Matrix4D operator*(const Matrix4D& mat4_) const;
			

	public:
		inline Matrix4D     get_transpose(void) const;
		bool                get_inverse(Matrix4D& mat4_) const;
		inline double       determinant() const;		
		inline const double* Matrix4D::get_matrix() const;	
		inline Matrix3D     get_matrix3() const ;

	public:		
		static Matrix4D makeTransform(const Vector3D& position, const Vector3D& scale, const Quaternion& orientation);		
		static Matrix4D make_translate_matrix(const Vector3D& trans_);
		static Matrix4D make_scale_matrix(const Vector3D& scale_);
		static Matrix4D make_rotation_matrix(const Vector3D& axis, double angle_in_rad_);
		static Matrix4D create_reflection(const Vector3D& normal_, double dist_to_origin_);
		static Matrix4D make_view_matrix(const Vector3D& pos_, const Vector3D& target_, const Vector3D& up_);
		static Matrix4D make_proj_matrix(double view_degree_rad_, double aspect_ratio_, double near_distance_, double far_distance_);
		static Matrix4D make_ortho_matrix(double width_, double height_, double near_dist_, double far_dist_);
		static Matrix4D make_ortho_matrix(double left, double right, double bottom, double top, double n, double f);		
	protected:
		union {
			double m[4][4];
			double _m[16];
		};
	};
}