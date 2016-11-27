CMD:odlicz(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new czas, buffer[256];
	if(LastOdlicz != 0) return SendClientMessage(playerid,COLOR_ERROR,"Musi minac przynajmniej 35 sekund od ostatniego odliczania.");
	if(sscanf(params,"d",czas)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /odlicz <sekundy>");
	if(czas < 3 || czas > 30) return SendClientMessage(playerid,COLOR_ERROR,"Zakres sekund 3 - 30");
	LastOdlicz = czas;
	Odliczanie(czas,0,0,playerid);
	format(buffer,sizeof(buffer),"{A4FA0F}Admin: {C4C4C4}%s {A4FA0F}uruchomil odliczanie.",GetPlayerNick(playerid));
	SendClientMessageToAll(0xFFFFFFFF,buffer);
	return 1;
}

CMD:count(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new czas, isFreeze, Float:distance, buffer[127];

	if(sscanf(params,"dfd",czas,distance,isFreeze)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /count <czas: 3-30> <zasieg: 1-100> <zamrozenie: 0-1>");

	if(distance > 100.0 || distance < 1.0) return SendClientMessage(playerid,COLOR_ERROR,"Dopuszczalny zasieg: 1-100");
	if(czas < 3 || czas > 30) return SendClientMessage(playerid,COLOR_ERROR,"Dopuszczalny czas: 3-30");
	if(isFreeze > 1 || isFreeze < 0) return SendClientMessage(playerid,COLOR_ERROR,"Dopuszczalne tryby: 0 - brak zamrozenia, 1 - zamrozenie.");
	
	LastOdlicz = czas;
	Odliczanie(czas,distance,isFreeze,playerid);
	format(buffer,sizeof buffer,"%s (%d) uruchomi³/a odliczanie (Zamro¿enie: %s | Czas: %ds | Zasiêg: %.0fm)",GetPlayerNick(playerid),playerid,isFreeze?("TAK"):("NIE"),czas,distance);
	MSGToAdmins(COLOR_RED,buffer,LEVEL_ADMIN);
	return 1;
}

CMD:dajbron(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new id, idbroni, ammount;
	new string[1000],string2[300];
	if(sscanf(params,"ddd",id,idbroni,ammount)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /dajbron [ID] [Id broni] [Amunicja]");
	} else if(!IsPlayerConnected(id)){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza");
	} else if(idbroni > 46){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiej broni");
	} else {
		gGracz[id][AdminDalBron] = true;
		GivePlayerWeapon(id,idbroni,ammount);
		format(string,sizeof(string),"{C3C3C3}Da³eœ graczowi {3374CC}%s [%i]{C3C3C3}: {3374CC}%s {C3C3C3}z amunicj¹ {3374CC}%d.",GetPlayerNick(id),id,GetGunName(idbroni),ammount);
		format(string2,sizeof(string2),"{3374CC}Admin {C3C3C3}%s[%i] {3374CC}da³ ci broñ: {C3C3C3}%s {3374CC}z amunicj¹ {C3C3C3}%d.",GetPlayerNick(playerid),playerid,GetGunName(idbroni),ammount);
		SendClientMessage(playerid,COLOR_GREEN,string);
		SendClientMessage(id,COLOR_GREEN,string2);
		format(string,sizeof(string),"BRON: %s > %s: %s(%i)",GetPlayerNick(playerid),GetPlayerNick(id),GetGunName(idbroni),ammount);
		WriteLog(string,LOG_FILE_ADMIN);
	}
	return 1;
}

CMD:givegun(playerid,params[])	return cmd_dajbron(playerid,params);

CMD:gun50(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new idbroni, ammount;
	new string[256];
	if(sscanf(params,"dd",idbroni,ammount)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /gun50 [Id broni] [Amunicja]");
	} else if(idbroni > 46){
		return SendClientMessage(playerid,COLOR_RED,"Nie ma takiej broni");
	} else {
		new int, vw;
		int = GetPlayerInterior(playerid);
		vw = GetPlayerVirtualWorld(playerid);
		format(string,sizeof(string),"{3374CC}Admin {C3C3C3}%s[%i] {3374CC}da³ ci broñ: {C3C3C3}%s {3374CC}z amunicj¹ {C3C3C3}%d.",GetPlayerNick(playerid),playerid,GetGunName(idbroni),ammount);
		FoxForeach(i,Player){
			if(playerid == i) continue;
			if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
				if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
					gGracz[i][AdminDalBron] = true;
					GivePlayerWeapon(i,idbroni,ammount);
					SendClientMessage(i,COLOR_GREEN,string);
				}
			}
		}
	}
	format(string,sizeof(string),"BRON: %s > 50M: %s(%i)",GetPlayerNick(playerid),GetGunName(idbroni),idbroni);
	WriteLog(string,LOG_FILE_ADMIN);
	return 1;
}

