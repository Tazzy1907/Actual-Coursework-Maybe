#pragma once
#include <strstream>
#include <fstream>
#include <vector>

using namespace std;
// Structures
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

struct mesh { // A mesh structure used to hold lists of triangles of vertices.
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
				tris.push_back({ vertices[face[0] - 1], vertices[face[1] - 1], vertices[face[2] - 1] });

			}
		}

		return true;
	}
};

struct matrix4x4 {
	float m[4][4] = { 0.0 }; // Creates a matrix of [row][column] with every value = 0.
};

// Standard constant values
namespace stdVals {

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


	void createProj(matrix4x4& matProj, float fAspectRatio, float fFovRad, float fFar, float fNear) {
		matProj.m[0][0] = fAspectRatio * fFovRad;
		matProj.m[1][1] = fFovRad;
		matProj.m[2][2] = fFar / (fFar - fNear);
		matProj.m[3][2] = (-fFar * fNear) / (fFar - fNear);
		matProj.m[2][3] = 1.0f;
		matProj.m[3][3] = 0.0f;
	}
	
	void createRotX(matrix4x4& matRotX, float fTheta) {
		matRotX.m[0][0] = 1;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1;
	}

	void createRotY(matrix4x4& matRotY, float fTheta) {
		matRotY.m[0][0] = cosf(fTheta);
		matRotY.m[0][2] = -sinf(fTheta);
		matRotY.m[1][1] = 1;
		matRotY.m[2][0] = sinf(fTheta);
		matRotY.m[2][2] = cosf(fTheta);
		matRotY.m[3][3] = 1;
	}

	void createRotZ(matrix4x4& matRotZ, float fTheta) {
		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1;
		matRotZ.m[3][3] = 1;
	}

};

// Math Functions
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
	float length = sqrtf(input.x * input.x + input.y * input.y + input.z * input.z);
	input.x /= length;
	input.y /= length;
	input.z /= length;
}

float DotProduct(vector3D input1, vector3D input2) {
	float dp = (input1.x * input2.x) + (input1.y * input2.y) + (input1.z * input2.z);
	return dp;
}

triangle ApplyMatTransformation(triangle tri, matrix4x4 transformation) {
	triangle triTranslated;
	triTranslated.p[0] = MultiplyMatrixVector(tri.p[0], transformation);
	triTranslated.p[1] = MultiplyMatrixVector(tri.p[1], transformation);
	triTranslated.p[2] = MultiplyMatrixVector(tri.p[2], transformation);
	
	return triTranslated;
}

vector3D SubtractVector(vector3D line1, vector3D line2) {
	vector3D result;

	result.x = line1.x - line2.x;
	result.y = line1.y - line2.y;
	result.z = line1.z - line2.z;

	return result;
}

vector3D AddVector(vector3D line1, vector3D line2) {
	vector3D result;

	result.x = line1.x + line2.x;
	result.y = line1.y + line2.y;
	result.z = line1.z + line2.z;

	return result;
}






















