// Copyright (c) Evangelion Manuhutu | ORigin Engine

#include "pch.h"
#include "OpenGLRendererAPI.h"
#include <glad\glad.h>
#include <GLFW\glfw3.h>

namespace origin
{
	void OpenGLRendererAPI::Init()
	{
		OGN_PROFILER_RENDERING();

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_LINE_SMOOTH);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_MULTISAMPLE);
	}

	void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::ClearColor(const glm::vec4 &color)
	{
		glClearColor(color.r * color.a, color.g * color.a, color.b * color.a, color.a);
	}

	void OpenGLRendererAPI::ClearColor(float r, float g, float b, float a)
	{
		glClearColor(r * a, g * a, b * a, a);
	}

	void OpenGLRendererAPI::Clear()
	{
		OGN_PROFILER_RENDERING();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t indexCount)
	{
		OGN_PROFILER_RENDERING();

		if (vertexArray)
		{
			vertexArray->Bind();
			uint32_t count = indexCount ? indexCount : vertexArray->GetIndexBuffer()->GetCount();
			glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		}
	}

	void OpenGLRendererAPI::DrawArrays(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount)
	{
		OGN_PROFILER_RENDERING();

		m_DrawLineMode ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		if (vertexArray)
		{
			vertexArray->Bind();
			glDrawArrays(GL_TRIANGLES, 0, vertexCount);
		}
	}

	void OpenGLRendererAPI::DrawLines(const std::shared_ptr<VertexArray>& vertexArray, uint32_t vertexCount)
	{
		OGN_PROFILER_RENDERING();

		if (vertexArray)
		{
			vertexArray->Bind();
			glDrawArrays(GL_LINES, 0, vertexCount);
		}
	}

	void OpenGLRendererAPI::SetLineWidth(float width)
	{
		glLineWidth(width);
	}

}