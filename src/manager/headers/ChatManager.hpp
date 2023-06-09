#pragma once

#include "ConfigManager.hpp"
#include <llapi/mc/Level.hpp>

namespace ChatManager {
	void send_msg_to_chat(uint8_t type, std::string message, std::string& name, float& pos_x, float& pos_y, float& pos_z);
	std::string remove_letter_msg(std::string& message);
	std::string get_local_chat(std::string& name, std::string& message);
	std::string get_global_chat(std::string& name, std::string& message);
	std::string get_global_prefix();
	std::string get_local_prefix();
	std::string croning_symbol(std::string& chat);
}