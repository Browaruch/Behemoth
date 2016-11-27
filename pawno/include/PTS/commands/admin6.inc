CMD:przeladujtowary(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_VICEHEADADMIN) return 0;
	new buffer[256];
	for(new i = 0, j = sizeof(punktyzaladunku); i < j; i++){
		ResetujTowary(i);
	}
	format(buffer,sizeof(buffer),"{D1D1D1}Admin {05A9FF}%s[%i] {D1D1D1}prze³adowa³ wszystkie towary.",GetPlayerNick(playerid),playerid);
	SendClientMessageToAll(COLOR_WHITE,buffer);
	format(buffer,sizeof(buffer),"[Towary]%s",GetPlayerNick(playerid));
	WriteLog(buffer,LOG_FILE_ADMIN);
	return 1;
}