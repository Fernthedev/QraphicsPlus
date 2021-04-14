#include "main.hpp"
#include "QraphicsPlus.hpp"
#include "QraphicsPlusConfig.hpp"

static ModInfo modInfo;

DEFINE_CONFIG(QraphicsPlusConfig);

Logger& getLogger() {
    static Logger* logger = new Logger(modInfo);
    return *logger;
}

extern "C" void setup(ModInfo& info) {
    info.id = ID;
    info.version = VERSION;
    modInfo = info;

    getQraphicsPlusConfig().Init(modInfo);
    getLogger().info("Completed QraphicsPlus setup!");
}

extern "C" void load() {
    il2cpp_functions::Init();

    getLogger().info("Installing QraphicsPlus...");
    QraphicsPlus::Install();
    getLogger().info("Installed QraphicsPlus!");
}