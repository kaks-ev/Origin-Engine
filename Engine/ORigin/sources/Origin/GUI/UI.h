// Copyright (c) 2022-present Evangelion Manuhutu | ORigin Engine

#ifndef UI_H
#define UI_H

#include <imgui.h>
#include <imgui_internal.h>

#include <glm/glm.hpp>
#include <functional>

namespace origin::UI
{
	// Enumeration for PushStyleColor() / PopStyleColor()
	enum OGN_API ColorStyle
	{
		Text,
		TextDisabled,
		WindowBg,              // Background of normal windows
		ChildBg,               // Background of child windows
		PopupBg,               // Background of popups, menus, tooltips windows
		Border,
		BorderShadow,
		FrameBg,               // Background of checkbox, radio button, plot, slider, text input
		FrameBgHovered,
		FrameBgActive,
		TitleBg,               // Title bar
		TitleBgActive,         // Title bar when focused
		TitleBgCollapsed,      // Title bar when collapsed
		MenuBarBg,
		ScrollbarBg,
		ScrollbarGrab,
		ScrollbarGrabHovered,
		ScrollbarGrabActive,
		CheckMark,             // Checkbox tick and RadioButton circle
		SliderGrab,
		SliderGrabActive,
		Button,
		ButtonHovered,
		ButtonActive,
		Header,                // Header* colors are used for CollapsingHeader, TreeNode, Selectable, MenuItem
		HeaderHovered,
		HeaderActive,
		Separator,
		SeparatorHovered,
		SeparatorActive,
		ResizeGrip,            // Resize grip in lower-right and lower-left corners of windows.
		ResizeGripHovered,
		ResizeGripActive,
		TabHovered,            // Tab background, when hovered
		Tab,                   // Tab background, when tab-bar is focused & tab is unselected
		TabSelected,           // Tab background, when tab-bar is focused & tab is selected
		TabSelectedOverline,   // Tab horizontal overline, when tab-bar is focused & tab is selected
		TabDimmed,             // Tab background, when tab-bar is unfocused & tab is unselected
		TabDimmedSelected,     // Tab background, when tab-bar is unfocused & tab is selected
		TabDimmedSelectedOverline,//..horizontal overline, when tab-bar is unfocused & tab is selected
		DockingPreview,        // Preview overlay color when about to docking something
		DockingEmptyBg,        // Background color for empty node (e.g. CentralNode with no window docked into it)
		PlotLines,
		PlotLinesHovered,
		PlotHistogram,
		PlotHistogramHovered,
		TableHeaderBg,         // Table header background
		TableBorderStrong,     // Table outer and header borders (prefer using Alpha=1.0 here)
		TableBorderLight,      // Table inner borders (prefer using Alpha=1.0 here)
		TableRowBg,            // Table row background (even rows)
		TableRowBgAlt,         // Table row background (odd rows)
		TextSelectedBg,
		DragDropTarget,        // Rectangle highlighting a drop target
		NavHighlight,          // Gamepad/keyboard: current highlighted item
		NavWindowingHighlight, // Highlight window when using CTRL+TAB
		NavWindowingDimBg,     // Darken/colorize entire screen behind the CTRL+TAB window list, when active
		ModalWindowDimBg,      // Darken/colorize entire screen behind a modal window, when one is active
		COUNT
	};

	struct OGN_API ColorStyleVarData
	{
		ColorStyle Style;
		glm::vec4 Color;

		ColorStyleVarData(ColorStyle style, const glm::vec4 &color)
			: Style(style), Color(color) { }
	};

	class OGN_API PushScopedColorStyle
	{
	public:
		PushScopedColorStyle(std::initializer_list<ColorStyleVarData> styles)
			: m_Styles(styles)
		{
			for(auto s : m_Styles)
				ImGui::PushStyleColor((ImGuiCol)s.Style, ImVec4(s.Color.x, s.Color.y, s.Color.z, s.Color.w));
		}
		~PushScopedColorStyle()
		{
			ImGui::PopStyleColor(m_Styles.size());
		}

	private:
		std::vector<ColorStyleVarData> m_Styles;
	};

	static float defColWidth = 100.0f;

	OGN_API bool DrawButton(const char *text, bool *value = nullptr);

	OGN_API bool DrawButtonWithColumn(const char *label, const char *text, bool *value = nullptr, std::function<void()> func = std::function<void()>(), float coloumnWidth = defColWidth);

	OGN_API bool DrawCheckbox(const char *label, bool *value, float coloumnWidth = defColWidth);

	OGN_API bool DrawCheckbox2(const char *label, bool *x, bool *y, float coloumnWidth = defColWidth);

	OGN_API bool DrawCheckbox3(const char *label, bool *x, bool *y, bool *z, float coloumnWidth = defColWidth);

	OGN_API bool DrawVec4Control(const char *label, glm::vec4 &values, float speed = 0.025f, float resetValue = 0.0f, float coloumnWidth = defColWidth);

	OGN_API bool DrawVec3Control(const char *label, glm::vec3 &values, float speed = 0.025f, float resetValue = 0.0f, float coloumnWidth = defColWidth);

	OGN_API bool DrawVec2Control(const char *label, glm::vec2 &values, float speed = 0.025f, float resetValue = 0.0f, float coloumnWidth = defColWidth);

	OGN_API bool DrawFloatControl(const char *label, float *value, float speed = 0.025f, float minValue = 0.0f, float maxValue = 1.0f, float resetValue = 0.0f, float coloumnWidth = defColWidth);

	OGN_API bool DrawIntControl(const char *label, int *value, float speed = 1.0f, int minValue = 0, int maxValue = INT_MAX, int resetValue = 0, float coloumnWidth = defColWidth);
}

#endif