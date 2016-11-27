#define TREE_TYPE_BIG               0
#define TREE_TYPE_SMALL             1
#define TREE_TYPE_SMALL2            2
#define CHRISTMAS_FILE				"/Event/ChristmasData.txt"		//zapis na stale
#define CHRISTMAS_FILE_TMP			"/Event/ChristmasDataTemp.txt"	//pamiec podreczna

forward Christmas_OnFilterScriptInit();

enum XmasTrees {
	XmasTreeX,
	XmasDynamicObject[10]
};

stock SaveChristmasData(type,Float:x,Float:y,Float:z,meta,desc[]){
	new wl_str[512];
	switch(type){
		case 0: format(wl_str,sizeof wl_str,"CreateChristmasTree(%d,%f,%f,%f); //%s\r\n",meta,x,y,z,desc);
		case 1: format(wl_str,sizeof wl_str,"CreateChristmasLights(%f,%f,%f); //%s\r\n",x,y,z,desc);
	}	
	if(!fexist(CHRISTMAS_FILE_TMP)){
		new File:cfile = fopen(CHRISTMAS_FILE_TMP,io_readwrite);
		fwrite(cfile,"");
		fclose(cfile);
	}
	new File:flog = fopen(CHRISTMAS_FILE_TMP,io_append);
	fwrite(flog,wl_str);
	fclose(flog);
}

stock LoadChristmasData(){
	new line[255], File:olist;
	if(fexist(CHRISTMAS_FILE)){
		olist = fopen(CHRISTMAS_FILE, io_read);
		while(fread(olist, line)){

			if(line[0]!='/' && strfind(line,"CreateChristmasTree",true)!=-1){
				new chtype, Float:mx, Float:my, Float:mz, Float:nul;
				if(sscanf(line,"P<,)>'('iffff",chtype,mx,my,mz,nul)){
					CreateChristmasTree(chtype,mx,my,mz);
				} else {
					printf("Blad w parsowaniu: %s",line);
				}
			} else if(line[0]!='/' && strfind(line,"CreateChristmasLights",true)!=-1){
				new Float:mx, Float:my, Float:mz, Float:nul;
				if(sscanf(line,"P<,)>'('fffd",mx,my,mz,nul)){
					CreateChristmasLights(mx,my,mz);
				} else {
					printf("Blad w parsowaniu: %s",line);
				}
			}
		}
		fclose(olist);
	}
}

stock CreateChristmasLights(Float:x,Float:y,Float:z){
	CreateDynamicObject(3472,x,y,z-0.5,0,0,300);
	CreateDynamicObject(3472,x,y,z+4,0,0,300);
}

stock CreateChristmasTree(type,Float:x,Float:y,Float:z){
	switch(type){
		case TREE_TYPE_BIG: {
			CreateDynamicObject(3472,x+0.28564453,y+0.23718262,z+27.00000000,0.00000000,0.00000000,230.48021);
			CreateDynamicObject(664,x+0.20312500,y+0.01171875,z+-3.00000000,0.00000000,0.00000000,0.00000000);
			CreateDynamicObject(3472,x+0.45312500,y+0.51562500,z+4.00000000,0.00000000,0.00000000,69.7851562);
			CreateDynamicObject(3472,x+0.65136719,y+1.84570312,z+17.00000000,0.00000000,0.00000000,41.863403);
			CreateDynamicObject(7666,x+0.34130859,y+0.16845703,z+45.00000000,0.00000000,0.00000000,298.12524);
			CreateDynamicObject(7666,x+0.34082031,y+0.16796875,z+45.00000000,0.00000000,0.00000000,27.850342);
			CreateDynamicObject(3472,x+0.45312500,y+0.51562500,z+12.00000000,0.00000000,0.00000000,350.02441);
			CreateDynamicObject(3472,x+0.45312500,y+0.51562500,z+7.00000000,0.00000000,0.00000000,30.0805664);
			CreateDynamicObject(3472,x+0.45312500,y+0.51562500,z+22.00000000,0.00000000,0.00000000,230.47119);
			CreateDynamicObject(1262,x+0.15039062,y+0.57128906,z+29.45285416,0.00000000,0.00000000,162.90527);
		}
		case TREE_TYPE_SMALL: {
			CreateDynamicObject(19076,x,y,z-1.0,0,0,300);
			CreateDynamicObject(19054,x,y+1.0,z-0.4,0,0,300);
			CreateDynamicObject(19058,x+1.0,y,z-0.4,0,0,300);
			CreateDynamicObject(19056,x,y-1.0,z-0.4,0,0,300);
			CreateDynamicObject(19057,x-1.0,y,z-0.4,0,0,300);
			CreateDynamicObject(19058,x-1.5,y+1.5,z-1.0,0,0,300);
			CreateDynamicObject(19055,x+1.5,y-1.5,z-1.0,0,0,300);
			CreateDynamicObject(19057,x+1.5,y+1.5,z-1.0,0,0,300);
			CreateDynamicObject(19054,x-1.5,y-1.5,z-1.0,0,0,300);
			CreateDynamicObject(3526,x,y,z-1.0,0,0,300);
		}
		case TREE_TYPE_SMALL2: {
			CreateDynamicObject(19076,x,y,z-1,0.00,0.00,0.00);
			CreateDynamicObject(19054,x+0.37,y+2.38,z-0.5,0.00,0.00,0.00);
			CreateDynamicObject(19055,x-1.18,y-1.18,z-0.5,0.00,0.00,0.00);
			CreateDynamicObject(19056,x+1.94,y-1.34,z-0.5,0.00,0.00,0.00);
			CreateDynamicObject(19057,x+1.67,y+1.52,z-0.5,0.00,0.00,0.00);
		}
	}
}

public Christmas_OnFilterScriptInit(){
	
	LoadChristmasData();
	
	return 1;
}

CMD:addchoinka(playerid,params[]){
	if(!IsPlayerAdmin(playerid)) return 0;
	new chtype, Float:mx, Float:my, Float:mz, opis[128];
	if(sscanf(params,"ds[128]",chtype,opis)) return SendClientMessage(playerid,0xFFFFFFFF,"/addchoinka <type> <opis>");
	if(chtype < 0 || chtype > 2) return SendClientMessage(playerid,0xFFFFFFFF,"Dostêpne typy 1-3");
	GetPlayerPos(playerid,mx,my,mz);
	CreateChristmasTree(chtype,mx,my,mz);
	SaveChristmasData(0,mx,my,mz,chtype,opis);
	return 1;
}

CMD:addlampa(playerid,params[]){
	if(!IsPlayerAdmin(playerid)) return 0;
	new Float:mx, Float:my, Float:mz, opis[128];
	if(sscanf(params,"s[128]",opis)) return SendClientMessage(playerid,0xFFFFFFFF,"/addlampa <opis>");
	GetPlayerPos(playerid,mx,my,mz);
	mz-=0.5;
	CreateChristmasLights(mx,my,mz);
	SaveChristmasData(1,mx,my,mz,0,opis);
	SetPlayerPos(playerid,mx,my,mz);
	return 1;
}