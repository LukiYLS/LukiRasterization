#include "Device.h"
#include "MathHelper.h"
namespace Core {

	Device::Device(int width, int height):_width(width), _height(height)
	{
		_zBuffer = new float*[width];
		for (int i = 0; i < width; ++i)
		{
			_zBuffer[i] = new float[height];
		}
	}

	Device::~Device()
	{
		if (_buffer)
			delete _buffer;
		if (_zBuffer)
			for (int i = 0; i < _width; ++i)
			{
				delete[] _zBuffer[i];
			}
	}

	void Device::setPixel(int x, int y, Vector3D color)
	{
		_buffer[_width * y + x] = MathHelper::ColorTo32(color);
	}

	float Device::getZDepth(int x, int y) const
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
			return _zBuffer[x][y];
		else
			return 1.f;
	}

	void Device::setZDepth(int x, int y, float depth)
	{
		if (x >= 0 && x < _width && y >= 0 && y < _height)
		{
			_zBuffer[x][y] = depth;
		}
	}

	void Device::clearBuffer(Vector3D color)
	{
		for (int x = 0; x < _width; ++x)
		{
			for (int y = 0; y < _height; ++y)
			{
				_buffer[_width*y + x] = MathHelper::ColorTo32(color);
				_zBuffer[x][y] = 0;
			}
		}
	}
}