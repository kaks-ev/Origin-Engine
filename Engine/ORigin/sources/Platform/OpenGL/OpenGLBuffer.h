// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef OPENGL_BUFFER_H
#define OPENGL_BUFFER_H

#include "Origin/Renderer/Buffer.h"

namespace origin
{
	class OGN_API OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(u32 size);
		OpenGLVertexBuffer(void* vertices, u32 size);
		virtual ~OpenGLVertexBuffer();
		
		void Bind() const override;
		void Unbind() const override;
		void SetData(const void* data, u32 size, u32 offset = 0) override;
		const BufferLayout& GetLayout() const override { return m_Layout; }
		void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }
	private:
		u32 m_BufferID;
		BufferLayout m_Layout;
	};

	class OGN_API OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(u32 size);
		OpenGLIndexBuffer(void* indices, u32 count);
		virtual ~OpenGLIndexBuffer();

		void Bind() const override;
		void Unbind() const override;
		u32 GetCount() const override { return m_Count; }
		u32 GetBufferID() const override { return m_BufferID; } 

	private:
		u32 m_BufferID;
		u32 m_Count = 0;
	};
}

#endif