CMD:vcmd(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new szAREA[3600];
	szAREA = "";
	if(gGracz[playerid][VipLvl] >= LEVEL_VIP){
		strcat(szAREA,"{F5C172}/vjedzenie /vj {A9C4E4}- nape³niasz swój ¿o³¹dek\n");
		strcat(szAREA,"{F5C172}/vulecz {A9C4E4}- uleczasz siê\n");
		strcat(szAREA,"{F5C172}/varmor {A9C4E4}- dajesz sobie kamizelke\n");
		strcat(szAREA,"{F5C172}/vspij {A9C4E4}- przestajesz byæ zmêczony\n");
		strcat(szAREA,"{F5C172}/vpogoda {A9C4E4}- zamieniasz sobie pogodê\n");
		strcat(szAREA,"{F5C172}/vnapraw {A9C4E4}- naprawiasz swoje auto\n");
		strcat(szAREA,"{F5C172}/vflip /vf {A9C4E4}- stawiasz pojazd na 4 ko³a\n");
		strcat(szAREA,"{F5C172}/vtrzezwosc /vtr {A9C4E4}- stajesz siê trzeŸwy\n");
		strcat(szAREA,"{F5C172}/v {A9C4E4}- piszesz na vipchacie\n");
		strcat(szAREA,"{F5C172}/like {A9C4E4}- 'Lubisz to'\n");
		strcat(szAREA,"{F5C172}/colors {A9C4E4}- kolory do chatu\n");
		strcat(szAREA,"{F5C172}/vbrama {A9C4E4}- otwierasz bramê do bazy vip\n");
	}
	if(gGracz[playerid][VipLvl] >= LEVEL_SVIP){
		strcat(szAREA,"{F5C172}/vrespawn {A9C4E4}- otwierasz g³osowanie na respawn\n");
		//strcat(szAREA,"{F5C172}/ {A9C4E4}- \n");
	}

	if(gGracz[playerid][VipLvl] >= LEVEL_SVIP){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Komendy Super Vip",szAREA,"Zamknij","");
	} else if(gGracz[playerid][VipLvl] >= LEVEL_VIP){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Komendy Vip",szAREA,"Zamknij","");
	}
	return 1;
}

CMD:vbrama(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP && (gGracz[playerid][FrakcjaPomocDrogowa] == 0 && !SkinyPomocyDrogowej(playerid))) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(IsPlayerInRangeOfPoint(playerid,15,2606.1001, 2302.6001, 7.1400)){
		MoveDynamicObject(SzlabanVip,2606.1001, 2302.6001, 7.1400,1.0,0.0000000,0.0000000,0.000);
		SetTimerEx("ZamykanieSzlabanu",15000,false,"i",playerid);
		SendClientMessage(playerid,COLOR_YELLOW,"Otworzy³eœ bramê do bazy vip!");
	} else {
		SendClientMessage(playerid,COLOR_RED,"*{FFFFFF}Nie jesteœ w pobli¿u bramy do bazy V.I.P");
	}
	return 1;
}

CMD:like(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP && gGracz[playerid][AdminLvl] < LEVEL_ADMIN) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new buffer[256], buffer2[256];
	format(buffer,sizeof(buffer),"{3259BD}[Fb]{FFFFFF}%s {3259BD}lubi to :)",GetPlayerNick(playerid));
	format(buffer2,sizeof(buffer2),"{3259BD}[Fb]{FFFFFF}%s [%i]{3259BD}lubi to :)",GetPlayerNick(playerid),playerid);
	FoxForeach(i,Player){
		if(gGracz[i][AdminLvl] > 4){
			SendClientMessage(i,0xFFFFFFAA,buffer2);
		} else {
			SendClientMessage(i,0xFFFFFFAA,buffer);
		}
	}
	return 1;
}