CMD:acolor(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,color;
	if(sscanf(params,"dx",userid,color)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /acolor <id gracza> <RGB>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	SetPlayerColor(userid,RGBToRGBA(color,0xFF));
	return 1;
}

CMD:uncolor(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /unacolor <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	if(!IsPlayerVisible[userid]){
		SetPlayerColor(userid,0x6DC5F300);
	} else if(GetPlayerWantedLevel(userid) <= 0){
		SetPlayerColor(userid,0x6DC5F3FF);
	} else {
		SetPlayerColor(userid,COLOR_ORANGE);
	}
	return 1;
}

CMD:acolor50(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new color;
	if(sscanf(params,"x",color)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /acolor50 <RGB>");
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SetPlayerColor(i,RGBToRGBA(color,0xFF));
			}
		}
	}
	return 1;
}

CMD:inserttoveh(playerid,params[]){
    if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
    new userid, vehid, pass = 0;
    if(sscanf(params,"ddd",userid,vehid,pass)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /inserttoveh <playerid> <vehicleid> <passenger 0-3>");
    PutPlayerInVehicle(userid,vehid,pass);
    return 1;
}

CMD:tpcar(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:x,Float:y,Float:z,vehicleid = strval(params);
	if(!IsValidVehicle(vehicleid)) return SendClientMessage(playerid,COLOR_ERROR,"Pojazd nie istnieje");
	GetPlayerPos(playerid,x,y,z);
	SetVehiclePos(vehicleid,x,y,z+2.0);
	return 1;
}

CMD:tpto(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:P[3],int,vw;
	if(sscanf(params,"fffI(-1)I(-1)",P[0],P[1],P[2],int,vw)) return SendClientMessage(playerid, 0xFFFFFFFF, "/tpto <X> <Y> <Z> [interior] [virtualworld]");
	SetPlayerPos(playerid,P[0],P[1],P[2]);
	if(int > -1) SetPlayerInterior(playerid,int);
	if(vw > -1) SetPlayerVirtualWorld(playerid,vw);
	return 1;
}

CMD:ptpto(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,Float:P[3],int,vw,Float:angle;
	if(sscanf(params,"dfffI(-1)I(-1)F(-1)",userid,P[0],P[1],P[2],int,vw,angle)) return SendClientMessage(playerid, 0xFFFFFFFF, "/ptpto <id> <X> <Y> <Z> [interior] [virtualworld] [angle]");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	SetPlayerPos(userid,P[0],P[1],P[2]);
	if(angle != -1) SetPlayerFacingAngle(userid,angle);
	if(int > -1) SetPlayerInterior(userid,int);
	if(vw > -1) SetPlayerVirtualWorld(userid,vw);
	return 1;
}

CMD:ntpto(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,Float:P[3],int,vw,Float:angle;
	if(sscanf(params,"dfffI(-1)I(-1)F(-1)",userid,P[0],P[1],P[2],int,vw,angle)) return SendClientMessage(playerid, 0xFFFFFFFF, "/ntpto <id> <X> <Y> <Z> [interior] [virtualworld] [angle]");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	FCNPC_SetPosition(userid,P[0],P[1],P[2]);
	if(angle != -1) FCNPC_SetAngle(userid,angle);
	if(int > -1) FCNPC_SetInterior(userid,int);
	if(vw > -1) FCNPC_SetVirtualWorld(userid,vw);
	return 1;
}

CMD:setint(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new int,userid;
	if(sscanf(params,"dd",userid,int)){
		return SendClientMessage(playerid,0xFFFFFFFF,"/setint <id gracza> <interior>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	} else if(int<0){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nieprawidlowy numer interioru (interiory ujemne nie wystepuja w GTA)!");
	}
	SetPlayerInterior(userid,int);
	return 1;
}

CMD:setvw(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new vw,userid;
	if(sscanf(params,"dd",userid,vw)){
		return SendClientMessage(playerid,0xFFFFFFFF,"/setvw <id gracza> <vw>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	}
	SetPlayerVirtualWorld(userid,vw);

	return 1;
}

CMD:front(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:dist,userid,Float:P[4];

	if(isnull(params)) return SendClientMessage(playerid,0xFFFFFFFF,"/front [id] <odleglosc>");

	if(!sscanf(params,"df",userid,dist)){
		if(!IsPlayerConnected(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest podlaczony");
		} else if (!IsPlayerSpawnedEx(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest zespawnowany");
		}
	} else if (!sscanf(params,"f",dist)){
		userid=playerid;
	}

	if(IsPlayerInAnyVehicle(userid)){
		new vehid;
		vehid = GetPlayerVehicleID(userid);
		GetVehiclePos(vehid,P[0],P[1],P[2]);
		new Float:V[3];
		GetVehicleVelocity(vehid,V[0],V[1],V[2]);
		GetVehicleZAngle(vehid,P[3]);
		GetPointInFront2D(P[0],P[1],P[3],dist,P[0],P[1]);
		SetVehiclePos(vehid,P[0],P[1],P[2]);
		SetVehicleVelocity(vehid,V[0],V[1],V[2]);
	} else {
		GetPlayerPos(userid,P[0],P[1],P[2]);
		GetPlayerFacingAngle(userid,P[3]);
		GetPointInFront2D(P[0],P[1],P[3],dist,P[0],P[1]);
		SetPlayerPos(userid,P[0],P[1],P[2]);
	}

	return 1;
}

CMD:wprzod(playerid,params[]) return cmd_front(playerid,params);

CMD:left(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:dist,userid,Float:P[4];

	if(isnull(params)) return SendClientMessage(playerid,0xFFFFFFFF,"/left [id] <odleglosc>");

	if(!sscanf(params,"df",userid,dist)){
		if(!IsPlayerConnected(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest podlaczony");
		} else if (!IsPlayerSpawnedEx(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest zespawnowany");
		}
	} else if (!sscanf(params,"f",dist)){
		userid = playerid;
	}

	if(IsPlayerInAnyVehicle(userid)){
		new vehid;
		vehid = GetPlayerVehicleID(userid);
		GetVehiclePos(vehid,P[0],P[1],P[2]);
		new Float:V[3];
		GetVehicleVelocity(vehid,V[0],V[1],V[2]);
		GetVehicleZAngle(vehid,P[3]);
		GetPointInFront2D(P[0],P[1],CompRotationFloat(P[3]+90.0),dist,P[0],P[1]);
		SetVehiclePos(vehid,P[0],P[1],P[2]);
		SetVehicleVelocity(vehid,V[0],V[1],V[2]);
	} else {
		GetPlayerPos(userid,P[0],P[1],P[2]);
		GetPlayerFacingAngle(userid,P[3]);
		GetPointInFront2D(P[0],P[1],CompRotationFloat(P[3]+90.0),dist,P[0],P[1]);
		SetPlayerPos(userid,P[0],P[1],P[2]);
	}

	return 1;
}

CMD:wlewo(playerid,params[]) return cmd_left(playerid,params);

CMD:right(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:dist,userid,Float:P[4];

	if(isnull(params)) return SendClientMessage(playerid,0xFFFFFFFF,"/right [id] <odleglosc>");

	if(!sscanf(params,"df",userid,dist)){
		if(!IsPlayerConnected(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest podlaczony");
		} else if (!IsPlayerSpawnedEx(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest zespawnowany");
		}
	} else if (!sscanf(params,"f",dist)){
		userid = playerid;
	}

	if(IsPlayerInAnyVehicle(userid)){
		new vehid;
		vehid = GetPlayerVehicleID(userid);
		GetVehiclePos(vehid,P[0],P[1],P[2]);
		new Float:V[3];
		GetVehicleVelocity(vehid,V[0],V[1],V[2]);
		GetVehicleZAngle(vehid,P[3]);
		GetPointInFront2D(P[0],P[1],CompRotationFloat(P[3]+270.0),dist,P[0],P[1]);
		SetVehiclePos(vehid,P[0],P[1],P[2]);
		SetVehicleVelocity(vehid,V[0],V[1],V[2]);
	} else {
		GetPlayerPos(userid,P[0],P[1],P[2]);
		GetPlayerFacingAngle(userid,P[3]);
		GetPointInFront2D(P[0],P[1],CompRotationFloat(P[3]+270.0),dist,P[0],P[1]);
		SetPlayerPos(userid,P[0],P[1],P[2]);
	}

	return 1;
}

CMD:wprawo(playerid,params[]) return cmd_right(playerid,params);

CMD:up(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:dist,userid,Float:P[3];

	if(isnull(params)) return SendClientMessage(playerid,0xFFFFFFFF,"/up [id] <odleglosc>");

	if(!sscanf(params,"df",userid,dist)){
		if(!IsPlayerConnected(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest podlaczony");
		} else if (!IsPlayerSpawnedEx(userid)){
			return SendClientMessage(playerid,0xFFFFFFFF,"Gracz nie jest zespawnowany");
		}
	} else if (!sscanf(params,"f",dist)){
		userid=playerid;
	}

	if(IsPlayerInAnyVehicle(userid)){
		new vehid;
		vehid=GetPlayerVehicleID(userid);
		GetVehiclePos(vehid,P[0],P[1],P[2]);

		new Float:V[3];
		GetVehicleVelocity(vehid,V[0],V[1],V[2]);

		SetVehiclePos(vehid,P[0],P[1],P[2]+dist);
		SetVehicleVelocity(vehid,V[0],V[1],V[2]);
	} else {
		GetPlayerPos(userid,P[0],P[1],P[2]);
		SetPlayerPos(userid,P[0],P[1],P[2]+dist);
	}

	return 1;
}

CMD:freeze(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,buffer[256];
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /freeze <gracz>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	}
	
	if(!IsPlayerSpawnedEx(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Podany gracz nie jest zespawnowany.");

	TogglePlayerControllable(userid,0);

	format(buffer,sizeof buffer,"Zamrozi³eœ gracza {006666}%s.",GetPlayerNick(userid));
	SendClientMessage(playerid,COLOR_INFO,buffer);

	if(userid == playerid) return 1;

	format(buffer,sizeof buffer,"Zosta³eœ zamro¿ony przez admina {006666}%s.",GetPlayerNick(playerid));
	SendClientMessage(userid,COLOR_INFO,buffer);
	return 1;
}

CMD:unfreeze(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,buffer[256];
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /unfreeze <gracz>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,0xFFFFFFFF,"Nie ma takiego gracza!");
	}
	
	if(!IsPlayerSpawnedEx(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Podany gracz nie jest zespawnowany.");

	TogglePlayerControllable(userid,1);

	format(buffer,sizeof buffer,"Odmrozi³eœ gracza {006666}%s.",GetPlayerNick(userid));
	SendClientMessage(playerid,COLOR_INFO,buffer);

	if(userid == playerid) return 1;

	format(buffer,sizeof buffer,"Zosta³eœ odmro¿ony przez admina {006666}%s.",GetPlayerNick(playerid));
	SendClientMessage(userid,COLOR_INFO,buffer);
	return 1;
}

CMD:kratka(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /kratka <id>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Nie ma takiego gracza!");

	new P[Float3D];
	GetPlayerPos(userid,P[T3D:X],P[T3D:Y],P[T3D:Z]);
	P[T3D:VW] = GetPlayerVirtualWorld(userid);
	P[T3D:INT] = GetPlayerInterior(userid);

	if(IsValidDynamicObject(oKratki[userid])) DestroyDynamicObject(oKratki[userid]);
	oKratki[userid] = CreateDynamicObject(19075,P[T3D:X],P[T3D:Y],P[T3D:Z]+0.5,0.0,0.0,0.0,P[T3D:VW],P[T3D:INT],-1,300);
	SetPlayerPos(userid,P[T3D:X],P[T3D:Y],P[T3D:Z]);
	Streamer_Update(userid);
	PlayerPlaySound(userid,1137,0.0,0.0,0.0);
	return 1;
}

CMD:tpkratka(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /tpkratka <id gracza>");
	if(!IsValidDynamicObject(oKratki[userid])) return SendClientMessage(playerid,COLOR_ERROR,"Nie odnaleziono podanej kratki.");
	
	new P[Float3D];
	GetDynamicObjectPos(oKratki[userid],P[T3D:X],P[T3D:Y],P[T3D:Z]);
	P[T3D:VW] = GetDynamicObjectVW(oKratki[userid]);
	P[T3D:INT] = GetDynamicObjectINT(oKratki[userid]);
	if(P[T3D:VW] == -1) P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	if(P[T3D:INT] == -1) P[T3D:INT] = GetPlayerInterior(playerid);

	SetPlayerPos(playerid,P[T3D:X],P[T3D:Y],P[T3D:Z]);
	SetPlayerInterior(playerid,P[T3D:INT]);
	SetPlayerVirtualWorld(playerid,P[T3D:VW]);
	SendClientMessage(playerid,COLOR_INFO,"Przeniesiono do kratki");
	return 1;
}

CMD:unkratka(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /unkratka <id gracza>");
	if(IsValidDynamicObject(oKratki[userid])) DestroyDynamicObject(oKratki[userid]);
	return 1;
}

CMD:unkratkaall(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new cnt = 0, buffer[256];
	for(new i = 0; i < MAX_PLAYERS; i++){
		if(IsValidDynamicObject(oKratki[i])){
			DestroyDynamicObject(oKratki[i]);
			cnt++;
		}
	}
	if(cnt == 0) return SendClientMessage(playerid,COLOR_INFO,"Brak kratek do usuniecia.");
	format(buffer,sizeof buffer,"Administrator %s usun¹³ wszystkie (%d) kratki.",GetPlayerNick(playerid),cnt);
	MSGToAdmins(COLOR_RED,buffer,LEVEL_ADMIN);
	return 1;
}

CMD:kratka50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				GetPlayerPos(i,P[T3D:X],P[T3D:Y],P[T3D:Z]);
				if(IsValidDynamicObject(oKratki[i])) DestroyDynamicObject(oKratki[i]);
				oKratki[i] = CreateDynamicObject(19075,P[T3D:X],P[T3D:Y],P[T3D:Z]+0.5,0.0,0.0,0.0,P[T3D:VW],P[T3D:INT],-1,300);
				SetPlayerPos(i,P[T3D:X],P[T3D:Y],P[T3D:Z]);
				Streamer_Update(i);
				PlayerPlaySound(i,1137,0.0,0.0,0.0);
			}
		}
	}
	return 1;
}

CMD:unkratka50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				if(IsValidDynamicObject(oKratki[i])) DestroyDynamicObject(oKratki[i]);
				Streamer_Update(i);
			}
		}
	}
	return 1;
}

CMD:unzaloz50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				for(new k = 0; k < 10; k++){
					RemovePlayerAttachedObject(i,k);
				}
			}
		}
	}
	return 1;
}

