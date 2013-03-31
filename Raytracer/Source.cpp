//
//  main.cpp
//  Raytracer
//
//  Created by Narendra Umate on 3/30/13.
//  Copyright (c) 2013 Narendra Umate. All rights reserved.
//

#include <vector>
#include "float.h"

#include "Disc.h"
#include "Header.h"
#include "HitRecord.h"
#include "Image.h"
#include "Plane.h"
#include "Ring.h"
#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"

int main(int argc, const char * argv[])
{
	HitRecord record;
	bool isHit;
	float tmax;
	Vec3 dir(0.0f, 0.0f, -1.0f);

	vector<Shape*> shapes;

	shapes.push_back(new Disc(Vec3(250.0f, 250.0f, -900.0f),
							  Vec3(0.5f, 0.5f, 1.0f),
							  200.0f,
							  Color::Green));

	shapes.push_back(new Plane(Vec3(0.0f, 0.0f, -2000.0f),
							   Vec3(0.0f, 0.0f, 1.0f),
							   Color::Gray));

	shapes.push_back(new Ring(Vec3(250.0f, 250.0f, -900.0f),
							  Vec3(0.0f, 0.0f, 1.0f),
							  200.0f,
							  250.0f,
							  Color::Gold));

	shapes.push_back(new Sphere(Vec3(250.0f, 250.0f, -1000.0f),
								150.0f,
								Color::Blue));

	shapes.push_back(new Triangle(Vec3(300.0f, 600.0f, -800.0f),
								  Vec3(0.0f, 100.0f, -1000.0f),
								  Vec3(450.0f, 20.0f, -1000.0f),
								  Color::Red));

	Image image(500, 500);

	// Loop over pixels
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			tmax = FLT_MAX;
			isHit = false;
			Ray ray(Vec3(i, j, 0), dir);


			// Loop over shapes
			
			for (int k = 0; k < shapes.size(); k++)
			{
				if (shapes[k]->hit(ray, 0.00001f, tmax, 0.0f, record))
				{
					tmax = record.t;
					isHit = true;
				}
			}

			if (isHit)
			{
				image.setPixel(i, j, record.color);
			}
			else
			{
				image.setPixel(i, j, Color4f(0.2f, 0.2f, 0.2f, 0.0f));
			}
		}
	}

	image.writeppm(OUTPUT_DIR "/image.ppm");
	image.writebmp(OUTPUT_DIR "/image.bmp");
}
