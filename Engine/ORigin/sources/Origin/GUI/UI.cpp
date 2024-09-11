// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#include "pch.h"
#include "UI.h"

namespace origin::UI
{
	bool DrawButton(const char *text, bool *value)
	{
		bool ret = false;

		ImGui::PushID((void *)&text);

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		float lineWidth = GImGui->FontSize + GImGui->Style.FramePadding.x * (ImGui::CalcTextSize(text).x / 4.0f);
		ImVec2 btSize = ImVec2(lineWidth, lineHeight);

		ret = ImGui::Button(text, btSize);
		if (value)
			*value = ret;

		ImGui::PopID();

		return ret;
	}

	bool DrawButtonWithColumn(const char *label, const char *text, bool *value, std::function<void()> func, float coloumnWidth)
	{
		bool ret = false;

		ImGui::PushID(label);

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		float lineWidth = GImGui->FontSize + GImGui->Style.FramePadding.x * (ImGui::CalcTextSize(text).x / 4.0f);
		ImVec2 btSize = ImVec2(lineWidth, lineHeight);

		ImGui::BeginColumns(label, 2, ImGuiOldColumnFlags_GrowParentContentsSize);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ret = ImGui::Button(text, btSize);

		if (func != nullptr)
			func();

		if (value)
			*value = ret;

		ImGui::EndColumns();
		ImGui::PopID();

		return ret;
	}

	bool DrawCheckbox(const char *label, bool *value, float coloumnWidth)
	{
		bool ret = false;

		ImGui::PushID(label);

		ImGui::BeginColumns(label, 2, ImGuiOldColumnFlags_GrowParentContentsSize);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ret = ImGui::Checkbox("##check_box", value);
		ImGui::EndColumns();
		ImGui::PopID();

		return ret;
	}

	bool DrawCheckbox2(const char *label, bool *x, bool *y, float coloumnWidth)
	{
		bool ret = false;

		ImGui::PushID(label);

		ImGui::BeginColumns(label, 3, ImGuiOldColumnFlags_GrowParentContentsSize);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();
		if (ImGui::Checkbox("X", x))
		{
			ret = true;
		}
		ImGui::NextColumn();
		if (ImGui::Checkbox("Y", y))
		{
			ret = true;
		}
		ImGui::EndColumns();
		ImGui::PopID();

		return ret;
	}

	bool DrawCheckbox3(const char *label, bool *x, bool *y, bool *z, float coloumnWidth)
	{
		bool ret = false;

		ImGui::PushID(label);

		ImGui::BeginColumns(label, 4, ImGuiOldColumnFlags_GrowParentContentsSize);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();
		if (ImGui::Checkbox("X", x))
		{
			ret = true;
		}
		ImGui::NextColumn();
		if (ImGui::Checkbox("Y", y))
		{
			ret = true;
		}
		ImGui::NextColumn();
		if (ImGui::Checkbox("Z", z))
		{
			ret = true;
		}
		ImGui::EndColumns();
		ImGui::PopID();

		return ret;
	}

	bool DrawVec4Control(const char *label, glm::vec4 &values, float speed, float resetValue, float coloumnWidth)
	{
		bool changed = false;
		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(4, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 5));

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = ImVec2(lineHeight, lineHeight);

