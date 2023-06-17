#pragma once

#include <nlohmann/json.hpp>
#include <llapi/LoggerAPI.h>

extern Logger logger;

class JsonConfig {
private:
	nlohmann::json json_config;
	bool create_file();
	bool isset_config_path();
	bool isset_config();
	void set_config();
	static JsonConfig instance;
	JsonConfig() {}
	JsonConfig(const JsonConfig&) = delete;
	JsonConfig& operator=(JsonConfig&) = delete;
	bool is_config_correct();
public:
	void init();
	static JsonConfig& get_instance();
	int get_radius();
	nlohmann::json get_config();
};
