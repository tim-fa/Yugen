#pragma once
//
// Created by Tim on 10.08.2020.
//

#ifndef ENGINE_OPENGLBUFFER_H
#define ENGINE_OPENGLBUFFER_H

// Local
#include "Macros.h"
#include "Renderer/Buffer.h"

namespace Yugen::Platform::OpenGL
{
	class OpenGLVertexBuffer : public Render::VertexBuffer
	{
		public:
			OpenGLVertexBuffer(float* vertices, uint32 size);
			~OpenGLVertexBuffer() override;

			void bind() const override;
			void unbind() const override;

			void setLayout(const Render::BufferLayout& layout) override;
			Render::BufferLayout& getBufferLayout() override;

		private:
			uint32 rendererId{};
			Render::BufferLayout layout;
	};

	class OpenGLIndexBuffer : public Render::IndexBuffer
	{
		public:
			OpenGLIndexBuffer(uint32* indices, uint32 count);
			~OpenGLIndexBuffer() override;

			void bind() const override;
			void unbind() const override;

			uint32 getCount() override;

		private:
			uint32 rendererId{};
			uint32 count;

	};
}

#endif //ENGINE_OPENGLBUFFER_H
