CMD:vrespawn(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_SVIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium SVIP");
	new buffer[500];
	if(VrespawnCount == 0 && AutomatycznyRespawnB == false){
		format(buffer,sizeof(buffer),"Gracz %s[%i] wywo�uje g�osowanie o respawn. {D1D1D1}U�yj /tak lub /nie, aby zag�osowa�.",GetPlayerNick(playerid),playerid);
		SendClientMessageToAll(COLOR_YELLOW,buffer);
		SendClientMessage(playerid,COLOR_WHITE,"G�osowanie zako�czy si� za 2 minuty.");
		VrespawnCount = 700;
		SetTimer("DoRespawnuVIP",2*60000,false);
		VGlosowTak = 0;
		VGlosowNie = 0;
		NickRSP = GetPlayerNick(playerid);
	} else {
		SendClientMessage(playerid,COLOR_RED,"Niedawno wywo�ano g�osowanie o respawn, odczekaj..");
	}
	return 1;
}
