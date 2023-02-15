#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

struct vector3D // A new structure that contains a coordinate.
{
    float x, y, z;
};

struct triangle // A new structure that contains three vector3D instances, or three coordinates.
{
    vector3D p[3];
};

struct mesh {
    std::vector<triangle> tris; // A dynamic list of triangles.
};

struct matrix4x4 {
	float m[4][4] = { 0 }; // Creates a matrix of [row][column] with every value = 0.
};

const std::vector<triangle> cubeMesh = { // Coordinates of a cube. Each sub {} initialises a triangle of 3 vector3Ds.
		// SOUTH
		{ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f },

		// EAST                                                      
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f },

		// NORTH                                                     
		{ 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f },

		// WEST                                                      
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f },

		// TOP                                                       
		{ 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f },
		{ 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f },

		// BOTTOM                                                    
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f },
		{ 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f },
};


class Engine : public olc::PixelGameEngine {
public:
    Engine() {
        sAppName = "Graphics Renderer";
    }

private:
    mesh meshCube;
	matrix4x4 matProj;
	matrix4x4 matRotZ, matRotX;

	float fTheta;

	vector3D MultiplyMatrixVector(vector3D& input, matrix4x4& matrix) {

		vector3D output;
		output.x = input.x * matrix.m[0][0] + input.y * matrix.m[1][0] + input.z * matrix.m[2][0] + matrix.m[3][0];
		output.y = input.x * matrix.m[0][1] + input.y * matrix.m[1][1] + input.z * matrix.m[2][1] + matrix.m[3][1];
		output.z = input.x * matrix.m[0][2] + input.y * matrix.m[1][2] + input.z * matrix.m[2][2] + matrix.m[3][2];
		
		float w = input.x * matrix.m[0][3] + input.y * matrix.m[1][3] + input.z * matrix.m[2][3] + matrix.m[3][3];

		if (w != 0) {
			output.x /= w; output.y /= w; output.z /= w;
		};

		return output;
	}


public:
    bool OnUserCreate() override {
		meshCube.tris = cubeMesh;

		// Projection Matrix
		float fNear = 0.1f;
		float fFar = 1000.0f;
		float fFov = 90.0f;
		float fAspectRatio = float(ScreenHeight()) / float(ScreenWidth());
		float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);

		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;


		return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
		FillRect(0, 0, 256, 256, olc::DARK_RED);

		fTheta += 1.0f * fElapsedTime;

		// Rotation Z
		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		// Rotation X
		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;


		// Drawing the triangles
		for (auto tri : meshCube.tris) {
			triangle triProjected, triTranslated, triRotatedZ, triRotatedZX;
			 
			// Rotatate around Z axis.
			triRotatedZ.p[0] = MultiplyMatrixVector(tri.p[0], matRotZ);
			triRotatedZ.p[1] = MultiplyMatrixVector(tri.p[1], matRotZ);
			triRotatedZ.p[2] = MultiplyMatrixVector(tri.p[2], matRotZ);
			// Rotate around X axis.
			triRotatedZX.p[0] = MultiplyMatrixVector(triRotatedZ.p[0], matRotX);
			triRotatedZX.p[1] = MultiplyMatrixVector(triRotatedZ.p[1], matRotX);
			triRotatedZX.p[2] = MultiplyMatrixVector(triRotatedZ.p[2], matRotX);

			// Project backwards.
			triTranslated = triRotatedZX;
			triTranslated.p[0].z = triRotatedZX.p[0].z + 3.0f;
			triTranslated.p[1].z = triRotatedZX.p[1].z + 3.0f;
			triTranslated.p[2].z = triRotatedZX.p[2].z + 3.0f;

			triProjected.p[0] = MultiplyMatrixVector(triTranslated.p[0], matProj);
			triProjected.p[1] = MultiplyMatrixVector(triTranslated.p[1], matProj);
			triProjected.p[2] = MultiplyMatrixVector(triTranslated.p[2], matProj);

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

			DrawTriangle(triProjected.p[0].x, triProjected.p[0].y,
				triProjected.p[1].x, triProjected.p[1].y,
				triProjected.p[2].x, triProjected.p[2].y, olc::WHITE);

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