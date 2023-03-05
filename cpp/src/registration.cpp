#include "objects/select_button.h"
#if _WIN64
#pragma pointers_to_members(full_generality, multiple_inheritance)
#endif
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

#include "objects/quit_button.h"

using namespace godot;

void register_types(ModuleInitializationLevel p_level) {
    if (p_level != ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    ClassDB::register_class<QuitButton>();
    ClassDB::register_class<SelectButton>();
}

void unregister_types(ModuleInitializationLevel p_level) {
    // DO NOTHING
}

extern "C" {
GDExtensionBool GDE_EXPORT library_init(const GDExtensionInterface* p_interface,
                                        GDExtensionClassLibraryPtr p_library,
                                        GDExtensionInitialization* r_initialization) {
    GDExtensionBinding::InitObject init_object(p_interface, p_library, r_initialization);

    init_object.register_initializer(register_types);
    init_object.register_terminator(unregister_types);
    init_object.set_minimum_library_initialization_level(
            ModuleInitializationLevel::MODULE_INITIALIZATION_LEVEL_SCENE);

    return init_object.init();
}
}
