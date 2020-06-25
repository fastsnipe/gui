#include "mojang.hpp"
#include "../http/http.hpp"
namespace mojang {
	std::string last_error = "";
}
bool mojang::name_taken(std::string name) {
	if (name.length() > 16) {
		return false; // name is longer than 16 letters
	}

	const auto res = http::get((std::string("https://api.mojang.com/users/profiles/minecraft/") + std::string(name)).c_str());
	return res.length() > 0;
}
std::string mojang::get_uuid_for_prevname(std::string prevname) {
	const auto now = std::chrono::system_clock::now();
	const auto ts = (std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count() - 2629000L) / 1000L;
	char url[512] = "";
	sprintf_s(url, 512, "https://api.mojang.com/users/profiles/minecraft/%s?at=%lld", prevname.c_str(), ts);
	const auto res = http::get(url);
	if (res.length() == 0) {
		return "";
	}
	const auto j = json::parse(res);
	if (j["id"].is_null()) return "";
	return j["id"].get<std::string>();
}

int64_t mojang::get_time_of_change(const std::string uuid, const std::string name) {
	char url[512] = "";
	sprintf_s(url, 512, "https://api.mojang.com/user/profiles/%s/names", uuid.c_str());
	const auto res = http::get(url);
	if (res.length() == 0)
		return 0L;
	int64_t time = 0;	
	auto j = json::parse(res);
	auto found = false;
	for (auto& obj : j) {
		if (obj["name"].is_null())
			continue;
		if (found) {
			time = obj["changedToAt"].get<int64_t>();
			break;
		}
		if (obj["name"].get<std::string>() == name) {
			found = true;
		}
	} 
	return time;
}

void mojang::change_name(const std::string uuid, const std::string password, const std::string token, const std::string name) {
	char url[512] = "";
	sprintf_s(url, 512, "https://api.mojang.com/user/profile/%s/name", uuid.c_str());
	json d = {
		{"name", name},
		{"password", password}
	};
	const auto res = http::post(url, d.dump().c_str(), token.c_str());
	printf("name change resp %s\n", res.c_str());
}

bool mojang::validate(const std::string token) {
	json j = {
		{"accessToken", token}
	};
	auto resp = http::post("https://authserver.mojang.com/validate", j.dump().c_str());
	if (resp.length() == 0) return true;
	auto j2 = json::parse(resp);
	last_error = j2["errorMessage"].get<std::string>();
	return false;
}

login_response_t mojang::login_with_token(const std::string token) {
	login_response_t res;

	auto token_valid = validate(token);
	if (!token_valid) {
		res.successful = false;
		return res;
	}
	
	auto mc_resp = http::get("https://api.mojang.com/user/profiles/agent/minecraft", token.c_str());
	auto mc_j = json::parse(mc_resp);
	if (!mc_j.is_array() && !mc_j["error"].is_null()) {
		// getting mc failed, error out
		last_error = mc_j["errorMessage"].get<std::string>();
		res.successful = false;
		return res;
	}
	res.successful = true;
	res.uuid = mc_j[0]["id"].get<std::string>();
	res.username = mc_j[0]["name"].get<std::string>();
	
	return res;
}