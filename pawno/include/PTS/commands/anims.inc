
CMD:anims(playerid){
	new buffer[900];
	buffer = "{C6C8C6}";
	strcat(buffer,"/poddajsie\t/jaraj\t\t/machaj\t\t/siad\n");
	strcat(buffer,"/striptiz\t/caluj\t\t/sex\t\t\t/wendka\n");
	strcat(buffer,"/klaps\t\t/klaps2\t\t/bar2\t\t\t/bar3\n");
	strcat(buffer,"/opalaj\t\t/opalaj2\t/rozmowaauto\t\t/szafka\n");
	strcat(buffer,"/zegarek\t/cpun2\t\t/cpun3\t\t\t/cpun4\n");
	strcat(buffer,"/cpun5\t\t/rolki\t\t/taniec\t\t\t/taniec2\n");
	strcat(buffer,"/taniec3\t/taniec4\t/taniec5\t\t/taniec6\n");
	strcat(buffer,"/taniec7\t/grubas\t/grubas2\t\t/jedz2\n");
	strcat(buffer,"/jedz3\t\t/rece4\t\t/rece5\t\t\t/rece6\n");
	strcat(buffer,"/krzeslo\t/krzeslo2\t/krzeslo3\t\t/turlaj\n");
	strcat(buffer,"/boks\t\t/kopniak\t/opalaj3\t\t/swat\n");
	strcat(buffer,"/swat2\t\t/swat3\t\t/trup2\t\t\t/ratunku\n");
	strcat(buffer,"/trup\t\t/calus\t\t/sikaj\t\t\t/rece\n");
	strcat(buffer,"/wankin\t/wankout\t/cellin\t\t\t/piwo\n");
	strcat(buffer,"/wino\t\t/papieros\t/sprunk\t\t/cellout\n");
	strcat(buffer,"/drunk\t\t/bomb\t\t/aresztuj\t\t/rap\n");
	strcat(buffer,"/lookout\t/napad\t\t/rece2\t\t\t/lez\n");
	strcat(buffer,"/lez2\t\t/hide\t\t/rzygaj\t\t\t/jedz\n");
	strcat(buffer,"/deal\t\t/deal2\t\t/cpun\t\t\t/smoke\n");
	strcat(buffer,"/fsmoke\t/smoke2\t/rece3\t\t\t/siadaj\n");
	strcat(buffer,"/chat\t\t/fucku\t\t/taichi\t\t\t/pij\n");
	strcat(buffer,"/inbedright\t/inbedleft\t/dance\t\t\t/skacz\n");
	strcat(buffer,"\n/astop\n\n{FFFFFF}OdwiedŸ nasze forum: {FF0000}www.ptstruck.pl!\n");
	
	ShowPlayerDialog(playerid,DIALOG_INF,DIALOG_STYLE_MSGBOX,"Animacje serwera",buffer,"Zamkij","");
	return 1;
}

CMD:animacje(playerid)
	return cmd_anims(playerid);

CMD:astop(playerid){
	if(IsAnimAllow(playerid)){
		ClearAnimations(playerid,0);
		gGracz[playerid][performingAnim] = false;
	}
	return 1;
}

CMD:poddajsie(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
		SendClientMessage(playerid,COLOR_INFO,"Poddajesz sie");
	}
	return 1;
}

