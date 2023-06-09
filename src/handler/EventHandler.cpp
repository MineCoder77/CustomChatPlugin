#include "headers/EventHandler.hpp"

inline EventHandler EventHandler::instance = EventHandler();

inline EventHandler& EventHandler::get_instance() {
	return instance;
}

inline void EventHandler::on_player_chat() {
	Event::PlayerChatEvent::subscribe([](const Event::PlayerChatEvent& event) {
		Player* p = event.mPlayer;
		std::string message = event.mMessage;
		bool is_global = message[0] == '!';
		float pos_x = p->getFeetPosition().x;
		float pos_y = p->getFeetPosition().y;
		float pos_z = p->getFeetPosition().z;
		std::string name = p->getRealName();
		is_global ? ChatManager::send_msg_to_chat(1, ChatManager::remove_letter_msg(message), 
				name, pos_x, pos_y, pos_z) : ChatManager::send_msg_to_chat(0, message, name, pos_x, pos_y, pos_z);
		return false;
	});
}

inline void EventHandler::init() {
	on_player_chat();
}
