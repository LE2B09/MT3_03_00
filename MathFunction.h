#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H

#define NOMINMAX
#include "AABB.h"
#include "Matrix4x4.h"
#include "Vector3.h"
#include "Segment.h"
#include "Sphereh.h"
#include "Plane.h"
#include "Triangle.h"
#include <algorithm>
#include <assert.h>
#include <cmath>
#include <corecrt_math_defines.h>

class MathFunction
{
public:
	/*----------Vector型の関数----------*/
	Vector3 Add(const Vector3& v1, const Vector3& v2);
	Vector3 Subtract(const Vector3& v1, const Vector3& v2);
	Vector3 Multiply(float scalar, const Vector3& v);
	float Dot(const Vector3& v1, const Vector3& v2);
	float Length(const Vector3& v);
	Vector3 Normalize(const Vector3& v);
	Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);
	Vector3 Cross(const Vector3& v1, const Vector3& v2);
	Vector3 Project(const Vector3& v1, const Vector3& v2);
	Vector3 ClosestPoint(const Vector3& point, const Segment& segment);
	Vector3 Perpendicular(const Vector3& vector);
	Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);

	/*----------Matrix型の関数----------*/
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);
	Matrix4x4 Inverse(const Matrix4x4& matrix);
	Matrix4x4 Transpose(const Matrix4x4& m);
	Matrix4x4 MakeIdentity();
	Matrix4x4 MakeScaleMatrix(const Vector3& scale);
	Matrix4x4 MakeRotateXMatrix(float radian);
	Matrix4x4 MakeRotateYMatrix(float radian);
	Matrix4x4 MakeRotateZMatrix(float radian);
	Matrix4x4 MakeTranslateMatrix(const Vector3& translate);
	Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& radian, const Vector3& translate);
	Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
	Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
	Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

	/*----------立体を描画する関数----------*/
	void DrawGrid(const Matrix4x4& ViewProjectionMatrix, const Matrix4x4& ViewportMatrix);
	void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
	void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
	void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
	void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
	void DrawBezier(const Vector3& controlPoint0, const Vector3& controlPoint1, const Vector3& controlPoint2, const Matrix4x4& viewProjection, const Matrix4x4& viewportMatrix, uint32_t color);
	void DrawControlPoint(const Vector3& controlPoint, const Matrix4x4& viewProjection, const Matrix4x4& viewportMatrix);

	/*----------衝突判定を取る関数----------*/
	bool IsCollision(const Sphere& s1, const Sphere& s2);
	bool IsCollision(const Sphere& sphere, const Plane& plane);
	bool IsCollision(const Segment& segment, const Plane& plane);
	bool IsCollision(const Triangle& triangle, const Segment& segment);
	bool IsCollision(const AABB& aabb1, const AABB& aabb2);
	bool IsCollision(const AABB& aabb, const Sphere& sphere);
	bool IsCollision(const AABB& aabb, const Segment& segment);
};
#endif // MATHFUNCTION_H