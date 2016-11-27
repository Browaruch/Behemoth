CMD:rozbroj(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new string[900], string2[900], id;
	if(sscanf(params,"d",id)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /rozbroj <id>");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Brak po³¹czonego gracza o takim ID");
	} else {
		format(string2,sizeof(string2),"{A4FA0F}Zresetowa³eœ bronie: {C4C4C4}%s[%i]",GetPlayerNick(id),id);
		SendClientMessage(playerid,COLOR_RED,string2);
		ResetPlayerWeapons(id);
		format(string,sizeof(string),"{A4FA0F}Admin: {C4C4C4}%s {A4FA0F}rozbroi³ ciê",GetPlayerNick(playerid));
		SendClientMessage(id,COLOR_RED,string);
		gGracz[id][AdminDalBron] = false;
		gGracz[id][PozwolenieBron] = false;
	}
	return 1;
}

CMD:da(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new string[900], string2[900], Float:distance;
	if(sscanf(params,"f",distance)) return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /da <zasiêg>");
	
	format(string2,sizeof(string2),"{A4FA0F}Rozbroi³eœ graczy w zasiêgu: {C4C4C4}%.0f metrów",distance);
	SendClientMessage(playerid,COLOR_RED,string2);
	format(string,sizeof(string),"{A4FA0F}Admin: {C4C4C4}%s {A4FA0F}rozbroi³ ciê",GetPlayerNick(playerid));
	new int, vw;
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= distance){
				ResetPlayerWeapons(i);
				SendClientMessage(i,COLOR_RED,string);
				gGracz[i][AdminDalBron] = false;
				gGracz[i][PozwolenieBron] = false;
				SendClientMessage(i,COLOR_GREEN,string);
			}
		}
	}
	return 1;
}

CMD:invisible(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /invisible <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	if(!IsPlayerVisible[userid] || (GetPlayerWantedLevel(userid) <= 0)){
		SetPlayerColor(userid,0x6DC5F300);
	} else {
		SetPlayerColor(userid,0xFFA50000);
	}
	return 1;
}

CMD:visible(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /visible <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	if(!IsPlayerVisible[userid]){
		SetPlayerColor(userid,0x6DC5F300);
	} else if(GetPlayerWantedLevel(userid) <= 0){
		SetPlayerColor(userid,0x6DC5F3FF);
	} else {
		SetPlayerColor(userid,0xFFA500FF);
	}
	return 1;
}

CMD:tankujall(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new buffer[256];
	for(new i = 0; i < MAX_VEHICLES; i++){
		Paliwo[i] = GetVehicleMaxFuel(GetVehicleModel(i));
	}
	format(buffer,sizeof(buffer),"Wszystkie pojazdy zosta³y zatankowane (%s)",GetPlayerNick(playerid));
	SendClientMessageToAll(COLOR_ORANGE,buffer);
	return 1;
}

CMD:jail(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new id, czas, powod[100], string[256];

	if(sscanf(params,"dds[100]",id,czas,powod)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /jail [ID] [Czas] [Powód]!");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	} else if(gGracz[id][StatusJail] == false){
		return SendClientMessage(playerid,COLOR_RED,"Ten gracz jest w wiêzieniu!");
	} else if(gGracz[playerid][AdminLvl] < 6 && czas > 25){
		SendClientMessage(playerid,COLOR_RED,"Wpisa³eœ za du¿o czasu jak na twoj¹ rangê!");
	} else if(gGracz[id][AdminLvl] > gGracz[playerid][AdminLvl]){
		SendClientMessage(playerid,COLOR_RED,"Gracz ma wy¿sz¹ rangê!");
	} else {
		gGracz[id][LicznikPrzejecia] = 0;
		SetPlayerInterior(id,6);
		SetPlayerPos(id,264.7467,77.5671,1001.0391);
		format(string,sizeof(string),"Gracz %s [%i] zosta³ uwiêziony na: %d minut przez admina %s[%i]. Powód: %s",GetPlayerNick(id),id,czas,GetPlayerNick(playerid),playerid,powod);
		gGracz[id][StatusJail] = false;

		SendClientMessageToAll(COLOR_RED,string);
		SendClientMessage(id,COLOR_WHITE,"Zosta³eœ zamkniêty w Admin Jail");
		GameTextForPlayer(id,"~r~Wiezienie",5000,3);
		SetPlayerHealth(id, 999999999);
		gGracz[id][Kajdanki] = 0;
		TogglePlayerControllable(id, 1);
		gGracz[id][CzasAJ] = czas*60;
		format(string,sizeof(string),"[Jail]%s > %s: %s [%i min.]",GetPlayerNick(playerid),GetPlayerNick(id),powod,czas);
		WriteLog(string,LOG_FILE_ADMIN);
	}
	return 1;
}

