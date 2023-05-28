#include "headers/ChatManager.hpp"

using namespace std::string_literals;

namespace ChatManager {
	
	inline void send_msg_to_chat(int type, std::string message, std::string& name, int& pos_x, int& pos_y, int& pos_z) {
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

	inline std::string remove_letter_msg(std::string& message)
	{
		return message.erase(0, 1);;
	}

	std::string get_local_chat(std::string& name, std::string& message) {
		return fmt::format(JsonConfig::get_instance().get_config()["settings"]["local_chat_view"], LOCAL_PREFIX, name, message);
	}

	std::string get_global_chat(std::string& name, std::string& message) {
		return fmt::format(JsonConfig::get_instance().get_config()["settings"]["global_chat_view"], GLOBAL_PREFIX, name, message);
	}

}


