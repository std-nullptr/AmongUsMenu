#include "pch-il2cpp.h"
#include "_hooks.h"
#include "state.hpp"
#include "utility.h"

void dHudManager_ShowMap(HudManager* __this, Action_1_MapBehaviour_* mapAction, MethodInfo* method) {
	HudManager_ShowMap(__this, mapAction, method);

	//if (State.ChatAlwaysActive)
	//	ChatController_SetVisible(__this->fields.Chat, true, NULL);
	//else
	//	ChatController_SetVisible(__this->fields.Chat, false, NULL);
}

void dHudManager_Update(HudManager* __this,  MethodInfo* method) {
	static bool bChatAlwaysActivePrevious = false;
	if (bChatAlwaysActivePrevious != State.ChatAlwaysActive)
	{
		if (State.ChatAlwaysActive)
			ChatController_SetVisible(__this->fields.Chat, true, NULL);
		else
			ChatController_SetVisible(__this->fields.Chat, State.ChatActiveOriginalState, NULL);
		bChatAlwaysActivePrevious = State.ChatAlwaysActive;
	}
	HudManager_Update(__this, method);
	__this->fields.PlayerCam->fields.Locked = State.FreeCam;
	//HudManager_SetHudActive(__this, State.ShowHud, NULL);
}

void dChatController_Update(ChatController* __this, MethodInfo* method) {
	SaveManager__TypeInfo->static_fields->chatModeType = 1;
	SaveManager__TypeInfo->static_fields->isGuest = false;
	ChatController_Update(__this, method);
}

void dAccountTab_Open(AccountTab* __this, MethodInfo* method) {
	AccountTab_Open(__this, method);
	FullAccount_CanSetCustomName(__this->fields.fullAccount, true, NULL);
}

void dVersionShower_Start(VersionShower* __this, MethodInfo* method) {
	VersionShower_Start(__this, method);
	std::string versionText = convert_from_string(__this->fields.text->fields.Text);
	versionText = versionText + "\n AmongUsMenu - " + GetGitBranch();
	__this->fields.text->fields.Text = convert_to_string(versionText);
}