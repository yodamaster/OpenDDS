#ifndef FACE_TS_COMMON_HPP_HEADER_FILE
#define FACE_TS_COMMON_HPP_HEADER_FILE
#include "common.hpp"


namespace FACE {

typedef Char CONNECTION_NAME_TYPE[64];

typedef Long MESSAGE_SIZE_TYPE;

typedef LongLong MESSAGE_INSTANCE_GUID;
typedef LongLong MESSAGE_SOURCE_GUID;
typedef LongLong MESSAGE_TYPE_GUID;

/**
 * OpenDDS only has Directions of SOURCE or DESTINATION
 * Therefore mappings for CONNECTION_DIRECTION_TYPE values are:
 * SOURCE mappings:
 *   ONE_WAY_REQUEST_SOURCE
 *   TWO_WAY_REQUEST_SYNCHRONOUS_SOURCE
 *   TWO_WAY_REQUEST_REPLY_ASYNCHRONOUS_SOURCE
 * DESTINATION mappings:
 *   ONE_WAY_REQUEST_DESTINATION
 *   TWO_WAY_REQUEST_SYNCHRONOUS_DESTINATION
 *   TWO_WAY_REQUEST_REPLY_ASYNCHRONOUS_DESTINATION
 * ERROR mappings (NOT SUPPORTED):
 *   BI_DIRECTIONAL
 *   NOT_DEFINED_CONNECTION_DIRECTION_TYPE
 */
enum CONNECTION_DIRECTION_TYPE {
  SOURCE,
  DESTINATION,
  BI_DIRECTIONAL,
  ONE_WAY_REQUEST_SOURCE,
  ONE_WAY_REQUEST_DESTINATION,
  TWO_WAY_REQUEST_SYNCHRONOUS_SOURCE,
  TWO_WAY_REQUEST_SYNCHRONOUS_DESTINATION,
  TWO_WAY_REQUEST_REPLY_ASYNCHRONOUS_SOURCE,
  TWO_WAY_REQUEST_REPLY_ASYNCHRONOUS_DESTINATION,
  NOT_DEFINED_CONNECTION_DIRECTION_TYPE
};

typedef LongLong CONNECTION_ID_TYPE;

typedef LongLong WRITER_ID_TYPE;

typedef LongLong TRANSACTION_ID_TYPE;

enum CONNECTION_TYPE {
  SAMPLING_PORT,
  QUEUING_PORT,
  SOCKET,
  MQ,
  SHM,
  CORBA,
  DDS
};

typedef Boolean WAITSET_TYPE[32];

enum QUEUING_DISCIPLINE_TYPE {
  FIFO,
  PRIORITY,
  NOT_DEFINED_QUEUING_DISCIPLINE_TYPE
};

// INET is used as an enumerator by FACE spec but collides
// with a macro defined by system headers on VxWorks.
#ifndef ACE_VXWORKS
#define DOMAIN_INET INET
#endif

enum CONNECTION_DOMAIN_TYPE {
  UNIX,
  DOMAIN_INET,
  NOT_DEFINED_CONNECTION_DOMAIN_TYPE
};

enum SOCKET_TYPE {
  STREAM,
  DGRAM,
  SEQPACKET,
  NOT_DEFINED_SOCKET_TYPE
};

enum RECEIVE_FLAG_TYPE {
  PEEK,
  OOB_RECEIVE_FLAG_TYPE,
  WAITALL,
  NOT_DEFINED_RECEIVE_FLAG_TYPE
};

enum SEND_FLAG_TYPE {
  EOR,
  OOB_SEND_FLAG_TYPE,
  NOSIGNAL,
  NOT_DEFINED_SEND_FLAG_TYPE
};

enum VALIDITY_TYPE {
  INVALID,
  VALID
};

enum MESSAGING_PATTERN_TYPE {
  PUB_SUB,
  CLIENT,
  SERVER
};

typedef Long WAITING_RANGE_TYPE;

struct TRANSPORT_CONNECTION_STATUS_TYPE {
  MESSAGE_RANGE_TYPE MESSAGE;
  MESSAGE_RANGE_TYPE MAX_MESSAGE;
  MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
  CONNECTION_DIRECTION_TYPE CONNECTION_DIRECTION;
  WAITING_RANGE_TYPE WAITING_PROCESSES_OR_MESSAGES;
  SYSTEM_TIME_TYPE REFRESH_PERIOD;
  VALIDITY_TYPE LAST_MSG_VALIDITY;
};

namespace TS {

struct MessageHeader
{
  MESSAGE_INSTANCE_GUID message_instance_guid;
  MESSAGE_TYPE_GUID platform_view_guid;
  MESSAGE_SOURCE_GUID message_source_guid;
  SYSTEM_TIME_TYPE message_timestamp;
  VALIDITY_TYPE message_validity;

  bool operator==(const MessageHeader& rhs) const;
};
}

}

#endif
