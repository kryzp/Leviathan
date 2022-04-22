#include <lev/graphics/framebuffer.h>
#include <backend/renderer.h>

using namespace lev;

// yes i should be using a seperate struct instead of just reusing TextureData since for framebuffers both width and height must all be the same so we're wasting memory but im lazy
// todo: fix this when im not lazy
// todo todo: stop being so lazy all of the time

Ref<Framebuffer> Framebuffer::create(u32 width, u32 height)
{
	static const FramebufferAttachments attachment = {
        Pair(TextureData(width, height, TEX_FMT_RGBA, I_TEX_FMT_RGBA32F, TEX_TYPE_UNSIGNED_BYTE), TextureSampler::pixel())
    };

	return create(attachment);
}

Ref<Framebuffer> Framebuffer::create(const FramebufferAttachments& attachments)
{
	LEV_ASSERT(attachments.begin(), "Attachments must not be null");
	LEV_ASSERT(attachments.size() > 0, "Attachment count must be higher than 0");
	LEV_ASSERT(attachments[0].first.width > 0 && attachments[0].first.height > 0, "Width and Height must be higher than 0");

	int depthstencilcount = 0;

	for (int i = 0; i < attachments.size(); i++)
	{
		if (attachments[i].first.format == TEX_FMT_DEPTH_STENCIL)
			depthstencilcount++;

		LEV_ASSERT(depthstencilcount < 2, "There must not be 2 or more depth stencil attachments");
	}

	return Renderer::inst()->create_framebuffer({
		.width = attachments[0].first.width,
		.height = attachments[0].first.height,
		.attachments = attachments
	});
}

void Framebuffer::unbind()
{
	Renderer::inst()->unbind_framebuffer();
}

const Ref<Texture>& Framebuffer::attachment(int i) const
{
	return attachments()[i];
}
