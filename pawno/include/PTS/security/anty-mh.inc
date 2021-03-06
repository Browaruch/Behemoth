
//Hook: GetPlayerMoney
stock AC_GetPlayerMoney(playerid){
	return gGracz[playerid][p_money];
}

#if defined _ALS_GetPlayerMoney
	#undef GetPlayerMoney
#else
	#define _ALS_GetPlayerMoney
#endif
#define GetPlayerMoney AC_GetPlayerMoney

//Hook: GivePlayerMoney
stock AC_GivePlayerMoney(playerid,money){
	gGracz[playerid][p_money] += money;
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,gGracz[playerid][p_money]);
}

#if defined _ALS_GivePlayerMoney
	#undef GivePlayerMoney
#else
	#define _ALS_GivePlayerMoney
#endif
#define GivePlayerMoney AC_GivePlayerMoney

stock SetPlayerMoney(playerid,money){
	gGracz[playerid][p_money] = money;
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,gGracz[playerid][p_money]);
}

//Hook: GetPlayerScore
stock AC_GetPlayerScore(playerid){
	return gGracz[playerid][p_score];
}

#if defined _ALS_GetPlayerScore
	#undef GetPlayerScore
#else
	#define _ALS_GetPlayerScore
#endif
#define GetPlayerScore AC_GetPlayerScore

//Hook: SetPlayerScore
stock AC_SetPlayerScore(playerid,score){
	gGracz[playerid][p_score] = score;
	SetPlayerScore(playerid,gGracz[playerid][p_score]);
}

#if defined _ALS_SetPlayerScore
	#undef SetPlayerScore
#else
	#define _ALS_SetPlayerScore
#endif
#define SetPlayerScore AC_SetPlayerScore
