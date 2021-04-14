#pragma once

#include "main.hpp"

#include "HMUI/ViewController.hpp"

namespace QraphicsPlus {
    namespace Hooks {
        void FPSCounterUIController();
        void GameplayCoreInstaller();
        void MainFlowCoordinator();
        void MainSystemInit();
        void MainSettingsModelSO();
        void OVRPlugin();
        void ParametricBoxFakeGlowController();
    }

    void Install();
}

DECLARE_CLASS_CODEGEN(QraphicsPlus, QraphicsPlusViewController, HMUI::ViewController,
    DECLARE_OVERRIDE_METHOD(void, DidActivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidActivate", 3), bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling);
    DECLARE_OVERRIDE_METHOD(void, DidDeactivate, il2cpp_utils::FindMethodUnsafe("HMUI", "ViewController", "DidDeactivate", 2), bool removedFromHierarchy, bool screenSystemDisabling);

    REGISTER_FUNCTION(
        REGISTER_METHOD(DidActivate);
        REGISTER_METHOD(DidDeactivate);
    )
)