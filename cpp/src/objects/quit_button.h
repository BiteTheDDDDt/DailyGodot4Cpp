#pragma once

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot {

class QuitButton : public Button {
    GDCLASS(QuitButton, Button) // NOLINT

public:
    static void _bind_methods() {}

    void _pressed() override {
        UtilityFunctions::print("QuitButton _pressed");
        get_tree()->quit(0);
    }
};

} // namespace godot