CMD:spawn(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	SetPlayerPos(playerid,1464.6426,2802.1094,10.8203);
	SetPlayerFacingAngle(playerid,212.1499);
	return 1;
}

CMD:settime(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new godzina,string[256];

	if(sscanf(params,"i",godzina)){
		return SendClientMessage(playerid,0xFF0000FF,"Wpisz /settime [Godzina]");
	} else if((godzina < 0 || godzina > 23) && godzina != -1){
		return SendClientMessage(playerid,0xFF0000FF,"Wartoœæ musi mieœciæ siê w przedziale od 0 do 23 lub -1");
	} else {
		GameRealTime = godzina;
		if(godzina == -1){
			gettime(godzina);
			SetWorldTime(godzina);
			format(string,sizeof(string),"{FF6B78}Administrator {D4D4D4}%s [%i] {FF6B78}zmieni³ wszystkim godzine na czas realny!",GetPlayerNick(playerid),playerid);
		} else {
			SetWorldTime(godzina);
			format(string,sizeof(string),"{FF6B78}Administrator {D4D4D4}%s [%i] {FF6B78}zmieni³ wszystkim godzine na {D4D4D4}%d:00{FF6B78}!",GetPlayerNick(playerid),playerid,godzina);
		}
		SendClientMessageToAll(0xDFDFDFAA,string);
	}
	return 1;
}

CMD:jetpack(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	SendClientMessage(playerid,COLOR_WHITE,"Doste³eœ/³aœ jetpack'a!");
	SetPlayerVelocity(playerid,0,0,1);
	SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USEJETPACK);
	return 1;
}

CMD:openall(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	for(new i = 0, j = GetVehiclePoolSize(); i <= j; i++){
		if(!IsVehicleInUse(i)){
			new engine,lights,alarm,bonnet,boot,doors,objective;
			GetVehicleParamsEx(i,engine,lights,alarm,doors,bonnet,boot,objective);
			SetVehicleParamsEx(i,engine,lights,alarm,0,bonnet,boot,objective);
		}
	}
	SendClientMessageToAll(COLOR_INFO,"Wszystkie nieu¿ywane pojazdy zosta³y otwarte!");
	return 1;
}

CMD:a(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new buffer[256];
	if(sscanf(params,"s[200]",buffer)){
		return SendClientMessage(playerid,COLOR_RED,"Wpisz: /a [text]!");
	} else {
		format(buffer,sizeof(buffer),"[Admin] {BFBFBF}%s [%i]: {BFBFBF}%s",GetPlayerNick(playerid),playerid,buffer);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
	}
	return 1;
}

/*
 else if(!CG_ProtVar::cgod_clear[id] || !CG_ProtVar::cgod_clear[doid] || !IsPlayerVisible[doid]){
		return SendClientMessage(playerid,COLOR_RED,"Nie mo¿na przenieœæ tego gracza");
	}
*/

CMD:tp(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_JUNIORADMIN) return 0;
	new Float:Px,Float:Py,Float:Pz,id,doid,buffer[300];
	
	if(sscanf(params,"dd",id,doid)){
		return SendClientMessage(playerid, COLOR_WHITE, "U¿yj: /Tp [ID 1 gracza] [do ID 2 gracza]");
	} else if(!IsPlayerConnected(id) || !IsPlayerConnected(doid)){
		return SendClientMessage(playerid,COLOR_RED,"Jeden z graczy nie jest w grze");
	} else {
		SetPlayerInterior(id,GetPlayerInterior(doid));
		GetPlayerPos(doid,Px,Py,Pz);
		SetPlayerPos(id,Px,Py,Pz);
		gGracz[id][NewX] = Px;
		gGracz[id][NewY] = Py;
		gGracz[id][NewZ] = Pz;
		SetPlayerVirtualWorld(id,GetPlayerVirtualWorld(doid));
		format(buffer,sizeof(buffer),"Teleportowa³eœ %s do %s",GetPlayerNick(id),GetPlayerNick(doid));
		SendClientMessage(playerid,COLOR_PURPLE,buffer);
		format(buffer,sizeof(buffer),"[Teleport]%s: %s <do> %s",GetPlayerNick(playerid),GetPlayerNick(id),GetPlayerNick(doid));
		WriteLog(buffer,LOG_FILE_ADMIN);
	}
	return 1;
}