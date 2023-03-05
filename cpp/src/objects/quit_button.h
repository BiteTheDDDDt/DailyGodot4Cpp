#pragma once

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/godot.hpp>

namespace godot {

class QuitButton : public Button {
    GDCLASS(QuitButton, Button) // NOLINT

public:
    static void _bind_methods() {}

    void _pressed() override { get_tree()->quit(0); }
};

} // namespace godot
