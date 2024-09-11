// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef OPENGL_VERTEX_ARRAY_H
#define OPENGL_VERTEX_ARRAY_H

#include "Origin/Renderer/VertexArray.h"

namespace origin
{
	class OGN_API OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const Ref<VertexBuffer> &vertexBuffer) override;
		void SetIndexBuffer(const Ref<IndexBuffer> &indexBuffer) override;

		const std::vector<Ref<VertexBuffer>>& GetVertexBuffer() const override { return m_VertexBuffer;  }
		const Ref<IndexBuffer>& GetIndexBuffer() const override { return m_IndexBuffer; }

	private:
		u32 m_RendererID;
		std::vector <Ref<VertexBuffer>> m_VertexBuffer;
		Ref<IndexBuffer> m_IndexBuffer;
		u32 m_VertexBufferIndex= 0;

	};
};

#endif