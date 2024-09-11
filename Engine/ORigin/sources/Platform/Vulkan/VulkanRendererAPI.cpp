// Copyright (c) Evangelion Manuhutu | ORigin Engine

#include "pch.h"
#include "VulkanRendererAPI.h"
#include "VulkanContext.h"

namespace origin
{
    void VulkanRendererAPI::Init()
    {
    }

    void VulkanRendererAPI::SetViewport(u32 x, u32 y, u32 width, u32 height)
    {
    }

    void VulkanRendererAPI::ClearColor(const glm::vec4 &color)
    {
        VulkanContext *vk_context = VulkanContext::GetInstance();
        vk_context->m_ClearValue.color.float32[0] = color.r * color.a;
        vk_context->m_ClearValue.color.float32[1] = color.g * color.a;
        vk_context->m_ClearValue.color.float32[2] = color.b * color.a;
        vk_context->m_ClearValue.color.float32[3] = color.a;
    }

    void VulkanRendererAPI::ClearColor(f32 r, f32 g, f32 b, f32 a)
    {
        VulkanContext *vk_context = VulkanContext::GetInstance();
        vk_context->m_ClearValue.color.float32[0] = r * a;
        vk_context->m_ClearValue.color.float32[1] = g * a;
        vk_context->m_ClearValue.color.float32[2] = b * a;
        vk_context->m_ClearValue.color.float32[3] = a;
    }

    void VulkanRendererAPI::Clear()
    {
    }

    void VulkanRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, u32 indexCount)
    {
    }

    void VulkanRendererAPI::DrawArrays(const std::shared_ptr<VertexArray>& vertexArray, u32 vertexCount)
    {
    }

    void VulkanRendererAPI::DrawLines(const std::shared_ptr<VertexArray>& vertexArray, u32 vertexCount)
    {
    }

    void VulkanRendererAPI::SetLineWidth(f32 width)
    {
    }
}