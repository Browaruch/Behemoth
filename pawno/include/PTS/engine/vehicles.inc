LoadVehicles(){
	new tmpobj;
	
	Lodzie[0] = AddStaticVehicleEx(453,-2201.6699,2419.6094,0.2591,50.0000,-1,-1,-1);
	Lodzie[1] = AddStaticVehicleEx(453,-2210.8103,2409.9932,0.4591,50.0000,-1,-1,-1);
	Lodzie[2] = AddStaticVehicleEx(453,-2231.9556,2447.8694,0.2591,220.0000,-1,-1,-1);
	Lodzie[3] = AddStaticVehicleEx(453,-2241.7429,2440.0588,0.2591,220.0000,-1,-1,-1);
	Lodzie[4] = AddStaticVehicleEx(595,-2259.7136,2421.9634,0.6000,-133.9800,-1,-1,-1);
	Lodzie[5] = AddStaticVehicleEx(595,-2230.9053,2392.0842,0.6000,41.9940,-1,-1,-1);
	Lodzie[6] = AddStaticVehicleEx(472,-2225.1062,2399.3721,1.4876,46.2000,-1,221,-1);
	Lodzie[7] = AddStaticVehicleEx(472,-2253.0559,2427.5918,1.0256,226.1900,235,7,-1);
	
	PojazdySG[0] = AddStaticVehicleEx(554,2414.5955,145.2123,26.5641,-90.0000000,1,0,-1,1);
	PojazdySG[1] = AddStaticVehicleEx(554,2414.6084,153.0965,26.2956,-90.0,1,0,-1,1);
	PojazdySG[2] = AddStaticVehicleEx(551,2414.3157,149.1269,26.2955,-90.0000,0,1,-1,1); //Mesa
	PojazdySG[3] = AddStaticVehicleEx(551,2414.7468,141.6130,26.6482,-90.0000,1,0,-1,1); //Mesa
	PojazdySG[4] = AddStaticVehicleEx(482,2432.4031,144.3523,26.6261,90.0000,0,0,-1,1); //Huntley
	PojazdySG[5] = AddStaticVehicleEx(482,2413.6191,133.1533,26.6261,-90.0000,0,0,-1,1); //Huntley
	PojazdySG[6] = AddStaticVehicleEx(579,2413.9382,137.2137,26.4482,-90.0000,86,86,-1); //Huntley
	PojazdySG[7] = AddStaticVehicleEx(579,2413.8267,125.0933,26.4482,-90.0000,86,86,-1); //Huntley
	PojazdySG[8] = AddStaticVehicleEx(579,2414.2458,121.1404,26.4482,-90.0000,86,86,-1); //Huntley
	PojazdySG[9] = AddStaticVehicleEx(579,2414.0867,117.0582,26.4482,-90.0000,86,86,-1); // autoSG1
	PojazdySG[10] = AddStaticVehicleEx(579,2414.6758,113.2682,26.4482,-90.0000,86,86,-1); // autoSG2

	tmpobj = CreateDynamicObject(19327,165.29523,1746.38318,17.48860,0.00000,0.00000,90.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",24,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[4],-1.0,-1,0.5,-5,0,-90);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",24,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[5],-1.0,-1,0.5,-5,0,-90);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[1],0,1.9,0.5,-85,0,180);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[0],0,1.9,0.5,-85,0,180);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[4],1.0,-1,0.5,-5,0,90);

	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[5],1.0,-1,0.5,-5,0,90);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[2],0,1.9,0.3,-85,0,180);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"Straø\nGraniczna",60,"Arial",22,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[3],0,1.9,0.3,-85,0,180);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[1],0,0.1,1,0,0,0);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[0],0,0.1,1,0,0,0);
	
	tmpobj = CreateDynamicObject(18646,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[2],0,0.3,0.9,0,0,0);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[3],0,0.1,0.8,0,0,0);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[4],0,1,0.9,0,0,0);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdySG[5],0,1,0.9,0,0,0);
	
	

	AutaDoPrawka[0] = AddStaticVehicleEx(401,1171.0316,1342.2573,11.6467,90.0000,126,126,100);
	AutaDoPrawka[1] = AddStaticVehicleEx(401,1171.0671,1337.6243,11.6467,90.0000,126,126,100);
	AutaDoPrawka[2] = AddStaticVehicleEx(401,1170.9856,1332.9117,11.6467,90.0000,126,126,100);
	AutaDoPrawka[3] = AddStaticVehicleEx(401,1152.0135,1341.1031,11.6467,-90.0000,126,126,100);
	AutaDoPrawka[4] = AddStaticVehicleEx(403,-2034.0673,-136.6743,35.8830,180.0000,126,126,100);
	AutaDoPrawka[5] = AddStaticVehicleEx(435,-2034.1888,-126.4292,35.8444,180.0000,126,126,100);
	AutaDoPrawka[6] = AddStaticVehicleEx(403,-2025.3226,-137.0883,35.8830,180.0000,126,126,100);
	AutaDoPrawka[7] = AddStaticVehicleEx(403,-2020.4388,-136.9166,35.8830,180.0000,126,126,100);
	AutaDoPrawka[8] = CreateVehicle(403,-2015.6952,-136.5492,35.8830,180.0000,126,126,100);
	AutaDoPrawka[9] = AddStaticVehicleEx(435,-2015.4362,-127.1649,35.7853,180.0000,126,126,100);
	AutaDoPrawka[10] = AddStaticVehicleEx(435,-2020.5269,-127.5799,35.7853,180.0000,126,126,100);
	AutaDoPrawka[11] = AddStaticVehicleEx(435,-2025.6550,-127.8849,35.7853,180.0000,126,126,100);
	
	
	
	
	PojazdyRS[0] = AddStaticVehicleEx(530,1395.8000,723.6000,10.6000,88.0000,-1,-1,-1);
	PojazdyRS[1] = AddStaticVehicleEx(530,1395.8000,719.3000,10.6000,87.9950,-1,-1,-1);
	PojazdyRS[2] = AddStaticVehicleEx(486,1392.9004,715.2998,11.2000,90.0000,-1,-1,-1);
	PojazdyRS[3] = AddStaticVehicleEx(552,1393.7523,729.4550,10.5120,90.0000,-1,-1,-1); //ok
	PojazdyRS[4] = AddStaticVehicleEx(552,1393.3000,707.8000,10.6000,90.0000,-1,-1,-1); //ok
	PojazdyRS[5] = AddStaticVehicleEx(611,1395.5000,702.6000,10.5000,90.0000,-1,-1,-1);
	PojazdyRS[6] = AddStaticVehicleEx(611,1395.5000,700.0000,10.5000,90.0000,-1,-1,-1);
	PojazdyRS[7] = AddStaticVehicleEx(515,1314.8263,752.7869,12.3601,270.0000,-1,-1,-1); //ok
	PojazdyRS[8] = AddStaticVehicleEx(515,1314.8551,747.5940,12.3598,270.0000,-1,-1,-1); //ok
	PojazdyRS[9] = AddStaticVehicleEx(563,1315.3351,661.2606,13.9323,270.0000,-1,-1,-1); //ok
	
	PojazdyRS[10] = AddStaticVehicleEx(525,1382.8495,759.7336,10.6955,180.0000,-1,-1,-1); //ok
	PojazdyRS[11] = AddStaticVehicleEx(525,1390.1655,760.0800,10.7030,180.0000,-1,-1,-1); //ok
	PojazdyRS[12] = AddStaticVehicleEx(473,1631.2687,572.0651,-0.1328,180.7051,0,226,-1); // ≥Ûdü
	PojazdyRS[13] = AddStaticVehicleEx(473,1623.8759,572.2596,-0.1591,178.1602,0,226,-1); // ≥Ûdü

	//PojazdyRS[12] = AddStaticVehicleEx(525,1314.4000,767.3000,10.8000,270.0000,-1,-1,-1);
	//PojazdyRS[13] = AddStaticVehicleEx(525,1314.0996,759.7002,10.8000,270.0000,-1,-1,-1);
	
	PojazdyRS[14] = AddStaticVehicleEx(525,1375.6469,759.5955,10.7310,180.0000,-1,-1,-1); //ok
	
	PojazdyRS[15] = AddStaticVehicleEx(525,1361.4521,760.2687,10.6970,180.0000,-1,-1,-1); //ok
	PojazdyRS[16] = AddStaticVehicleEx(525,1368.4261,760.1799,10.6998,180.0000,-1,-1,-1); //ok
	
	PojazdyRS[17] = AddStaticVehicleEx(443,1317.8000,700.5000,11.6000,270.0000,-1,-1,-1);
	PojazdyRS[18] = AddStaticVehicleEx(443,1317.8000,707.0000,11.6000,270.0000,-1,-1,-1);
	PojazdyRS[19] = AddStaticVehicleEx(578,1313.3000,715.1000,11.6000,270.0000,-1,-1,-1);
	PojazdyRS[20] = AddStaticVehicleEx(578,1313.2000,720.9000,11.6000,270.0000,-1,-1,-1);

	PojazdyTaxi[0] = AddStaticVehicleEx(420,2622.3394,1228.1869,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[1] = AddStaticVehicleEx(420,2622.3401,1222.9359,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[2] = AddStaticVehicleEx(420,2622.3508,1218.0876,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[3] = AddStaticVehicleEx(420,2622.3401,1212.8960,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[4] = AddStaticVehicleEx(438,2622.7625,1207.8792,11.0065,90.0000,-1,-1,-1);
	PojazdyTaxi[5] = AddStaticVehicleEx(438,2622.7625,1202.8593,11.0065,90.0600,-1,-1,-1);
	PojazdyTaxi[6] = AddStaticVehicleEx(438,2622.7849,1197.8221,11.0065,90.0000,-1,-1,-1);
	PojazdyTaxi[7] = AddStaticVehicleEx(438,2622.7627,1192.7992,11.0065,90.0000,-1,-1,-1);
	PojazdyTaxi[8] = AddStaticVehicleEx(437,2643.4473,1227.7802,10.8450,180.0000,-1,-1,-1);
	PojazdyTaxi[9] = AddStaticVehicleEx(437,2652.7222,1228.0873,10.8450,180.0000,-1,-1,-1);
	PojazdyTaxi[10] = AddStaticVehicleEx(437,2661.7627,1228.0210,10.8450,180.0000,-1,-1,-1);
	PojazdyTaxi[11] = AddStaticVehicleEx(409,2668.6841,1228.8616,10.6228,180.0000,194,194,-1);
	PojazdyTaxi[12] = AddStaticVehicleEx(420,2622.6663,1233.0021,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[13] = AddStaticVehicleEx(420,2622.8335,1237.7356,10.7506,90.0000,-1,-1,-1);
	PojazdyTaxi[14] = AddStaticVehicleEx(438,2622.7180,1187.7399,11.0065,90.0000,-1,-1,-1);
	PojazdyTaxi[15] = AddStaticVehicleEx(420,2637.2969,1234.9652,10.7506,0.0000,-1,-1,-1);
	PojazdyTaxi[16] = AddStaticVehicleEx(420,2637.3601,1226.4402,10.7506,0.0000,-1,-1,-1);
	PojazdyTaxi[17] = AddStaticVehicleEx(438,2630.2578,1165.9181,11.0065,-90.0000,-1,-1,-1);
	PojazdyTaxi[18] = AddStaticVehicleEx(438,2623.3943,1165.9290,11.0065,-90.0000,-1,-1,-1);
	PojazdyTaxi[19] = AddStaticVehicleEx(420,2637.5574,1165.9387,10.7506,-90.0000,-1,-1,-1);
	PojazdyTaxi[20] = AddStaticVehicleEx(580,2671.7798,1228.0879,10.4469,180.0000,6,6,-1);
	PojazdyTaxi[21] = AddStaticVehicleEx(561,2657.4954,1179.9794,10.7531,-90.0000,6,6,-1);
	PojazdyTaxi[22] = AddStaticVehicleEx(561,2657.5295,1185.5762,10.7531,-90.0000,6,6,-1);
	
	tmpobj = CreateDynamicObject(19308,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyTaxi[21],0,0.0,0.90,0,0,90);
	
	tmpobj = CreateDynamicObject(19308,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyTaxi[22],0,0.0,0.90,0,0,90);
	
	PojazdyMedykow[0] = AddStaticVehicleEx(416,1593.2471,1847.7797,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[1] = AddStaticVehicleEx(416,1600.2047,1848.7959,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[2] = AddStaticVehicleEx(416,1604.1656,1848.3135,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[3] = AddStaticVehicleEx(416,1608.4089,1849.3983,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[4] = AddStaticVehicleEx(416,1614.1095,1848.6387,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[5] = AddStaticVehicleEx(416,1619.3735,1848.0642,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[6] = AddStaticVehicleEx(416,1625.2164,1847.6917,11.0160,180.0000,-1,-1,-1);
	PojazdyMedykow[7] = AddStaticVehicleEx(489,1604.1512,1857.0729,11.0330,180.0000,-1,-1,-1);
	PojazdyMedykow[8] = AddStaticVehicleEx(489,1598.5176,1856.9478,11.0330,180.0000,-1,-1,-1);
	PojazdyMedykow[9] = AddStaticVehicleEx(489,1594.1327,1856.5399,11.0330,180.0000,-1,-1,-1);
	PojazdyMedykow[10] = AddStaticVehicleEx(563,1607.4521,1802.1949,33.9585,0.0000,-1,-1,-1);
	PojazdyMedykow[11] = AddStaticVehicleEx(452,1639.7074,573.4970,0.6802,185.3501,1,128,-1);

	PojazdyPolicji[0] = AddStaticVehicleEx(598,2314.0000000,2495.3999000,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[1] = AddStaticVehicleEx(598,2314.0000000,2490.1999500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[2] = AddStaticVehicleEx(598,2314.0000000,2485.3000500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[3] = AddStaticVehicleEx(598,2314.0000000,2480.1999500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[4] = AddStaticVehicleEx(598,2314.0000000,2475.1999500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[5] = AddStaticVehicleEx(598,2314.0000000,2469.8999000,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[6] = AddStaticVehicleEx(598,2314.0000000,2465.3999000,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[7] = AddStaticVehicleEx(598,2314.0000000,2460.3000500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[8] = AddStaticVehicleEx(598,2314.0000000,2455.6999500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[9] = AddStaticVehicleEx(427,2316.0000000,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[10] = AddStaticVehicleEx(597,-1606.1710,673.2775,6.9564,180.3967,6,1,-1); // sfpd-auto
	PojazdyPolicji[11] = AddStaticVehicleEx(597,-1600.0846,673.1047,6.9566,180.8190,6,1,-1); // sfpd-auto
	PojazdyPolicji[12] = AddStaticVehicleEx(597,-1616.2357,651.9667,6.9558,0.4393,6,1,-1); // sfpd-auto
	PojazdyPolicji[13] = AddStaticVehicleEx(597,-1622.5615,651.1688,6.9553,0.8535,6,1,-1); // sfpd-auto
	PojazdyPolicji[14] = AddStaticVehicleEx(597,-1599.6295,651.5461,6.9563,181.7888,6,1,-1); // sfpd-auto
	PojazdyPolicji[15] = AddStaticVehicleEx(599,-1608.4806,749.7832,-5.0530,180.4892,0,1,-1); // rancherpd
	PojazdyPolicji[16] = AddStaticVehicleEx(599,-1604.3413,748.5417,-5.0513,0.9673,0,1,-1); // rancherpd
	PojazdyPolicji[17] = AddStaticVehicleEx(599,-1600.6996,748.3405,-5.0544,359.4777,0,1,-1); // rancherpd
	PojazdyPolicji[18] = AddStaticVehicleEx(523,-1612.1935,732.6043,-5.6711,0.2843,0,0,-1); // motor
	PojazdyPolicji[19] = AddStaticVehicleEx(523,-1616.4330,731.9722,-5.6716,8.3414,0,0,-1); // motor
	PojazdyPolicji[20] = AddStaticVehicleEx(523,-1583.9906,750.8786,-5.6767,359.3375,0,0,-1); // motor
	PojazdyPolicji[21] = AddStaticVehicleEx(523,-1627.5835,738.6392,-5.6709,169.4659,0,0,-1); // rancherpd
	PojazdyPolicji[22] = AddStaticVehicleEx(497,-1681.5999756,705.5000000,30.8999996,88.0000000,6,1,-1); //Police Maverick
	PojazdyPolicji[23] = AddStaticVehicleEx(430,2503.1000977,-2268.3000488,0.0000000,270.0000000,1,1,-1); //Predator
	PojazdyPolicji[24] = AddStaticVehicleEx(430,2531.8000488,-2268.1999512,0.0000000,272.7500000,1,1,-1); //Predator
	PojazdyPolicji[25] = AddStaticVehicleEx(430,2541.1999512,-2257.5000000,0.0000000,180.0000000,1,1,-1); //Predator
	PojazdyPolicji[26] = AddStaticVehicleEx(427,2308.0000000,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[27] = AddStaticVehicleEx(427,2299.3000500,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[28] = AddStaticVehicleEx(427,2290.1999500,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[29] = AddStaticVehicleEx(427,2272.8999000,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[30] = AddStaticVehicleEx(427,2264.1999500,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[31] = AddStaticVehicleEx(427,2255.3000500,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[32] = AddStaticVehicleEx(427,2246.3999000,2431.0000000,3.5000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[33] = AddStaticVehicleEx(523,2285.6999500,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[34] = AddStaticVehicleEx(523,2281.3000500,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[35] = AddStaticVehicleEx(523,2277.0000000,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[36] = AddStaticVehicleEx(523,2272.8999000,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[37] = AddStaticVehicleEx(523,2268.1999500,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[38] = AddStaticVehicleEx(523,2264.1001000,2475.0000000,2.9000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[39] = AddStaticVehicleEx(599,2312.0000000,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[40] = AddStaticVehicleEx(599,2303.6999500,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[41] = AddStaticVehicleEx(599,2294.8999000,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[42] = AddStaticVehicleEx(599,2286.1999500,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[43] = AddStaticVehicleEx(599,2276.8999000,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[44] = AddStaticVehicleEx(599,2268.1001000,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[45] = AddStaticVehicleEx(599,2259.3000500,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[46] = AddStaticVehicleEx(599,2251.1001000,2431.0000000,3.7000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[47] = AddStaticVehicleEx(490,2298.0000000,2456.0000000,3.6000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[48] = AddStaticVehicleEx(490,2298.0000000,2460.3000500,3.6000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[49] = AddStaticVehicleEx(490,2298.0000000,2464.1999500,3.6000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[50] = AddStaticVehicleEx(490,2298.0000000,2451.6001000,3.6000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[51] = AddStaticVehicleEx(598,2314.0000000,2500.1999500,3.1000000,90.0000000,-1,-1,-1);
	PojazdyPolicji[52] = AddStaticVehicleEx(601,2307.6001000,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[53] = AddStaticVehicleEx(601,2299.1001000,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[54] = AddStaticVehicleEx(601,2289.8999000,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[55] = AddStaticVehicleEx(601,2272.5000000,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[56] = AddStaticVehicleEx(601,2263.8999000,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[57] = AddStaticVehicleEx(601,2255.3000500,2432.0000000,-7.5000000,0.0000000,245,245,-1);
	PojazdyPolicji[58] = AddStaticVehicleEx(528,2241.0000000,2437.5000000,-7.3000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[59] = AddStaticVehicleEx(528,2241.0000000,2442.3000500,-7.3000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[60] = AddStaticVehicleEx(528,2241.0000000,2447.0000000,-7.3000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[61] = AddStaticVehicleEx(528,2241.0000000,2471.1001000,-7.3000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[62] = AddStaticVehicleEx(528,2241.0000000,2475.5000000,-7.3000000,270.0000000,-1,-1,-1);
	PojazdyPolicji[63] = AddStaticVehicleEx(497,2343.1999500,2494.8000500,18.2000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[64] = AddStaticVehicleEx(497,2329.1999500,2494.5000000,18.2000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[65] = AddStaticVehicleEx(497,2314.6999500,2494.3999000,18.2000000,0.0000000,-1,-1,-1);
	PojazdyPolicji[66] = AddStaticVehicleEx(596,1585.2002000,-1667.7998000,5.6999998,270.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[67] = AddStaticVehicleEx(596,1585.5000000,-1671.5996000,5.6999998,270.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[68] = AddStaticVehicleEx(596,1601.5996000,-1667.2002000,5.6999998,90.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[69] = AddStaticVehicleEx(596,1601.7002000,-1670.5000000,5.6999998,90.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[70] = AddStaticVehicleEx(596,1602.2002000,-1673.7998000,5.6999998,90.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[71] = AddStaticVehicleEx(596,1601.7002000,-1677.4004000,5.6999998,90.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[72] = AddStaticVehicleEx(596,1601.4004000,-1683.5996000,5.6999998,90.0000000,16,1,-1); //Police Car (LSPD)
	PojazdyPolicji[73] = AddStaticVehicleEx(523,-2784.2000000,-2599.8999000,18.1000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[74] = AddStaticVehicleEx(523,-2782.1001000,-2598.7000000,18.1000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[75] = AddStaticVehicleEx(598,-2827.0000000,-2518.8999000,18.2000000,204.9940000,-1,-1,-1); //Police Car (LVPD)
	PojazdyPolicji[76] = AddStaticVehicleEx(598,-2814.8000000,-2513.1001000,18.2000000,204.9940000,-1,-1,-1); //Police Car (LVPD)
	PojazdyPolicji[77] = AddStaticVehicleEx(523,-2786.3999000,-2600.7000000,18.1000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[78] = AddStaticVehicleEx(490,1595.5000000,-1708.0996000,6.1999998,0.0000000,16,-1,-1); //FBI Rancher
	PojazdyPolicji[79] = AddStaticVehicleEx(490,1591.9004000,-1708.7002000,6.1999998,0.0000000,16,-1,-1); //FBI Rancher
	PojazdyPolicji[80] = AddStaticVehicleEx(490,1587.5000000,-1709.5000000,6.1999998,0.0000000,16,-1,-1); //FBI Rancher
	PojazdyPolicji[81] = AddStaticVehicleEx(490,1583.5000000,-1709.0996000,6.1999998,0.0000000,16,-1,-1); //FBI Rancher
	PojazdyPolicji[82] = AddStaticVehicleEx(599,1578.7002000,-1708.5996000,6.3000002,0.0000000,16,1,-1); //Police Ranger
	PojazdyPolicji[83] = AddStaticVehicleEx(599,1574.7002000,-1709.0996000,6.3000002,0.0000000,16,1,-1); //Police Ranger
	PojazdyPolicji[84] = AddStaticVehicleEx(599,1570.7002000,-1709.9004000,6.3000002,0.0000000,16,1,-1); //Police Ranger
	PojazdyPolicji[85] = AddStaticVehicleEx(599,1565.7998000,-1709.9004000,6.3000002,0.0000000,16,1,-1); //Police Ranger
	PojazdyPolicji[86] = AddStaticVehicleEx(599,1559.0000000,-1710.5000000,6.3000002,0.0000000,16,1,-1); //Police Ranger
	PojazdyPolicji[87] = AddStaticVehicleEx(528,1530.2998000,-1688.0000000,6.0999999,271.9995100,16,-1,-1); //FBI Truck
	PojazdyPolicji[88] = AddStaticVehicleEx(528,1530.0996000,-1684.2998000,6.0999999,271.9995100,16,-1,-1); //FBI Truck
	PojazdyPolicji[89] = AddStaticVehicleEx(427,1545.2002000,-1684.0000000,6.0999999,87.9949950,16,1,-1); //Enforcer
	PojazdyPolicji[90] = AddStaticVehicleEx(427,1544.9004000,-1680.2998000,6.0999999,87.9949950,16,1,-1); //Enforcer
	PojazdyPolicji[91] = AddStaticVehicleEx(427,1544.7998000,-1676.0000000,6.0999999,87.9949950,16,1,-1); //Enforcer
	PojazdyPolicji[92] = AddStaticVehicleEx(427,1544.5996000,-1671.7998000,6.0999999,87.9949950,16,1,-1); //Enforcer
	PojazdyPolicji[93] = AddStaticVehicleEx(427,1545.0996000,-1667.7998000,6.0999999,87.9949950,16,1,-1); //Enforcer
	PojazdyPolicji[94] = AddStaticVehicleEx(601,1544.7998000,-1662.4004000,5.8000002,90.0000000,16,16,-1); //S.W.A.T. Van
	PojazdyPolicji[95] = AddStaticVehicleEx(601,1544.9000000,-1659.3000000,5.8000000,90.0000000,-1,-1,-1); //S.W.A.T. Van
	PojazdyPolicji[96] = AddStaticVehicleEx(601,1544.4000000,-1655.0000000,5.8000000,90.0000000,-1,-1,-1); //S.W.A.T. Van
	PojazdyPolicji[97] = AddStaticVehicleEx(601,1544.0000000,-1651.1000000,5.8000000,90.0000000,-1,-1,-1); //S.W.A.T. Van
	PojazdyPolicji[98] = AddStaticVehicleEx(523,1537.8000000,-1645.4000000,5.6000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[99] = AddStaticVehicleEx(523,1534.8000000,-1644.5000000,5.6000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[76] = AddStaticVehicleEx(523,1530.2000000,-1645.0000000,5.6000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[101] = AddStaticVehicleEx(523,1526.5000000,-1645.1000000,5.6000000,0.0000000,-1,-1,-1); //HPV1000
	PojazdyPolicji[102] = AddStaticVehicleEx(497,1546.6000000,-1643.6000000,28.7000000,0.0000000,-1,-1,-1); //Police Maverick
	PojazdyPolicji[103] = AddStaticVehicleEx(497,1559.7000000,-1657.5000000,28.7000000,0.0000000,-1,-1,-1); //Police Maverick
	PojazdyPolicji[104] = AddStaticVehicleEx(430,1617.4662,590.1376,0.9114,180.0000,-1,-1,-1);
	PojazdyPolicji[105] = AddStaticVehicleEx(541,2240.2637,2452.1987,2.8982,271.3309,1,1,-1,1);
	PojazdyPolicji[106] = AddStaticVehicleEx(541,2240.1633,2447.1860,2.8984,270.0669,1,1,-1,1);
	PojazdyPolicji[107] = AddStaticVehicleEx(598,-2820.7000000,-2515.8999000,18.2000000,204.9940000,-1,-1,-1); //Police Car (LVPD)
	

	
	

	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"{000000}Policja",60,"Arial",24,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyPolicji[105],0,1.5,0.3,-90,0,180);
	
	tmpobj = CreateDynamicObject(19327,164.04025,1748.06201,17.87550,-85.00000,0.00000,180.00000);
	SetDynamicObjectMaterialText(tmpobj,0,"{000000}Policja",60,"Arial",24,1,0xFFFFFFFF,0,OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyPolicji[106],0,1.5,0.3,-90,0,180);

	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyPolicji[105],0,0.0,0.65,0,0,0);
	
	tmpobj = CreateDynamicObject(19419,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyPolicji[106],0,0.0,0.65,0,0,0);

	
	
	PojazdyVip[0] = AddStaticVehicleEx(482,2594.3000000,2251.0000000,11.0000000,0.0000000,8,37,-1); //Burrito
	PojazdyVip[1] = AddStaticVehicleEx(482,2589.6001000,2251.1001000,11.0000000,0.0000000,8,37,-1); //Burrito
	PojazdyVip[2] = AddStaticVehicleEx(482,2585.1001000,2251.1001000,11.0000000,0.0000000,8,37,-1); //Burrito
	PojazdyVip[3] = AddStaticVehicleEx(482,2580.8999000,2251.0000000,11.0000000,0.0000000,8,37,-1); //Burrito
	PojazdyVip[14] = AddStaticVehicleEx(459,2565.6001000,2249.5000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[15] = AddStaticVehicleEx(459,2565.7000000,2253.5000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[16] = AddStaticVehicleEx(459,2565.6001000,2257.8999000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[17] = AddStaticVehicleEx(459,2565.7000000,2262.3000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[18] = AddStaticVehicleEx(459,2565.8000000,2266.7000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[19] = AddStaticVehicleEx(459,2565.8000000,2271.3000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[20] = AddStaticVehicleEx(459,2565.8000000,2275.2000000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[22] = AddStaticVehicleEx(459,2565.8999000,2279.6001000,11.0000000,270.0000000,187,173,-1); //Berkley's RC Van
	PojazdyVip[21] = AddStaticVehicleEx(482,2609.8999000,2250.3999000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[23] = AddStaticVehicleEx(482,2609.8999000,2254.2000000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[24] = AddStaticVehicleEx(482,2610.0000000,2258.3000000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[25] = AddStaticVehicleEx(482,2609.8999000,2262.6001000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[26] = AddStaticVehicleEx(482,2610.0000000,2266.8999000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[27] = AddStaticVehicleEx(482,2610.0000000,2271.1001000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[28] = AddStaticVehicleEx(482,2610.1001000,2275.3000000,11.0000000,90.0000000,8,37,-1); //Burrito
	PojazdyVip[29] = AddStaticVehicleEx(482,2610.1001000,2279.6001000,11.0000000,90.0000000,8,37,-1); //Burrito
	SamolotyVip[0] = CreateVehicle(511,-1453.5743,-523.0653,16.3896,-149.7320,65,65,-1);
	SamolotyVip[1] = CreateVehicle(511,-1432.9092,-513.5718,16.3896,-161.2820,65,65,-1);
	SamolotyVip[2] = CreateVehicle(593,-1449.3787,-549.4901,15.0043,208.3760,65,65,-1);
	SamolotyVip[3] = CreateVehicle(593,-1415.4032,-533.1269,15.0043,208.3760,65,65,-1);
	SamolotyVip[4] = CreateVehicle(593,-1380.7849,-488.4975,14.9995,-157.5420,65,65,-1);
	SamolotyVip[5] = CreateVehicle(593,-1360.8700,-480.3741,14.9995,-157.5420,65,65,-1);
	
	PojazdyAdmin[0] = AddStaticVehicle(449,-2265.3921,525.4000,35.8584,0.0000,-1,-1);
	PojazdyAdmin[1] = CreateVehicle(601,29.6159,1480.0641,12.6760,28.4255,1,1,-1);
	PojazdyAdmin[2] = CreateVehicle(601,-9.9775,1579.7030,12.6760,257.8572,1,1,-1);
	PojazdyAdmin[3] = AddStaticVehicleEx(592,-1335.1683,-604.1883,15.4000,0.0000,6,6,-1);
	PojazdyAdmin[4] = AddStaticVehicleEx(452,1364.6046,-4661.0293,-0.0120,0.0000,-1,-1,-1,1); // ≥Ûdka wyspa
	
	PojazdyAdmin[6] = AddStaticVehicleEx(409,58.9027,1484.3182,13.7070,0.0000,0,0,-1,1);
	AddVehicleComponent(PojazdyAdmin[6],1010);
	AddVehicleComponent(PojazdyAdmin[6],1080);
	tmpobj = CreateDynamicObject(18646,163.00000,9908.00000,1747.00000,0.00000,0.00000,0.00000);
	AttachDynamicObjectToVehicle(tmpobj,PojazdyAdmin[6],0.2,0.6,0.8,0,0,0);
	
	AutaMiniJob[0] = AddStaticVehicleEx(574,1626.8466,2199.1277,10.5453,180.1867,1,0,-1); // wozek1
	AutaMiniJob[1] = AddStaticVehicleEx(574,1632.5710,2198.4353,10.5455,179.1658,101,0,-1); // wozek2
	AutaMiniJob[2] = AddStaticVehicleEx(574,1638.0155,2199.1848,10.5453,179.4261,106,0,-1); // wozek3
	AutaMiniJob[3] = AddStaticVehicleEx(574,1643.8687,2199.1675,10.5455,179.8374,108,0,-1); // wozek4
	AutaMiniJob[4] = AddStaticVehicleEx(574,1649.4288,2199.1494,10.5453,179.4306,126,0,-1); // wozek5
	
	AutaMiniJob[5] = AddStaticVehicleEx(532,-40.9100,-17.3382,4.2285,85.0000,-1,-1,100);
	AutaMiniJob[6] = AddStaticVehicleEx(532,-39.7735,-6.3831,4.2285,85.0000,-1,-1,100);
	AutaMiniJob[7] = AddStaticVehicleEx(532,-31.4185,-1.2220,4.2285,0.0000,-1,-1,100);
	AutaMiniJob[8] = AddStaticVehicleEx(532,-79.4813,-9.4865,4.2285,-85.0000,-1,-1,100);
	AutaMiniJob[13] = CreateVehicle(572,1417.4767,2768.2742,10.5000,90.0000,-1,-1,100);
	AutaMiniJob[14] = CreateVehicle(572,1417.5927,2766.0596,10.5000,90.0000,-1,-1,100);
	AutaMiniJob[15] = CreateVehicle(572,1417.5087,2763.6917,10.5000,90.0000,-1,-1,100);
	AutaMiniJob[16] = CreateVehicle(572,1417.6039,2761.2869,10.5000,90.0000,-1,-1,100);
	AutaMiniJob[17] = CreateVehicle(572,1417.6559,2758.8167,10.5000,90.0000,-1,-1,100);

	PojazdyWojska[0] = AddStaticVehicleEx(446,1639.4072,591.6166,-0.4713,180.0000,30,30,-1);//lodz LV
	PojazdyWojska[1] = 	AddStaticVehicleEx(409,243.5000,1858.3000,-3.5000,50.5000,-1,-1,-1);
	PojazdyWojska[2] = 	AddStaticVehicleEx(425,353.5996,2028.5000,23.4000,124.0000,-1,-1,-1);
	PojazdyWojska[3] = 	AddStaticVehicleEx(548,315.2000,2077.3999,19.8000,180.0000,-1,-1,-1);
	PojazdyWojska[4] = 	AddStaticVehicleEx(548,282.7000,2077.8999,20.0000,180.0000,-1,-1,-1);
	PojazdyWojska[5] = 	AddStaticVehicleEx(432,275.7000,2002.0000,17.7000,270.0000,-1,-1,-1);
	PojazdyWojska[6] = 	AddStaticVehicleEx(432,275.6000,2012.2000,17.7000,270.0000,-1,-1,-1);
	PojazdyWojska[7] = 	AddStaticVehicleEx(520,376.9000,1976.9000,18.3000,61.0000,-1,-1,-1);
	PojazdyWojska[8] = 	AddStaticVehicleEx(520,377.3000,1991.5000,18.3000,119.0000,-1,-1,-1);
	PojazdyWojska[9] = 	AddStaticVehicleEx(476,379.8000,1962.4000,18.8000,110.0000,-1,-1,-1);
	PojazdyWojska[10] = AddStaticVehicleEx(476,379.6000,1946.9000,18.8000,70.0000,-1,-1,-1);
	PojazdyWojska[11] = AddStaticVehicleEx(470,280.9000,1936.4000,17.7000,315.0000,-1,-1,-1);
	PojazdyWojska[12] = AddStaticVehicleEx(470,268.9000,1944.8000,17.7000,270.0000,-1,-1,-1);
	PojazdyWojska[14] = AddStaticVehicleEx(470,280.8000,1959.3000,17.7000,225.0000,-1,-1,-1);
	PojazdyWojska[13] = AddStaticVehicleEx(470,269.0000,1949.0000,17.7000,270.0000,-1,-1,-1);
	PojazdyWojska[15] = AddStaticVehicleEx(470,276.5000,1936.8000,17.7000,315.0000,-1,-1,-1);
	PojazdyWojska[16] = AddStaticVehicleEx(470,272.0000,1936.9000,17.7000,315.0000,-1,-1,-1);
	PojazdyWojska[17] = AddStaticVehicleEx(470,269.9000,1940.4000,17.7000,296.7500,-1,-1,-1);
	PojazdyWojska[18] = AddStaticVehicleEx(470,276.3000,1958.6000,17.7000,225.0000,-1,-1,-1);
	PojazdyWojska[19] = AddStaticVehicleEx(470,272.4000,1957.5000,17.7000,225.0000,-1,-1,-1);
	PojazdyWojska[20] = AddStaticVehicleEx(470,270.0000,1953.8000,17.7000,243.2500,-1,-1,-1);
	PojazdyWojska[21] = AddStaticVehicleEx(433,280.0000,1988.1000,18.1000,225.0000,-1,-1,-1);
	PojazdyWojska[22] = AddStaticVehicleEx(433,273.8000,1987.3000,18.1000,225.0000,-1,-1,-1);
	PojazdyWojska[23] = AddStaticVehicleEx(433,280.8000,1967.6000,18.1000,315.0000,-1,-1,-1);
	PojazdyWojska[24] = AddStaticVehicleEx(433,274.4000,1967.8000,18.1000,315.0000,-1,-1,-1);
	PojazdyWojska[25] = AddStaticVehicleEx(433,271.5000,1974.0000,18.1000,283.5000,-1,-1,-1);
	PojazdyWojska[26] = AddStaticVehicleEx(433,271.0000,1981.8000,18.1000,254.7500,-1,-1,-1);
	PojazdyWojska[27] = AddStaticVehicleEx(470,234.8000,1861.9000,-3.3000,142.0000,-1,-1,-1);
	PojazdyWojska[28] = AddStaticVehicleEx(470,230.6000,1856.4000,-3.3000,141.9980,-1,-1,-1);
	PojazdySP[0] = AddStaticVehicleEx(489,1021.1000000,2363.6001000,11.0000000,90.0000000,222,-1,-1); //Rancher
	PojazdySP[1] = AddStaticVehicleEx(489,1021.0000000,2377.1001000,11.0000000,90.0000000,222,-1,-1); //Rancher
	PojazdySP[2] = AddStaticVehicleEx(544,1031.6000000,2377.1001000,11.0000000,0.0000000,222,-1,-1); //Firetruck LA
	PojazdySP[3] = AddStaticVehicleEx(544,1047.7000000,2377.8999000,11.0000000,0.0000000,222,-1,-1); //Firetruck LA
	PojazdySP[4] = AddStaticVehicleEx(544,1070.7000000,2377.8999000,11.0000000,0.0000000,222,-1,-1); //Firetruck LA
	PojazdySP[5] = AddStaticVehicleEx(407,1075.5000000,2377.6001000,11.0000000,0.0000000,222,-1,-1); //Firetruck
	PojazdySP[6] = AddStaticVehicleEx(407,1053.8000000,2377.3999000,11.0000000,0.0000000,222,-1,-1); //Firetruck
	PojazdySP[7] = AddStaticVehicleEx(407,1027.2998000,2376.5000000,11.0000000,0.0000000,222,-1,-1); //Firetruck
	PojazdySP[8] = AddStaticVehicleEx(407,1037.2000000,2354.5000000,11.0000000,0.0000000,222,-1,-1); //Firetruck
	PojazdySP[9] = AddStaticVehicleEx(407,1033.2000000,2354.3999000,11.0000000,0.0000000,222,-1,-1); //Firetruck
	PojazdySP[10] = AddStaticVehicleEx(552,1054.7000000,2348.3000000,10.6000000,0.0000000,222,-1,-1); //Utility
	PojazdySP[11] = AddStaticVehicleEx(552,1054.8000000,2355.5000000,10.6000000,0.0000000,222,-1,-1); //Utility
	PojazdySP[12] = AddStaticVehicleEx(563,1105.7000000,2393.2000000,12.1000000,90.0000000,222,-1,-1); //Raindance
	
	
	
	
	
	
	
	//lotnisko LV garaø
	CreateVehicle(525,1283.8635,1333.7008,10.7317,-90.0000,93,93,-1);
	CreateVehicle(485,1284.2991,1329.0375,10.7285,-90.0000,93,93,-1);
	CreateVehicle(485,1284.5974,1325.1035,10.7285,-90.0000,-1,-1,-1);
	CreateVehicle(485,1284.3569,1321.8953,10.7285,-90.0000,-1,-1,-1);
	CreateVehicle(608,1281.4891,1314.7660,11.1965,-90.0000,-1,-1,100);
	CreateVehicle(608,1281.8656,1317.3688,11.1965,-90.0000,93,93,100);
	CreateVehicle(606,1279.3978,1329.0603,10.8000,-90.0000,-1,-1,-1);
	CreateVehicle(607,1279.6088,1321.8196,11.2023,-90.0000,93,93,-1);
	//bb obiekty
	CreateVehicle(457,123.5846,-87.2649,1.3000,-90.0000,-1,-1,100);
	CreateVehicle(457,123.7430,-90.9192,1.3000,-90.0000,-1,-1,100);
	CreateVehicle(457,123.5994,-94.5341,1.3000,-90.0000,-1,-1,100);
	
	//szpital ls
	CreateVehicle(457,2036.3950,-1441.5537,16.9318,90.0000,145,145,100);
	CreateVehicle(457,2036.4142,-1439.4067,16.8118,90.0000,145,145,100);
	CreateVehicle(457,2036.0778,-1432.7849,16.8118,90.0000,145,145,100);
	CreateVehicle(457,2036.1749,-1435.0002,16.8118,90.0000,145,145,100);
	CreateVehicle(457,2036.2899,-1437.2196,16.8118,90.0000,145,145,100);

	CreateVehicle(531,1532.5668,788.4486,11.1901,180.0000,-1,-1,100);
	CreateVehicle(531,1544.7019,787.9545,11.1901,180.0000,-1,-1,100);
	CreateVehicle(531,1538.5592,788.0353,11.1901,180.0000,-1,-1,100);
	CreateVehicle(531,1547.8217,788.1700,11.1901,180.0000,-1,-1,100);
	CreateVehicle(531,1541.5454,788.1404,11.1901,180.0000,-1,-1,100);
	CreateVehicle(531,1535.4093,788.2581,11.1901,180.0000,-1,-1,100);


	AddStaticVehicleEx(514,1460.3008,2838.0830,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1465.4766,2838.0830,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1470.5179,2838.0830,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1475.1906,2838.0830,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1479.9973,2838.0830,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1485.0226,2838.0830,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1489.6676,2838.0830,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1494.3258,2838.0830,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1429.0414,2878.1870,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1433.6533,2877.9783,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1442.6088,2877.9717,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(543,1438.1132,2877.8950,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(543,1446.8281,2878.0549,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(543,1451.3076,2878.1687,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1455.8027,2877.9338,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(543,1460.3749,2877.9392,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1464.9072,2878.0459,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(478,1469.3896,2877.9353,10.6400,180.0000,-1,-1,-1);
	AddStaticVehicleEx(498,1422.9745,2842.8750,10.8500,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(498,1423.2018,2834.5803,10.8500,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(498,1423.2407,2826.0588,10.8500,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(498,1423.4774,2851.9678,10.8500,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(609,1423.0410,2859.9580,10.7530,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(609,1423.1356,2868.7866,10.7530,-90.0000,-1,-1,-1);
	AddStaticVehicleEx(450,1494.5389,2847.9414,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(450,1484.9008,2848.2546,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(450,1470.4941,2847.8943,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(450,1460.3519,2848.3936,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(591,1475.0559,2847.5142,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(591,1480.0831,2848.2695,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(591,1465.4166,2848.2156,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(591,1489.9316,2847.9343,11.3934,180.0000,-1,-1,-1);
	AddStaticVehicleEx(435,1529.0559,2862.6184,11.3483,90.0000,-1,-1,-1);
	AddStaticVehicleEx(435,1528.4456,2849.3708,11.3483,90.0000,-1,-1,-1);
	AddStaticVehicleEx(435,1527.9418,2836.3892,11.3483,90.0000,-1,-1,-1);
	AddStaticVehicleEx(435,1528.0804,2823.0417,11.3483,90.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1513.7107,2877.2676,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1504.8409,2877.0652,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1495.7826,2876.7566,11.2000,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1487.4229,2876.2158,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1478.4270,2875.7241,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1522.5051,2875.9812,11.2470,180.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1527.6526,2818.2034,11.2470,90.0000,-1,-1,-1);
	AddStaticVehicleEx(514,1527.7589,2809.0479,11.2470,90.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1528.1830,2813.5715,11.2000,90.0000,-1,-1,-1);
	AddStaticVehicleEx(403,1528.3793,2800.3054,11.2000,90.0000,-1,-1,-1);
	
	//salon sf
	CreateVehicle(411,-1954.8000000,271.6000100,40.8000000,32.0000000,70,15,15); //Infernus
	CreateVehicle(451,-1955.5000000,260.5996100,40.8000000,24.0000000,6,9,15); //Turismo
	CreateVehicle(562,-1959.8000000,270.7999900,35.2000000,36.0000000,255,255,15); //Elegy
	CreateVehicle(560,-1961.8000000,259.3999900,35.3000000,32.0000000,28,51,15); //Sultan
	CreateVehicle(492,-1949.0000000,259.2999900,35.4000000,32.0000000,-1,-1,15); //Greenwood
	CreateVehicle(534,-1961.5000000,285.1000100,35.3000000,42.0000000,12,8,15); //Remington
	CreateVehicle(535,-1950.6000000,271.7999900,35.3000000,44.0000000,73,2,15); //Slamvan
	CreateVehicle(542,-1946.8000000,262.0000000,40.9000000,30.0000000,-1,-1,15); //Clover
}