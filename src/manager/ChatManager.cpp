#include "headers/ChatManager.hpp"

using namespace std::string_literals;

namespace ChatManager {
	
	inline void send_msg_to_chat(uint8_t type, std::string message, std::string& name, float& pos_x, float& pos_y, float& pos_z) {
		switch (type) {
		case 0:
			Global<Level>->runcmdEx("tellraw @a [x = "s + std::to_string(pos_x) + ", y = "s + 
				std::to_string(pos_y) + ", z = "s + std::to_string(pos_z) + ", r = "s + 
				std::to_string(JsonConfig::get_instance().get_radius()) + "]{\"rawtext\":[{\"text\":\""s + get_local_chat(name, message) + "\"}]}");
			break;
		case 1:
			Global<Level>->runcmdEx("tellraw @a {\"rawtext\": [{\"text\":\""s + get_global_chat(name, message) + "\"}]}");
			break;
		}
	}

	inline std::string remove_letter_msg(std::string& message) {
		return message.erase(0, 1);
	}

	inline std::string get_local_chat(std::string& name, std::string& message) {
		std::string chat = JsonConfig::get_instance().get_config()["settings"]["local_chat_view"];
		return fmt::format(croning_symbol(chat), get_local_prefix(), name, message);
		
	}

	inline std::string get_global_chat(std::string& name, std::string& message) {
		std::string chat = JsonConfig::get_instance().get_config()["settings"]["global_chat_view"];
		return fmt::format(croning_symbol(chat), get_global_prefix(), name, message);
	}
	
	inline std::string get_local_prefix() {
		return JsonConfig::get_instance().get_config()["settings"]["local_prefix"];
	}

	inline std::string get_global_prefix() {
		return JsonConfig::get_instance().get_config()["settings"]["global_prefix"];
	}

	inline std::string croning_symbol(std::string& chat) {
		for (const auto& x : chat)
			chat.replace(chat.find(x), 1, fmt::format("\{}", x));
		return chat;
	}
}


