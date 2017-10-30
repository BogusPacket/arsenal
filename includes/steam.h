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
