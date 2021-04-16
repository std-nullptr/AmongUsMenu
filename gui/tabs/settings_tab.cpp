#include "pch-il2cpp.h"
#include "settings_tab.h"
#include "utility.h"
#include "gui-helpers.hpp"
#include "state.hpp"

namespace SettingsTab {
	void Render() {
		if (ImGui::BeginTabItem("Settings")) {
			ImGui::Dummy(ImVec2(4, 4));
			ImGui::Text("Show/Hide Menu Keybind:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Menu)) {
				State.Save();
			}

			ImGui::Text("Show/Hide Console Keybind:");
			ImGui::SameLine();
			if (HotKey(State.KeyBinds.Toggle_Console)) {
				State.Save();
			}
#ifdef _DEBUG
			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));
			if (ImGui::Checkbox("Show Debug Tab", &State.showDebugTab)) {
				State.Save();
			}
			ImGui::Dummy(ImVec2(4, 4));
#endif
			//Change this to in game only once account is overridden
			{
				char* nameBuffer[12]{ const_cast<char*>(State.userName.c_str()) };
				if (ImGui::InputText("PlayerName", *nameBuffer, IM_ARRAYSIZE(nameBuffer))) {
					State.userName = std::string(*nameBuffer);
				}
			}

			ImGui::Dummy(ImVec2(7, 7));
			ImGui::Separator();
			ImGui::Dummy(ImVec2(7, 7));

			char* codeBuffer[15]{ const_cast<char*>(State.CustomCode.c_str()) };
			if (ImGui::InputText("Custom Code", *codeBuffer, IM_ARRAYSIZE(codeBuffer))) {
				State.CustomCode = std::string(*codeBuffer);
			}
			if (ImGui::Checkbox("Replace Lobby Code", &State.HideCode)) {
				State.Save();
			}

			ImGui::EndTabItem();
		}
	}
} 