#pragma once

#include "ConfigManager.hpp"
#include <llapi/mc/Level.hpp>

namespace ChatManager {
	const char GLOBAL_PREFIX = 'G';
	const char LOCAL_PREFIX = 'L';
	void send_msg_to_chat(int type_message, std::string message, std::string& name, int& pos_x, int& pos_y, int& pos_z);
	std::string remove_letter_msg(std::string& message);
	std::string get_local_chat(std::string& name, std::string& message);
	std::string get_global_chat(std::string& name, std::string& message);
}