CMD:unzaloz(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /unzaloz <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	for(new k = 0; k < 10; k++){
		RemovePlayerAttachedObject(userid,k);
	}
	return 1;
}

CMD:anapraw(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /anapraw <id gracza>");
	if(!IsPlayerInAnyVehicle(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Podany gracz musi byæ w pojeŸdzie");
	new vid = GetPlayerVehicleID(userid);
	RepairVehicle(vid);
	SetVehicleHealth(vid,1000.0);
	return 1;
}

CMD:paliwo50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s zatankowa³ twój pojazd.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				if(IsPlayerInAnyVehicle(i)){
					new vid = GetPlayerVehicleID(i);
					Paliwo[vid] = GetVehicleMaxFuel(GetVehicleModel(vid));
					SendClientMessage(i,COLOR_INFO,buffer);
					pCount++;
				}
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Zatankowa³eœ/aœ pojazd %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:apaliwo(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /apaliwo <id gracza>");
	if(!IsPlayerInAnyVehicle(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Podany gracz musi byæ w pojeŸdzie");
	new vid = GetPlayerVehicleID(userid);
	Paliwo[vid] = GetVehicleMaxFuel(GetVehicleModel(vid));
	return 1;
}

CMD:heal(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /heal <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	SetPlayerHealth(userid,100.0);
	return 1;
}

CMD:armor(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /armor <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	SetPlayerArmour(userid,100.0);
	return 1;
}

CMD:freeze50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s zamrozi³ Cie.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SendClientMessage(i,COLOR_INFO,buffer);
				TogglePlayerControllable(i,0);
				pCount++;
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Zamrozi³eœ/aœ %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:unfreeze50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s odmrozi³ Cie.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SendClientMessage(i,COLOR_INFO,buffer);
				TogglePlayerControllable(i,1);
				pCount++;
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Odmrozi³eœ/aœ %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:napraw50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s naprawi³ twój pojazd.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				if(IsPlayerInAnyVehicle(i)){
					new vid = GetPlayerVehicleID(i);
					RepairVehicle(vid);
					SetVehicleHealth(vid,1000.0);
					SendClientMessage(i,COLOR_INFO,buffer);
					pCount++;
				}
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Naprawi³eœ/aœ pojazd %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:armor50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s za³adowa³ twój armor.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SetPlayerArmour(i,100.0);
				SendClientMessage(i,COLOR_INFO,buffer);
				pCount++;
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Za³adowa³eœ/aœ armor %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:unarmor(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /unarmor <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	SetPlayerArmour(userid,0.0);
	return 1;
}

CMD:unarmor50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s zabra³ ci armor.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SetPlayerArmour(i,0.0);
				SendClientMessage(i,COLOR_INFO,buffer);
				pCount++;
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Zabra³eœ/aœ armor %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:heal50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[160], pCount = 0, int, vw;
   
	int = GetPlayerInterior(playerid);
	vw = GetPlayerVirtualWorld(playerid);

	format(buffer,sizeof buffer,"Administrator %s za³adowa³ twoje ¿ycie.",GetPlayerNick(playerid));
	FoxForeach(i,Player){
		if(playerid == i) continue;
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == int && GetPlayerVirtualWorld(i) == vw){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SetPlayerHealth(i,100.0);
				SendClientMessage(i,COLOR_INFO,buffer);
				pCount++;
			}
		}
	}
	if(pCount){
		format(buffer,sizeof buffer,"Za³adowa³eœ/aœ ¿ycie %d %s.",pCount,dli(pCount,"gracz¹","graczy","graczy"));
		SendClientMessage(playerid,COLOR_INFO,buffer);
	} else {
		SendClientMessage(playerid,COLOR_ERROR,"Nikogo nie ma w poblizu");
	}
	return 1;
}

CMD:evsp(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	GetPlayerPos(playerid,evtp[T3D:X],evtp[T3D:Y],evtp[T3D:Z]);
	evtp[T3D:INT] = GetPlayerInterior(playerid);
	evtp[T3D:VW] = GetPlayerVirtualWorld(playerid);
	GetPlayerFacingAngle(playerid,evtp[T3D:rZ]);
	SendClientMessage(playerid,COLOR_INFO,"Teleport na event zapisany, dostepny dla graczy pod komenda /evtp.");
	return 1;
}

CMD:evdel(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	evtp[T3D:X] = FLOAT_INFINITY;
	SendClientMessage(playerid,COLOR_INFO,"Teleport na event usuniety!");
	return 1;
}

CMD:tapi(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid,color;
	if(sscanf(params,"dx",userid,color)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /tapi <id gracza> <RGB>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	SetPlayerAttachedObject(userid,9,1559,1, 2.0,0.0,0.0, 0.0,90.0,0.0, 1.0,1.0,1.0, RGBToARGB(color,0xFF));
	return 1;
}

CMD:untapi(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /untapi <id gracza>");
	if(!IsPlayerConnected(userid)) return SendClientMessage(playerid,COLOR_RED,"Nie ma takiego gracza!");
	RemovePlayerAttachedObject(userid,9);
	return 1;
}

CMD:tapi50(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new color;
	if(sscanf(params,"x",color)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /tapi50 <RGB>");
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				SetPlayerAttachedObject(i,9,1559,1, 2.0,0.0,0.0, 0.0,90.0,0.0, 1.0,1.0,1.0, RGBToARGB(color,0xFF));
			}
		}
	}
	return 1;
}

