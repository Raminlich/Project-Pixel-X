#include "Vector.h"

const Vector2 Vector2::UP = Vector2(0, 1);
const Vector2 Vector2::RIGHT = Vector2(1, 0);


Vector2::Vector2(int x, int y)
	: x(x), y(y)
{
}

Vector2 Vector2::operator + (const Vector2& givenVector)
{
	return Vector2(x + givenVector.x, y + givenVector.y);
}
Vector2 Vector2::operator * (float multiplyValue)
{
	return Vector2(x * multiplyValue, y * multiplyValue);
}

void Vector2::operator+=(const Vector2& givenVector)
{
	*this = *this + givenVector;
}

float Vector2::Magnitude(const Vector2& v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

float Vector2::CrossProduct(const Vector2& v1, const Vector2& v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}

float Vector2::FindAngle(const Vector2& v1, const Vector2& v2)
{
	float magnitudeProduct = Magnitude(v1) * Magnitude(v2);
	if (magnitudeProduct == 0.0f) return 0.0f; // Check for zero vectors

	float dotProduct = DotProduct(v1, v2);
	float angleInRadians = acos(dotProduct / magnitudeProduct);

	// Account for directional ambiguity
	float crossProduct = CrossProduct(v1, v2);
	if (crossProduct < 0) 
	{
		angleInRadians = 2 * M_PI - angleInRadians;
	}
	// Check for directional ambiguity
	if (std::isnan(angleInRadians)) return 0.0f;

	float angleInDegrees = angleInRadians * 180.0f / M_PI;
	if (std::fabs(angleInDegrees) < std::numeric_limits<float>::epsilon()) return 0.0f; // Account for floating point precision

	
	angleInDegrees = 360.0f - angleInDegrees; // Convert to clockwise angle

	return angleInDegrees;
}

static Vector2 WorldToSDL(Vector2& v) 
{
	return Vector2(v.x , -v.y);
}

void Vector2::Rotate(float angle)
{
	float radians = -angle * M_PI / 180.0f;  // Convert degrees to radians
	float cosTheta = cos(radians);
	float sinTheta = sin(radians);

	float newX = x * cosTheta - y * sinTheta;
	float newY = x * sinTheta + y * cosTheta;

	if (std::fabs(newX) < std::numeric_limits<float>::epsilon()) newX = 0.0f; // Account for floating point precision
	if (std::fabs(newY) < std::numeric_limits<float>::epsilon()) newY = 0.0f; // Account for floating point precision

	x = newX;
	y = newY;
}

void Vector2::Normalize()
{
	float magnitudeProduct = Magnitude(*this);
	x /= magnitudeProduct;
	y /= magnitudeProduct;
}

Vector2 Vector2::Nomralized()
{
	Vector2 copyVector = *this;
	copyVector.Normalize();
	return copyVector;
}



std::ostream& operator<<(std::ostream& stream, const Vector2& vector2)
{
	stream << "(" << vector2.x << " ," << vector2.y << ")";
	return stream;
}
