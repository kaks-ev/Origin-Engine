// Copyright (c) 2023 Evangelion Manuhutu | ORigin Engine

#include "Editor.h"

namespace Origin
{
	bool Editor::OnMouseButtonPressed(MouseButtonPressedEvent& e)
	{
		auto bt = e.GetMouseButton();
		bool control = Input::IsKeyPressed(Key::LeftControl);

		if (bt == Mouse::ButtonLeft && m_ViewportHovered)
		{
			if (!ImGuizmo::IsOver())
			{
				if (m_HoveredEntity)
					m_SceneHierarchy.SetSelectedEntity(m_HoveredEntity);

				else if (m_HoveredEntity == m_SceneHierarchy.GetSelectedEntity() && !control || !m_HoveredEntity)
					m_SceneHierarchy.SetSelectedEntity({});
			}

			if (control) {
				if (m_HoveredEntity == m_SelectedEntity && !ImGuizmo::IsOver())
				{
					m_GizmosType == -1 ? m_GizmosType = ImGuizmo::OPERATION::TRANSLATE : m_GizmosType == ImGuizmo::OPERATION::TRANSLATE ?
						m_GizmosType = ImGuizmo::OPERATION::ROTATE : m_GizmosType == ImGuizmo::OPERATION::ROTATE ? m_GizmosType = ImGuizmo::OPERATION::SCALE : m_GizmosType = -1;
				}
			}
		}
		return false;
	}

	void Editor::InputProccedure(Timestep time)
	{
		if (Input::IsMouseButtonPressed(Mouse::ButtonRight))
		{
			lastMouseX = lastMouseX;
			lastMouseY = lastMouseY;
			RMHoldTime += time.GetDeltaTime();

			if (lastMouseX == mouseX && lastMouseY == mouseY) VpMenuContextActive = true;
			else if (lastMouseX != mouseX && lastMouseY != mouseY) VpMenuContextActive = false;

			if (lastMouseX == mouseX && lastMouseY == mouseY)
			{
				if (m_HoveredEntity == m_SelectedEntity && m_HoveredEntity)
					m_VpMenuContext = ViewportMenuContext::EntityProperties;
				if (m_HoveredEntity != m_SelectedEntity || !m_HoveredEntity)
					m_VpMenuContext = ViewportMenuContext::CreateMenu;
			}
		}
		else
		{
			lastMouseX = mouseX;
			lastMouseY = mouseY;
			RMHoldTime = 0.0f;
		}
	}

	bool Editor::OnKeyPressed(KeyPressedEvent& e)
	{
		auto& app = Application::Get();
		bool control = Input::IsKeyPressed(Key::LeftControl) || Input::IsKeyPressed(Key::RightControl);
		bool shift = Input::IsKeyPressed(Key::LeftShift) || Input::IsKeyPressed(Key::RightShift);

		ImGuiIO& io = ImGui::GetIO();

		switch (e.GetKeyCode())
		{
			// File Operation
			case Key::S:
			{
				if (control)
				{
					if (shift)
						SaveSceneAs();
					else
						SaveScene();
				}
				break;
			}

			case Key::O:
			{
				if (control) OpenScene();
				break;
			}

			case Key::N:
			{
				if (control) NewScene();
				break;
			}

			case Key::T:
			{
				if (!ImGuizmo::IsUsing() && !io.WantTextInput)
					m_GizmosType = ImGuizmo::OPERATION::TRANSLATE;
				break;
			}

			case Key::D:
			{
				if (control)
					OnDuplicateEntity();
				break;
			}

			case Key::E:
			{
				if (!ImGuizmo::IsUsing() && !io.WantTextInput && m_GizmosMode == ImGuizmo::MODE::LOCAL)
					m_GizmosType = ImGuizmo::OPERATION::SCALE;
				break;
			}

			case Key::R:
			{
				if (!ImGuizmo::IsUsing() && !io.WantTextInput)
					m_GizmosType = ImGuizmo::OPERATION::ROTATE;
				break;
			}

			case Key::F11:
			{
				guiMenuFullscreen == false ? guiMenuFullscreen = true : guiMenuFullscreen = false;
				app.GetWindow().SetFullscreen(guiMenuFullscreen);
				break;
			}
		}

		return false;
	}

	bool Editor::OnWindowResize(WindowResizeEvent& e)
	{
		return false;
	}

	bool Editor::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		return false;
	}

	bool Editor::OnMouseButtonEvent(MouseButtonEvent& e)
	{
		return false;
	}
}