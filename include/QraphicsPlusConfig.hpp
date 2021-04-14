#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(QraphicsPlusConfig,
    CONFIG_VALUE(Resolution, float, "Resolution", 1.0f);
    CONFIG_VALUE(RefreshRate, int, "Refresh Rate", 0);
    CONFIG_VALUE(EnhancedFakeGlow, bool, "Enhanced Fake Glow", true, "Removes Fake Glow from *small* walls, recommended for ME/NE maps.");
    CONFIG_VALUE(BurnMarks, bool, "Burn Marks", true);
    CONFIG_VALUE(Smoke, bool, "Smoke", false);
    CONFIG_VALUE(Fps, bool, "FPS", true);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Resolution);
        CONFIG_INIT_VALUE(RefreshRate);
        CONFIG_INIT_VALUE(EnhancedFakeGlow);
        CONFIG_INIT_VALUE(BurnMarks);
        CONFIG_INIT_VALUE(Smoke);
        CONFIG_INIT_VALUE(Fps);
    )
)