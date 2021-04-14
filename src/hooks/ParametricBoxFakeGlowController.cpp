#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

#include "GlobalNamespace/ParametricBoxFakeGlowController.hpp"

#include <cmath>
#include <vector>

using namespace GlobalNamespace;

#define MIN 0.5f
#define X 13.5f

// Reimplementation of UnityEngine::Mathf::Min(float[]), isn't ideal but it works.
float Mathf_Min(std::vector<float> values) {
    float value = values[0];

    for (int i = 1; i < values.size(); i++) {
        value = fmin(value, values[i]);
    }

    return value;
}

MAKE_HOOK_OFFSETLESS(
    ParametricBoxFakeGlowController_Refresh,
    void,
    ParametricBoxFakeGlowController* self
) {
    if (getQraphicsPlusConfig().EnhancedFakeGlow.GetValue()) {
        float value = Mathf_Min({ self->width, self->height, self->length });

        self->edgeSizeMultiplier = fmin(self->edgeSizeMultiplier, fmax(MIN, value * X));
    }

    ParametricBoxFakeGlowController_Refresh(self);
}

void QraphicsPlus::Hooks::ParametricBoxFakeGlowController() {
    INSTALL_HOOK_OFFSETLESS(getLogger(), ParametricBoxFakeGlowController_Refresh, il2cpp_utils::FindMethodUnsafe("", "ParametricBoxFakeGlowController", "Refresh", 0));
}