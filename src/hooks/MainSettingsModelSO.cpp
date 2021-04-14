#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

#include "GlobalNamespace/BoolSO.hpp"
#include "GlobalNamespace/FloatSO.hpp"
#include "GlobalNamespace/MainSettingsModelSO.hpp"

using namespace GlobalNamespace;

MAKE_HOOK_OFFSETLESS(
    MainSettingsModelSO_Load,
    void,
    MainSettingsModelSO* self,
    bool forced
) {
    MainSettingsModelSO_Load(self, forced);
    
    self->vrResolutionScale->set_value(getQraphicsPlusConfig().Resolution.GetValue());
    self->burnMarkTrailsEnabled->set_value(getQraphicsPlusConfig().BurnMarks.GetValue());
    self->smokeGraphicsSettings->set_value(getQraphicsPlusConfig().Smoke.GetValue());
    self->depthTextureEnabled->set_value(getQraphicsPlusConfig().Smoke.GetValue());
}

void QraphicsPlus::Hooks::MainSettingsModelSO() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), MainSettingsModelSO_Load, il2cpp_utils::FindMethodUnsafe("", "MainSettingsModelSO", "Load", 1));
}