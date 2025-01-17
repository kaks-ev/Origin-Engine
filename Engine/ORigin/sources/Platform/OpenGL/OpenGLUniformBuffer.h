// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef OPENGL_UNIFORM_BUFFER_H
#define OPENGL_UNIFORM_BUFFER_H

#include "Origin/Renderer/UniformBuffer.h"

namespace origin
{
	class OpenGLUniformBuffer : public UniformBuffer
	{
	public:
		OpenGLUniformBuffer(uint32_t size, uint32_t binding);
		~OpenGLUniformBuffer();

		void Bind() override;
		void Unbind() override;
		void SetData(const void* data, uint32_t size, uint32_t offset = 0) override;

		uint32_t Get() override;
	private:
		uint32_t m_RendererID = 0;
		uint32_t m_BufferSize = 0;
		uint32_t m_BindingPoint;
	};
}

#endif