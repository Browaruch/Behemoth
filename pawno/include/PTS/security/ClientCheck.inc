native SendClientCheck(playerid, actionid, memaddr, memOffset, bytesCount);

function OnClientCheckResponse(playerid, actionid, memaddr, retndata){
	if(retndata == 0xA){
		new buffer[200];
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used ModSobeit",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu ModSobeit.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
	}
	return 1;
}

stock CheckPlayersIP(playerid,src[]){
	new cnt = 0;
	FoxForeach(i,Player){
		if(strcmp(GetPlayerIP(i),src,false) == 0){
			cnt++;
		}
	}
	if(cnt > 5){
		new buffer[200];
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used Bot",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		BanEx(playerid,"[HD] Bots");
		FoxForeach(i,Player){
			if(i != playerid){
				if(strcmp(GetPlayerIP(i),src,false) == 0){
					Kick(i);
				}
			}
		}
		return 1;
	} else if(cnt == 5){
		new buffer[200];
		format(buffer,sizeof buffer,"[SECURITY] [%s](%d)%s too much connection",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		return 0;
	}
	return 0;
}

function TimerWeaponHack(tec){
	FoxForeach(i,Player){
		if(gGracz[i][AdminLvl] < 7){
			new buffer[200];
			if(gGracz[i][AdminDalBron] == false){
				new wepid = GetPlayerWeapon(i), ammo = GetPlayerAmmo(i);
				if(ammo != 0){
					switch(wepid){
						case 2,8,25,26,27,28,30,32,33,35,36,37,38,39: {
							format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used WH WEP: %d AMMO: %d",GetPlayerIP(i),i,GetPlayerNick(i),wepid,ammo);
							print(buffer);
							WriteLog(buffer,LOG_FILE_HACK);
							MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
							SendClientMessage(i,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu WH.");
							SetTimerEx("KickGracza",200,false,"d",i);
							return 1;
						}
					}
				}
			}
			if(GetPlayerSpecialAction(i) == SPECIAL_ACTION_USEJETPACK){
				if(gGracz[i][AdminLvl] < 5 && !IsPlayerAdmin(i)){
					format(buffer,sizeof(buffer),"[HACK DETECT] [%s](%d)%s used Jetpack",GetPlayerIP(i),i,GetPlayerNick(i));
					print(buffer);
					WriteLog(buffer,LOG_FILE_HACK);
					MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
					SendClientMessage(i,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu Jetpacka.");
					SetTimerEx("KickGracza",200,false,"d",i);
					return 1;
				}
			}
		}
	}
	return 1;
}


function OnPlayerChangeWeapon(playerid,oldwepid,wepid){

	if(!IsPlayerSpawnedEx(playerid)) return 0;
	if(IsPlayerNPC(playerid)) return 0;

	//pistolet 9mm
	if(oldwepid == 22){
		RemovePlayerAttachedObject(playerid,3);
	}
	if(wepid == 22){
		SetPlayerAttachedObject(playerid,3,18643,6,0.156490,0.027780,0.103976,335.000000,350.000000,0.000000,0.600000,0.600000,0.6 ); // LaserPointer1 - laser
	}

	new ammo_0 = 0, ammo_1 = 0, ammo_10 = 0, ammo_a, ammo_b,
		wep_0 = -1, wep_1 = -1, wep_10 = -1, wep_a, wep_b;
	GetPlayerWeaponData(playerid,0,wep_0,ammo_0);
	GetPlayerWeaponData(playerid,1,wep_1,ammo_1);
	GetPlayerWeaponData(playerid,10,wep_10,ammo_10);
	
	GetPlayerWeaponData(playerid,weaponSlots[oldwepid],wep_a,ammo_a);
	GetPlayerWeaponData(playerid,weaponSlots[wepid],wep_b,ammo_b);
	
	if(ammo_a < 0 || ammo_a > 15000 || ammo_b < 0 || ammo_b > 15000){
		if(!gGracz[playerid][prot_hack_detect]) return 1;
		gGracz[playerid][prot_hack_detect] = false;
		new buffer[200];
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used WH WEP1: %d AMMO1: %d WEP2: %d AMMO2: %d",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),wep_a,ammo_a,wep_b,ammo_b);
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu WH.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
		return 1;
	} else if((ammo_0 >= 10 || ammo_0 < 0) || (ammo_1 >= 10 || ammo_1 < 0) || (ammo_10 >= 10 || ammo_10 < 0)){ //(wepid == 44) || (wepid == 45) ||
		if(!gGracz[playerid][prot_hack_detect]) return 1;
		gGracz[playerid][prot_hack_detect] = false;
		new buffer[200];
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used ModSobeit/WH/AIM D:%d:%d:%d:%d",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),wepid,ammo_0,ammo_1,ammo_10);
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu ModSobeit/WH/AIM.");
		SetTimerEx("KickGracza",200,false,"d",playerid);
		return 1;
	}
	return 1;
}

function CheckPlayerWeaponPickup(playerid,pickupid){
	if(GetDynamicPickupType(pickupid) == 2){
		switch(GetDynamicPickupModel(pickupid)){
		
			//Slot 0
			case 331: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,0,wepid,ammo);
				SetPlayerAmmo(playerid,wepid,1);
			}
			
			//Slot 1
			case 333..339, 341: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,1,wepid,ammo);
				SetPlayerAmmo(playerid,wepid,1);
			}
			
			//Slot 2
			case 346..348: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,2,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 3
			case 349..351: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,3,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 4
			case 352..353, 372: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,4,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 5
			case 355..356: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,5,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 6
			case 357..358: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,6,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 7
			case 359..362: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,7,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 8
			case 342..344, 363: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,8,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 9
			case 365..367: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,9,wepid,ammo);
				if(ammo >= 10000){
					SetPlayerAmmo(playerid,wepid,10000);
				}
			}
			
			//Slot 10
			case 321..326: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,10,wepid,ammo);
				SetPlayerAmmo(playerid,wepid,1);
			}
			
			//Slot 11
			case 368..369, 371: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,11,wepid,ammo);
				SetPlayerAmmo(playerid,wepid,1);
			}
			
			//Slot 12
			case 364: {
				new wepid, ammo;
				GetPlayerWeaponData(playerid,12,wepid,ammo);
				SetPlayerAmmo(playerid,wepid,1);
			}
		}
	}
	return 1;
}

