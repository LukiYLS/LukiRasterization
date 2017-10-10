#include "DrawHelper.h"

namespace Core {


	//This time the vertex postion is already the screen coordinates
	void DrawHelper::drawLineSB(Device& device, Vertex v1, Vertex v2)
	{
		Vector3D pos1 = v1.position;
		Vector3D pos2 = v2.position;
		int dx = pos2.x - pos1.x;
		int dy = pos2.y - pos1.y;

		int k = (int)(dy / dx);
		for (int i = (int)pos1.x, j = (int)pos1.y; i <= (int)pos2.x; i++)
		{
			Vector3D color;
			if (v1.color != v2.color)
				color = Vector3D::lerp(v1.color, v2.color, (i - pos1.x) / dx);
			else
				color = v1.color;
			device.setPixel(i, j, color);
			j += k;
		}
	}
	void DrawHelper::drawLineBSH(Device& device, Vertex v1, Vertex v2)
	{
		Vector3D pos1 = v1.position;
		Vector3D pos2 = v2.position;
		int dx = (int)abs(pos2.x - pos1.x);		
		int dy = (int)abs(pos2.y - pos1.y);
		int sx = pos1.x < pos2.x ? 1 : -1;
		int sy = pos1.y < pos2.y ? 1 : -1;

		int x = (int)pos1.x;
		int y = (int)pos1.y;
	

		int deltaX = 2 * dx;
		int deltaY = 2 * dy;

		if (dx > dy)
		{
			int error = deltaY - dx;
			for (int i = 0; i <= dx; ++i)
			{
				Vector3D color;
				if (v1.color != v2.color)
					color = Vector3D::lerp(v1.color, v2.color, (x - pos1.x) / dx);
				else
					color = v1.color;
				if (x >= 0 && x < device.width() && y >= 0 && y < device.height())
					device.setPixel(x, y, color);
				if (error >= 0)
				{
					error -= deltaX;
					y += sy;
				}
				error += deltaY;
				x += sx;
			}
		}
		else
		{
			int error = deltaX - dy;
			for (int i = 0; i <= dy; i++)
			{
				Vector3D color;
				if (v1.color != v2.color)
					color = Vector3D::lerp(v1.color, v2.color, (y - pos1.y) / dy);
				else
					color = v1.color;
				if (x >= 0 && x < device.width() && y >= 0 && y < device.height())
					device.setPixel(x, y, color);				
				if (error >= 0)
				{
					error -= deltaY;
					x += sx;
				}
				error += deltaX;
				y += sy;
			}
		}
		
	}
	void DrawHelper::drawTriangleLine(Device& device, Vertex v1, Vertex v2, Vertex v3)
	{
		drawLineBSH(device, v1, v2);
		drawLineBSH(device, v1, v3);
		drawLineBSH(device, v2, v3);
	}

	void DrawHelper::drawTriangleFill(Device& device, Vertex v1, Vertex v2, Vertex v3)
	{
		//p1,p2,p3根据y值排序
		if (v1.position.y > v2.position.y)
		{
			Vertex temp = v1;
			v1 = v2;
			v2 = temp;
		}
		if (v1.position.y > v3.position.y)
		{
			Vertex temp = v1;
			v1 = v3;
			v3 = temp;
		}
		if (v2.position.y > v3.position.y)
		{
			Vertex temp = v2;
			v2 = v3;
			v3 = temp;
		}

		if ((v1.position.y == v2.position.y == v3.position.y) || (v1.position.x == v2.position.x == v3.position.x))return;

		if (((int)v1.position.y == (int)v2.position.y) || ((int)v2.position.y == (int)v3.position.y))//不需要拆分
		{
			drawTriangleImmediate(device, v1, v2, v3);
		}
		else
		{
			float k = (v3.position.x - v1.position.x) / (v3.position.y - v1.position.y);
			float xmid = k*(v2.position.y - v1.position.y) + v1.position.x;
			Vertex mid = Vertex::lerp(v1, v3, (v2.position.y - v1.position.y) / (v3.position.y - v1.position.y));
			mid.position.x = xmid;
			mid.position.y = v2.position.y;
			drawTriangleImmediate(device, v1, v2, mid);//top
			drawTriangleImmediate(device, v2, mid, v3);//bottom
		}

	}
	void DrawHelper::drawTriangleImmediate(Device& device, Vertex v1, Vertex v2, Vertex v3)
	{
		Vector3D pos1 = v1.position;
		Vector3D pos2 = v2.position;
		Vector3D pos3 = v3.position;
		float dy = 0;
		for (float y = v1.position.y; y <= v3.position.y; y++,dy++)
		{
			if (y >= 0 && y <= device.width())
			{
				float scale = dy / (v3.position.y - v1.position.y);//
				Vertex start, end;
				if ((int)v1.position.y == (int)v2.position.y)//top
				{
					start = Vertex::lerp(v1, v3, scale);
					end = Vertex::lerp(v2, v3, scale);
					//Vector3D startcolor = Vector3D::lerp(p1.color, p2.color, scale);
				}
				else
				{
					start = Vertex::lerp(v1, v2, scale);
					end = Vertex::lerp(v1, v3, scale);
				}
				
				if (start.position.x > end.position.x)
				{
					Vertex temp = start;
					start = end;
					end = temp;
				}
				for (float x = start.position.x; x <= end.position.x; x++)
				{
					//depth test
					float factor = 0;
					if (end.position.x - start.position.x > 0.0)						
						factor = (x - start.position.x) / (end.position.x - start.position.x);
					Vertex v = Vertex::lerp(start, end, factor);
					float one_divide_z = v.one_divide_z;
					float oldZ = device.getZDepth((int)x, (int)y);
					if (oldZ == 0.0 || one_divide_z >= oldZ) {
						device.setZDepth((int)x, (int)y, one_divide_z);	
						float w = 1 / one_divide_z;
						v.unpPerspectiveCorrection(w);
						if (x >= 0 && x < device.width() && y >= 0 && y < device.height())
							device.setPixel((int)x, (int)y, v.color);
					}
					
				}
			}
		}
	}	

	void DrawHelper::drawTriangle(Device& device, Vertex p1, Vertex p2, Vertex p3)
	{
		if (false)
		{
			///drawLineBSH(device, p1.position, p2.position, color);
			///drawLineBSH(device, p1, p3, color);
			//drawLineBSH(device, p2, p3, color);
		}
		else
		{

		}
	}
}