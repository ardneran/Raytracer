//
//  Image.h
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#ifndef __Raytracer__Image__
#define __Raytracer__Image__

#include "Color.h"

class Image
{
public:
	Image();
	Image(const int &width, const int &height);
	Image(const int &width, const int &height, const Color4f& fillColor);
	~Image();

	bool	setPixel(const int &x, const int &y, const Color4f& color);
	Color4f getPixel(const int &x, const int &y);
	void	gammaCorrect(const float &gamma);
	void	readppm(char* path);
	void	writeppm(char* path);
	void	readbmp(char* path);
	void	writebmp(char* path);

private:
	Color4f** pixels;
	int width;
	int height;
};

#endif /* defined(__Raytracer__Image__) */
