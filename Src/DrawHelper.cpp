#include "DrawHelper.h"

namespace Core {



	void DrawHelper::drawLineSB(Device& device, Vertex p1, Vertex p2)
	{
		Vector3D pos1 = p1.position;
		Vector3D pos2 = p2.position;
		double dx = pos2.x - pos1.x;
		double dy = pos2.y - pos1.y;

		double k = dy / dx;
		for (double i = pos1.x, j = pos1.y; i <= pos1.x; i++)
		{
			Vector3D color;
			if (p1.color != p2.color)
				color = Vector3D::lerp(p1.color, p2.color, (i - pos1.x) / dx);
			else
				color = p1.color;
			device.setPixel((int)i, (int)j, color);
			j += k;
		}
	}
	void DrawHelper::drawLineBSH(Device& device, Vertex p1, Vertex p2)
	{
		Vector3D pos1 = p1.position;
		Vector3D pos2 = p2.position;
		double dx = abs(pos2.x - pos1.x);		
		double dy = abs(pos2.y - pos1.y);
		int sx = pos1.x < pos2.x ? 1 : -1;
		int sy = pos1.y < pos2.y ? 1 : -1;

		double x = pos1.x;
		double y = pos1.y;

		int err = (dx > dy ? dx : -dy) / 2, e2;//误差积累

		for (;;) {
			Vector3D color;
			if (p1.color != p2.color)
				color = Vector3D::lerp(p1.color, p2.color, (x - pos1.x) / dx);
			else
				color = p1.color;
			device.setPixel((int)x, (int)y, color);
			if (x == pos2.x && y == pos2.y) break;
			e2 = err;
			if (e2 > -dx) { err -= dy; x += sx; }
			if (e2 < dy) { err += dx; y += sy; }
		}
	}
	void DrawHelper::drawTriangleLine(Device& device, Vertex p1, Vertex p2, Vertex p3)
	{
		drawLineBSH(device, p1, p2);
		drawLineBSH(device, p1, p3);
		drawLineBSH(device, p2, p3);
	}

	void DrawHelper::drawTriangleFill(Device& device, Vertex p1, Vertex p2, Vertex p3)
	{
		//p1,p2,p3根据y值排序
		if (p1.position.y > p2.position.y)
		{
			Vertex temp = p1;
			p1 = p2;
			p2 = temp;
		}
		if (p1.position.y > p3.position.y)
		{
			Vertex temp = p1;
			p1 = p3;
			p3 = temp;
		}
		if (p2.position.y > p3.position.y)
		{
			Vertex temp = p2;
			p2 = p3;
			p3 = temp;
		}

		if ((p1.position.y == p2.position.y == p3.position.y) || (p1.position.x == p2.position.x == p3.position.x))return;

		if ((p1.position.y == p2.position.y) || (p2.position.y == p3.position.y))//不需要拆分
		{
			drawTriangleImmediate(device, p1, p2, p3);
		}
		else
		{
			double k = (p3.position.x - p1.position.x) / (p3.position.y - p1.position.y);
			double xmid = k*(p2.position.y - p1.position.y) + p1.position.x;
			Vertex mid = Vertex::lerp(p1, p3, (p2.position.y - p1.position.y) / (p3.position.y - p1.position.y));
			mid.position.x = xmid;
			mid.position.y = p2.position.y;
			drawTriangleImmediate(device, p1, p2, mid);//top
			drawTriangleImmediate(device, p2, mid, p3);//bottom
		}

	}
	void DrawHelper::drawTriangleImmediate(Device& device, Vertex p1, Vertex p2, Vertex p3)
	{
		Vector3D pos1 = p1.position;
		Vector3D pos2 = p2.position;
		Vector3D pos3 = p3.position;
		int dy = 0;
		for (int y = p1.position.y; y <= p3.position.y; y++,dy++)
		{
			if (y >= 0 && y <= device.width())
			{
				float scale = dy / (p3.position.y - p1.position.y);//插值出起始点和终止点
				Vertex start, end;
				if (p1.position.y == p2.position.y)//top
				{
					start = Vertex::lerp(p1, p3, scale);
					end = Vertex::lerp(p2, p3, scale);
					//Vector3D startcolor = Vector3D::lerp(p1.color, p2.color, scale);
				}
				else
				{
					start = Vertex::lerp(p1, p2, scale);
					end = Vertex::lerp(p1, p3, scale);
				}
				
				if (start.position.x > end.position.x)
				{
					Vertex temp = start;
					start = end;
					end = temp;
				}
				for (int x = start.position.x; x <= end.position.x; x++)
				{
					Vector3D color = Vector3D::lerp(start.color, end.color, (x - start.position.x) / (end.position.x - end.position.x));
					device.setPixel(x, y, color);
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