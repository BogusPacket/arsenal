#include "arsenal.h"
#include "socket.h"

struct SteamMsg_Header = {
  uint64_t steamid;
  int client_sessionid;
  uint32_t routing_appid;
  uint64_t jobid_source;
  uing64_t jobid_target;
  std::string target_job_name;
  int seq_num;
  int eresult;
  std::string error_message;
  uint32_t ip;
  uint32_t auth_account_flags;
  uint32_t token_source;
  bool admin_spoofing_user;
  int transport_error;
  uint64_t messageid;
  uint32_t publisher_group_id;
  uint32_t sysid;
  uint64_t trace_tag;
  uint32_t webapi_key_id;
  bool is_from_external_source;
  uint32_t forward_to_sysid;};

struct SteamMsg_Logon {
	uint32_t protocol_version = 1;
	uint32_t obfustucated_private_ip = 2;
	uint32_t cell_id = 3;
	uint32_t last_session_id = 4;
	uint32_t client_package_version = 5;
	std::string client_language = 6;
	uint32_t client_os_type = 7;
	bool should_remember_password = 8 [default = false];
  std::string wine_version = 9;
  uint32_t ping_ms_from_cell_search = 10;
	uint32_t public_ip = 20;
	uint32_t qos_level = 21;
	int64_t client_supplied_steam_id = 22;
	int machine_id = 30; //ehhhh...
	uint32_t launcher_type = 0;
	uint32_t ui_mode = 0;
	int steam2_auth_ticket = 41;
	std::string email_address = 42;
	int32_t rtime32_account_creation = 43;
	std::string account_name = 50;
	std::string password = 51;
	std::string game_server_token = 52;
	std::string login_key = 60;
	bool was_converted_deprecated_msg = false;
	std::string anon_user_target_account_name;
	int64_t resolved_user_steam_id = 81;
	int32_t eresult_sentryfile = 82;
	sha_sentryfile = 83;
	std::string auth_code = 84;
	int32_t otp_type = 85;
	uint32_t otp_value = 86;
	std::string otp_identifier = 87;
	bool steam2_ticket_request = 88;
	int sony_psn_ticket = 90;
	std::string sony_psn_service_id = 91;
	bool create_new_psn_linked_account_if_needed = false;
	std::string sony_psn_name = 93;
	int32_t game_server_app_id = 94;
	bool steamguard_dont_remember_computer = 95;
	std::string machine_name = 96;
	std::string machine_name_userchosen = 97;
  std::string country_override = 98;
	bool is_steam_box = 99;
	uint64_t client_instance_id = 100;
	std::string two_factor_code = 101;
	bool supports_rate_limit_response = 102;
	std::string web_logon_nonce = 103;
}
