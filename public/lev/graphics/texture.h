#pragma once

#include <lev/core/util.h>
#include <lev/math/rect.h>
#include <lev/graphics/image.h>

namespace lev
{
	class Texture;

	enum TextureFormat
	{
		TEXTURE_FORMAT_RED,
		TEXTURE_FORMAT_RG,
		TEXTURE_FORMAT_RGB,
		TEXTURE_FORMAT_RGBA,
		TEXTURE_FORMAT_DEPTH_STENCIL
	};

	enum TextureType
	{
		TEXTURE_TYPE_UNSIGNED_BYTE,
		TEXTURE_TYPE_FLOAT,
		TEXTURE_TYPE_INT_24_8
	};

	enum TextureFilter
	{
		TEXTURE_FILTER_NEAREST,
		TEXTURE_FILTER_LINEAR
	};

	enum TextureWrap
	{
		TEXTURE_WRAP_CLAMP,
		TEXTURE_WRAP_REPEAT
	};

	struct TextureData
	{
		int width;
		int height;
		TextureFormat format;
		TextureType type;

		TextureData()
			: width(0)
			, height(0)
			, format(TEXTURE_FORMAT_RGBA)
			, type(TEXTURE_TYPE_UNSIGNED_BYTE)
		{
		}

		TextureData(int width, int height, TextureFormat format, TextureType type)
			: width(width)
			, height(height)
			, format(format)
			, type(type)
		{
		}
	};

	struct TextureSampler
	{
		TextureFilter filter;
		TextureWrap wrap_x;
		TextureWrap wrap_y;

		TextureSampler()
			: filter(TEXTURE_FILTER_NEAREST)
			, wrap_x(TEXTURE_WRAP_CLAMP)
			, wrap_y(TEXTURE_WRAP_CLAMP)
		{
		}

		TextureSampler(TextureFilter filter, TextureWrap wrap_x, TextureWrap wrap_y)
			: filter(filter)
			, wrap_x(wrap_x)
			, wrap_y(wrap_y)
		{
		}

		static const TextureSampler& pixel();
		static const TextureSampler& linear();
	};

	struct TextureRegion
	{
		Ref<Texture> source;
		RectI bounds;

		TextureRegion(const Ref<Texture>& source, const RectI& bounds)
			: source(source)
			, bounds(bounds)
		{
		}
	};

	class Texture
	{
	public:
		Texture();
		virtual ~Texture();

		static Ref<Texture> create(const char* path);
		static Ref<Texture> create(const Image& image);
		static Ref<Texture> create(int width, int height, TextureFormat format, TextureType type, const byte* data);

		Int2 size() const { return Int2(width(), height()); }

		// todo: unbind functions?

		virtual void copy_to(Ref<Texture>& other) = 0;

		virtual void bind(int i) const = 0;
		virtual void bind_image(int i) const = 0;
		virtual void generate(const void* data) = 0;
		virtual void get_data(float* buf) = 0;
		virtual int width() const = 0;
		virtual int height() const = 0;
		virtual TextureFormat format() const = 0;
	};
}
