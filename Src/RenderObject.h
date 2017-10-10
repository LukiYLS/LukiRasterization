#pragma once
#include <memory>
#include <vector>
#include "Shader.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Camera.h"
#include "Device.h"
#include "MathHelper.h"
namespace Core {	

	struct Vertex {
		Vector3D position;
		Vector3D color;
		Vector3D normal;
		Vector2D uv;
		double one_divide_z;
		void perspectiveCorrection(double onedivz)
		{			
			one_divide_z = onedivz;

			color.x *= one_divide_z;
			color.y *= one_divide_z;
			color.z *= one_divide_z;

			normal.x *= one_divide_z;
			normal.y *= one_divide_z;
			normal.z *= one_divide_z;

			uv.x *= one_divide_z;
			uv.y *= one_divide_z;			
		}
		void unpPerspectiveCorrection(double z)
		{
			color.x *= z;
			color.y *= z;
			color.z *= z;

			normal.x *= z;
			normal.y *= z;
			normal.z *= z;

			uv.x *= z;
			uv.y *= z;
		}
		
		static Vertex lerp(Vertex p1, Vertex p2, double scale)
		{
			Vertex v;
			v.position = Vector3D::lerp(p1.position, p2.position, scale);
			v.color = Vector3D::lerp(p1.color, p2.color, scale);
			v.normal = Vector3D::lerp(p1.normal, p2.normal, scale);
			v.uv = Vector2D::lerp(p1.uv, p2.uv, scale);
			v.one_divide_z = MathHelper::lerp(p1.one_divide_z, p2.one_divide_z, scale);
			return v;
		}
	};
	class RenderObject {
	public:
		typedef std::shared_ptr<RenderObject> ptr;
	public:
		RenderObject() {}
		virtual ~RenderObject() {}
	public:

		void draw(Device& device);
		void setVertices(std::vector<Vertex> vertices) { _vertices = vertices; }
		void setIndex(std::vector<unsigned int> indices) { _indices = indices; }
		void setCamera(Camera* camera) { _camera = (Camera::ptr)camera; }
		//void setTexture();
		//void setPrimitiveType(PrimitiveType type) { _type = type; }
	protected:
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;
		Camera::ptr _camera;
	};
}