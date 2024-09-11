// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef OPENGL_UNIFORM_BUFFER_H
#define OPENGL_UNIFORM_BUFFER_H

#include "Origin/Renderer/UniformBuffer.h"

namespace origin
{
	class OGN_API OpenGLUniformBuffer : public UniformBuffer
	{
	public:
		OpenGLUniformBuffer(u32 size, u32 binding);
		~OpenGLUniformBuffer();

		void Bind() override;
		void Unbind() override;
		void SetData(const void* data, u32 size, u32 offset = 0) override;

		u32 Get() override;
	private:
		u32 m_RendererID = 0;
		u32 m_BufferSize = 0;
		u32 m_BindingPoint;
	};
}

#endif