CMD:untapi50(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new P[Float3D];
	P[T3D:INT] = GetPlayerInterior(playerid);
	P[T3D:VW] = GetPlayerVirtualWorld(playerid);
	FoxForeach(i,Player){
		if(IsPlayerSpawnedEx(i) && GetPlayerInterior(i) == P[T3D:INT] && GetPlayerVirtualWorld(i) == P[T3D:VW]){
			if(GetDistanceBetweenPlayers(playerid,i) <= 50.0){
				RemovePlayerAttachedObject(i,9);
			}
		}
	}
	return 1;
}

CMD:tenwoz(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new userid;
	if(sscanf(params,"d",userid)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /tenwoz <id gracza>");
	if(!IsPlayerInAnyVehicle(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Podany gracz musi byæ w pojeŸdzie");
	new vid = GetPlayerVehicleID(userid);
	new engine,lights,alarm,doors,bonnet,boot,objective;
	GetVehicleParamsEx(vid,engine,lights,alarm,doors,bonnet,boot,objective);
	SetVehicleParamsEx(vid,1,lights,alarm,doors,bonnet,boot,(objective>0?0:1));
	return 1;
}

CMD:tpmap(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:MAz,Float:angle;
	GetPlayerFacingAngle(playerid,angle);
	Tryg3DMapAndreasFindZ(MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz);
	SetPlayerAbsolutePosition(playerid,MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz+1.5,angle,0,0);
	return 1;
}

CMD:vtpmap(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:MAz,Float:angle;
	GetPlayerFacingAngle(playerid,angle);
	Tryg3DMapAndreasFindZ(MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz);
	SetPlayerAbsolutePositionVeh(playerid,MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz+1.5,angle,0,0);
	return 1;
}

CMD:xtpmap(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new Float:distance, max_players = 0, idx = 0, Float:px, Float:py, Float:pz;
	if(sscanf(params,"f",distance)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /xtpmap <distance>");
	GetPlayerPos(playerid,px,py,pz);
	
	FoxForeach(i,Character){
		if(i != playerid){
			if(GetDistanceBetweenPlayers(playerid,i) <= distance) max_players++;
		}
	}
	
	new Float:x,Float:y,Float:angle,Float:MAz,Float:radius;
	if(max_players < 4){
		radius = 3.0;
	} else {
		radius = 3.0+(0.25*max_players);
	}
	Tryg3DMapAndreasFindZ(MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz);
	SetPlayerPos(playerid,MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],MAz+1.5);
	SetPlayerInterior(playerid,0);
	SetPlayerVirtualWorld(playerid,0);
	
	if(max_players > 0){
		FoxForeach(i,Character){
			if(i != playerid){
				if(GetPlayerDistanceFromPoint(i,px,py,pz) <= distance){
					GetRandomPointOnClock(MapClick[playerid][T3D:X],MapClick[playerid][T3D:Y],radius,x,y,angle,single_clock(max_players,idx));
					Tryg3DMapAndreasFindZ(x,y,MAz);
					if(!IsPlayerNPC(i)){
						SetPlayerPos(i,x,y,MAz+1.5);
						GetPlayerFacingAngle(i,angle);
						SetPlayerInterior(i,0);
						SetPlayerVirtualWorld(i,0);
						SetCameraBehindPlayer(i);
					} else {
						FCNPC_SetPosition(i,x,y,MAz+1.5);
						FCNPC_SetAngle(i,angle);
						FCNPC_SetInterior(i,0);
						FCNPC_SetVirtualWorld(i,0);
					}
					idx++;
				}
			}
		}
	}
	return 1;
}

CMD:scena(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,55.0801,1551.8951,12.9172);
	SetPlayerFacingAngle(playerid,93.9111);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:wyspa(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,1606.4799,-5133.4521,7.1826);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:salonsf(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,-1957.5500,302.2543,35.4688);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:banksf(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,-2756.4065,373.3420,4.3414);
	return 1;
}

CMD:lowisko(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,1123.3206,-2037.0670,69.8874);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:portbay(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	SetPlayerPos(playerid,-2192.0164,2406.5803,4.9694);
	SetCameraBehindPlayer(playerid);
	return 1;
}

CMD:ucar(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	for(new i = 0, j = sizeof(AutaAdmina); i < j; i++){
		if(IsValidVehicle(AutaAdmina[i])){
			DestroyVehicle(AutaAdmina[i]);
		}
	}
	idautaadmina = 0;
	return 1;
}

CMD:bazy(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	ShowPlayerDialog(playerid,292,DIALOG_STYLE_LIST,"Bazy","Przegl¹daj istniej¹ce bazy\nDodaj bazê\nUsuñ bazê","Wybierz","WyjdŸ");
	return 1;
}

CMD:vipsy(playerid){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	new buffer[3096], part[500], Premium[500];
	for(new OIVIP = 515; OIVIP < MAX_VIPOW; OIVIP++){
		format(Premium,sizeof(Premium),"/Premium/UID%i.txt",OIVIP);
		if(dini_Exists(Premium)){
			format(part,sizeof(part),"%s > %i: UID: %i\n",dini_Get(Premium,"Nick"),dini_Int(Premium,"LiczbaDni"),OIVIP);
			strcat(buffer,part);
		}
	}
	ShowPlayerDialog(playerid,234,DIALOG_STYLE_MSGBOX,"vipy",buffer,"Dalej","Zamknij");
	return 1;
}

CMD:car(playerid,params[]){
	if(gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return 0;
	if(idautaadmina >= sizeof(AutaAdmina)) return SendClientMessage(playerid,COLOR_WHITE,"Nie mo¿na zrespiæ wiêcej aut");
	new Float:x, Float:y,Float:z,Float:r;
	new vehicleid;
	GetPlayerPos(playerid,x,y,z);
	GetPlayerFacingAngle(playerid,r);
	if(sscanf(params,"d",vehicleid)){
		return SendClientMessage(playerid,COLOR_WHITE,"/car [id auta]");
	} else {
		if(vehicleid < 400 || vehicleid > 611) return SendClientMessage(playerid,COLOR_WHITE,"Zakres aut 400 - 611");
		
		if(vehicleid == 596 || vehicleid == 597 || vehicleid == 598 || vehicleid == 599){
			AutaAdmina[idautaadmina] = CreateVehicle(vehicleid,x+2,y,z,r,-1,-1,-1);
		} else {
			AutaAdmina[idautaadmina] = CreateVehicle(vehicleid,x+2,y,z,r,3,0,-1);
		}
		if(AutaAdmina[idautaadmina] == INVALID_VEHICLE_ID) return SendClientMessage(playerid,COLOR_WHITE,"Dodawanie auta nie powiod³o siê!");
		Paliwo[AutaAdmina[idautaadmina]] = GetVehicleMaxFuel(vehicleid);
		idautaadmina++;
	}
	return 1;
}