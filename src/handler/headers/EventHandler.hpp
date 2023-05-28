#pragma once

#include <llapi/EventAPI.h>
#include <llapi/mc/ColorFormat.hpp>
#include <llapi/mc/Player.hpp>
#include <llapi/mc/Vec3.hpp>
#include "../../manager/headers/ChatManager.hpp"

class EventHandler {
private:
	EventHandler() {}
	static EventHandler instance;
	void on_player_chat();
	EventHandler(const EventHandler&) = delete;
	EventHandler& operator=(EventHandler&) = delete;
public:
	void init();
	static EventHandler& get_instance();
};
