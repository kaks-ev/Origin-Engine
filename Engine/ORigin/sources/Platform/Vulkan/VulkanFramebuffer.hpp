// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef VULKAN_FRAMEBUFFER_H
#define VULKAN_FRAMEBUFFER_H

#include "Origin/Renderer/Framebuffer.h"

namespace origin {

class VulkanFramebuffer : public Framebuffer
{
public:
    VulkanFramebuffer(const FramebufferSpecification &specification);
    ~VulkanFramebuffer();

    void Resize(u32 width, u32 height) override;
    int ReadPixel(u32 attachmentIndex, int x, int y) override;
    void ClearAttachment(u32 attachmentIndex, int value) override;

    u32 GetWidth() const override { return m_Specification.Width; }
    u32 GetHeight() const override { return m_Specification.Height; }

    void Bind() override;
    void Unbind() override;

    u32 GetColorAttachmentRendererID(u32 index = 0) const override { return m_ColorAttachments[index]; };
    u32 GetDepthAttachmentRendererID() const override { return m_DepthAttachment; }
    u32 GetDepthCubeAttachmentRendererID() const override { return m_DepthCubeAttachment; }

    const FramebufferSpecification &GetSpecification() const override { return m_Specification; }

    virtual u32 GetBufferID() const override { return m_BufferID; }

private:
    u32 m_BufferID = 0, m_Renderbuffer = 0;
    FramebufferSpecification m_Specification;
    std::vector<FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
    FramebufferTextureSpecification m_DepthAttachmentSpecification = FramebufferTextureFormat::None;

    // Texture ID
    std::vector<u32> m_ColorAttachments;
    u32 m_DepthAttachment = 0;
    u32 m_DepthCubeAttachment = 0;

};

}

#endif
