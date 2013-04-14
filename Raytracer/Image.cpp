//
//  Image.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include "Image.h"

#define XRIGHTYUP
//#define XRIGHTYDOWN // TODO Fix this

Image::Image()
:	width(0),
	height(0),
	pixels(nullptr)
{}

Image::Image(const int &width, const int &height)
:	width(width),
	height(height)
{
	pixels = new Color4f*[width];
	for(int i = 0; i < width; i++)
	{
		pixels[i] = new Color4f[height];
	}
}

Image::Image(const int &width, const int &height, const Color4f& fillColor)
:	width(width),
	height(height)
{
	pixels = new Color4f*[width];
	for(int i = 0; i < width; i++)
	{
		pixels[i] = new Color4f[height];
		for (int j = 0; j < height; j++)
		{
			pixels[i][j] = fillColor;
		}
	}
}

Image::~Image()
{
	if (pixels != nullptr)
	{
		for (int i = 0; i < width; i++)
		{
			delete [] pixels[i];
		}
		delete [] pixels;
	}
}

bool Image::setPixel(const int &x, const int &y, const Color4f& color)
{
	if (0 > x || x > width || 0 > y || y > height)
	{
		return false;
	}
	else
	{
		pixels[x][y] = color;
		return true;
	}
}

Color4f Image::getPixel(const int &x, const int &y)
{
	if (0 > x || x > width || 0 > y || y > height)
	{
		return Color4f();
	}
	else
	{
		return pixels[x][y];
	}
}

void Image::gammaCorrect(const float &gamma)
{
	float power = 1.0f / gamma;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			pixels[i][j].r = pow(pixels[i][j].r, power);
			pixels[i][j].g = pow(pixels[i][j].g, power);
			pixels[i][j].b = pow(pixels[i][j].b, power);
			pixels[i][j].a = pow(pixels[i][j].a, power);
		}
	}
}

//  untested
void Image::readppm(char* path)
{
	FILE* f = fopen(path, "r");
	if (f == NULL)
	{
		printf("Couldn't open file %s for reading\n", path);
		return;
	}

	//  Destroy
	if (pixels != nullptr)
	{
		for (int i = 0; i < width; i++)
		{
			delete [] pixels[i];
		}
		delete [] pixels;
	}

	//  Magic Number, Width, Height, Maximum Color
	char* magicNumber = new char(sizeof(char) * 3);
	int maxColorValue = 0;
	fscanf(f, "%s %i %i %i", magicNumber, &width, &height, &maxColorValue);

#ifdef DEBUGTEXT
	printf("%s\n", FUNCTION);
	printf("%s %i %i %i", magicNumber, width, height, maxColorValue);
#endif

	//  Reallocate
	pixels = new Color4f*[width];
	for(int i = 0; i < width; i++)
	{
		pixels[i] = new Color4f[height];
	}

	//  RGB No Alpha in PPM
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int r = 0;
			int g = 0;
			int b = 0;
			fscanf(f, " %i %i %i", &r, &g, &b);
#ifdef DEBUGTEXT
			printf(" %.3i %.3i %.3i", r, g, b);
#endif
#if defined XRIGHTYUP
			pixels[x][height - y - 1] = Color4f((float)r/255.0f,
												(float)g/255.0f,
												(float)b/255.0f);
#elif defined XRIGHTYDOWN
			pixels[x][y]			  = Color4f((float)r/255.0f,
												(float)g/255.0f,
												(float)b/255.0f);
#endif
		}
	}

#ifdef DEBUGTEXT
	printf("\n");
#endif

	fclose(f);
}

void Image::writeppm(char* path)
{
	if (width == 0 || height == 0)
	{
		printf("Couldn't write file %s Width %d Height %d\n",
			   path, width, height);
		return;
	}

	FILE* f = fopen(path, "w");
	if (f == NULL)
	{
		printf("Couldn't open file %s for writing\n", path);
		return;
	}
	
	//  Magic Number, Width, Height, Maximum Color
	fprintf(f, "%s %i %i %i", "P3", width, height, 255);

#ifdef DEBUGTEXT
	printf("%s\n", FUNCTION);
	printf("%s %i %i %i", "P3", width, height, 255);
#endif

	//  RGB No Alpha in PPM
	Color4f color;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
#if defined XRIGHTYUP
			color	= pixels[x][height - y - 1];
#elif defined XRIGHTYDOWN
			color	= pixels[x][y];
#endif
			fprintf(f, " %.3i %.3i %.3i",
					int(color.r * 255.0f),
					int(color.g * 255.0f),
					int(color.b * 255.0f));
#ifdef DEBUGTEXT
			printf(" %.3i %.3i %.3i",
				   int(color.r * 255.0f),
				   int(color.g * 255.0f),
				   int(color.b * 255.0f));
#endif
		}
	}

#ifdef DEBUGTEXT
	printf("\n");
#endif

	fclose(f);
}