		// ================================
		// X
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.8f, 0.1f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.3f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.8f, 0.1f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("X", buttonSize))
			{
				values.x = resetValue;
				changed = true;
			}

			ImGui::SameLine();

			if (ImGui::DragFloat("##X", &values.x, speed))
				changed = true;

			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// Y
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.1f, 0.6f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.3f, 0.8f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.1f, 0.8f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("Y", buttonSize))
			{
				values.y = resetValue;
				changed = true;
			}
			ImGui::SameLine();
			if (ImGui::DragFloat("##Y", &values.y, speed))
				changed = true;
			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// Z
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.1f, 0.1f, 0.8f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.3f, 0.3f, 0.9f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.1f, 0.1f, 0.8f, 1.0f } }
			});

			if (ImGui::Button("Z", buttonSize))
			{
				values.z = resetValue;
				changed = true;
			}

			ImGui::SameLine();
			if (ImGui::DragFloat("##Z", &values.z, speed))
				changed = true;
			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// W
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.8f, 0.8f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.9f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.8f, 0.8f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("W", buttonSize))
			{
				values.x = resetValue;
				changed = true;
			}

			ImGui::SameLine();
			if (ImGui::DragFloat("##W", &values.w, speed))
				changed = true;
			ImGui::PopItemWidth();
		}

		ImGui::PopStyleVar(1);
		ImGui::Columns(1);
		ImGui::PopID();

		return changed;
	}

	bool DrawVec3Control(const char *label, glm::vec3 &values, float speed, float resetValue, float coloumnWidth)
	{
		bool changed = false;

		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 2));

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = ImVec2(lineHeight, lineHeight);

		// ================================
		// X
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.8f, 0.1f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.3f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.8f, 0.1f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("X", buttonSize))
			{
				values.x = resetValue;
				changed = true;
			}

			ImGui::SameLine();

			changed |= ImGui::DragFloat("##X", &values.x, speed);


			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// Y
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.1f, 0.6f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.3f, 0.8f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.1f, 0.8f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("Y", buttonSize))
			{
				values.y = resetValue;
				changed = true;
			}
			ImGui::SameLine();
			changed |= ImGui::DragFloat("##Y", &values.y, speed);

			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// Z
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.1f, 0.1f, 0.8f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.3f, 0.3f, 0.9f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.1f, 0.1f, 0.8f, 1.0f } }
			});

			if (ImGui::Button("Z", buttonSize))
			{
				values.z = resetValue;
				changed = true;
			}

			ImGui::SameLine();
			changed |= ImGui::DragFloat("##Z", &values.z, speed);
			ImGui::PopItemWidth();
		}

		ImGui::PopStyleVar(1);
		ImGui::Columns(1);

		ImGui::PopID();

		return changed;
	}

	bool DrawVec2Control(const char *label, glm::vec2 &values, float speed, float resetValue, float coloumnWidth)
	{
		bool changed = false;

		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(2, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 2));

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = ImVec2(lineHeight + 3.0f, lineHeight);

		// ================================
		// X
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.8f, 0.1f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.3f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.8f, 0.1f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("X", buttonSize))
			{
				values.x = resetValue;
				changed = true;
			}

			ImGui::SameLine();

			if (ImGui::DragFloat("##X", &values.x, speed))
				changed = true;

			ImGui::PopItemWidth();
			ImGui::SameLine();
		}

		// ================================
		// Y
		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.1f, 0.6f, 0.1f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.3f, 0.8f, 0.3f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.1f, 0.8f, 0.1f, 1.0f } }
			});

			if (ImGui::Button("Y", buttonSize))
			{
				values.y = resetValue;
				changed = true;
			}
			ImGui::SameLine();
			if (ImGui::DragFloat("##Y", &values.y, speed))
				changed = true;
			ImGui::PopItemWidth();
		}

		ImGui::PopStyleVar(1);
		ImGui::Columns(1);

		ImGui::PopID();

		return changed;
	}

	bool DrawFloatControl(const char *label, float *value, float speed, float minValue, float maxValue, float resetValue, float coloumnWidth)
	{
		bool changed = false;

		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(1, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 2));

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = ImVec2(lineHeight + 3.0f, lineHeight);

		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.5f, 0.5f, 0.5f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.9f, 0.9f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.5f, 0.5f, 0.5f, 1.0f } }
			});
			if (ImGui::Button("V", buttonSize))
			{
				*value = resetValue;
				changed = true;
			}
			ImGui::SameLine();
			if (ImGui::DragFloat("##V", value, speed, minValue, maxValue))
				changed = true;
			ImGui::PopItemWidth();
		}

		ImGui::PopStyleVar(1);
		ImGui::Columns(1);

		ImGui::PopID();

		return changed;
	}

	bool DrawIntControl(const char *label, int *value, float speed, int minValue, int maxValue, int resetValue, float coloumnWidth)
	{
		bool changed = false;

		ImGui::PushID(label);

		ImGui::Columns(2);
		ImGui::SetColumnWidth(0, coloumnWidth);
		ImGui::Text("%s", label);
		ImGui::NextColumn();

		ImGui::PushMultiItemsWidths(1, ImGui::CalcItemWidth());
		ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0, 2));

		float lineHeight = GImGui->FontSize + GImGui->Style.FramePadding.y * 2.0f;
		ImVec2 buttonSize = ImVec2(lineHeight + 3.0f, lineHeight);

		{
			PushScopedColorStyle buttonStyle({
				{ ColorStyle::Button,          { 0.5f, 0.5f, 0.5f, 1.0f } },
				{ ColorStyle::ButtonHovered,   { 0.9f, 0.9f, 0.9f, 1.0f } },
				{ ColorStyle::ButtonActive,    { 0.5f, 0.5f, 0.5f, 1.0f } }
			});

			if (ImGui::Button("V", buttonSize))
			{
				*value = resetValue;
				changed = true;
			}

			ImGui::SameLine();
			if (ImGui::DragInt("##V", value, speed, minValue, maxValue))
				changed = true;
			ImGui::PopItemWidth();
		}

		ImGui::PopStyleVar(1);
		ImGui::Columns(1);

		ImGui::PopID();

		return changed;
	}
}