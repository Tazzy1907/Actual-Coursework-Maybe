#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>
#include "math functions.h"

using namespace std;
using namespace stdVals;

const bool wireframe = true;

class Engine : public olc::PixelGameEngine {
public:
    Engine() {
        sAppName = "Graphics Renderer";
    }

private:
    mesh currentMesh;
	vector3D vCamera;
	vector3D lightDirection = { 0.0f, 0.0f, -1.0f };

	float fTheta;
	const float fNear = 0.1f;
	const float fFar = 1000.0f;
	const float fFov = 90.0f;
	const float fAspectRatio = float(ScreenHeight()) / float(ScreenWidth());
	const float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
	const float offset = 4.0f;

public:
    bool OnUserCreate() override {
		currentMesh.AccessObjectFile("C:\\Users\\TanLi\\Desktop\\Coursework Computing A Level\\Object Files\\testcar.obj");

		return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
		FillRect(0, 0, 256, 256, olc::WHITE);

		fTheta += 1.0f * fElapsedTime;
		matrix4x4 matProj, matRotZ, matRotX, matRotY;

		createProj(matProj, fAspectRatio, fFovRad, fFar, fNear);
		createRotX(matRotX, fTheta);
		createRotY(matRotY, fTheta);
		createRotZ(matRotZ, fTheta);

		vector<triangle> trianglesToDisplay;

		// Drawing the triangles
		for (auto tri : currentMesh.tris) {
			triangle triProjected, triTranslated;

			// Rotatate around Z axis.
			triTranslated = ApplyMatTransformation(tri, matRotZ);

			// Rotate around X axis.
			triTranslated = ApplyMatTransformation(triTranslated, matRotX);

			// Offset backwards into the screen.
			triTranslated.p[0].z += offset;
			triTranslated.p[1].z += offset;
			triTranslated.p[2].z += offset;

			// Get 2 lines from the origin of the triangle to its points.
			vector3D line1 = SubtractVector(triTranslated.p[1], triTranslated.p[0]);
			vector3D line2 = SubtractVector(triTranslated.p[2], triTranslated.p[0]);

			triTranslated.normal = CrossProduct(line1, line2);
			NormaliseVector(triTranslated.normal);
			

			// A line from the camera to the triangle.
			triTranslated.cameraToTri = SubtractVector(triTranslated.p[0], vCamera);

			if (DotProduct(triTranslated.normal, triTranslated.cameraToTri) < 0.0f) {

				// Projects the triangles from their 3D coordinates into 2D coordinates.
				triProjected = ApplyMatTransformation(triTranslated, matProj);

				// Scale into view
				triProjected.p[0].x += 1.0f;	triProjected.p[0].y += 1.0f;
				triProjected.p[1].x += 1.0f;	triProjected.p[1].y += 1.0f;
				triProjected.p[2].x += 1.0f;	triProjected.p[2].y += 1.0f;

				triProjected.p[0].x *= 0.5f * float(ScreenWidth());
				triProjected.p[0].y *= 0.5f * float(ScreenWidth());

				triProjected.p[1].x *= 0.5f * float(ScreenWidth());
				triProjected.p[1].y *= 0.5f * float(ScreenWidth());

				triProjected.p[2].x *= 0.5f * float(ScreenWidth());
				triProjected.p[2].y *= 0.5f * float(ScreenWidth());

				trianglesToDisplay.push_back(triProjected);

				// Decides which triangles SHOULD be rendered and stores them for sorting.
			}

		}

		sort(trianglesToDisplay.begin(), trianglesToDisplay.end(), [](triangle& tri1, triangle& tri2){

			// Calculates the midpoint of each triangle.
			float z1 = (tri1.p[0].z + tri1.p[1].z + tri1.p[2].z) / 3.0f;
			float z2 = (tri2.p[0].z + tri2.p[1].z + tri2.p[2].z) / 3.0f;
			
			return z1 > z2;

			});

		// The above sorting algorithm uses a lambda function, which swaps triangles if the first has a greater
		// z value than another.

		for (auto& triProjected : trianglesToDisplay) {

			NormaliseVector(lightDirection);

			float lightDP = DotProduct(lightDirection, triProjected.normal);
			
		
			FillTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y, olc::Pixel(olc::VERY_DARK_MAGENTA * lightDP));

			if (wireframe) {
				DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
					triProjected.p[1].x, triProjected.p[1].y,
					triProjected.p[2].x, triProjected.p[2].y, olc::BLACK);
			}
		}

		return true;
    }
};


int main()
{
    Engine render;

    if (render.Construct(256, 256, 4, 4)) {
        render.Start();
    }

}