void Image::readbmp(char* path)
{
	FILE* f = fopen(path, "r");
	if (f == NULL)
	{
		printf("Couldn't open file %s for reading\n", path);
		return;
	}

	//  Destroy
	if (pixels != nullptr)
	{
		for (int i = 0; i < width; i++)
		{
			delete [] pixels[i];
		}
		delete [] pixels;
	}

	unsigned char bmpHeader[14];
	unsigned char dibHeader[40];

	fread(bmpHeader, 1, sizeof(bmpHeader), f);
	fread(dibHeader, 1, sizeof(dibHeader), f);

#ifdef DEBUGTEXT
	printf("%s\n", FUNCTION);
	for (int i = 0; i < sizeof(bmpHeader); i++)
		printf("%.2X ", bmpHeader[i]);
	for (int i = 0; i < sizeof(dibHeader); i++)
		printf("%.2X ", dibHeader[i]);
#endif

	width  = (dibHeader[ 4] <<  0 |
			  dibHeader[ 5] <<  8 |
			  dibHeader[ 6] << 16 |
			  dibHeader[ 7] << 24);

	height =-(dibHeader[ 8] <<  0 |
			  dibHeader[ 9] <<  8 |
			  dibHeader[10] << 16 |
			  dibHeader[11] << 24);

	//  Reallocate
	pixels = new Color4f*[width];
	for(int i = 0; i < width; i++)
	{
		pixels[i] = new Color4f[height];
	}

	//  BGRA
	Color4f color;
	uint8_t b, g, r, a;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			fread(&b, 1, sizeof(char), f);
			fread(&g, 1, sizeof(char), f);
			fread(&r, 1, sizeof(char), f);
			fread(&a, 1, sizeof(char), f);

			color.b = (float)b / 255.0f;
			color.g = (float)g / 255.0f;
			color.r = (float)r / 255.0f;
			color.a = (float)a / 255.0f;

#if defined XRIGHTYUP
			pixels[x][height - y - 1] = color;
#elif defined XRIGHTYDOWN
			pixels[x][y] = color;
#endif

#ifdef DEBUGTEXT
			printf("%.2X %.2X %.2X %.2X", b, g, r, a);
#endif
		}
	}

#ifdef DEBUGTEXT
	printf("\n");
#endif

	fclose(f);
}

void Image::writebmp(char* path)
{
	if (width == 0 || height == 0)
	{
		printf("Couldn't write file %s Width %d Height %d\n",
			   path, width, height);
		return;
	}

	FILE* f = fopen(path, "wb");
	if (f == NULL)
	{
		printf("Couldn't open file %s for writing\n", path);
		return;
	}

	unsigned char bmpHeader[14] =   {
		66, 77,			//  Magic number unsigned integer B 66, M 77
		0, 0, 0, 0,		//  Size of BMP file
		0, 0,			//  Application specific
		0, 0,			//  Application specific
		54, 0, 0, 0,	//  Offset of pixel array bitmap data
	};

	unsigned char dibHeader[40] =   {
		40, 0, 0, 0,	//  Number of bytes in the DIB header from this point
		0, 0, 0, 0,		//  Width of bmp in pixels
		0, 0, 0, 0,		//  Height of bmp in pixels, + bottom top, - top bottom
		1, 0,			//  Number of color planes being used
		32, 0,			//  Number of bits per pixel
		0, 0, 0, 0,		//  BIRGB no pixel array compression used
		0, 0, 0, 0,		//  Size of raw data in pixel array including padding
		0, 0, 0, 0,		//  Horizontal resolution of the image
		0, 0, 0, 0,		//  Vertical resolution of the image
		0, 0, 0, 0,		//  Number of colors in the palette
		0, 0, 0, 0,		//  All colors important 0
	};

	uint32_t fileSize = sizeof(bmpHeader) +
						sizeof(dibHeader) +
						4 * width * height;

	bmpHeader[ 2] = (unsigned char)(fileSize >>  0);
	bmpHeader[ 3] = (unsigned char)(fileSize >>  8);
	bmpHeader[ 4] = (unsigned char)(fileSize >> 16);
	bmpHeader[ 5] = (unsigned char)(fileSize >> 24);

	dibHeader[ 4] = (unsigned char)(width >>  0);
	dibHeader[ 5] = (unsigned char)(width >>  8);
	dibHeader[ 6] = (unsigned char)(width >> 16);
	dibHeader[ 7] = (unsigned char)(width >> 24);

	dibHeader[ 8] = (unsigned char)(-height >>  0);
	dibHeader[ 9] = (unsigned char)(-height >>  8);
	dibHeader[10] = (unsigned char)(-height >> 16);
	dibHeader[11] = (unsigned char)(-height >> 24);

	fwrite(bmpHeader, 1, sizeof(bmpHeader), f);
	fwrite(dibHeader, 1, sizeof(dibHeader), f);

#ifdef DEBUGTEXT
	printf("%s\n", FUNCTION);
	for (int i = 0; i < sizeof(bmpHeader); i++)
		printf("%.2X ", bmpHeader[i]);
	for (int i = 0; i < sizeof(dibHeader); i++)
		printf("%.2X ", dibHeader[i]);
#endif

	//  BGRA
	Color4f color;
	uint8_t b, g, r, a;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
#if defined XRIGHTYUP
			color	= pixels[x][height - y - 1];
#elif defined XRIGHTYDOWN
			color	= pixels[x][y];
#endif
			b = (uint8_t)(color.b * 255.0f);
			g = (uint8_t)(color.g * 255.0f);
			r = (uint8_t)(color.r * 255.0f);
			a = (uint8_t)(color.a * 255.0f);

			fwrite(&b, 1, sizeof(char), f);
			fwrite(&g, 1, sizeof(char), f);
			fwrite(&r, 1, sizeof(char), f);
			fwrite(&a, 1, sizeof(char), f);

#ifdef DEBUGTEXT
			printf("%.2X %.2X %.2X %.2X", b, g, r, a);
#endif
		}
	}

#ifdef DEBUGTEXT
	printf("\n");
#endif

	fclose(f);
}
