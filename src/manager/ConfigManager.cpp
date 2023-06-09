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
	j["settings"]["global_prefix"] = "Глобально";
	j["settings"]["local_prefix"] = "Локально";
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

bool JsonConfig::check_config_correct() {
	if (!get_config()["settings"]["radius"].is_number() || !get_config()["settings"]["radius"].is_number_integer()) {
		logger.error("Радиус должен быть числом целочисленного типа!");
		return false;
	}
	if (!get_config()["settings"]["local_chat_view"].is_string()) {
		logger.error("Оформление локального чата должно быть строкой!");
		return false;
	}
	if (!get_config()["settings"]["global_chat_view"].is_string()) {
		logger.error("Оформление глобального чата должно быть строкой!");
		return false;
	}
	if (!get_config()["settings"]["local_prefix"].is_string()) {
		logger.error("Оформление префикса локального чата должно быть строкой!");
		return false;
	}
	if (!get_config()["settings"]["global_prefix"].is_string()) {
		logger.error("Оформление префикса глобального чата должно быть строкой!");
		return false;
	}
	return true;
}

void JsonConfig::init() {
	if (!isset_config_path()) {
		logger.info("Папка CustomChat не существует. Создаю...");
		std::filesystem::create_directories("plugins/CustomChat");
		logger.info("Папка успешно создана.");
		logger.info("Создаю конфиг settings.json.");
		!create_file() ? logger.error("Проблемы с созданием конфига. Проверьте права на запись файла.") : 
			logger.info("Файл settings.json успешно создан!");
	}
	else if (!isset_config()) {
		logger.info("Не найден конфиг settings.json. Создаю новый...");
		!create_file() ? logger.error("Проблемы с созданием конфига. Проверьте права на запись файла.") :
			logger.info("Файл settings.json успешно создан!");
	}
	set_config();
	check_config_correct() ? logger.info("Конфиг-файл настроен правильно. Плагин работает!") : 
		logger.error("В конфиг-файле были найдены ошибки. Пока Вы их не исправите, код не будет работать!");
	
}