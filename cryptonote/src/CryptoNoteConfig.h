// Copyright (c) 2017-2018, Intense Coin developers
// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint64_t DIFFICULTY_TARGET                             = 90; // seconds
const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 5000000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 60; // addresses start with "B"
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 10;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 270; // DIFFICULTY_TARGET * (DIFFICULTY_WINDOW_V4 - 1) / 20

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;
const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW_V4          = 11;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY					= UINT64_C(777777700000000); // 7.77M
const uint64_t FINAL_SUBSIDY_PER_MINUTE				= UINT64_C(2000000); // 0.02 BOLD
const unsigned EMISSION_SPEED_FACTOR                         	= 20;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               	= 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     	= 1000000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  	= 1000000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;

const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;
const uint64_t MINIMUM_FEE                                   = UINT64_C(100000);    // pow(10, 5)
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(100000);    // pow(10, 5)

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t  DIFFICULTY_BLOCKS_V2							 = 17;
const size_t  DIFFICULTY_CUT_V2								 = 6;
const size_t  DIFFICULTY_WINDOW_V2							 = DIFFICULTY_BLOCKS_V2 + DIFFICULTY_CUT_V2 * 2;
const size_t  DIFFICULTY_WINDOW_V4							 = 61;


const size_t   MAX_BLOCK_SIZE_INITIAL                        = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR_V2		 = 35 * 100 * 1024;
const size_t   MAX_BLOCK_SIZE_ALLOWED_EVERY_N_BLOCK		     = 5;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       	= 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     	= 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    	= DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                	= 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME 	= 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 15 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 2000000;
const uint32_t UPGRADE_HEIGHT_V2                             = 2;
const uint32_t UPGRADE_HEIGHT_MAX_BLOCK_SIZE                 = 120;
const uint32_t UPGRADE_HEIGHT_V3                             = 3;
const uint32_t UPGRADE_HEIGHT_V4                             = 4;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks

static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  	= "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            	= "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                	= "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       	= "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      	= "miner_conf.json";
} // parameters


const char     CRYPTONOTE_NAME[]                             = "Bold";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  128;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

const int      P2P_DEFAULT_PORT                              =  53940;
const int      RPC_DEFAULT_PORT                              =  53941;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 64 * 1024 * 1024; // 64 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds

const char     P2P_STAT_TRUSTED_PUB_KEY[] = "";

const char* const SEED_NODES[] = {
	"seed1.boldprivate.network:53940",
	"seed2.boldprivate.network:53940",
	"pool.boldprivate.network:53940"
};

struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const CheckpointData CHECKPOINTS[] = {
	{ 2000, "72e998c99196037b05dcf6e7573d8c0febd1f650f70c013e44ea144b416f10f8"}, // 2k
	{ 20000, "63a2c322d0179c5e44243091ea2fea664881a0291037590ac15b534c216e9467"}, // 20k
	{ 50000, "c4995fb8530af096b5923775988daa07b3eef80cd183f209374574264faa226a"}, // 50k
	{ 75000, "aa22e6bc1e489154c84de634a0d78f659d856168782d8afb69f492a159caf3b8"}, // 75k
	{ 100000, "23dac10fe2b1a47346c6fdfc1818b8f6f9c734e1656a2ef177b1c2866e117bf2"}, // 100k
	{ 125000, "58bc7f89114d77e170d5fddd22d354fa253353212ed2f6fb7db79d7b4f3cfaf3"}, // 125k
	{ 150000, "6be2e3d40801e8fbf01bf942a1c5867c980c17c1bf3ac883c423fc513cd451eb"}, // 150k
	{ 175000, "eb74055772c99fdf708b1c8dfcf71df78cde2e589456f46e2e60431ebb803581"}, // 175k
	{ 200000, "347ec0c17cccf437798a25a08633538e7f3d1642a9684ad9cc3b35b418a87dd1"}, // 200k
	{ 225000, "65d6c5ef32a56f9bc80c3491f6a7b93f3dca777e536f61095dd090ab73717aca"}, // 225k
	{ 250000, "d269845d4e0029f01b73056004ea9d4b98d58db6bf333a590b0cec2fe24ff3f9"} // 250k
};
}

#define ALLOW_DEBUG_COMMANDS
