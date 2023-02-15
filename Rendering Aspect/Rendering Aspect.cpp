#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>
#include <fstream>
#include <strstream>
#include <algorithm>

using namespace std;

const bool wireframe = true;

// Structures used.

struct vector3D // A new structure that contains a coordinate.
{
    float x, y, z;
};

struct triangle // A new structure that contains three vector3D instances, or three coordinates.
{
    vector3D p[3];
	vector3D normal;
	vector3D cameraToTri;
};

struct mesh {
    std::vector<triangle> tris; // A dynamic list of triangles.

	bool AccessObjectFile(std::string sFileName) {

		fstream file;
		file.open(sFileName);

		if (!file.is_open()) {
			return false;
		}

		vector <vector3D> vertices;

		while (!file.eof()) {
			char line[64]; // Assumes each line will be no longer than 64 characters.
			file.getline(line, 64);

			strstream strm;
			strm << line;

			char unused;

			if (line[0] == 'v') {
				vector3D currentVector;
				strm >> unused >> currentVector.x >> currentVector.y >> currentVector.z;
				vertices.push_back(currentVector);
			}

			if (line[0] == 'f') {
				int face[3];
				strm >> unused >> face[0] >> face[1] >> face[2];
				tris.push_back({ vertices[face[0] - 1], vertices[face[1] - 1], vertices[face[2] - 1]});

			}
		}

		return true;
	}
};

struct matrix4x4 {
	float m[4][4] = { 0.0 }; // Creates a matrix of [row][column] with every value = 0.
};

const std::vector<triangle> cubeTris = { // Coordinates of a cube. Each sub {} initialises a triangle of 3 vector3Ds.
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
	matrix4x4 matProj, matRotZ, matRotX, matRotY;

	vector3D vCamera;
	vector3D lightDirection = { 0.0f, 0.0f, -1.0f };

	float fTheta;
	const float fNear = 0.1f;
	const float fFar = 1000.0f;
	const float fFov = 90.0f;
	const float fAspectRatio = float(ScreenHeight()) / float(ScreenWidth());
	const float fFovRad = 1.0f / tanf(fFov * 0.5f / 180.0f * 3.14159f);
	const float offset = 4.0f;


	vector3D MultiplyMatrixVector(vector3D input, matrix4x4 matrix) { // Multiplies a vector by a matrix using dot product.

		vector3D output;
		output.x = input.x * matrix.m[0][0] + input.y * matrix.m[1][0] + input.z * matrix.m[2][0] + matrix.m[3][0];
		output.y = input.x * matrix.m[0][1] + input.y * matrix.m[1][1] + input.z * matrix.m[2][1] + matrix.m[3][1];
		output.z = input.x * matrix.m[0][2] + input.y * matrix.m[1][2] + input.z * matrix.m[2][2] + matrix.m[3][2];
		
		float w = input.x * matrix.m[0][3] + input.y * matrix.m[1][3] + input.z * matrix.m[2][3] + matrix.m[3][3];
		
		// Used to normalise the vector.

		if (w != 0) {
			output.x /= w; output.y /= w; output.z /= w;
		};

		return output;
	}

	vector3D CrossProduct(vector3D input1, vector3D input2) {
		vector3D normal;
		
		normal.x = input1.y * input2.z - input1.z * input2.y;
		normal.y = input1.x * input2.z - input1.z * input2.x;
		normal.z = input1.x * input2.y - input1.y * input2.x;

		return normal;

	}

	void NormaliseVector(vector3D& input) {
		float length = sqrtf(input.x*input.x + input.y*input.y + input.z*input.z);
		input.x /= length;
		input.y /= length;
		input.z /= length;
	}

	float DotProduct(vector3D input1, vector3D input2) {
		float dp = (input1.x * input2.x) + (input1.y * input2.y) + (input1.z * input2.z);
		return dp;
	}


public:
    bool OnUserCreate() override {
		meshCube.AccessObjectFile("C:\\Users\\TanLi\\Desktop\\Coursework Computing A Level\\Object Files\\testcar.obj");

		// Projection Matrix
		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;


		return true;
    }

    bool OnUserUpdate(float fElapsedTime) override {
		FillRect(0, 0, 256, 256, olc::BLACK);

		fTheta += 1.0f * fElapsedTime;

		// Rotation X
		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;

		// Rotation Y
		matRotY.m[0][0] = cosf(fTheta);
		matRotY.m[0][2] = -sinf(fTheta);
		matRotY.m[1][1] = 1;
		matRotY.m[2][0] = sinf(fTheta);
		matRotY.m[2][2] = cosf(fTheta);
		matRotY.m[3][3] = 1;

		// Rotation Z
		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;

		vector<triangle> trianglesToDisplay;


		// Drawing the triangles
		for (auto tri : meshCube.tris) {
			triangle triProjected, triTranslated;

			// Rotatate around Z axis.
			triTranslated.p[0] = MultiplyMatrixVector(tri.p[0], matRotZ);
			triTranslated.p[1] = MultiplyMatrixVector(tri.p[1], matRotZ);
			triTranslated.p[2] = MultiplyMatrixVector(tri.p[2], matRotZ);
			// Rotate around X axis.
			triTranslated.p[0] = MultiplyMatrixVector(triTranslated.p[0], matRotX);
			triTranslated.p[1] = MultiplyMatrixVector(triTranslated.p[1], matRotX);
			triTranslated.p[2] = MultiplyMatrixVector(triTranslated.p[2], matRotX);

			// Offset backwards into the screen.
			triTranslated.p[0].z += offset;
			triTranslated.p[1].z += offset;
			triTranslated.p[2].z += offset;

			vector3D line1, line2;
			// Get 2 lines from the origin of the triangle to its points.
			line1.x = triTranslated.p[1].x - triTranslated.p[0].x;
			line1.y = triTranslated.p[1].y - triTranslated.p[0].y;
			line1.z = triTranslated.p[1].z - triTranslated.p[0].z;

			line2.x = triTranslated.p[2].x - triTranslated.p[0].x;
			line2.y = triTranslated.p[2].y - triTranslated.p[0].y;
			line2.z = triTranslated.p[2].z - triTranslated.p[0].z;

			triTranslated.normal = CrossProduct(line1, line2);
			NormaliseVector(triTranslated.normal);
			

			// A line from the camera to the triangle.
			triTranslated.cameraToTri.x = triTranslated.p[0].x - vCamera.x;
			triTranslated.cameraToTri.y = triTranslated.p[0].y - vCamera.y;
			triTranslated.cameraToTri.z = triTranslated.p[0].z - vCamera.z;


			if (DotProduct(triTranslated.normal, triTranslated.cameraToTri) < 0.0f) {

				// Projects the triangles from their 3D coordinates into 2D coordinates.
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
				triProjected.p[2].x, triProjected.p[2].y, olc::Pixel(olc::WHITE * lightDP));

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