CMD:jaraj(playerid){
	if(LoopingAnim(playerid,"SMOKING","M_smk_drag",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Jarasz");
	return 1;
}

CMD:machaj(playerid){
	if(LoopingAnim(playerid,"KISSING","GFWAVE2",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Machasz");
	return 1;
}

CMD:siad(playerid){
	if(LoopingAnim(playerid,"INT_HOUSE","LOU_LOOP",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Siadasz");
	return 1;
}

CMD:skacz(playerid){
	if(LoopingAnim(playerid,"DAM_JUMP","DAM_LAUNCH",2,0,1,1,0,0)) SendClientMessage(playerid,COLOR_INFO,"Skaczemy");
	return 1;
}

CMD:striptiz(playerid){
	if(LoopingAnim(playerid,"STRIP","STR_LOOP_A",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Uprawiasz striptiz");
	return 1;
}

CMD:sex(playerid){
	if(LoopingAnim(playerid,"STRIP","STR_Loop_C",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Dymasz sie");
	return 1;
}

CMD:wendka(playerid){
	if(LoopingAnim(playerid,"SWORD","sword_IDLE",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Lowisz ryby");
	return 1;
}

CMD:klaps(playerid){
	if(LoopingAnim(playerid,"SWEET","sweet_ass_slap",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Dajesz klapsa komus");
	return 1;
}

CMD:klaps2(playerid){
	if(LoopingAnim(playerid,"SWEET","ho_ass_slapped",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Dajesz klapsa komus");
	return 1;
}

CMD:bar2(playerid){
	if(LoopingAnim(playerid,"BAR","Barserve_bottle",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Podajesz zimne piwko");
	return 1;
}

CMD:bar3(playerid){
	if(LoopingAnim(playerid,"BAR","Barserve_give",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Podajesz zimne piwko");
	return 1;
}

CMD:opalaj(playerid){
	if(LoopingAnim(playerid,"BEACH","ParkSit_W_loop",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Opalasz sie");
	return 1;
}

CMD:opalaj2(playerid){
	if(LoopingAnim(playerid,"BEACH","SitnWait_loop_W",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Opalasz sie");
	return 1;
}

CMD:rozmowaauto(playerid){
	if(LoopingAnim(playerid,"CAR_CHAT","car_talkm_loop",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Rozmawiasz z kims w aucie");
	return 1;
}

CMD:szafka(playerid){
	if(LoopingAnim(playerid,"COP_AMBIENT","Copbrowse_nod",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Bierzesz cos z szafki");
	return 1;
}

CMD:zegarek(playerid){
	if(LoopingAnim(playerid,"COP_AMBIENT","Coplook_nod",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Patrzysz na zegarek");
	return 1;
}

CMD:cpun2(playerid){
	if(LoopingAnim(playerid,"CRACK","crckdeth1",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz jak cpun");
	return 1;
}

CMD:cpun3(playerid){
	if(LoopingAnim(playerid,"CRACK","crckdeth3",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz jak cpun");
	return 1;
}

CMD:cpun4(playerid){
	if(LoopingAnim(playerid,"CRACK","crckdeth4",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz jak cpun");
	return 1;
}

CMD:cpun5(playerid){
	if(LoopingAnim(playerid,"CRACK","crckidle4",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz jak cpun");
	return 1;
}

CMD:rolki(playerid){
	if(LoopingAnim(playerid,"SKATE","skate_sprint",4.0999,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Jedziesz na rolkach");
	return 1;
}

CMD:taniec(playerid){
	if(LoopingAnim(playerid,"DANCING","bd_clap",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec2(playerid){
	if(LoopingAnim(playerid,"DANCING","bd_clap1",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec3(playerid){
	if(LoopingAnim(playerid,"DANCING","DAN_Down_A",4.0,1,1,1,1,1))SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec4(playerid){
	if(LoopingAnim(playerid,"DANCING","DAN_Left_A",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec5(playerid){
	if(LoopingAnim(playerid,"DANCING","DAN_Right_A",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec6(playerid){
	if(LoopingAnim(playerid,"DANCING","DAN_Up_A",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:taniec7(playerid){
	if(LoopingAnim(playerid,"DANCING","dnce_M_a",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Tanczysz");
	return 1;
}

CMD:grubas(playerid){
	if(LoopingAnim(playerid,"FAT","FatWalk",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Idziesz jak grubas");
	return 1;
}

CMD:grubas2(playerid){
	if(LoopingAnim(playerid,"FAT","FatRun",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Biegniesz jak grubas");
	return 1;
}

CMD:jedz2(playerid){
	if(LoopingAnim(playerid,"FOOD","FF_Die_Bkw",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Jesz cos");
	return 1;
}

CMD:jedz3(playerid){
	if(LoopingAnim(playerid,"FOOD","FF_Sit_Eat1",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Jesz cos");
	return 1;
}

CMD:rece4(playerid){
	if(LoopingAnim(playerid,"GANGS","hndshkfa",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Wymachujesz Rekami");
	return 1;
}

CMD:rece5(playerid){
	if(LoopingAnim(playerid,"GHANDS","gsign1",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Wymachyjesz Rekami");
	return 1;

}

CMD:rece6(playerid){
	if(LoopingAnim(playerid,"GHANDS","gsign1LH",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Wymachyjesz Rekami");
	return 1;
}

CMD:krzeslo(playerid){
	if(LoopingAnim(playerid,"INT_OFFICE","OFF_Sit_Idle_Loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Siadasz na krzesle");
	return 1;
}

CMD:krzeslo2(playerid){
	if(LoopingAnim(playerid,"JST_BUISNESS","girl_02",4.0,1,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Siadasz na krzesle jak kobieta");
	return 1;
}

CMD:krzeslo3(playerid){
	if(LoopingAnim(playerid,"Attractors","Stepsit_loop",4.0,0,0,0,1,0)) SendClientMessage(playerid,COLOR_INFO,"Siadasz na krzesle");
	return 1;
}

CMD:turlaj(playerid){
	if(LoopingAnim(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll_F",4.0,1,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Turlasz sie xD");
	return 1;
}

CMD:boks(playerid){
	if(LoopingAnim(playerid,"GYMNASIUM","GYMshadowbox",4.0,1,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Trenujesz boks");
	return 1;
}

CMD:kopniak(playerid){
	if(LoopingAnim(playerid,"POLICE","Door_Kick",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Kopiesz :P");
	return 1;
}

CMD:opalaj3(playerid){
	if(LoopingAnim(playerid,"SUNBATHE","ParkSit_W_idleA",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Opalasz sie");
	return 1;
}

CMD:swat(playerid){
	if(LoopingAnim(playerid,"SWAT","swt_breach_01",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Biegasz jak SWAT");
	return 1;
}

CMD:swat2(playerid){
	if(LoopingAnim(playerid,"SWAT","swt_breach_02",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Biegasz jak SWAT");
	return 1;
}

CMD:swat3(playerid){
	if(LoopingAnim(playerid,"SWAT","swt_breach_03",4.0,0,1,1,1,0)) SendClientMessage(playerid,COLOR_INFO,"Biegasz jak SWAT");
	return 1;
}

CMD:trup2(playerid){
	if(LoopingAnim(playerid,"SWAT","gnstwall_injurd",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Udajesz trupa");
	return 1;
}

CMD:ratunku(playerid){
	if(LoopingAnim(playerid,"BD_FIRE","BD_Panic_03",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Machasz o pomoc!");
	return 1;
}

CMD:trup(playerid){
	if(LoopingAnim(playerid,"WUZI","CS_Dead_Guy",4.1,0,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Udajesz trupa");
	return 1;
}

CMD:calus(playerid){
	if(LoopingAnim(playerid,"KISSING","Playa_Kiss_02",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Calujesz kogos");
	return 1;
}

CMD:sikaj(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,68);
		SendClientMessage(playerid,COLOR_INFO,"Odlewasz sie");
	}
	return 1;
}

CMD:rece(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);
		SendClientMessage(playerid,COLOR_INFO,"Poddajesz sie");
	}
	return 1;
}

CMD:wankin(playerid){
	if(LoopingAnim(playerid,"PAULNMAC","wank_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Walisz konia");
	return 1;
}

CMD:wankout(playerid){
	if(LoopingAnim(playerid,"PAULNMAC","wank_out",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Robisz wytrysk xD");
	return 1;
}

CMD:cellin(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USECELLPHONE);
		SendClientMessage(playerid,COLOR_INFO,"Dzwonisz do mamy");
	}
	return 1;
}

CMD:piwo(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerDrunkLevel(playerid,10000);
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_BEER);
		SetPlayerFightingStyle(playerid,FIGHT_STYLE_ELBOW);
		SendClientMessage(playerid,COLOR_INFO,"Pijesz Piwo!");
	}
	return 1;
}

CMD:wino(playerid){
	if(IsAnimAllow(playerid)){	
		SetPlayerDrunkLevel(playerid,1000000);
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_WINE);
		SetPlayerFightingStyle(playerid,FIGHT_STYLE_GRABKICK);
		SendClientMessage(playerid,COLOR_INFO,"Pijesz Wino!");
	}
	return 1;
}

CMD:papieros(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_SMOKE_CIGGY);
		SendClientMessage(playerid,COLOR_INFO,"Palisz Papierosa!");
	}
	return 1;
}

CMD:sprunk(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DRINK_SPRUNK);
		SetPlayerDrunkLevel(playerid,0);
		SendClientMessage(playerid,COLOR_INFO,"Pijesz Sprunka!");
	}
	return 1;
}

CMD:cellout(playerid){
	if(IsAnimAllow(playerid)){
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_STOPUSECELLPHONE);
		SendClientMessage(playerid,COLOR_INFO,"Odkladasz telefon");
	}
	return 1;
}

CMD:drunk(playerid){
	if(LoopingAnim(playerid,"PED","WALK_DRUNK",4.0,1,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Chodzisz jak pijany(a)");
	return 1;
}

CMD:bomb(playerid){
	if(OnePlayAnim(playerid,"BOMBER","BOM_Plant",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Podkladasz bombe");
	return 1;
}

/*
CMD:aresztuj(playerid){
	if(LoopingAnim(playerid,"ped","ARRESTgun",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Aresztujesz kogos");
	return 1;
}
*/

CMD:rap(playerid){
	if(LoopingAnim(playerid,"RAPPING","RAP_B_Loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Rapujesz");
	return 1;
}

CMD:lookout(playerid){
	if(OnePlayAnim(playerid,"SHOP","ROB_Shifty",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Rozgladasz sie");
	return 1;
}

CMD:napad(playerid){
	if(LoopingAnim(playerid,"SHOP","ROB_Loop_Threat",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Robisz napad");
	return 1;
}

CMD:rece2(playerid){
	if(LoopingAnim(playerid,"COP_AMBIENT","Coplook_loop",4.0,0,1,1,1,-1)) SendClientMessage(playerid,COLOR_INFO,"Zakladasz rece");
	return 1;
}

CMD:lez(playerid){
	if(LoopingAnim(playerid,"SUNBATHE","batherdown",4.1,0,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Lezysz");
	return 1;
}

CMD:lez2(playerid){
	if(LoopingAnim(playerid,"BEACH","bather",4.0,0,0,0,1,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz");
	return 1;
}

CMD:hide(playerid){
	if(LoopingAnim(playerid,"ped","cower",3.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Oslaniasz sie.");
	return 1;
}

CMD:rzygaj(playerid){
	if(OnePlayAnim(playerid,"FOOD","EAT_Vomit_P",3.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Blee!");
	return 1;
}

CMD:jedz(playerid){
	if(OnePlayAnim(playerid,"FOOD","EAT_Burger",3.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Jesz cos");
	return 1;
}

CMD:deal(playerid){
	if(OnePlayAnim(playerid,"DEALER","DEALER_DEAL",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Dealujesz z kims");
	return 1;
}

CMD:deal2(playerid){
	if(LoopingAnim(playerid,"DEALER","SHOP_PAY",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Dealujesz z kims");
	return 1;
}

CMD:cpun(playerid){
	if(LoopingAnim(playerid,"CRACK","crckdeth2",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Lezysz jak cpun");
	return 1;
}

CMD:smoke(playerid){
	if(LoopingAnim(playerid,"SMOKING","M_smklean_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Palisz papierosa");
	return 1;
}

CMD:fsmoke(playerid){
	if(LoopingAnim(playerid,"SMOKING","F_smklean_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Palisz papierosa jak kobieta");
	return 1;
}

CMD:smoke2(playerid){
	if(LoopingAnim(playerid,"SMOKING","M_smkstnd_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Palisz papierosa");
	return 1;
}

CMD:rece3(playerid){
	if(LoopingAnim(playerid,"DAM_JUMP","DAM_Dive_Loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Stoisz na rekach");
	return 1;
}

CMD:siadaj(playerid){
	if(LoopingAnim(playerid,"BEACH","ParkSit_M_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Siadasz");
	return 1;
}

CMD:chat(playerid){
	if(LoopingAnim(playerid,"PED","IDLE_CHAT",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Rozmawiasz z kims");
	return 1;
}

CMD:fucku(playerid){
	if(OnePlayAnim(playerid,"PED","fucku",4.0,0,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Pokazujesz Spier...");
	return 1;
}

CMD:taichi(playerid){
	if(LoopingAnim(playerid,"PARK","Tai_Chi_Loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Umiesz takewondo");
	return 1;
}

CMD:pij(playerid){
	if(LoopingAnim(playerid,"BAR","dnk_stndF_loop",4.0,1,0,0,0,0)) SendClientMessage(playerid,COLOR_INFO,"Pijesz cos");
	return 1;
}

CMD:inbedright(playerid){
	if(LoopingAnim(playerid,"INT_HOUSE","BED_In_R",4.1,0,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Idzisz spac");
	return 1;
}

CMD:inbedleft(playerid){
	if(LoopingAnim(playerid,"INT_HOUSE","BED_In_L",4.1,0,1,1,1,1)) SendClientMessage(playerid,COLOR_INFO,"Idziesz spac");
	return 1;
}

CMD:dance(playerid,cmdtext[]){
	if(IsAnimAllow(playerid)){
		new dance;
		if(sscanf(cmdtext,"d",dance)){
			SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /dance [1-4]");
			return 1;
		}
		if(dance < 1 || dance > 4) {
			SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /dance [1-4]");
			return 1;
		}
		if(dance == 1) {
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
		} else if(dance == 2) {
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
		} else if(dance == 3) {
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
		} else if(dance == 4) {
			SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
		}
	}
	return 1;
}

CMD:caluj(playerid,params[]){
	new buffer[128],userid;
	if(isnull(params)) return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /caluj <id>");
	if(sscanf(params,"d",userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"U¿yj: /caluj <id>");
	} else if(!IsPlayerConnected(userid)){
		return SendClientMessage(playerid,COLOR_ERROR,"Nie ma takiego gracza");
	}
	if(userid == playerid) return SendClientMessage(playerid,COLOR_ERROR,"Nie potrafiê ca³owaæ samego siebie");
	if(GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(userid) || GetPlayerInterior(playerid) != GetPlayerInterior(userid)) return SendClientMessage(playerid,COLOR_ERROR,"Gracz nie znajduje siê w pobli¿u");
	new F4[e_float];
	GetPlayerPos(playerid,F4[X],F4[Y],F4[Z]);
	GetPlayerPos(userid,F4[tX],F4[tY],F4[tZ]);
	new Float:dist = GetDistanceBetweenPoints3D(F4[X],F4[Y],F4[Z],F4[tX],F4[tY],F4[tZ]);
	if(dist <= 2.0){
		if(!IsAnimAllow(playerid) || !IsAnimAllow(userid)) return 1;
		GetPlayerFacingAngle(playerid,F4[rZ]);
		GetPointInFront2D(F4[X],F4[Y],F4[rZ],0.7,F4[tX],F4[tY]);
		SetPlayerPos(userid,F4[tX],F4[tY],F4[Z]);
		SetPlayerFacingAngle(userid,F4[rZ]+180.0);
		LoopingAnim(playerid,"KISSING","Playa_Kiss_02",4.0,0,0,0,0,0);
		LoopingAnim(userid,"KISSING","Playa_Kiss_02",4.0,0,0,0,0,0);
		format(buffer,sizeof buffer,"Calujesz %s",GetPlayerNick(userid));
		SendClientMessage(playerid,COLOR_INFO,buffer);
		format(buffer,sizeof buffer,"Jestes calowany przez %s",GetPlayerNick(playerid));
		SendClientMessage(userid,COLOR_INFO,buffer);
	} else return SendClientMessage(playerid,COLOR_ERROR,"Gracz nie znajduje siê w pobli¿u");
	return 1;
}

// EOF
