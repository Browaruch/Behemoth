CMD:pcmd(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,command[200];
	if(sscanf(params,"ds[200]",userid,command)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /pcmd <id> <komenda>");
	CallLocalFunction("OnPlayerCommandText","ds",userid,command);
	return 1;
}

CMD:filterscript(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new szAREA[1024], buffer[128];
	szAREA = "";
	for(new i = 0; i < 16; i++){
		GetFilterScriptName(i,buffer,sizeof(buffer));
		if(buffer[0] != EOS){
			format(buffer,sizeof buffer,"{FFFFFF}%i. {00FF00}%s\n",i,buffer);
			strcat(szAREA,buffer);
		} else {
			format(buffer,sizeof buffer,"{FFFFFF}%i. {FF0000}---\n",i,buffer);
			strcat(szAREA,buffer);
		}
	}
	format(buffer,sizeof buffer,"{FFFFFF}Filterscript: {909090}%d/16",GetFilterScriptCount());
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_LIST,buffer,szAREA, "OK", "Anuluj");
	return 1;
}

CMD:cvisible(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	FoxForeach(i,Player){
		new buf[127];
		if(!IsPlayerVisible[i]){
			format(buf,sizeof buf,"(%d) %s aktywna niewidzialnoœæ",i,GetPlayerNick(i));
			SendClientMessage(playerid,-1,buf);
		}
	}
	SendClientMessage(playerid, -1, "--");
	return 1;
}

CMD:hideplayer(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /hideplayer <id>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"Nie ma takiego gracza");
	}
	FoxForeach(i,Player){
		HidePlayerForPlayer(i,userid);
	}
	IsPlayerVisible[userid] = false;
	SetPlayerColor(playerid,0x6DC5F300);
	DisableRemoteVehicleCollisions(userid,1);
	return 1;
}

CMD:showplayer(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /showplayer <id>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"Nie ma takiego gracza");
	}
	FoxForeach(i,Player){
		ShowPlayerForPlayer(i,userid);
	}
	IsPlayerVisible[userid] = true;
	SetPlayerColor(playerid,0x6DC5F3FF);
	SetPlayerSkin(userid,GetPlayerSkin(userid));
	DisableRemoteVehicleCollisions(userid,0);
	return 1;
}

CMD:restart(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	if(isnull(params)) return SendClientMessage(playerid,COLOR_ERROR,"U¿ywaj /restart 00:00");
	new buffer[256];
	format(buffer,sizeof(buffer),"Uwaga! O godzinie %s serwer zostanie zrestartowany.",params);
	SendClientMessageToAll(0xFF0000FF," ");
	SendClientMessageToAll(0xFF0000FF,buffer);
	SendClientMessageToAll(0xFF0000FF,"Prosimy do tego momentu zakoñczyæ misjê transportowe.");
	SendClientMessageToAll(0xFF0000FF," ");
	return 1;
}

CMD:przerwatechniczna(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	if(isnull(params)) return SendClientMessage(playerid,COLOR_ERROR,"U¿ywaj /przerwatechniczna 00:00 - 00:00");
	new buffer[256];
	format(buffer,sizeof(buffer),"Uwaga! W godzinach %s serwer bêdzie nie aktywny.",params);
	SendClientMessageToAll(0xFF0000FF," ");
	SendClientMessageToAll(0xFF0000FF,buffer);
	SendClientMessageToAll(0xFF0000FF,"Prosimy do tego momentu zakoñczyæ misjê transportowe.");
	SendClientMessageToAll(0xFF0000FF," ");
	return 1;
}

CMD:odwolaj(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	SendClientMessageToAll(0xFF0000FF," ");
	SendClientMessageToAll(0xFF0000FF,"Planowana przerwa techniczna zosta³a odwo³ana.");
	SendClientMessageToAll(0xFF0000FF," ");
	return 1;
}

CMD:mc(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new buffer[256];
	if(isnull(params)) return SendClientMessage(playerid,COLOR_ERROR,"››› U¿yj: /mc <text>");
	format(buffer,sizeof buffer,"{006666}(Rcon) %s: {00FFFF}%s",GetPlayerNick(playerid),params);
	FoxForeach(i,Player){
		if(gGracz[i][AdminLvl] == LEVEL_HEADADMIN){
			SendClientMessage(i,0xFFFFFFFF,buffer);
		}
	}
	return 1;
}

CMD:kickall(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new buffer[256];
	format(buffer,sizeof(buffer),"{D1D1D1}Administrator {FF0000}%s[%i] {D1D1D1}wyrzuci³ wszystkich z serwera.",GetPlayerNick(playerid),playerid);
	FoxForeach(i,Player){
		if(gGracz[i][AdminLvl] < 4){
			SetTimerEx("KickGracza",200,false,"d",i);
			SendClientMessage(i,-1,buffer);
		}
	}
	return 1;
}

CMD:objreload(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	SendClientMessageToAll(0xFF0000FF,"[IMPORTANT] Trwa prze³adowywanie obiektów...");
	FoxForeach(i,Player){
		TogglePlayerControllable(i,false);
	}
	SendRconCommand("reloadfs saoi_fm");
	UpdateAllDynamicObjects();
	FoxForeach(i,Player){
		TogglePlayerControllable(i,true);
	}
	return 1;
}

CMD:stext(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new buffer[256];
	if(isnull(params)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /stext <text>");
	
	format(buffer,sizeof(buffer),"{C9C9C9}[?]SERVER {909090}[SI]: {E3E3E3}%s",params);
	//format(buffer,sizeof buffer,"{C00000}? {FFFF00}SERVER: {FFFFFF}%s",params);
	SendClientMessageToAll(playerid,buffer);
	return 1;
}

CMD:uptimeall(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	CallToAllScript(playerid,CALL_CHANEL_ID_BROADCAST,0xFF,"none");
	return 1;
}

CMD:callall(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	CheckAllScript(playerid,0);
	return 1;
}

CMD:calldata(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new chanel, errorlevel, data[200];
	if(sscanf(params,"xxs[200]",chanel,errorlevel,data)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /calldata <hex:chanel> <hex:errorlevel> <data>");
	CallToAllScript(playerid,chanel,errorlevel,data);
	return 1;
}

CMD:licho(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	gGracz[playerid][Glod] = 999;
	gGracz[playerid][Zmeczenie] = 999;
	UpdatujPaski(playerid,1);
	UpdatujPaski(playerid,2);
	return 1;
}

CMD:god(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_HEADADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /god <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	SetPlayerHealth(userid,1000000.0);
	SetPlayerArmour(userid,1000000.0);
	return 1;
}

