#pragma once
#include <memory>
#include <vector>
#include "Shader.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Camera.h"
namespace Core {	

	struct Vertex {
		Vector3D position;
		Vector3D color;
		Vector3D normal;
		Vector2D uv;
		static Vertex lerp(Vertex p1, Vertex p2, double scale)
		{
			Vertex v;
			v.position = Vector3D::lerp(p1.position, p2.position, scale);
			v.color = Vector3D::lerp(p1.color, p2.color, scale);
			v.normal = Vector3D::lerp(p1.normal, p2.normal, scale);
			v.uv = Vector2D::lerp(p1.uv, p2.uv, scale);
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

		void draw(Shader::ptr shader);
		void setVertices(std::vector<Vertex> vertices) { vertices = vertices; }
		void setIndex(std::vector<unsigned int> indices) { _indices = indices; }
		void setCamera();
		void setTexture();
		//void setPrimitiveType(PrimitiveType type) { _type = type; }
	protected:
		std::vector<Vertex> _vertices;
		std::vector<unsigned int> _indices;
		Camera::ptr _camera;
	};
}