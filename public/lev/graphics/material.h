#pragma once

#include <lev/core/util.h>
#include <lev/graphics/texture.h>
#include <lev/graphics/shader.h>

#define LEV_MAT_TEXTURES 32

namespace lev
{
	class Material
	{
	public:
		Material();
		Material(
			const Ref<Shader>& shader,
			const Ref<Texture>* textures,
			const TextureSampler* samplers,
			unsigned texture_count
		);

		Ref<Shader> shader();
		const Ref<Shader> shader() const;
		void set_shader(const Ref<Shader>& shader);

		Ref<Texture> texture(unsigned idx);
		const Ref<Texture> texture(unsigned idx) const;
		void set_texture(const Ref<Texture>& texture, unsigned idx);

		TextureSampler& sampler(unsigned idx);
		const TextureSampler& sampler(unsigned idx) const;
		void set_sampler(const TextureSampler& sampler, unsigned idx);

	private:
		Ref<Shader> m_shader;

		// todo Vector<T>???
		Ref<Texture> m_textures[LEV_MAT_TEXTURES];
		TextureSampler m_samplers[LEV_MAT_TEXTURES];
	};
}
