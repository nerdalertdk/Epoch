/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for vr.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/vr.h
*/
class VR : Default
{
	worldSize = 10000;
	plantLimit = 0;
	vehicleSpawnTypes[] = {};
	radioactiveLocations[] = {};
	radioactiveLocationsCount = 0;
	allowedVehiclesList[] = {};
	shipwreckLootEnabled = 0;
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098, 0]
		// S [-0.415527,-7.05298,-10.3098, 180]
		// E [13.5127,0.410156,-10.3098, 90]
		// W [-14.4316,0.112793,-10.3098, -90]
		{ "TP_Booth_c_EPOCH", { -0.286865, 8.17383, -10.3098, 0}, "", { 4089.82, 4597.71, 0.00143433 } }
	};
	lightPos[] = {};
	debugBoxClass = "";
	cloneClasses[] = {};
	propsPos[] = {};
	staticNpcPos[] = {};
};
