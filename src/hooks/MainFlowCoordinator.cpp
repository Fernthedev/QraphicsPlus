#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"
#include "hooks/MainFlowCoordinator.hpp"

#include "GlobalNamespace/MainFlowCoordinator.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    MainFlowCoordinator_DidActivate,
    void,
    MainFlowCoordinator* self,
    bool firstActivation,
    bool addedToHierarchy,
    bool screenSystemEnabling
) {
    menuTransitionsHelper = self->menuTransitionsHelper;

    MainFlowCoordinator_DidActivate(self, firstActivation, addedToHierarchy, screenSystemEnabling);
}

void QraphicsPlus::Hooks::MainFlowCoordinator() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), MainFlowCoordinator_DidActivate, il2cpp_utils::FindMethodUnsafe("", "MainFlowCoordinator", "DidActivate", 3));
}