function OnPlayersCheck(playerid){
	new Float:P[6]/*, curpos, Float:dist*/;
	GetPlayerPos(playerid,P[0],P[1],P[2]);
	GetPlayerFacingAngle(playerid,P[3]);
	GetPlayerHealth(playerid,P[5]);
	GetPlayerArmour(playerid,P[4]);
	//curpos = floatround(P[0]) * floatround(P[1]) * floatround(P[2]/4);
	//dist = VectorSize(gGracz[playerid][lastXYZ][0]-P[0],gGracz[playerid][lastXYZ][1]-P[1],gGracz[playerid][lastXYZ][2]-P[2]);
	
	if(P[5] == 100.0 && P[3] == 0.0 && P[4] == 0.0 && !gGracz[playerid][firstspawn] && IsPlayerSpawnedEx(playerid)){
		if((GetTickCount() - gGracz[playerid][prot_pizdr] >= 10000) && gGracz[playerid][prot_pizdr] != 0){
			new buffer[200];
			format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used Pizdarvanka",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
			print(buffer);
			WriteLog(buffer,LOG_FILE_HACK);
			MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
			SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu Pizdarvanka");
			SetTimerEx("KickGracza",200,false,"d",playerid);
			return 1;
		} else {
			SetPlayerArmour(playerid,1.0);
		}
	} else {
		gGracz[playerid][prot_pizdr] = GetTickCount();
	}

	if(!IsPlayerInAnyVehicle(playerid)){
		
		switch(GetPlayerAnimationIndex(playerid)){
			case 958, 959: { //animacja z spadochronu
				new wepid, ammo;
				GetPlayerWeaponData(playerid,11,wepid,ammo);
				if(wepid != 46){ //gracz nie ma spadochronu
					if(IsCollisionFlag(GetPlayerCollisionFlags(playerid),POSITION_FLAG_AIR)){
						new buffer[200];
						format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used FlyHack T:A",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
						print(buffer);
						WriteLog(buffer,LOG_FILE_HACK);
						MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
						SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu FlyHack");
						SetTimerEx("KickGracza",200,false,"d",playerid);
						return 1;
					}
				}
			}
			case 1539, 1058: { //1539 - p³ywanie, 1058 - lataj¹ca miot³a
				if(IsCollisionFlag(GetPlayerCollisionFlags(playerid),POSITION_FLAG_AIR)){
					new buffer[200];
					format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used FlyHack T:B",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid));
					print(buffer);
					WriteLog(buffer,LOG_FILE_HACK);
					MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
					SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu FlyHack");
					SetTimerEx("KickGracza",200,false,"d",playerid);
					return 1;
				}
			}
		}
	}
	
	/*
	new cnt = CheckPlayerObject(playerid);
	if(cnt != 0){
		new buffer[200], cnt2 = Streamer_CountVisibleItems(playerid,STREAMER_TYPE_OBJECT,1)+AST_CountPlayerObjects(playerid);
		format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used FakeObjectCreator: [%d/%d] illegal: %d",GetPlayerIP(playerid),playerid,GetPlayerNick(playerid),cnt+cnt2,cnt2,cnt);
		print(buffer);
		WriteLog(buffer,LOG_FILE_HACK);
		MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
		SendClientMessage(playerid,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu FakeObjectCreator");
		SetTimerEx("KickGracza",200,false,"d",playerid);
		return 1;
	}
	*/
	//gGracz[playerid][lastPos] = gGracz[playerid][curPos];
	//gGracz[playerid][curPos] = curpos;
	//GetPlayerPos(playerid,gGracz[playerid][lastXYZ][0],gGracz[playerid][lastXYZ][1],gGracz[playerid][lastXYZ][2]);
	return 1;
}

	
/*
//w pojeŸdzie
if(GetTickCount() - gGracz[i][prot_block_ab] > 10000){
	if(GetPlayerInterior(i) == 0 && GetPlayerVehicleSeat(i) == 0 && IsPlayerSpawnedEx(i) && !IsPlayerNGC(i)){
		new vid = GetPlayerVehicleID(i);
		if((GetVehicleFlags(vid) & VF_STREET == VF_STREET) && (GetVehicleFlags(vid) & VF_RC != VF_RC)){
			if(GetVehicleSpeed(vid) == 0.0){
				if(IsCollisionFlag(GetPlayerCollisionFlags(i),POSITION_FLAG_AIR)){
					if(curpos != gGracz[i][curPos] && gGracz[i][lastPos] != -1 && curpos != gGracz[i][lastPos] && dist >= 10.0){
						new buffer[200];
						format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used AirBrake D:V",GetPlayerIP(i),i,GetPlayerNick(i));
						print(buffer);
						WriteLog(buffer,LOG_FILE_HACK);
						MSGToAdmins(COLOR_ADMIN,buffer,false,LEVEL_ADMIN1);
						SendClientMessage(i,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu AirBrake");
						if(pData[i][accountID] != 0){ //Gracz ma konto wiêc Kick
							Kick(i);
						} else {
							BanEx(i,"[HD] AirBrake D:V");
						}
						return 1;
					}
				}
			}
		}
	}
}

//bez pojazdu
if(GetTickCount() - gGracz[i][prot_block_ab] > 10000){
	if(GetPlayerInterior(i) == 0 && !gGracz[i][isFreezed] && IsPlayerSpawnedEx(i)){
		if(GetPlayerSpeed(i) <= 0.1){
			if(IsCollisionFlag(GetPlayerCollisionFlags(i),POSITION_FLAG_AIR)){
				if(IsPointInAir(P[0],P[1],P[2],false,8.0) && GetPlayerSpecialAction(i) != SPECIAL_ACTION_USEJETPACK){
					if(curpos != gGracz[i][curPos] && gGracz[i][lastPos] != -1 && curpos != gGracz[i][lastPos] && dist >= 10.0){
						new buffer[200];
						format(buffer,sizeof buffer,"[HACK DETECT] [%s](%d)%s used AirBrake D:P",GetPlayerIP(i),i,GetPlayerNick(i));
						print(buffer);
						WriteLog(buffer,LOG_FILE_HACK);
						MSGToAdmins(COLOR_RED,buffer,LEVEL_JUNIORADMIN);
						SendClientMessage(i,0xFF0000FF,"Zosta³eœ wyrzucony z serwera z powodu AirBrake");
						if(pData[i][accountID] != 0){ //Gracz ma konto wiêc Kick
							Kick(i);
						} else {
							BanEx(i,"[HD] AirBrake D:P");
						}
						return 1;
					}
				}
			}
		}
	}
}
*/