#include "atk2ext_asp_user_config.h"

const Atk2ExtFlagMapEntryType atk2ext_flag_user_map[ATK2EXT_ASP_FLAG_USER_NUM] = {
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtTcpTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtEthIfLinkTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtEthInputTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtHBPubTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtHBSubTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtSPDPTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtWriterTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtReaderTask),
		ATK2EXT_FLAG_MAP_ENTRY(Atk2ExtMROS2Task),
		ATK2EXT_FLAG_MAP_ENTRY(MAIN_TASK),
};

Atk2ExtFlagMapEntryType* cmsis_get_flag_user_map(void)
{
	return atk2ext_flag_user_map;
}

int cmsis_get_flag_user_num(void)
{
	return ATK2EXT_ASP_FLAG_USER_NUM;
}
