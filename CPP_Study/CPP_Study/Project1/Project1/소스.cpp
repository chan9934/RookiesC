#include <iostream>

using namespace std;

class Framebuffer
{
public:
	Framebuffer()
	{
		clear();
	}
	void clear()
	{
		for (int i = 0; i < WIDTH * HEIGHT; ++i)
		{
			pixels_[i] = WHITE;
		}
	}
	void draw(int x, int y)
	{
		pixels_[(WIDTH * y) + x] = BLACK;
	}
	const char* getPixels() { return pixels_; }

private:
	static const int WIDTH = 160;
	static const int HEIGHT = 120;

	char pixels_[WIDTH * HEIGHT];
};