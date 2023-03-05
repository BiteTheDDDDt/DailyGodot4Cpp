#pragma once

#include <godot_cpp/classes/button.hpp>
#include <godot_cpp/classes/confirmation_dialog.hpp>
#include <godot_cpp/classes/font.hpp>
#include <godot_cpp/classes/item_list.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/godot.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <memory>

namespace godot {

class SelectButton : public Button {
    GDCLASS(SelectButton, Button) // NOLINT

public:
    static void _bind_methods() {}

    void _pressed() override { _new_selector(); }

private:
    void _new_selector() {
        _selector = std::make_unique<ConfirmationDialog>();
        _selector->set_title("stages");
        _selector->get_ok_button()->add_theme_font_size_override("font_size", _selector_font_size);
        _selector->get_cancel_button()->add_theme_font_size_override("font_size",
                                                                     _selector_font_size);
        _selector->add_theme_font_size_override("title_font_size", _selector_font_size);
        _selector->set_size(Vector2(_selector_w, _selector_h));
        _new_items();

        add_child(_selector.get());

        _selector->popup_centered();
    }

    void _new_items() {
        _items = std::make_unique<ItemList>();
        _items->set_size(Vector2(_items_w, _items_h));
        _items->add_item("stage-0");
        _items->add_item("stage-1");

        _selector->add_child(_items.get());
        _items->set_allow_rmb_select(true);
        _items->set_auto_height(true);
        _items->ensure_current_is_visible();
    }

    std::unique_ptr<ConfirmationDialog> _selector;
    static constexpr int _selector_w = 400;
    static constexpr int _selector_h = 400;
    static constexpr int _selector_font_size = 30;

    std::unique_ptr<ItemList> _items;
    static constexpr int _items_w = 350;
    static constexpr int _items_h = 200;
};

} // namespace godot
