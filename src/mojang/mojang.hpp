#pragma once
#include "../dependencies/common_includes.hpp"

struct login_response_t {
	bool successful = false;
	std::string id;
	std::string access_token;
	std::string client_token;

	std::string uuid;
	std::string username;
};

namespace mojang {
	extern std::string last_error;
	inline std::string get_last_error() {
		return last_error;
	}

	bool name_taken(std::string name);
	std::string get_uuid_for_prevname(std::string prevname);
	int64_t get_time_of_change(const std::string uuid, const std::string name);
	void change_name(const std::string uuid, const std::string password, const std::string token, const std::string name);
	bool validate(const std::string token);
	login_response_t login_with_token(const std::string token);
}