CMD:vf(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_ERROR,"Musisz byæ w pojeŸdzie.");
	new vid = GetPlayerVehicleID(playerid), Float:x,Float:y,Float:z,string[256], Float:ang;
	GetPlayerPos(playerid,x,y,z);
	SetVehiclePos(vid,x,y,z);
	GetVehicleZAngle(vid,ang);
	SetVehicleZAngle(vid,ang);
	SendClientMessage(playerid,COLOR_YELLOW,"Postawi³eœ auto na 4 ko³a.");
	format(string,sizeof(string),"{E5D800}Vip {FF0000}%s[%i] {E5D800}postawi³ ten pojazd na 4 ko³a.",GetPlayerNick(playerid),playerid);
	FoxForeach(i,Player){
		if(i != playerid){
			if(GetPlayerVehicleID(i) == vid){
				SendClientMessage(i,COLOR_WHITE,string);
			}
		}
	}
	return 1;
}

CMD:vflip(playerid) return cmd_vf(playerid);

CMD:vtrzezwosc(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(gettime() - GetPVarInt(playerid, "vtrzezwosc") < 520){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Tej komendy mo¿esz u¿yæ co 8 minut!\nOdczekaj...","Zamknij","");
		return 1;
	}
	SetPVarInt(playerid, "vtrzezwosc", gettime());
	gGracz[playerid][Zemdlenie] = false;
	SetPlayerDrunkLevel(playerid,0);
	SendClientMessage(playerid,COLOR_YELLOW,"Jesteœ trzeŸwy.");
	return 1;
}

CMD:vtr(playerid) return cmd_vtrzezwosc(playerid);

CMD:vspij(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(gettime() - GetPVarInt(playerid, "Zmeczenie") < 1020){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Tej komendy mo¿esz u¿yæ co 17 minut!\nOdczekaj...","Zamknij","");
		return 1;
	}
	gGracz[playerid][Zemdlenie] = false;
	SetPlayerDrunkLevel(playerid,0);
	SetPVarInt(playerid, "Zmeczenie", gettime());
	gGracz[playerid][Zmeczenie] = 100;
	UpdatujPaski(playerid,2);
	TextDrawHideForPlayer(playerid,TDZasypianie);
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}Vip cmd","{00ff00}Wyspa³eœ siê!","Zamknij","");
	return 1;
}

CMD:vjedzenie(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(gettime() - GetPVarInt(playerid, "jedzenie") < 1020){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Tej komendy mo¿esz u¿yæ co 17 minut!\nOdczekaj...","Zamknij","");
		return 1;
	}
	SetPVarInt(playerid, "jedzenie", gettime());
	gGracz[playerid][Zemdlenie] = false;
	SetPlayerDrunkLevel(playerid,0);
	gGracz[playerid][Glod] = 100;
	UpdatujPaski(playerid,1);
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}Vip cmd","{00ff00}Nape³ni³eœ swój ¿o³¹dek!","Zamknij","");
	return 1;
}

CMD:vj(playerid) return cmd_vjedzenie(playerid);

CMD:vnapraw(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new vid = GetPlayerVehicleID(playerid);
	if(!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_ERROR,"Musisz byæ w pojeŸdzie.");
	if(gettime() - GetPVarInt(playerid, "naprawa") < 700){
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Tej komendy mo¿esz u¿yæ co 7 minut!\nOdczekaj...","Zamknij","");
		return 1;
	}
	RepairVehicle(vid);
	SetVehicleHealth(vid,1000.0);
	SetPVarInt(playerid, "naprawa", gettime());
	if(gGracz[playerid][VipLvl] == 2){
		Paliwo[vid] += 10.0;
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}Vip cmd","{00ff00}Naprawi³eœ i zatankowa³eœ swoje auto!","Zamknij","");
	} else {
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{FFFF00}Vip cmd","{00ff00}Naprawi³eœ swoje auto!","Zamknij","");
	}
	return 1;
}

