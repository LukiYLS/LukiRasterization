#pragma once
#include <windows.h>
#include "Vector3D.h"
namespace Core {

	class Device {
	public:
		Device(int width, int height);
		~Device();
	public:

		void setPixel(int x, int y, Vector3D color);
		float getZDepth(int x, int y) const;
		void setZDepth(int x, int y, float depth);
		int width()const { return _width; }
		int height()const { return _height; }
		UINT*& getFrameBuffer() { return _buffer; }
		void clearBuffer(Vector3D color);
	private:
		int _width;
		int _height;
		UINT32* _buffer;
		float **_zBuffer;
	};
}