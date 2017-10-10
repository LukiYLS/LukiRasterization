#include "GeometryCreator.h"

namespace Core {

	RenderObject* GeometryCreator::createBox(int width, int height, int depth)
	{
		RenderObject *box = new RenderObject;
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;	
	

		float halfW = width * 0.5f;
		float halfH = height * 0.5f;
		float halfD = depth * 0.5f;

		//眼睛面向z轴正方向
		//构建顶点
		//前面
		Vertex v1;
		v1.position = Vector3D(-halfW, -halfH, -halfD);
		v1.normal = Vector3D(0.f, 0.f, -1.f);
		v1.color = Vector3D(1.f, 0.f, 0.f);
		v1.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v1);		
		Vertex v2;
		v2.position = Vector3D(-halfW, halfH, -halfD);
		v2.normal = Vector3D(0.f, 0.f, -1.f);
		v2.color = Vector3D(0.f, 0.f, 0.f);
		v2.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v2);
		Vertex v3;
		v3.position = Vector3D(halfW, halfH, -halfD);
		v3.normal = Vector3D(0.f, 0.f, -1.f);
		v3.color = Vector3D(1.f, 0.f, 0.f);
		v3.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v3);
		Vertex v4;
		v4.position = Vector3D(halfW, -halfH, -halfD);
		v4.normal = Vector3D(0.f, 0.f, -1.f);
		v4.color = Vector3D(0.f, 1.f, 0.f);
		v4.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v4);

		Vertex v5;
		v5.position = Vector3D(-halfW, -halfH, halfD);
		v5.normal = Vector3D(-1.f, 0.f, 0.f);
		v5.color = Vector3D(0.f, 0.f, 1.f);
		v5.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v5);		
		Vertex v6;
		v6.position = Vector3D(-halfW, halfH, halfD);
		v6.normal = Vector3D(-1.f, 0.f, 0.f);
		v6.color = Vector3D(1.f, 1.f, 0.f);
		v6.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v6);
		Vertex v7;
		v7.position = Vector3D(-halfW, halfH, -halfD);
		v7.normal = Vector3D(-1.f, 0.f, 0.f);
		v7.color = Vector3D(0.f, 0.f, 0.f);
		v7.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v7);
		Vertex v8;
		v8.position = Vector3D(-halfW, -halfH, -halfD);
		v8.normal = Vector3D(-1.f, 0.f, 0.f);
		v8.color = Vector3D(1.f, 1.f, 1.f);
		v8.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v8);

		Vertex v9;
		v9.position = Vector3D(halfW, -halfH, halfD);
		v9.normal = Vector3D(0.f, 0.f, 1.f);
		v9.color = Vector3D(1.f, 0.f, 1.f);
		v9.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v9);
		Vertex v10;
		v10.position = Vector3D(halfW, halfH, halfD);
		v10.normal = Vector3D(0.f, 0.f, 1.f);
		v10.color = Vector3D(0.f, 1.f, 1.f);
		v10.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v10);
		Vertex v11;
		v11.position = Vector3D(-halfW, halfH, halfD);
		v11.normal = Vector3D(0.f, 0.f, 1.f);
		v11.color = Vector3D(1.f, 1.f, 0.f);
		v11.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v11);
		Vertex v12;
		v12.position = Vector3D(-halfW, -halfH, halfD);
		v12.normal = Vector3D(0.f, 0.f, 1.f);
		v12.color = Vector3D(0.f, 0.f, 1.f);
		v12.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v12);

		Vertex v13;
		v13.position = Vector3D(halfW, -halfH, -halfD);
		v13.normal = Vector3D(1.f, 0.f, 0.f);
		v13.color = Vector3D(0.f, 1.f, 0.f);
		v13.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v13);
		Vertex v14;
		v14.position = Vector3D(halfW, halfH, -halfD);
		v14.normal = Vector3D(1.f, 0.f, 0.f);
		v14.color = Vector3D(1.f, 0.f, 0.f);
		v14.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v14);
		Vertex v15;
		v15.position = Vector3D(halfW, halfH, halfD);
		v15.normal = Vector3D(1.f, 0.f, 0.f);
		v15.color = Vector3D(0.f, 1.f, 1.f);
		v15.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v15);
		Vertex v16;
		v16.position = Vector3D(halfW, -halfH, halfD);
		v16.normal = Vector3D(1.f, 0.f, 0.f);
		v16.color = Vector3D(1.f, 0.f, 1.f);
		v16.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v16);

		Vertex v17;
		v17.position = Vector3D(-halfW, halfH, -halfD);
		v17.normal = Vector3D(0.f, 1.f, 0.f);
		v17.color = Vector3D(0.f, 0.f, 0.f);
		v17.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v17);
		Vertex v18;
		v18.position = Vector3D(-halfW, halfH, halfD);
		v18.normal = Vector3D(0.f, 1.f, 0.f);
		v18.color = Vector3D(1.f, 1.f, 0.f);
		v18.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v18);
		Vertex v19;
		v19.position = Vector3D(halfW, halfH, halfD);
		v19.normal = Vector3D(0.f, 1.f, 0.f);
		v19.color = Vector3D(0.f, 1.f, 1.f);
		v19.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v19);
		Vertex v20;
		v20.position = Vector3D(halfW, halfH, -halfD);
		v20.normal = Vector3D(0.f, 1.f, 0.f);
		v20.color = Vector3D(1.f, 0.f, 0.f);
		v20.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v20);
	
		Vertex v21;
		v21.position = Vector3D(-halfW, -halfH, halfD);
		v21.normal = Vector3D(0.f, -1.f, 0.f);
		v21.color = Vector3D(0.f, 0.f, 1.f);
		v21.uv = Vector2D(0.f, 1.f);
		vertices.push_back(v21);
		Vertex v22;
		v22.position = Vector3D(-halfW, -halfH, -halfD);
		v22.normal = Vector3D(0.f, -1.f, 0.f);
		v22.color = Vector3D(1.f, 1.f, 1.f);
		v22.uv = Vector2D(0.f, 0.f);
		vertices.push_back(v22);
		Vertex v23;
		v23.position = Vector3D(halfW, -halfH, -halfD);
		v23.normal = Vector3D(0.f, -1.f, 0.f);
		v23.color = Vector3D(0.f, 1.f, 0.f);
		v23.uv = Vector2D(1.f, 0.f);
		vertices.push_back(v23);
		Vertex v24;
		v24.position = Vector3D(halfW, -halfH, halfD);
		v24.normal = Vector3D(0.f, -1.f, 0.f);
		v24.color = Vector3D(1.f, 0.f, 1.f);
		v24.uv = Vector2D(1.f, 1.f);
		vertices.push_back(v24);
		indices = { 0,1,2,0,2,3,4,5,6,4,6,7,8,9,10,8,10,11,12,13,14,12,14,15,16,17,18,16,18,19,20,21,22,20,22,23 };

		box->setVertices(vertices);
		box->setIndex(indices);
		return box;
	}
}