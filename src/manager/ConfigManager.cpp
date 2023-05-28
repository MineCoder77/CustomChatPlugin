#include "headers/ConfigManager.hpp"

JsonConfig JsonConfig::instance = JsonConfig();

JsonConfig& JsonConfig::get_instance() {
	return instance;
}

int JsonConfig::get_radius() {
	return get_config()["settings"]["radius"];
}

nlohmann::json JsonConfig::get_config() {
	return JsonConfig::json_config;
}

void JsonConfig::set_config() {
	std::ifstream file("plugins/CustomChat/settings.json");
	JsonConfig::json_config = nlohmann::json::parse(file);
	file.close();
}

bool JsonConfig::create_file() {
	nlohmann::json j;
	j["settings"]["radius"] = 10;
	j["settings"]["global_chat_view"] = "[{}] <{}> {}";
	j["settings"]["local_chat_view"] = "[{}] <{}> {}";
	std::ofstream file("plugins/CustomChat/settings.json");
	if (!file) {
		file.close();
		return false;
	}
	file << std::setw(4) << j << std::endl;
	file.close();
	return true;
}

bool JsonConfig::isset_config_path() {
	return std::filesystem::exists("plugins/CustomChat");
}

bool JsonConfig::isset_config() {
	return std::filesystem::exists("plugins/CustomChat/settings.json");
}

void JsonConfig::init() {
	if (!isset_config_path()) {
		logger.info("Папка CustomChat не существует. Создаю...");
		std::filesystem::create_directories("plugins/CustomChat");
		logger.info("Папка успешно создана.");
		logger.info("Создаю конфиг settings.json.");
		if (!create_file())
			throw std::runtime_error("Проблемы с созданием конфига. Проверьте права на запись файла.");
		else
			logger.info("Файл settings.json успешно создан!");
	}
	else if (!isset_config()) {
		logger.info("Не найден конфиг settings.json. Создаю новый...");
		if (!create_file())
			throw std::runtime_error("Проблемы с созданием конфига. Проверьте права на запись файла.");
		else
			logger.info("Файл settings.json успешно создан!");
	}
	set_config();
}