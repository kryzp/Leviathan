#pragma once

namespace lev
{
	struct Mat3x2;

	struct Mat4x4
	{
		static const Mat4x4 IDENTITY;

		union
		{
			struct
			{
				float m11;
				float m12;
				float m13;
				float m14;
				float m21;
				float m22;
				float m23;
				float m24;
				float m31;
				float m32;
				float m33;
				float m34;
				float m41;
				float m42;
				float m43;
				float m44;
			};

			float elements[16];
		};

		Mat4x4();
		Mat4x4(float initial);
		Mat4x4(
			float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44
		);

		static Mat4x4 from_mat3x2(const Mat3x2& mat);

		static Mat4x4 create_translation(float x, float y, float z);
		static Mat4x4 create_scale(float x, float y, float z);

		static Mat4x4 create_orthographic(float width, float height, float near, float far);
		static Mat4x4 create_orthographic_ext(float left, float right, float bottom, float top, float near, float far);

		float* value_ptr();
		const float* value_ptr() const;

		Mat4x4 operator - (const Mat4x4& other) const;
		Mat4x4 operator + (const Mat4x4& other) const;
		Mat4x4 operator * (const Mat4x4& other) const;

		Mat4x4& operator -= (const Mat4x4& other);
		Mat4x4& operator += (const Mat4x4& other);
		Mat4x4& operator *= (const Mat4x4& other);
	};
};
