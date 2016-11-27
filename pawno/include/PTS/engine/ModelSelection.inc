public OnPlayerSelectedMenuRow(playerid,row){

	return 1;
}


public OnPlayerModelSelection(playerid,response,listid,modelid){
	new string[256];
	if(listid == SkinyDomowe){
		if(response){
			if(GetPlayerWantedLevel(playerid) <= 0){
				SetPlayerColor(playerid,0x6DC5F3FF);
			}
			ResetPlayerWeapons(playerid);
			gGracz[playerid][ZapisanySkin] = modelid;
			if(gGracz[playerid][VipLvl] < 1){
				SetPlayerArmour(playerid,0);
			}
			StatusTrucka[playerid] = true;
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
		} else {
			SendClientMessage(playerid,COLOR_BLUE,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyKierowcy){
		if(response){
			if(GetPlayerWantedLevel(playerid) <= 0){
				SetPlayerColor(playerid,0x6DC5F3FF);
			}
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,0xFF0000FF,"Koszt zmiany postaci: 500$");
			gGracz[playerid][ZapisanySkin] = modelid;
			SetPlayerArmour(playerid,0);
			StatusTrucka[playerid] = true;
			
			GivePlayerMoney(playerid,-500);
			if(SkinyStrazyGranicznej(playerid)){
				format(string,sizeof(string),"Stra¿nik {DEDEDE}%s [%i]{FF8A14} zakoñczy³ s³u¿bê na skinie.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_PURPLE,string);
				new straznicy = 0;
				FoxForeach(i,Player){
					if(gGracz[i][Zalogowany] == true && SkinyStrazyGranicznej(i)){
						straznicy++;
					}
				}
				if(straznicy < 1){
					OtworzGranice();
				}
			}
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			if(gGracz[playerid][VipLvl] >= 1){
				gGracz[playerid][PozwolenieBron] = true;
				GivePlayerWeapon(playerid,5,1);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyW){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}¯o³nierz {FFFFFF}zmieniona");
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			gGracz[playerid][ZapisanySkin] = modelid;
			SetPlayerArmour(playerid,100);
			StatusTrucka[playerid] = false;
			SetPlayerColor(playerid,0xFFFFFF00);
		}
		return 1;
	}
	if(listid == SkinyM){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Lekarz {FFFFFF}zmieniona");
			StatusTrucka[playerid] = false;
			SetPlayerArmour(playerid,100);
			gGracz[playerid][ZapisanySkin] = modelid;
			if(!SkinyMedykow(playerid)){
				format(string,sizeof(string),"{FF8A14}Gracz {D1D1D1}%s [%i]{FF8A14} rozpocz¹³ s³u¿bê jako {C3C3C3}Medyk.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_PURPLE,string);
			}
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			if(gGracz[playerid][VipLvl] >= 1){
				gGracz[playerid][PozwolenieBron] = true;
				GivePlayerWeapon(playerid,5,1);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinySG){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Stra¿nik {FFFFFF}zmieniona");
			gGracz[playerid][PozwolenieBron] = true;
			GivePlayerWeapon(playerid,22,600);
			GivePlayerWeapon(playerid,3,1);
			SetPlayerColor(playerid,0xFFFFFF00);
			SetPlayerArmour(playerid,100);
			if(!SkinyStrazyGranicznej(playerid)){
				format(string,sizeof(string),"{FF1AB0}Gracz {DEDEDE}%s [%i]{FF1AB0} rozpocz¹³ s³u¿bê jako {FFFFFF}Stra¿nik.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_PURPLE,string);
			}
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			StatusTrucka[playerid] = false;
			gGracz[playerid][ZapisanySkin] = modelid;
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyPD){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			StatusTrucka[playerid] = false;
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Mechanik {FFFFFF}zmieniona");
			gGracz[playerid][PozwolenieBron] = true;
 			GivePlayerWeapon(playerid,41,1000);
			SetPlayerArmour(playerid,0);
			gGracz[playerid][ZapisanySkin] = modelid;
			if(!SkinyPomocyDrogowej(playerid)){
				format(string,sizeof(string),"{FF1AB0}Gracz {DEDEDE}%s [%i]{FF1AB0} rozpocz¹³ s³u¿bê jako {AFFF14}Mechanik.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_PURPLE,string);
			}
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			if(gGracz[playerid][VipLvl] >= 1){
				gGracz[playerid][PozwolenieBron] = true;
				GivePlayerWeapon(playerid,5,1);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyStrazyP){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			StatusTrucka[playerid] = false;
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Stra¿ak {FFFFFF}zmieniona");
			gGracz[playerid][PozwolenieBron] = true;
 			GivePlayerWeapon(playerid,42,999999);
			SetPlayerArmour(playerid,0);
			gGracz[playerid][ZapisanySkin] = modelid;
			if(!SkinySP(playerid)){
				format(string,sizeof(string),"{FF1AB0}Gracz {DEDEDE}%s [%i]{FF1AB0} rozpocz¹³ s³u¿bê jako {AFFF14}Stra¿ak.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_PURPLE,string);
			}
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			if(gGracz[playerid][VipLvl] >= 1){
				gGracz[playerid][PozwolenieBron] = true;
				GivePlayerWeapon(playerid,5,1);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyT)
	{
		if(response)
		{
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Taxówkarz {FFFFFF}zmieniona");
			SetPlayerArmour(playerid,0);
			StatusTrucka[playerid] = false;
			gGracz[playerid][ZapisanySkin] = modelid;
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			if(!SkinyTaxi(playerid)){
				format(string,sizeof(string),"{FF8A14}Gracz {D1D1D1}%s [%i]{FF8A14} rozpocz¹³ s³u¿bê jako {FFF714}Taxówkarz.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_WHITE,string);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	if(listid == SkinyP){
		if(response){
			gGracz[playerid][SkinKierowcy] = GetPlayerSkin(playerid);
			ResetPlayerWeapons(playerid);
			SendClientMessage(playerid,COLOR_WHITE,"Postaæ na: {FF0000}Policjant {FFFFFF}zmieniona");
			SetPlayerArmour(playerid,100);
			StatusTrucka[playerid] = false;
			gGracz[playerid][PozwolenieBron] = true;
			GivePlayerWeapon(playerid,24,1000);
			GivePlayerWeapon(playerid,3,1);
			SetPlayerColor(playerid,0xFFFFFF00);
			gGracz[playerid][ZapisanySkin] = modelid;
			SetPlayerSkin(playerid,modelid);
			PokazPasekStanu(playerid);
			GivePlayerWeapon(playerid,29,250);
			if(!SkinyPolicji(playerid)){
				format(string,sizeof(string),"{FF1AB0}Gracz {DEDEDE}%s [%i]{FF1AB0} rozpocz¹³ s³u¿bê jako {14A7FF}Policjant.",GetPlayerNick(playerid),playerid);
				SendClientMessageToAll(COLOR_WHITE,string);
			}
		} else {
			SendClientMessage(playerid,0xFF0000FF,"Anulowa³eœ zmiane postaci");
		}
		return 1;
	}
	return 1;
}

public OnPlayerExitedMenu(playerid){

	return 1;
}