CMD:colors(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new buffer[2000];
	if(gGracz[playerid][VipLvl] == 1){
		strcat(buffer,"{FFFFFF}[z] - {FFF63D}kolor ¿ó³ty\n");
		strcat(buffer,"{FFFFFF}[b] - {3D63FF}kolor niebieski\n");
		strcat(buffer,"\n{D1D1D1}Przyk³ad zastosowania:\n{FFFFFF}![b]Heja wszystkim");
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{C91313}Kolory",buffer,"Zamknij","");
	} else if(gGracz[playerid][VipLvl] >= 2){
		strcat(buffer,"{FFFFFF}[z] - {FFF63D}kolor ¿ó³ty\n");
		strcat(buffer,"{FFFFFF}[b] - {3D63FF}kolor niebieski\n");
		strcat(buffer,"{FFFFFF}[zi] - {7ED30D}kolor zielony\n");
		strcat(buffer,"{FFFFFF}[f] - {6E05FF}kolor fioletowy\n");
		strcat(buffer,"{FFFFFF}[r] - {FB3DFF}kolor ró¿owy\n");
		strcat(buffer,"{FFFFFF}[c] - {D30D10}kolor czerwony\n");
		strcat(buffer,"\n{D1D1D1}Przyk³ad zastosowania:\n{FFFFFF}![b]Siema wszystkim");
		ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"{C91313}Kolory",buffer,"Zamknij","");
	}
	return 1;
}

CMD:vpogoda(playerid,params[]){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new id;
	new string[700];
	if(sscanf(params,"d",id)){
		return SendClientMessage(playerid,COLOR_WHITE,"U¿yj: /vpogoda [ID pogody]!");
	} else if((gGracz[playerid][VipLvl] <= 1 && id > 20) || (gGracz[playerid][VipLvl] <= 1 && id < 0)){
		return SendClientMessage(playerid,COLOR_RED,"Niepoprawne id pogody");
	} else {
		format(string,sizeof(string),"Zmieni³eœ sobie pogode na %d!",id);
		SetPlayerWeather(playerid,id);
		SendClientMessage(playerid,COLOR_YELLOW,string);
	}
	return 1;
}

CMD:vulecz(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(gettime() - GetPVarInt(playerid,"hp") < 500) return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Mo¿esz uleczyæ siê co 5 minut!\nOdczekaj...","Zamknij","");
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FFFB2E}Uleczy³eœ siê, jako posiadacz konta premium!","Zamknij","");
	SetPlayerHealth(playerid,100);
	SetPVarInt(playerid,"hp",gettime());
	return 1;
}

CMD:varmor(playerid){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	if(gettime() - GetPVarInt(playerid,"armor") < 500) return ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FF0000}Mo¿esz odnawiac armor co 5 minut!\nOdczekaj...","Zamknij","");
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Vip","{FFFB2E}Odnowi³eœ pancerz, jako posiadacz konta premium!","Zamknij","");
	SetPlayerArmour(playerid,100);
	SetPVarInt(playerid,"armor",gettime());
	return 1;
}

CMD:v(playerid,params[]){
	if(gGracz[playerid][VipLvl] < LEVEL_VIP && gGracz[playerid][AdminLvl] < LEVEL_OPERATOR) return SendClientMessage(playerid,COLOR_ERROR,"Nie posiadasz konta premium VIP");
	new text[300];
	new string[700];
	new kolor[14];
	if(sscanf(params,"s[250]",text)){
		return SendClientMessage(playerid,COLOR_WHITE,"Wpisz: /v [tekst]!");
	} else if(gGracz[playerid][StatusMute] == true){
		format(string,sizeof(string),"Jesteœ uciszony, odczekaj %i.",CzasMute[playerid]);
		return SendClientMessage(playerid,COLOR_RED,string);
	} else if(gGracz[playerid][Zalogowany] == false){
		return SendClientMessage(playerid,COLOR_RED,"Nie jesteœ zalogowany!");
	} else {
		if(gGracz[playerid][VipLvl] >= 1){kolor="{E6E6E6}";}
		if(gGracz[playerid][VipLvl] >= 2){kolor="{00D675}";}
		if(gGracz[playerid][AdminLvl] >= 4){kolor="{F02F00}";}
		format(string,sizeof(string),"[VipCzat]%s[%i]%s {FFFF00}mówi: {C4C4C4}%s",kolor,playerid,GetPlayerNick(playerid),text);
		FoxForeach(i,Player){
			if(gGracz[i][VipLvl] >= LEVEL_VIP || gGracz[i][AdminLvl] >= LEVEL_OPERATOR){
				SendClientMessage(i,COLOR_YELLOW,string);
			}
		}
	}
	return 1;
}

